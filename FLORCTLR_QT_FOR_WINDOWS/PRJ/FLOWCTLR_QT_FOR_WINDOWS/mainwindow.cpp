#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "QString"
#include "QDateTime"
#include "comcmd.h"
#include "QFile"
#include "QFileDialog"
void sleep(unsigned int msec);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize( QSize( 800, 450 ));
    this->setWindowTitle("流速控制系统");
    flag_cyc_rec_ok = new bool();
    flag_sin_rec_ok = new bool();
    // 初始化UI
    ui->pushButton_setLink->setEnabled(true);
    ui->pushButton_disLink->setEnabled(false);
    ui->pushButton_cyc_xrsj->setEnabled(false);
    ui->pushButton_sin_xrsj->setEnabled(false);
    // 初始化串口
    serialPort = new QSerialPort;
    serialPort->setBaudRate(QSerialPort::Baud115200);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);
    connect(serialPort,SIGNAL(readyRead()),this,SLOT(RxData()));
    // 初始化定时器
    qTimer = new QTimer();
    connect(qTimer,SIGNAL(timeout()),this,SLOT(timerOut()) );
    qTimer->start(10000);   // 10000ms = 10s 进入一次槽函数

    qTimer0 = new QTimer();
    connect(qTimer0,SIGNAL(timeout()),this,SLOT(timer0Out()) );
    ui->comboBox_cyc_bh->setEnabled(false);
    ui->textBrowser->append(tr("--------------------------------------------------"));
    ui->textBrowser->append(tr("SYSTEM: 欢迎使用流量控制系统，本系统为Windows PC版本！"));
    ui->textBrowser->append(tr("SYSTEM: 此消息框为系统提示框，会更新该软件的即时消息。"));
    ui->textBrowser->append(tr("SYSTEM: 使用本系统，请先点击右侧的【建立连接】按钮。"));
    ui->textBrowser->append(tr("--------------------------------------------------"));

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::timerOut()
{
    QByteArray cmd;
    qDebug() <<"请求温度数据！！";

    cmd.append(0xEE);
    serialPort->write(cmd);
    cmd.clear();

    cmd.append(CMD_DATA_HEAD_0);          // 数据头1
    cmd.append(CMD_DATA_HEAD_1);          // 数据头2
    cmd.append(0x2);
    cmd.append(CMD_ALL_GETTEMP);              // 命令内容
    for( int i = 0; i < 11; i++ ) {             // 一共补充长度为15位
        cmd.append((char)0x00);
    }
    serialPort->write(cmd);                 // 写入串口
    ui->statusBar->showMessage(tr("Send:")+cmd.toHex());

}
void MainWindow::on_pushButton_setLink_clicked()
{
    QString portName;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        QSerialPort serial;

        serial.setPort(info);
        if (serial.open(QIODevice::ReadWrite))
        {
            portName = info.portName();
            ui->textBrowser->append(tr("SYSTEM: 扫描串口")+info.portName()+tr("建立连接....."));
            qDebug()<<"打开系统成功，通信串口号为：";
            qDebug()<<portName;
            serialPort->setPortName(info.portName());
            qDebug()<< "现在可以进行操作了！";

            serial.close();
        }
    }
    if (!serialPort->open(QIODevice::ReadWrite))
    {
        QMessageBox::warning(this,"Warring","Open serial port fail!");
        ui->textBrowser->append(tr("SYSTEM: 串口打开失败，请检查串口是否被其他软件占用，或检查串口连接是否正常！"));
        ui->statusBar->showMessage(tr("串口打开失败！"));
    }
    else
    {
        ui->statusBar->showMessage(tr("通信已经被建立！！"));
        ui->textBrowser->append(tr("SYSTEM: 已经和串口")+portName+tr("建立连接！！"));
        QMessageBox::information(this,"Success", "The "+ portName+" has been opened!");
        ui->pushButton_disLink->setEnabled(true);
        ui->pushButton_setLink->setEnabled(false);
        ui->pushButton_cyc_xrsj->setEnabled(true);
        ui->pushButton_sin_xrsj->setEnabled(true);
    }
}

// 断开连接按钮槽函数
void MainWindow::on_pushButton_disLink_clicked()
{
    serialPort->close();
    ui->pushButton_disLink->setEnabled(false);
    ui->pushButton_setLink->setEnabled(true);
    ui->pushButton_cyc_xrsj->setEnabled(false);
    ui->pushButton_sin_xrsj->setEnabled(false);
    QMessageBox::information(this,"Success", "Serial port has been closed!");
    ui->textBrowser->append(tr("SYSTEM: 已经断开通信端口，现在无法使用软件！"));
    ui->statusBar->showMessage(tr("通信切断中..."));
}

