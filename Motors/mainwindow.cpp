#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Motors GUI");

    serialPort = new QSerialPort;
    serialPort->setBaudRate(QSerialPort::Baud9600);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    connect(serialPort,SIGNAL(readyRead()),this,SLOT(RxData()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


//start button
void MainWindow::on_pushButton_Start_clicked()
{
    ui->textBrowser->append(tr("Search port list:"));
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        QSerialPort serial;
        serial.setPort(info);
        if (serial.open(QIODevice::ReadWrite))
        {
            //ui->textBrowser->append(info.portName());
            serialPort->setPortName(info.portName());
            ui->textBrowser->append(info.portName() +"  " + info.description()/* +info.manufacturer()*/);
            serial.close();
        }
    }
    if (!serialPort->open(QIODevice::ReadWrite))
    {
        QMessageBox::warning(this,"Warring","Open serial port fail!");
    }
    else
    {
        ui->textBrowser->append("Open " + serialPort->portName() + " OK." );
        QByteArray ByteDtat;
        ByteDtat.append(0xAA);       //head1
        ByteDtat.append(0xBB);       //head2
        ByteDtat.append(0xAC);       //cmd
        ByteDtat.append((char)0x00);//data
        uchar checkSum = 0xAA ^ 0xBB ^ 0xAC ^ 0x00;
        ByteDtat.append(checkSum);   //check
        serialPort->write(ByteDtat); //send data
        ui->textBrowser->append("Start all  Motors.");
    }

}

//dial_1
void MainWindow::on_dial_1_sliderReleased()
{
    qint8  dial_valus = ui->dial_1->value();
    ui->label_Motor1->setText(QString::number(dial_valus,10) + "%");
    QByteArray ByteDtat;
    ByteDtat.append(0xAA);       //head1
    ByteDtat.append(0xBB);       //head2
    ByteDtat.append(0x01);       //cmd
    ByteDtat.append(dial_valus); //data
    uchar checkSum = 0xAA ^ 0xBB ^ 0x01 ^ dial_valus;
    ByteDtat.append(checkSum);   //check
    serialPort->write(ByteDtat); //send data
}

void MainWindow::on_dial_2_sliderReleased()
{
    qint8  dial_valus = ui->dial_2->value();
    ui->label_Motor2->setText(QString::number(dial_valus,10) + "%");
    QByteArray ByteDtat;
    ByteDtat.append(0xAA);       //head1
    ByteDtat.append(0xBB);       //head2
    ByteDtat.append(0x02);       //cmd
    ByteDtat.append(dial_valus);//data
    uchar checkSum = 0xAA ^ 0xBB ^ 0x02 ^ dial_valus;
    ByteDtat.append(checkSum);   //check
    serialPort->write(ByteDtat); //send data
}

void MainWindow::on_dial_3_sliderReleased()
{
    qint8  dial_valus = ui->dial_3->value();
    ui->label_Motor3->setText(QString::number(dial_valus,10) + "%");
    QByteArray ByteDtat;
    ByteDtat.append(0xAA);       //head1
    ByteDtat.append(0xBB);       //head2
    ByteDtat.append(0x03);       //cmd
    ByteDtat.append(dial_valus);//data
    uchar checkSum = 0xAA ^ 0xBB ^ 0x03 ^ dial_valus;
    ByteDtat.append(checkSum);   //check
    serialPort->write(ByteDtat); //send data
}

void MainWindow::on_dial_4_sliderReleased()
{
    qint8  dial_valus = ui->dial_4->value();
    ui->label_Motor4->setText(QString::number(dial_valus,10) + "%");
    QByteArray ByteDtat;
    ByteDtat.append(0xAA);       //head1
    ByteDtat.append(0xBB);       //head2
    ByteDtat.append(0x04);       //cmd
    ByteDtat.append(dial_valus); //data
    uchar checkSum = 0xAA ^ 0xBB ^ 0x04 ^ dial_valus;
    ByteDtat.append(checkSum);   //check
    serialPort->write(ByteDtat); //send data
}

//send command
void MainWindow::on_pushButton_clicked()
{
    QString LineString = ui->lineEdit->text();
    serialPort->write(LineString.toLatin1()); //send data
}

//串口接收数据槽函数
void MainWindow::RxData()
{
    QByteArray ByteRxData = serialPort->readAll();
    QString StringRxData = ByteRxData.toHex();
    ui->textBrowser->append(StringRxData);
    qDebug()<<"StringRxData"<<StringRxData;
    qDebug()<<"ByteRxData"<<ByteRxData;
    bool ok;
    if (StringRxData.left(4) == "aabb")
    {
        if (StringRxData.mid(4,2) == "0a")      // processBar alpha
        {
            ui->progressBar_1->setValue(StringRxData.mid(6,2).toInt(&ok,16));
        }
        else if (StringRxData.mid(4,2) == "0b") //processBar beta
        {
            ui->progressBar_2->setValue(StringRxData.mid(6,2).toInt(&ok,16));
        }
        else if (StringRxData.mid(4,2) == "10") //dial_1
        {
            qDebug()<<"StringRxData.mid(6,2).toInt()"<<StringRxData.mid(6,2).toInt(&ok,16);
            ui->dial_1->setValue(StringRxData.mid(6,2).toInt(&ok,16));
        }
        else if (StringRxData.mid(4,2) == "11") //dial_2
        {
            ui->dial_2->setValue(StringRxData.mid(6,2).toInt(&ok,16));
        }
        else if (StringRxData.mid(4,2) == "12") //dial_3
        {
            ui->dial_3->setValue(StringRxData.mid(6,2).toInt(&ok,16));
        }
        else if (StringRxData.mid(4,2) == "13") //dial_4
        {
            ui->dial_4->setValue(StringRxData.mid(6,2).toInt(&ok,16));
            //ui->textBrowser->append("");
        }
        else if (StringRxData.mid(4,4) == "ff00")
        {
            ui->textBrowser->append("Message :-> DSP return smile!!");
        }
        else if (StringRxData.mid(4,4) == "ff01")
        {
            ui->textBrowser->append("Message :-> DSP return error!!");
        }
    }






}

//停止电机
void MainWindow::on_pushButton_Stop_clicked()
{
    if (serialPort->isOpen()) serialPort->close();
    QByteArray ByteDtat;
    ByteDtat.append(0xAA);       //head1
    ByteDtat.append(0xBB);       //head2
    ByteDtat.append(0xBD);       //cmd
    ByteDtat.append((char)0x00);//data
    uchar checkSum = 0xAA ^ 0xBB ^ 0xBD ^ 0x00;
    ByteDtat.append(checkSum);   //check
    serialPort->write(ByteDtat); //send data
    ui->textBrowser->clear();
    ui->textBrowser->append("Message :-> Stop all Motors.");
}


//set 抽取总量 channel
void MainWindow::on_pushButton_8_clicked()
{
    qint8 value = ui->spinBox_1->value();
    QByteArray ByteDtat;
    ByteDtat.append(0xAA);       //head1
    ByteDtat.append(0xBB);       //head2
    ByteDtat.append(0x05);       //cmd
    ByteDtat.append(value);        //data
    uchar checkSum = 0xAA ^ 0xBB ^ 0x05 ^ value;
    ByteDtat.append(checkSum);   //check
    serialPort->write(ByteDtat); //send data
    ui->textBrowser->append("Message :-> System has been set Alpha channel total!!!");
}

void MainWindow::on_pushButton_9_clicked()
{
    qint8 value = ui->spinBox_2->value();
    QByteArray ByteDtat;
    ByteDtat.append(0xAA);       //head1
    ByteDtat.append(0xBB);       //head2
    ByteDtat.append(0x06);       //cmd
    ByteDtat.append(value);        //data
    uchar checkSum = 0xAA ^ 0xBB ^ 0x06 ^ value;
    ByteDtat.append(checkSum);   //check
    serialPort->write(ByteDtat); //send data
    ui->textBrowser->append("Message :-> System has been set Beta channel total!!!");
}

void MainWindow::on_pushButton_10_clicked()
{
    qint8 value = ui->spinBox_3->value();
    QByteArray ByteDtat;
    ByteDtat.append(0xAA);       //head1
    ByteDtat.append(0xBB);       //head2
    ByteDtat.append(0x07);       //cmd
    ByteDtat.append(value);        //data
    uchar checkSum = 0xAA ^ 0xBB ^ 0x07 ^ value;
    ByteDtat.append(checkSum);   //check
    serialPort->write(ByteDtat); //send data
    ui->textBrowser->append("Message :-> System has been set Gamma channel total!!!");
}

void MainWindow::on_pushButton_11_clicked()
{
    qint8 value = ui->spinBox_4->value();
    QByteArray ByteDtat;
    ByteDtat.append(0xAA);       //head1
    ByteDtat.append(0xBB);       //head2
    ByteDtat.append(0x08);       //cmd
    ByteDtat.append(value);        //data
    uchar checkSum = 0xAA ^ 0xBB ^ 0x08 ^ value;
    ByteDtat.append(checkSum);   //check
    serialPort->write(ByteDtat); //send data
    ui->textBrowser->append("Message :-> System has been set Delta channel total!!!");
}


//开始抽取命令
void MainWindow::on_pushButton_2_clicked()
{
    QByteArray ByteDtat;
    ByteDtat.append(0xAA);       //head1
    ByteDtat.append(0xBB);       //head2
    ByteDtat.append(0x0C);       //cmd
    ByteDtat.append((char)0x00); //data
    uchar checkSum = 0xAA ^ 0xBB ^ 0x0C;
    ByteDtat.append(checkSum);   //check
    serialPort->write(ByteDtat); //send data
    ui->textBrowser->append("Message :-> DSP extracting Alpha channel !!!");
}

void MainWindow::on_pushButton_3_clicked()
{
    QByteArray ByteDtat;
    ByteDtat.append(0xAA);       //head1
    ByteDtat.append(0xBB);       //head2
    ByteDtat.append(0x0D);       //cmd
    ByteDtat.append((char)0x00); //data
    uchar checkSum = 0xAA ^ 0xBB ^ 0x0D;
    ByteDtat.append(checkSum);   //check
    serialPort->write(ByteDtat); //send data
    ui->textBrowser->append("Message :-> DSP extracting Beta channel !!!");
}

void MainWindow::on_pushButton_4_clicked()
{
    QByteArray ByteDtat;
    ByteDtat.append(0xAA);       //head1
    ByteDtat.append(0xBB);       //head2
    ByteDtat.append(0x0E);       //cmd
    ByteDtat.append((char)0x00); //data
    uchar checkSum = 0xAA ^ 0xBB ^ 0x0E;
    ByteDtat.append(checkSum);   //check
    serialPort->write(ByteDtat); //send data
    ui->textBrowser->append("Message :-> DSP extracting Gamma channel !!!");
}

void MainWindow::on_pushButton_5_clicked()
{
    QByteArray ByteDtat;
    ByteDtat.append(0xAA);       //head1
    ByteDtat.append(0xBB);       //head2
    ByteDtat.append(0x0F);       //cmd
    ByteDtat.append((char)0x00); //data
    uchar checkSum = 0xAA ^ 0xBB ^ 0x0F;
    ByteDtat.append(checkSum);   //check
    serialPort->write(ByteDtat); //send data
    ui->textBrowser->append("Message :-> DSP extracting Delta channel !!!");
}

//加温开
void MainWindow::on_pushButton_6_clicked()
{
    QByteArray ByteDtat;
    ByteDtat.append(0xAA);       //head1
    ByteDtat.append(0xBB);       //head2
    ByteDtat.append(0x14);       //cmd
    ByteDtat.append((char)0x00); //data
    uchar checkSum = 0xAA ^ 0xBB ^ 0x14;
    ByteDtat.append(checkSum);   //check
    serialPort->write(ByteDtat); //send data
    ui->textBrowser->append("Message :-> Heating start  !!!");
}
//加温关
void MainWindow::on_pushButton_7_clicked()
{
    QByteArray ByteDtat;
    ByteDtat.append(0xAA);       //head1
    ByteDtat.append(0xBB);       //head2
    ByteDtat.append(0x14);       //cmd
    ByteDtat.append(0x01);       //data
    uchar checkSum = 0xAA ^ 0xBB ^ 0x14 ^ 0x01;
    ByteDtat.append(checkSum);   //check
    serialPort->write(ByteDtat); //send data
    ui->textBrowser->append("Message :-> Heating halt  !!!");
}


