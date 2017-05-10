#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDateTime"
#include "QLinkedList"
#include "carinfo.h"
#include "QString"
#include <QtSql/QSqlDatabase>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setWindowTitle("公路收费系统上位机");
    currentChe = 0;

    ui->openDoorButton->setEnabled(false);
    ui->closeDoorButton->setEnabled(false);
    serialPort = new QSerialPort;
    serialPort->setBaudRate(QSerialPort::Baud115200);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);
    connect(serialPort,SIGNAL(readyRead()),this,SLOT(RxData()));
    ui->infodisp-> append( "欢迎使用 科院停车场信息管理系统" );
    ui->infodisp-> append( "温馨提示：" );
    ui->infodisp-> append( "（1）本计费系统按时段收费：" );
    ui->infodisp-> append( " 22：00 --- 6：00 为夜间停车时间，其他时间为白天停车时间" );
    ui->infodisp-> append( " 其他时间为白天停车时间。" );
    ui->infodisp-> append( "（2）计费系统分计费卡种：" );
    ui->infodisp-> append( " 临时卡、月票卡、年票卡、VIP卡" );
    ui->infodisp-> append( " 欢迎办理VIP卡！" );
    carStation = new CarStation;
    carInfo1   = new CarInfo;
    carInfo2   = new CarInfo;
    carInfo3  = new CarInfo;
    carInfo4  = new CarInfo;
    carInfo5  = new CarInfo;
    carInfo6 = new CarInfo;
    blankCarInfo = new CarInfo;

    /////////////////////////////////////////////////////////////////////////////////////////////////
    // 录入第一个卡的信息
    carInfo1->setChepaihao("吉M 6F58E");
    carInfo1->setCheqing("无损坏");
    carInfo1->setChexing("小汽车");
    carInfo1->setChikaren("李刚");
    carInfo1->setIntKazhong(2);                         // 0是临时卡， 1是月票卡， 2是年卡， 3是VIP卡
    carInfo1->setKazhong("年卡");                       // 改这个的时候注意上面对应的数字 2是年卡
    carInfo1->setKahao("d5cc4571");

    qer.exec("select*from mo where kahao='d5cc4571';");
    while( qer.next() ) {
        dkahao = qer.value(0).toString();
        dyue    =   qer.value(1).toFloat();
        qDebug() << "kahao:" << dkahao <<"  " << "yue:" << dyue;
    }
    carInfo1->setYue( QString("%1").arg(dyue) );
    carInfo1->setFloatYue( dyue );
    /////////////////////////////////////////////////////////////////////////////////////////////////
    // 录入第二个卡
    carInfo2->setChepaihao("粤S 7887E");
    carInfo2->setCheqing("无损坏");
    carInfo2->setChexing("出租车");
    carInfo2->setChikaren("张明");
    carInfo2->setIntKazhong(1);                         // 0是临时卡， 1是月票卡， 2是年卡， 3是VIP卡
    carInfo2->setKazhong("月票卡");                       // 改这个的时候注意上面对应的数字 2是年卡
    carInfo2->setKahao("ebea3935");
    qer.exec("select*from mo where kahao='ebea3935';");
    while( qer.next() ) {
        dkahao = qer.value(0).toString();
        dyue    =   qer.value(1).toFloat();
        qDebug() << "kahao:" << dkahao <<"  " << "yue:" << dyue;
    }
    carInfo2->setYue( QString("%1").arg(dyue) );
    carInfo2->setFloatYue( dyue );
    /////////////////////////////////////////////////////////////////////////////////////////////////
    // 录入第三个卡
    carInfo3->setChepaihao("川A 3669E");
    carInfo3->setCheqing("良好");
    carInfo3->setChexing("跑车");
    carInfo3->setChikaren("张三");
    carInfo3->setIntKazhong(0);                         // 0是临时卡， 1是月票卡， 2是年卡， 3是VIP卡
    carInfo3->setKazhong("临时卡");                       // 改这个的时候注意上面对应的数字 2是年卡
    carInfo3->setKahao("a5843f35");                     // 随便编
    qer.exec("select*from mo where kahao='a5843f35';");
    while( qer.next() ) {
        dkahao = qer.value(0).toString();
        dyue    =   qer.value(1).toFloat();
        qDebug() << "kahao:" << dkahao <<"  " << "yue:" << dyue;
    }
    carInfo3->setYue( QString("%1").arg(dyue) );
    carInfo3->setFloatYue( dyue );
    /////////////////////////////////////////////////////////////////////////////////////////////////
    // 录入第四个卡
    carInfo4->setChepaihao("渝F A145DF");
    carInfo4->setCheqing("良好");
    carInfo4->setChexing("出租车");
    carInfo4->setChikaren("张红");
    carInfo4->setIntKazhong(3);                         // 0是临时卡， 1是月票卡， 2是年卡， 3是VIP卡
    carInfo4->setKazhong("VIP卡");                       // 改这个的时候注意上面对应的数字 2是年卡
    carInfo4->setKahao("b567e370");                     // 随便编
    qer.exec("select*from mo where kahao='b567e370';");
    while( qer.next() ) {
        dkahao = qer.value(0).toString();
        dyue    =   qer.value(1).toFloat();
        qDebug() << "kahao:" << dkahao <<"  " << "yue:" << dyue;
    }
    carInfo4->setYue( QString("%1").arg(dyue) );
    carInfo4->setFloatYue( dyue );
    /////////////////////////////////////////////////////////////////////////////////////////////////
    // 录入第五个卡
    carInfo5->setChepaihao("辽A 89877");
    carInfo5->setCheqing("良好");
    carInfo5->setChexing("卡车");
    carInfo5->setChikaren("张红");
    carInfo5->setIntKazhong(3);                         // 0是临时卡， 1是月票卡， 2是年卡， 3是VIP卡
    carInfo5->setKazhong("VIP卡");                       // 改这个的时候注意上面对应的数字 2是年卡
    carInfo5->setKahao("751ed870");                     // 随便编
    qer.exec("select*from mo where kahao='751ed870';"); // 调用数据库
    while( qer.next() ) {
        dkahao = qer.value(0).toString();
        dyue    =   qer.value(1).toFloat();
        qDebug() << "kahao:" << dkahao <<"  " << "yue:" << dyue;
    }
    carInfo5->setYue( QString("%1").arg(dyue) );
    carInfo5->setFloatYue( dyue );

    /////////////////////////////////////////////////////////////////////////////////////////////////

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startSystem_clicked()
{
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        QSerialPort serial;
        serial.setPort(info);
        if (serial.open(QIODevice::ReadWrite))
        {
            ui->infodisp->clear();
            ui->infodisp->append("打开系统成功，通信串口号为：");
            ui->infodisp->append(info.portName());
            serialPort->setPortName(info.portName());
            ui->infodisp->append("现在可以进行操作了！");

            serial.close();
        }
    }
    if (!serialPort->open(QIODevice::ReadWrite))
    {
        QMessageBox::warning(this,"Warring","Open serial port fail!");
    }
    else
    {
        qDebug()<<"Open COM port succuss!";
        QByteArray ByteDtat;
        ByteDtat.append(0xAA);       //head1
        ByteDtat.append(0xBB);       //head2
        ByteDtat.append(0xAC);       //cmd
        ByteDtat.append((char)0x00);//data
        uchar checkSum = 0xAA ^ 0xBB ^ 0xAC ^ 0x00;
        ByteDtat.append(checkSum);   //check
        serialPort->write(ByteDtat); //send data
    }
}