void MainWindow::protocalProcess(QString str)
{
    ui->statusBar->showMessage(tr("Get:")+str);
    double tempThreshold = 0.0;
    QByteArray cmd;
    unsigned int t_cmd;
    unsigned int data0;
    unsigned int data1;
    unsigned int data2;
    unsigned int data3;
    unsigned int length;
    quint8 code;
    double dd = 0.0;
    unsigned long dl = 0;
    unsigned int scmd;
    bool ok;
    qDebug() <<"rec :" << str;
    code = str.mid(2,2).toInt(&ok,16);
    t_cmd = str.mid(4,2).toInt(&ok,16);
    length =str.mid(6,2).toInt(&ok,16);
    data0 = str.mid(8,2).toInt(&ok,16);
    data1 = str.mid(10,2).toInt(&ok,16);
    data2 = str.mid(12,2).toInt(&ok,16);
    data3 = str.mid(14,2).toInt(&ok,16);

    if( length == 2 ) {                 // 命令长度为2 则单字节命令
        scmd = data0;
    }else if( length == 5 ) {            // 命令长度为5 数据包含浮点
        dl |= (unsigned long)data0&0xFF;
        dl |= (unsigned long)data1 << 8;
        dl |= (unsigned long)data2 << 16;
        dl |= (unsigned long)data3 << 24;
        dd = (double)dl /1000000.0;
    }
    switch( t_cmd ) {
    case CMD_SIN_WORKFLAG:
        if( scmd ==  SCMD_SIN_WORKSTATE_EXTRACT ) {
            if( (code == 0xa0 && ui->comboBox_sin_zsqbh->currentIndex() == 0) ||
                    (code == 0xa1 && ui->comboBox_sin_zsqbh->currentIndex() == 1) ||
                    (code == 0xa2 && ui->comboBox_sin_zsqbh->currentIndex() == 2) ||
                    (code == 0xa3 && ui->comboBox_sin_zsqbh->currentIndex() == 3) )
                ui->lineEdit_sin_gzzt->setText(tr("正在抽取"));

        }else if( scmd == SCMD_SIN_WORKSTATE_OFFLINE ) {
            if( (code == 0xa0 && ui->comboBox_sin_zsqbh->currentIndex() == 0) ||
                    (code == 0xa1 && ui->comboBox_sin_zsqbh->currentIndex() == 1) ||
                    (code == 0xa2 && ui->comboBox_sin_zsqbh->currentIndex() == 2) ||
                    (code == 0xa3 && ui->comboBox_sin_zsqbh->currentIndex() == 3) )
                ui->lineEdit_sin_gzzt->setText(tr("脱机状态"));
        }else if( scmd == SCMD_SIN_WORKSTATE_PAUSE ) {
            if( (code == 0xa0 && ui->comboBox_sin_zsqbh->currentIndex() == 0) ||
                    (code == 0xa1 && ui->comboBox_sin_zsqbh->currentIndex() == 1) ||
                    (code == 0xa2 && ui->comboBox_sin_zsqbh->currentIndex() == 2) ||
                    (code == 0xa3 && ui->comboBox_sin_zsqbh->currentIndex() == 3) )
                ui->lineEdit_sin_gzzt->setText(tr("暂停状态"));
        }else if( scmd == SCMD_SIN_WORKSTATE_REALSE ) {
            if( (code == 0xa0 && ui->comboBox_sin_zsqbh->currentIndex() == 0) ||
                    (code == 0xa1 && ui->comboBox_sin_zsqbh->currentIndex() == 1) ||
                    (code == 0xa2 && ui->comboBox_sin_zsqbh->currentIndex() == 2) ||
                    (code == 0xa3 && ui->comboBox_sin_zsqbh->currentIndex() == 3) )
                ui->lineEdit_sin_gzzt->setText(tr("释放液体"));
        }else if( scmd == SCMD_SIN_WORKSTATE_STANDBY ) {
            if( (code = 0xa0 && ui->comboBox_sin_zsqbh->currentIndex() == 0) ||
                    (code == 0xa1 && ui->comboBox_sin_zsqbh->currentIndex() == 1) ||
                    (code == 0xa2 && ui->comboBox_sin_zsqbh->currentIndex() == 2) ||
                    (code == 0xa3 && ui->comboBox_sin_zsqbh->currentIndex() == 3) )
                ui->lineEdit_sin_gzzt->setText(tr("挂起状态"));
        }else if( scmd == SCMD_SIN_WORKSTATE_STOP ) {
            if( (code = 0xa0 && ui->comboBox_sin_zsqbh->currentIndex() == 0) ||
                    (code == 0xa1 && ui->comboBox_sin_zsqbh->currentIndex() == 1) ||
                    (code == 0xa2 && ui->comboBox_sin_zsqbh->currentIndex() == 2) ||
                    (code == 0xa3 && ui->comboBox_sin_zsqbh->currentIndex() == 3) )
                ui->lineEdit_sin_gzzt->setText(tr("停止状态"));
        }
        break;
    case CMD_CYC_WORKFLAG:

        if( scmd == SCMD_CYC_WORKSTATE_WORDING  ) {
            ui->lineEdit_cyc_gzzt->setText(tr("工作中"));
        }else if( scmd == SCMD_CYC_WORKSTATE_PAUSE ) {
            ui->lineEdit_cyc_gzzt->setText(tr("暂停中"));
        }else if( scmd == SCMD_CYC_WORKSTATE_STOP ) {
            ui->lineEdit_cyc_gzzt->setText(tr("停止中"));
        }else if( scmd == SCMD_CYC_WORKSTATE_OFFLINE ) {
            ui->lineEdit_cyc_gzzt->setText(tr("脱机中"));
        }
        break;

    case CMD_ALL_TVALUE:

        ui->lineEdit_all_temp->setText(QString::number(dd,'f',2));
        if( dd > 50.0 ) {
            ui->textBrowser->append(tr("SYSTEM: 温度超过50.0摄氏度，请注意！！"));
        }else if( dd < 10.0 ) {
            ui->textBrowser->append(tr("SYSTEM: 温度超过10.0摄氏度，请注意！！"));
        }
        tempThreshold = ui->lineEdit_all_setTemp->text().toDouble();

        if( tempThreshold > dd ) {
            ui->textBrowser->append(tr("SYSTEM: 当前温度低于设定的温度阈值，加热中...."));
            cmd.append((char)0xEE);
            serialPort->write(cmd);
            cmd.clear();
            // 发送数据头文件
            cmd.append(CMD_DATA_HEAD_0);          // 数据头1
            cmd.append(CMD_DATA_HEAD_1);          // 数据头2

            // 命令内容发送温度阈值命令
            cmd.append(0x01);                       // 此命令下数据长度
            cmd.append(CMD_ALL_ADDTEMP);          // 命令内容
            for(int i = 0; i < 14; i ++ )   cmd.append( (char)0x00 );
            serialPort->write(cmd);                 // 写入串口
            ui->statusBar->showMessage(tr("Send:")+cmd.toHex());
            cmd.clear();
        }else{
            // 发送数据头文件
            cmd.append(CMD_DATA_HEAD_0);          // 数据头1
            cmd.append(CMD_DATA_HEAD_1);          // 数据头2

            // 命令内容发送温度阈值命令
            cmd.append(0x01);                       // 此命令下数据长度
            cmd.append(CMD_ALL_DECTEMP);          // 命令内容
            for(int i = 0; i < 14; i ++ )   cmd.append( (char)0x00 );
            serialPort->write(cmd);                 // 写入串口
            ui->statusBar->showMessage(tr("Send:")+cmd.toHex());
            cmd.clear();
        }
        break;

    case CMD_SIN_HASINJECTVALUE:
        if( (code == 0xa0 && ui->comboBox_sin_zsqbh->currentIndex() == 0) ||
                (code == 0xa1 && ui->comboBox_sin_zsqbh->currentIndex() == 1) ||
                (code == 0xa2 && ui->comboBox_sin_zsqbh->currentIndex() == 2) ||
                (code == 0xa3 && ui->comboBox_sin_zsqbh->currentIndex() == 3) ) {
            if(dd < 2000.0) {
                ui->lineEdit_sin_yzsl->setText(QString::number(dd,'f',4));
            }else {
                ui->lineEdit_sin_yzsl->setText(tr("数据计算中..."));
            }
        }
        break;
    case CMD_CYC_HASINJECTVALUE:

        ui->lineEdit_cyc_yzsl->setText(QString::number(dd,'f',4));

        break;
    case CMD_SIN_CURRSPEED:
        if( (code == 0xa0 && ui->comboBox_sin_zsqbh->currentIndex() == 0) ||
                (code == 0xa1 && ui->comboBox_sin_zsqbh->currentIndex() == 1) ||
                (code == 0xa2 && ui->comboBox_sin_zsqbh->currentIndex() == 2) ||
                (code == 0xa3 && ui->comboBox_sin_zsqbh->currentIndex() == 3) ) {
            if(dd < 2000.0) {
                ui->lineEdit_sin_dqsd->setText(QString::number(dd,'f',4));
            }else {
                ui->lineEdit_sin_dqsd->setText(tr("速度获取中..."));
            }

        }

        break;
    case CMD_CYC_CURRSPEED:
        ui->lineEdit_cyc_dqsd->setText(QString::number(dd,'f',4));
        break;
    case CMD_SIN_STATE:
        if( (code == 0xa0 && ui->comboBox_sin_zsqbh->currentIndex() == 0) ||
                (code == 0xa1 && ui->comboBox_sin_zsqbh->currentIndex() == 1) ||
                (code == 0xa2 && ui->comboBox_sin_zsqbh->currentIndex() == 2) ||
                (code == 0xa3 && ui->comboBox_sin_zsqbh->currentIndex() == 3) )
            ui->progressBar_sin_jqzt->setValue((int)scmd);
        if( scmd >= 99 ) {
            qTimer0->stop();
            time = 0;
        }
        break;
    case CMD_CYC_CYCNUM:
        ui->lineEdit_cyc_xhzq->setText(QString::number((int)scmd,'g',4));
        break;
    }

}
// 接收数据槽函数
void MainWindow::RxData(){

    QByteArray rxArray;
    QString rxString;
    QString cs;
    int length;
    rxArray = serialPort->readAll();
    rxString = rxArray.toHex();
    qDebug() << "rec:" << rxString;
    for( int i = 0; i < rxString.length(); i++ ) {
        if( rxString.mid(i,3) == "aaa" ) {
            cs.clear();
            length = rxString.mid(i+6,2).toInt();
            cs.append(rxString.mid(i,4));
            cs.append(rxString.mid(i+4,2));
            cs.append(rxString.mid(i+6,2*length));
            protocalProcess(cs);

        }
    }



}

