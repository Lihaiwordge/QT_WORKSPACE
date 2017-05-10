#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include "QString"
#include <QSound>

QVector<double> x(500), y(500);

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    strWavPath=QCoreApplication::applicationDirPath();
    strWavPath+="/1822.wav";
    sound = new QSound(strWavPath, this);
    // 初始化串口
    serialPort = new QSerialPort;
    serialPort->setBaudRate(QSerialPort::Baud115200);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);
    connect(serialPort,SIGNAL(readyRead()),this,SLOT(RxData()));
    // 初始化Timer
    serialRead  = false;
    serialTimer = new QTimer;
    connect(serialTimer,SIGNAL(timeout()),this,SLOT(SerialTimeOut()));
    serialTimer->start(10);

    tempCheckTimer = new QTimer;
    connect(tempCheckTimer,SIGNAL(timeout()),this,SLOT(TempCheckTimeOut()));
    tempCheckTimer->start(100); // 100ms检测一次
    //  初始化变量
    xcount = 0;
    xrange = 50;
    ui->plot->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom)); // period as decimal separator and comma as thousand separator
    ui->plot->legend->setVisible(true);
    QFont legendFont = font();  // start out with MainWindow's font..
    legendFont.setPointSize(9); // and make a bit smaller for legend
    ui->plot->legend->setFont(legendFont);
    ui->plot->legend->setBrush(QBrush(QColor(255,255,255,230)));
    // by default, the legend is in the inset layout of the main axis rect. So this is how we access it to change legend placement:
    ui->plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom|Qt::AlignRight);
    // 生成数据，画出的是抛物线
    ui->plot->addGraph();
    // 为坐标轴添加标签
    ui->plot->xAxis->setLabel("x");
    ui->plot->yAxis->setLabel("y");
    // 设置坐标轴的范围，以看到所有数据
    ui->plot->xAxis->setRange(0, xrange);
    ui-> plot->yAxis->setRange(0, 50);

    // 初始化ui
    ui->pushButton_startDevice->setEnabled(true);
    ui->pushButton_stopDevice->setEnabled(false);
    ui->label_diatemp->setText("警戒温度:"+QString::number(40.0)+"℃");
    ui->dial->setValue(400);
    setPloyTemp = 40.0;

}

Widget::~Widget()
{
    delete ui;
}

void Widget::SerialTimeOut()
{
    serialRead = true;
}

void Widget::TempCheckTimeOut()
{
    if( setPloyTemp < ds18b20SensorTemp  ) {    // 报警
        ui->pushButton_light->setStyleSheet("background-color: rgb(170, 0, 255);");
        if( playFlag == false ) {
            sound->play();//播放
            sound->setLoops(100);
            playFlag = true;
        }

    }else{
        ui->pushButton_light->setStyleSheet("background-color: rgb(170, 255, 0);");
        sound->stop();
        playFlag = false;
    }

}

void Widget::on_pushButton_startDevice_clicked()
{
    QString portName;
    u_int num = 0;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        QSerialPort serial;
        serial.setPort(info);
        num ++;
        if (serial.open(QIODevice::ReadWrite))
        {

            portName = info.portName();
            ui->textBrowser->append( tr("SYSTEM: 扫描到串口") + info.portName() );
            serialPort->setPortName(info.portName());
            //serial.close();
        }
    }
    if (!serialPort->open(QIODevice::ReadWrite)) {
        QMessageBox::warning(this,"Warring","Open serial port fail!");
        ui->textBrowser->append(tr("SYSTEM: 串口打开失败，请检查串口是否被其他软件占用，或检查串口连接是否正常！"));

    }else {
        ui->textBrowser->append("SYSTEM: 系统检测当前有"+QString::number(num)+"个串口正在和计算机连接！");
        ui->textBrowser->append(tr("SYSTEM: 已经和")+portName+tr("建立连接.."));
        qDebug() << "The serial has been openned!! \n";
        ui->pushButton_startDevice->setEnabled(false);
        ui->pushButton_stopDevice->setEnabled(true);
    }


}

void Widget::RxData()
{

    QString rxString;

    if( serialRead == true ) {
        rxString = serialPort->readAll();
        rec_cmd += rxString;
        rxString.clear();
        if( rec_cmd.length() >=  30 ) {
            ui->textBrowser->append("REC:"+rec_cmd.toUtf8().toHex());
            qDebug() << rec_cmd ;
            ProcessData(rec_cmd);
            serialRead = false;
            rec_cmd.clear();

        }
    }
}
int ms_50 = 0;
void Widget::ProcessData( QString cmd )
{
    double error;
    if( cmd.at(0) != '#' ) {
        return ;
    }
    QList<QString> tempValueStringList = cmd.split('#');
    for( int i = 0; i < tempValueStringList.length(); i++) {
        qDebug() << tempValueStringList.at(i) << "\n";
    }

    lm75aSensorTemp = tempValueStringList.at(2).toDouble();
    resSensorTemp = tempValueStringList.at(3).toDouble();
    if(ui->checkBox->checkState() == Qt::Checked) {
        error = 3.6703;
    }else{
        error = 0.0;
    }
    ds18b20SensorTemp = tempValueStringList.at(1).toDouble()+ (resSensorTemp * 0.00127) + error;

    qDebug() << tr("DS18B20 TEMP:") << ds18b20SensorTemp << "\n";
    qDebug() << tr("LM75A TEMP:") << lm75aSensorTemp << "\n";
    qDebug() << tr("Res TEMP:") << resSensorTemp << "\n";

    ui->lcdNumber->display(QString::number(ds18b20SensorTemp));
    ui->label_currentTemp->setText(QString::number(ds18b20SensorTemp)+"℃");
    ui->plot->graph(0)->addData(xcount,ds18b20SensorTemp);
    ui->plot->replot();
    xcount ++;
    if(xcount%50 == 0 ) {
        ms_50 ++;
        ui->plot->xAxis->setRange(0, xrange * ms_50 + 50);
    }


}

void Widget::on_pushButton_stopDevice_clicked()
{
    serialPort->close();

    QMessageBox::information(this,"Success", "Serial port has been closed!");
    ui->textBrowser->append(tr("SYSTEM: 已经断开通信端口，现在无法使用软件！"));
    ui->pushButton_stopDevice->setEnabled(false);
    ui->pushButton_startDevice->setEnabled(true);
}

void Widget::on_dial_valueChanged(int value)
{

    setPloyTemp = (float)value/10;
    ui->label_diatemp->setText("警戒温度:"+QString::number(setPloyTemp)+"℃");
    playFlag = false;


}

void Widget::on_pushButton_light_clicked()
{
    sound->stop();
    playFlag = true;
}