void MainWindow::on_openDoorButton_clicked()
{
    QByteArray byteData;
    byteData.append(0x01);
    serialPort->write(byteData);



}

void MainWindow::on_closeDoorButton_clicked()
{
    QByteArray byteData;
    byteData.append(0x02);
    serialPort->write(byteData);

}

void MainWindow::RxData()
{
    QByteArray ByteRxData = serialPort->readAll();
    QString StringRxData = ByteRxData.toHex();
    QString kahaoString;

    qDebug()<<"StringRxData:"<<StringRxData;
    qDebug()<<"ByteRxData:"<<ByteRxData;
    // aabb0133445566
    if (StringRxData.left(4) == "aabb")
    {
        if (StringRxData.mid(4,2) == "01")      // 收到卡号命令，后边N个字符都是卡号
        {
            kahaoString = StringRxData.mid(6,8);

        }

        if(kahaoString == "d5cc4571"){

            MainWindow::DisplayToUI( carInfo1, carStation );
            currentChe = 1;

        } else if( kahaoString == "ebea3935" ){

            MainWindow::DisplayToUI( carInfo2, carStation );
            currentChe = 2;
        }else if( kahaoString == "a5843f35" ) {
             MainWindow::DisplayToUI( carInfo3, carStation );
            currentChe = 3;
        } else if( kahaoString == "b567e370" ) {

             MainWindow::DisplayToUI( carInfo4, carStation );
            currentChe = 4;
        } else if( kahaoString == "751ed870" ) {

            MainWindow::DisplayToUI( carInfo5, carStation );
            currentChe = 5;
        }else {
            MainWindow::DisplayToUI( blankCarInfo, carStation );
            currentChe = 0;
        }

    }
}