// 循环模式槽函数区域
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

// 按下循环模式的运行按钮的槽函数
void MainWindow::on_pushButton_cyc_yx_clicked()
{
    QByteArray cmd;
    cmd.append((char)0xEE);
    serialPort->write(cmd);
    cmd.clear();
    cmd.append(CMD_DATA_HEAD_0);          // 数据头1
    cmd.append(CMD_DATA_HEAD_1);          // 数据头2
    cmd.append(0x02);
    cmd.append(CMD_CYC_RUN);              // 命令内容
    for( int i = 0; i < 11; i++   ) {
        cmd.append( (char)0x00 );
    }
    serialPort->write(cmd);                 // 写入串口
    ui->statusBar->showMessage(tr("Send:")+cmd.toHex());
}
// 按下循环模式的暂停按钮的槽函数
void MainWindow::on_pushButton_cyc_zt_clicked()
{
    QByteArray cmd;
    cmd.append((char)0xEE);
    serialPort->write(cmd);
    cmd.clear();
    cmd.append(CMD_DATA_HEAD_0);          // 数据头1
    cmd.append(CMD_DATA_HEAD_1);          // 数据头2
    cmd.append(0x01);                       // 命令长度
    cmd.append(CMD_CYC_STOP);              // 命令内容
    for(int i = 0; i < 11; i ++) {
        cmd.append( (char)0x00 );
    }


    serialPort->write(cmd);                 // 写入串口
    ui->statusBar->showMessage(tr("Send:")+cmd.toHex());
}
// 按下循环模式的停止按钮的槽函数
void MainWindow::on_pushButton_cyc_tz_clicked()
{
    QByteArray cmd;
    cmd.append((char)0xEE);
    serialPort->write(cmd);
    cmd.clear();
    cmd.append(CMD_DATA_HEAD_0);          // 数据头1
    cmd.append(CMD_DATA_HEAD_1);          // 数据头2
    cmd.append( (char)0x01 );                       // 命令长度
    cmd.append(CMD_CYC_HALT);              // 命令内容
    for(int i = 0; i < 11; i ++) {
        cmd.append( (char)0x00 );
    }
    serialPort->write(cmd);                 // 写入串口
    ui->statusBar->showMessage(tr("Send:")+cmd.toHex());
}
// 按下循环模式的参数保存的槽函数
void MainWindow::on_pushButton_cyc_csbc_clicked()
{

    QByteArray f1_bytes;
    QString filename = QFileDialog::getSaveFileName(this,
                                                    tr("Save Text"),
                                                    "",
                                                    tr("Text Files(*.txt)")); //选择路径
    QFile f1_txt(filename);
    if(filename.isEmpty()) {
        QMessageBox::warning(this, tr("Path"),
                             tr("You did not select any file."));
    }else{
        f1_bytes.append("------------------------------------------------\n");
        f1_bytes.append("循环模式数据已经成功保存\n");
        f1_bytes.append("注射器编号：");
        switch( ui->comboBox_cyc_bhx->currentIndex() ) {
        case 0:
            f1_bytes.append("1号\n");
            break;
        case 1:
            f1_bytes.append("2号\n");
            break;
        case 2:
            f1_bytes.append("3号\n");
            break;
        case 3:
            f1_bytes.append("4号\n");
            break;
        default:
            qDebug()<< ui->comboBox_cyc_bhx->currentIndex();
            break;
        }
        f1_bytes.append("注射规格：");
        f1_bytes.append(ui->lineEdit_cyc_zsgg->text());
        f1_bytes.append("\n");
        f1_bytes.append("开始速度：");
        f1_bytes.append(ui->lineEdit_cyc_kssd->text());
        f1_bytes.append("\n");
        f1_bytes.append("结束速度：");
        f1_bytes.append(ui->lineEdit_cyc_jssd->text());
        f1_bytes.append("\n");
        f1_bytes.append("循环周期：");
        f1_bytes.append(ui->lineEdit_cyc_xhzqx->text());
        f1_bytes.append("\n");
        f1_bytes.append("运行时间：");
        f1_bytes.append(ui->timeEdit_cyc_yxsj->text());
        f1_bytes.append("\n");
        f1_bytes.append("------------------------------------------------");
        f1_bytes.append("\n");
        f1_txt.open(QIODevice::WriteOnly|QIODevice::Text);
        if( !f1_txt.write(f1_bytes) ) {
            QMessageBox::information(this,
                                     tr("Failed to save the txt"),
                                     tr("Failed to save the txt!"));
            return;
        }else{
            QMessageBox::information(this,
                                     tr("Success"),
                                     tr("Success to save the text!"));
        }

        f1_txt.close();
    }


}
// 循环模式清除数据槽函数
void MainWindow::on_pushButton_cyc_qksj_clicked()
{
    ui->lineEdit_cyc_zsgg->clear();
    ui->lineEdit_cyc_kssd->clear();
    ui->lineEdit_cyc_jssd->clear();
    ui->comboBox_cyc_bhx->setCurrentIndex(0);
    ui->comboBox_cyc_jssddw->setCurrentIndex(0);
    ui->comboBox_cyc_kssddw->setCurrentIndex(0);
    ui->lineEdit_cyc_xhzqx->clear();

}
// 循环模式写入数据槽函数
void MainWindow::on_pushButton_cyc_xrsj_clicked()
{
    QByteArray cmd;

    unsigned int data0 = 0x0000;
    unsigned int data1 = 0x0000;

    double lineEditData = 0.0;

    cmd.append((char)0xCC);
    serialPort->write(cmd);
    cmd.clear();

    // 命令内容注射器编号，命令长度1
    cmd.append(CMD_DATA_HEAD_0);          // 数据头1
    cmd.append(CMD_DATA_HEAD_1);          // 数据头2
    data0 = ui->comboBox_cyc_bhx->currentIndex();
    cmd.append(0x02);                     // 此命令下数据长度
    cmd.append(CMD_CYC_CODEX);          // 命令内容
    cmd.append( data0 );
    for( int i = 0; i < 10; i ++) {
        cmd.append( (char)0x00 );
    }
    serialPort->write(cmd);                 // 写入串口
    ui->statusBar->showMessage(tr("Send:")+cmd.toHex());
    cmd.clear();

    // 命令内容注射器规格，命令长度5
    cmd.append(CMD_DATA_HEAD_0);          // 数据头1
    cmd.append(CMD_DATA_HEAD_1);          // 数据头2
    lineEditData = ui->lineEdit_cyc_zsgg->text().toDouble();
    cmd.append(0x05);                       // 此命令下数据长度
    cmd.append(CMD_CYC_INSIZE);          // 命令内容
    connectCmdBytes(lineEditData,&cmd);
    for(int i = 0; i < 15-8; i++) {
        cmd.append( (char)0x00 );
    }
    serialPort->write(cmd);                 // 写入串口
    ui->statusBar->showMessage(tr("Send:")+cmd.toHex());
    cmd.clear();


    // 命令内容注射器开始速度，命令长度6，数据+单位
    cmd.append(CMD_DATA_HEAD_0);          // 数据头1
    cmd.append(CMD_DATA_HEAD_1);          // 数据头2
    lineEditData =  ui->lineEdit_cyc_kssd->text().toDouble();
    data1 = ui->comboBox_cyc_kssddw->currentIndex();
    cmd.append(0x06);
    cmd.append(CMD_CYC_SPEED_ON);
    connectCmdBytes(lineEditData,&cmd);
    cmd.append(data1);
    for( int i  = 0; i < 9; i++ ) {
        cmd.append( (char)0x00 );
    }

    serialPort->write(cmd);                 // 写入串口
    ui->statusBar->showMessage(tr("Send:")+cmd.toHex());
    cmd.clear();

    // 命令内容注射器结束速度，命令长度6.数据+单位
    cmd.append(CMD_DATA_HEAD_0);          // 数据头1
    cmd.append(CMD_DATA_HEAD_1);          // 数据头2
    lineEditData = ui->lineEdit_cyc_jssd->text().toDouble();
    data1 = ui->comboBox_cyc_jssddw->currentIndex();
    cmd.append(0x06);
    cmd.append(CMD_CYC_SPEED_OFF);
    connectCmdBytes(lineEditData,&cmd);
    cmd.append(data1);
    for(int i = 0; i < 9; i ++) {
        cmd.append( (char)0x00 );
    }
    serialPort->write(cmd);                 // 写入串口
    ui->statusBar->showMessage(tr("Send:")+cmd.toHex());
    cmd.clear();


    // 命令内容注射器的循环周期，命令长度1
    cmd.append(CMD_DATA_HEAD_0);          // 数据头1
    cmd.append(CMD_DATA_HEAD_1);          // 数据头2
    data0 = ui->lineEdit_cyc_xhzqx->text().toInt();
    cmd.append(0x02);
    cmd.append(CMD_CYC_CYCNUMX);
    cmd.append(data0);
    for( int i = 0; i < 11; i ++ ) {
        cmd.append( (char)0x00 );
    }

    serialPort->write(cmd);                 // 写入串口
    ui->statusBar->showMessage(tr("Send:")+cmd.toHex());

    data0 = 0;
    data1 = 0;
    cmd.clear();
    flag_cyc_rec_ok = false;
    ui->textBrowser->append(tr("SYSTEM: 批量赋值成功！"));
    // while( flag_rec_ok != true );
    QMessageBox::information(this,
                             tr("Success"),
                             tr("Data has been written!"));

}