void MainWindow::on_clear_button_clicked()
{

    ui->kahao->clear();
    ui->yue->clear();
    ui->chikaren->clear();
    ui->jiluhao->clear();
    ui->shoufeizhan->clear();
    ui->chedao->clear();
    ui->cheqing->clear();
    ui->shoufeiyuan->clear();
    ui->chepaihao->clear();
    ui->shijian->clear();
    ui->chexing->clear();

}
void MainWindow::DisplayToUI(CarInfo *info, CarStation *station) {

    QDateTime currentTime = QDateTime::currentDateTime();
    QString textCurrentTime = currentTime.toString("yyyy-MM-dd hh:mm:ss ddd");
    QByteArray byteData;
    QString currentKahao;
    float currentLeft = 0.0f;
    float yu_e = 0.0f;
    float addLeft = 0.0f;
    int cheweiNum;
    float spand = 0.0f;
   // QString te = currentTime.toString("yyyy-MM-dd hh:mm:ss ddd");
    //int timehour =  ce.toString("hh").toInt();
    //int timem = ce.toString("mm").toInt();
    //qDebug("%d,%d,",te,ta);
   // qDebug()<< "timeee";
    ui->yue->setText(info->getYue());
    //ui->yue->setText("nihao");

    ui->chikaren->setText(info->getChikaren());

    ui->jiluhao->setText(station->getJiluhao());
    ui->shoufeizhan->setText(station->getShoufeizhan());
    ui->chedao->setText(station->getChedao());
    ui->cheqing->setText(info->getCheqing());
    ui->chexing->setText(info->getChexing());
    ui->shoufeiyuan->setText(station->getShoufeiyuan());
    ui->chepaihao->setText(info->getChepaihao());
    ui->kazhong->setText(info->getKazhong());
    ui->kahao->setText(info->getKahao());
    ui->shijian->setText(textCurrentTime);
    ui->chewei->setText(QString::number( station->getIntChewei() ) );

    if( info->isIn == false ) {
        ui->koufei->setText("计费开始");
        info->setTimeInhour(currentTime.toString("hh").toInt());
        info->setTimeInmm(currentTime.toString("mm").toInt());
        cheweiNum = station->getIntChewei();
        station->setIntChewei( cheweiNum - 1);

        info->isIn = true;
    }else{
        currentKahao = info->getKahao();
        if( info->getIntKazhong() == 0 ){
            // 早晚计费不同
            if( currentTime.toString("hh").toInt() > 22 || currentTime.toString("hh").toInt() < 6 ){
                addLeft = 0.552;
            }else {
                addLeft = 0.600;
            }
            info->setTimeOuthour(currentTime.toString("hh").toInt());
            info->setTimeOutmm(currentTime.toString("mm").toInt());
            station->setFloatKoufei(addLeft);
            currentLeft = info->getFloatYue();
            spand = addLeft * (info->getTimeInhour() - info->getTimeOuthour()) * 60 + (info->getTimeInmm() - info->getTimeOutmm());
            ui->koufei->setText(QString("%1").arg(spand));
            yu_e = currentLeft + spand;
            info->setYue(QString("%1").arg(yu_e));
            info->setFloatYue(yu_e);
            ui->yue->setText(QString("%1").arg(yu_e));
            cmd1 = "update mo set yue='";
            cmd2 = QString("%1").arg(yu_e);
            cmd3 = "' where kahao='";
            cmd4 = currentKahao;
            cmd5 = "';";
            cmd = cmd1 + cmd2 + cmd3 + cmd4 + cmd5;
            qer.exec(cmd);
            qDebug("%f",yu_e);
        }else if( info->getIntKazhong() == 1 ) {
            // 早晚计费不同
            if( currentTime.toString("hh").toInt() > 22 || currentTime.toString("hh").toInt() < 6 ){
                addLeft = 0.452;
            }else {
                addLeft = 0.500;
            }
            info->setTimeOuthour(currentTime.toString("hh").toInt());
            info->setTimeOutmm(currentTime.toString("mm").toInt());
            station->setFloatKoufei(addLeft);
            currentLeft = info->getFloatYue();
            spand = addLeft * (info->getTimeInhour() - info->getTimeOuthour()) * 60 + (info->getTimeInmm() - info->getTimeOutmm());
            ui->koufei->setText(QString("%1").arg(spand));
            cmd1 = "update mo set yue='";
            cmd2 = QString("%1").arg(yu_e);
            cmd3 = "' where kahao='ebea3935';";
            cmd = cmd1 + cmd2 + cmd3;
            qer.exec(cmd);
            yu_e = currentLeft + spand;
            info->setYue(QString("%1").arg(yu_e));
            info->setFloatYue(yu_e);
            ui->yue->setText(QString("%1").arg(yu_e));
            cmd1 = "update mo set yue='";
            cmd2 = QString("%1").arg(yu_e);
            cmd3 = "' where kahao='";
            cmd4 = currentKahao;
            cmd5 = "';";
            cmd = cmd1 + cmd2 + cmd3 + cmd4 + cmd5;
            qer.exec(cmd);
            qDebug("%f",yu_e);
        }else if( info->getIntKazhong() == 2 ) {
            if( currentTime.toString("hh").toInt() > 22 || currentTime.toString("hh").toInt() < 6 ){
                addLeft = 0.300;
            }else {
                addLeft = 0.450;
            }
            info->setTimeOuthour(currentTime.toString("hh").toInt());
            info->setTimeOutmm(currentTime.toString("mm").toInt());
            station->setFloatKoufei(addLeft);

            currentLeft = info->getFloatYue();
            spand = addLeft * (info->getTimeInhour() - info->getTimeOuthour()) * 60 + (info->getTimeInmm() - info->getTimeOutmm());
            ui->koufei->setText(QString("%1").arg(spand));
            yu_e = currentLeft + spand;
            info->setYue(QString("%1").arg(yu_e));
            info->setFloatYue(yu_e);
            ui->yue->setText(QString("%1").arg(yu_e));
            cmd1 = "update mo set yue='";
            cmd2 = QString("%1").arg(yu_e);
            cmd3 = "' where kahao='";
            cmd4 = currentKahao;
            cmd5 = "';";
            cmd = cmd1 + cmd2 + cmd3 + cmd4 + cmd5;
            qer.exec(cmd);
            qDebug("%f",yu_e);

        }else if( info->getIntKazhong() == 3 ) {
            if( currentTime.toString("hh").toInt() > 22 || currentTime.toString("hh").toInt() < 6 ){
                addLeft = 0.278;
            }else {
                addLeft = 0.400;
            }
            info->setTimeOuthour(currentTime.toString("hh").toInt());
            info->setTimeOutmm(currentTime.toString("mm").toInt());
            station->setFloatKoufei(addLeft);
            currentLeft = info->getFloatYue();
            spand = addLeft * (info->getTimeInhour() - info->getTimeOuthour()) * 60 + (info->getTimeInmm() - info->getTimeOutmm());
            ui->koufei->setText(QString("%1").arg(spand));
            yu_e = currentLeft + spand;
            info->setYue(QString("%1").arg(yu_e));
            info->setFloatYue(yu_e);
            ui->yue->setText(QString("%1").arg(yu_e));
            cmd1 = "update mo set yue='";
            cmd2 = QString("%1").arg(yu_e);
            cmd3 = "' where kahao='";
            cmd4 = currentKahao;
            cmd5 = "';";
            cmd = cmd1 + cmd2 + cmd3 + cmd4 + cmd5;
            qer.exec(cmd);
            qDebug("%f",yu_e);
        }
        cheweiNum = station->getIntChewei();
        station->setIntChewei(cheweiNum + 1);
        info->isIn = false;

    }
    byteData.append(0xf1);
    serialPort->write(byteData);

}
void MainWindow::Chongzhi(void) {

    QString string = "1234565";
    float currentLeft = 0.0f;
    float addLeft = 0.0f;
    float yu_e = 0.0f;


    switch(currentChe) {
    case 1:
        addLeft = ui->chongzhi->text().toFloat();
        currentLeft = carInfo1->getFloatYue();
        yu_e = currentLeft + addLeft;
        carInfo1->setFloatYue(yu_e);
        string = QString("%1").arg(yu_e);
        carInfo1->setYue(string);
        ui->yue->setText(string);
        cmd1 = "update mo set yue='";
        cmd2 = QString("%1").arg(yu_e);
        cmd3 = "' where kahao='d5cc4571';";
        cmd = cmd1 + cmd2 + cmd3;
        qer.exec(cmd);
        break;

    case 2:
        addLeft = ui->chongzhi->text().toFloat();
        currentLeft = carInfo2->getFloatYue();
        yu_e = currentLeft + addLeft;
        carInfo2->setFloatYue(yu_e);
        string = QString("%1").arg(yu_e);
        carInfo2->setYue(string);
        ui->yue->setText(string);
        cmd1 = "update mo set yue='";
        cmd2 = QString("%1").arg(yu_e);
        cmd3 = "' where kahao='ebea3935';";
        cmd = cmd1 + cmd2 + cmd3;
        qer.exec(cmd);
        break;
    case 3:
        addLeft = ui->chongzhi->text().toFloat();
        currentLeft = carInfo3->getFloatYue();
        yu_e = currentLeft + addLeft;
        carInfo3->setFloatYue(yu_e);
        string = QString("%1").arg(yu_e);
        carInfo3->setYue(string);
        ui->yue->setText(string);
        cmd1 = "update mo set yue='";
        cmd2 = QString("%1").arg(yu_e);
        cmd3 = "' where kahao='a5843f35';";
        cmd = cmd1 + cmd2 + cmd3;
        qer.exec(cmd);
        break;

    case 4:
        addLeft = ui->chongzhi->text().toFloat();
        currentLeft = carInfo4->getFloatYue();
        yu_e = currentLeft + addLeft;
        carInfo4->setFloatYue(yu_e);
        string = QString("%1").arg(yu_e);
        carInfo4->setYue(string);
        ui->yue->setText(string);
        cmd1 = "update mo set yue='";
        cmd2 = QString("%1").arg(yu_e);
        cmd3 = "' where kahao='b567e370';";
        cmd = cmd1 + cmd2 + cmd3;
        qer.exec(cmd);
        break;
    case 5:
        addLeft = ui->chongzhi->text().toFloat();
        currentLeft = carInfo5->getFloatYue();
        yu_e = currentLeft + addLeft;
        carInfo5->setFloatYue(yu_e);
        string = QString("%1").arg(yu_e);
        carInfo5->setYue(string);
        ui->yue->setText(string);
        cmd1 = "update mo set yue='";
        cmd2 = QString("%1").arg(yu_e);
        cmd3 = "' where kahao='751ed870';";
        cmd = cmd1 + cmd2 + cmd3;
        qer.exec(cmd);
        break;

    case 0:
        addLeft = ui->chongzhi->text().toFloat();

        break;
    }
    QMessageBox::warning(this,"充值信息","充值成功");
}
void MainWindow::on_chongzhiButton_clicked()
{
   // MainWindow::DisplayToUI( carInfo1, carStation );
    MainWindow::Chongzhi();

}