// 单次模式槽函数区域
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
// 单次循环模式运行按钮槽函数
void MainWindow::on_pushButton_sin_yx_clicked()
{
    QByteArray cmd;
   // qTimer0->start(1000);
    cmd.append(0xEE);
    serialPort->write(cmd);
    cmd.clear();
    cmd.append(CMD_DATA_HEAD_0);          // 数据头1
    cmd.append(CMD_DATA_HEAD_1);          // 数据头2
    cmd.append( 0x02) ;                      // 命令长度
    cmd.append(CMD_SIN_RUN);              // 命令内容
    cmd.append(ui->comboBox_sin_zsqbh->currentIndex());
    for(int i = 0; i < 10; i ++ )   cmd.append( (char)0x00 );
    serialPort->write(cmd);                 // 写入串口
    ui->statusBar->showMessage(tr("Send:")+cmd.toHex());
    ui->textBrowser->append(tr("SYSTEM: 释放开始！"));

}
void MainWindow::timer0Out()
{
    time ++;
    ui->lineEdit_sin_yxsj->setText(QString::number(time, 1));
}
// 单次循环模式暂停按钮槽函数
void MainWindow::on_pushButton_sin_zt_clicked()
{
    QByteArray cmd;
    cmd.append((char)0xEE);
    serialPort->write(cmd);
    cmd.clear();
    cmd.append(CMD_DATA_HEAD_0);          // 数据头1
    cmd.append(CMD_DATA_HEAD_1);          // 数据头2
    cmd.append(2);                       // 命令长度
    cmd.append(CMD_SIN_STOP);              // 命令内容
    cmd.append(ui->comboBox_sin_zsqbh->currentIndex());
    for(int i = 0; i < 10; i ++ )   cmd.append( (char)0x00 );
    serialPort->write(cmd);                 // 写入串口
    ui->statusBar->showMessage(tr("Send:")+cmd.toHex());
    ui->textBrowser->append(tr("SYSTEM: 单次循环模式已暂停，单机运行后继续！"));
    ui->lineEdit_sin_gzzt->setText("暂停中");
}

// 单次循环模式停止按钮槽函数
void MainWindow::on_pushButton_sin_tz_clicked()
{
    QByteArray cmd;
    cmd.append((char)0xEE);
    serialPort->write(cmd);
    cmd.clear();

    cmd.append(CMD_DATA_HEAD_0);          // 数据头1
    cmd.append(CMD_DATA_HEAD_1);          // 数据头2
    cmd.append(0x02);                          // 命令长度
    cmd.append(CMD_SIN_HALT);              // 命令内容
    cmd.append( ui->comboBox_sin_zsqbh->currentIndex() );
    for(int i = 0; i < 10; i ++ )   cmd.append( (char)0x00 );
    serialPort->write(cmd);
    ui->statusBar->showMessage(tr("Send:")+cmd.toHex());
    ui->textBrowser->append(tr("SYSTEM: 单次循环已经停止，点击开始继续运行！"));
    ui->lineEdit_sin_gzzt->setText("停止中");

}
// 单次循环模式写入数据槽函数
void MainWindow::on_pushButton_sin_xrsj_clicked()
{
    QByteArray cmd;
    unsigned int data0 = 0x00;
    unsigned int data1 = 0x00;
    double lineEditData = 0.0;

    cmd.append(0xCC);
    serialPort->write(cmd);

    cmd.clear();

    // 发送数据头文件
    cmd.append(CMD_DATA_HEAD_0);          // 数据头1
    cmd.append(CMD_DATA_HEAD_1);          // 数据头2

    // 命令内容注射器编号，命令长度1
    data0 = ui->comboBox_sin_bhx->currentIndex();
    cmd.append(0x02);                     // 接下来数据的长度（不算这个字节），命令+数据+checksum
    cmd.append(CMD_SIN_CODEX);          // 命令内容
    cmd.append( data0 );
    for(int i = 0; i < 10; i ++ )   cmd.append( (char)0x00 );
    serialPort->write(cmd);                 // 写入串口
    ui->statusBar->showMessage(tr("Send:")+cmd.toHex());
    cmd.clear();

    //-----------------------------------------------------------------------------------------

    // 发送数据头文件
    cmd.append(CMD_DATA_HEAD_0);          // 数据头1
    cmd.append(CMD_DATA_HEAD_1);          // 数据头2
    // 命令内容注射器规格，命令长度6
    lineEditData = ui->lineEdit_sin_zsgg->text().toDouble();
    cmd.append(0x05);                      // 此命令下数据长度
    cmd.append(CMD_SIN_INSIZE);          // 命令内容
    connectCmdBytes(lineEditData,&cmd);

    for(int i = 0; i < 15-8; i ++ )   cmd.append( (char)0x00 );
    serialPort->write(cmd);                 // 写入串口
    ui->statusBar->showMessage(tr("Send:")+cmd.toHex());
    cmd.clear();


    //-----------------------------------------------------------------------------------------
    // 发送数据头文件
    cmd.append(CMD_DATA_HEAD_0);          // 数据头1
    cmd.append(CMD_DATA_HEAD_1);          // 数据头2
    // 命令内容注射器开始速度，命令长度6，数据+单位
    lineEditData =  ui->lineEdit_sin_kssd->text().toDouble();
    data1 = ui->comboBox_sin_kssddw->currentIndex();
    cmd.append(0x06);
    cmd.append(CMD_SIN_SPEED_ON);
    connectCmdBytes(lineEditData,&cmd);
    cmd.append(data1);

    for(int i = 0; i < 15-9; i ++ )   cmd.append( (char)0x00 );
    serialPort->write(cmd);                 // 写入串口
    ui->statusBar->showMessage(tr("Send:")+cmd.toHex());
    cmd.clear();


    //-----------------------------------------------------------------------------------------
    // 发送数据头文件
    cmd.append(CMD_DATA_HEAD_0);          // 数据头1
    cmd.append(CMD_DATA_HEAD_1);          // 数据头2
    // 命令内容注射器结束速度，命令长度6.数据+单位
    lineEditData = ui->lineEdit_sin_jssd->text().toDouble();
    data1 = ui->comboBox_sin_jssddw->currentIndex();
    cmd.append(0x06);
    cmd.append(CMD_SIN_SPEED_OFF);
    connectCmdBytes(lineEditData,&cmd);
    cmd.append(data1);
    for(int i = 0; i < 15-9; i ++ )   cmd.append( (char)0x00 );
    serialPort->write(cmd);                 // 写入串口
    ui->statusBar->showMessage(tr("Send:")+cmd.toHex());
    cmd.clear();

    //-----------------------------------------------------------------------------------------
    // 发送数据头文件
    cmd.append(CMD_DATA_HEAD_0);          // 数据头1
    cmd.append(CMD_DATA_HEAD_1);          // 数据头2
    // 命令内容控制模式，命令长度1
    data0 = ui->comboBox_sin_kzms->currentIndex();
    cmd.append(0x02);
    cmd.append(CMD_SIN_CTRLMODE);
    cmd.append(data0);

    for(int i = 0; i < 10; i ++ )   cmd.append( (char)0x00 );
    serialPort->write(cmd);                 // 写入串口
    ui->statusBar->showMessage(tr("Send:")+cmd.toHex());
    cmd.clear();


    flag_sin_rec_ok = false;
    ui->textBrowser->append(tr("SYSTEM: 批量赋值完成！"));
    // while( flag_sin_rec_ok != true );
    QMessageBox::information(this,
                             tr("Success"),
                             tr("Data has been written!"));
}
// 单次模式，保存参数按钮槽函数
void MainWindow::on_pushButton_sin_csbc_clicked()
{
    QByteArray f1_bytes;
    QString filename = QFileDialog::getSaveFileName(this,
                                                    tr("Save Text"),
                                                    "",
                                                    tr("Text Files(*.txt)")); //选择路径
    QFile f1_txt(filename);
    if(filename.isEmpty()) {
        QMessageBox::warning(this, tr("Path"),
                             tr("You did not select any file."));
    }else{
        f1_bytes.append("------------------------------------------------\n");
        f1_bytes.append("单次模式数据已经成功保存\n");
        f1_bytes.append("注射器编号：");
        switch( ui->comboBox_sin_bhx->currentIndex() ) {
        case 0:
            f1_bytes.append("1号\n");
            break;
        case 1:
            f1_bytes.append("2号\n");
            break;
        case 2:
            f1_bytes.append("3号\n");
            break;
        case 3:
            f1_bytes.append("4号\n");
            break;
        default:
            qDebug()<< ui->comboBox_sin_bhx->currentIndex();
            break;
        }
        f1_bytes.append("注射规格：");
        f1_bytes.append(ui->lineEdit_sin_zsgg->text());
        f1_bytes.append("\n");
        f1_bytes.append("开始速度：");
        f1_bytes.append(ui->lineEdit_sin_kssd->text());
        f1_bytes.append("\n");
        f1_bytes.append("结束速度：");
        f1_bytes.append(ui->lineEdit_sin_jssd->text());
        f1_bytes.append("\n");
        f1_bytes.append("控制模式：");
        if( ui->comboBox_sin_kzms->currentIndex() == 0 ) {
            f1_bytes.append("PID控制模式\n");
        }else if( ui->comboBox_sin_kzms->currentIndex() == 1 ) {
            f1_bytes.append("匀速控制模式\n");
        }
        f1_bytes.append("运行时间：");
        f1_bytes.append(ui->timeEdit_sin_yxsj->text());
        f1_bytes.append("\n");
        f1_bytes.append("------------------------------------------------");
        f1_bytes.append("\n");
        f1_txt.open(QIODevice::WriteOnly|QIODevice::Text);
        if( !f1_txt.write(f1_bytes) ) {
            QMessageBox::information(this,
                                     tr("Failed to save the txt"),
                                     tr("Failed to save the txt!"));
            return;
        }else{
            QMessageBox::information(this,
                                     tr("Success"),
                                     tr("Success to save the text!"));
        }

        f1_txt.close();
    }
}
// 单次模式清空数据按钮
void MainWindow::on_pushButton_sin_qksj_clicked()
{
    ui->lineEdit_sin_zsgg->clear();
    ui->lineEdit_sin_kssd->clear();
    ui->lineEdit_sin_jssd->clear();
    ui->comboBox_sin_kzms->setCurrentIndex(0);
    ui->timeEdit_sin_yxsj->clear();
    ui->comboBox_sin_bhx->setCurrentIndex(0);
    ui->comboBox_sin_jssddw->setCurrentIndex(0);
    ui->comboBox_sin_kssddw->setCurrentIndex(0);

}


void MainWindow::connectCmdBytes(double f_data, QByteArray *qb)
{
    unsigned char byte0 = 0x00;
    unsigned char byte1 = 0x00;
    unsigned char byte2 = 0x00;
    unsigned char byte3 = 0x00;
    unsigned long bytes = 0x00000000;

    bytes = (unsigned long)(f_data*1000000);
    byte0 =bytes&0xFF;
    byte1 = (bytes >> 8)&0xFF;
    byte2 = (bytes >> 16)&0xFF;
    byte3 = (bytes >> 24)&0xFF;
    qb->append(byte0);
    qb->append(byte1);
    qb->append(byte2);
    qb->append(byte3);

}


void MainWindow::on_pushButton_all_setTemp_clicked()
{
    ui->textBrowser->append(tr("SYSTEM: 设定温度阈值成功，但不要把温度阈值数字删除哦！！"));
}

void sleep(unsigned int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void MainWindow::on_pushButton_sin_extract_clicked()
{
    QByteArray cmd;
    double lineEditData = 0.0;
    ui->textBrowser->append(tr("SYSTEM: 你点击了抽取按钮！"));
    cmd.append((char)0xEE);
    serialPort->write(cmd);
    cmd.clear();
    // 发送数据头文件
    cmd.append(CMD_DATA_HEAD_0);          // 数据头1
    cmd.append(CMD_DATA_HEAD_1);          // 数据头2

    // 命令内容发送温度阈值命令
    lineEditData = ui->lineEdit_all_setTemp->text().toDouble();
    cmd.append(0x02);                       // 此命令下数据长度
    cmd.append(CMD_SIN_STARTEXTRACT);          // 命令内容
    cmd.append(ui->comboBox_sin_zsqbh->currentIndex());
    for(int i = 0; i < 10; i ++ )   cmd.append( (char)0x00 );
    serialPort->write(cmd);                 // 写入串口
    ui->statusBar->showMessage(tr("Send:")+cmd.toHex());
    cmd.clear();
}

void MainWindow::on_comboBox_sin_zsqbh_currentIndexChanged(int index)
{
    ui->lineEdit_sin_dqsd->clear();
    ui->lineEdit_sin_yzsl->clear();
    ui->lineEdit_sin_yxsj->clear();
    ui->lineEdit_sin_gzzt->clear();
    ui->progressBar_sin_jqzt->setValue(0);
}
