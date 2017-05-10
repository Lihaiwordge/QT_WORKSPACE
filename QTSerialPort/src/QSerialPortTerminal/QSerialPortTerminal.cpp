/********************************************************************************************************
* PROGRAM      : QSerialPortTerminal
* DATE - TIME  : mardi 04 mars 2008 - 11h20
* AUTHOR       : VIANNEY-LIAUD Philippe ( philippe.vianney.liaud@gmail.com )
* FILENAME     : QSerialPortTerminal.cpp
* LICENSE      : GPL
* COMMENTARY   :
********************************************************************************************************/
#include <QtGui>
#include "QSerialPortTerminal.h"

QSerialPortTerminal::QSerialPortTerminal( QWidget* parent )
        : QMainWindow( parent )
{
    setupUi( this );
    setWindowIcon(QIcon(":/images/plats.ico"));

    serialPort = new ManageSerialPort;
    connect(serialPort, SIGNAL(newDataReceived(const QByteArray &)), this, SLOT(slot_newDataReceived(const QByteArray &)));
    //window=======================
    comboBoxPortName->addItem("com1", QVariant::fromValue(QString("com1")));
    comboBoxPortName->addItem("com2", QVariant::fromValue(QString("com2")));
    comboBoxPortName->addItem("com3", QVariant::fromValue(QString("com3")));
    comboBoxPortName->addItem("com4", QVariant::fromValue(QString("com4")));
    comboBoxPortName->addItem("com5", QVariant::fromValue(QString("com5")));
    comboBoxPortName->addItem("com6", QVariant::fromValue(QString("com6")));
    comboBoxPortName->addItem("com7", QVariant::fromValue(QString("com7")));
    comboBoxPortName->addItem("com8", QVariant::fromValue(QString("com8")));
    //linux=========================
    //comboBoxPortName->addItem("/dev/ttyS0", QVariant::fromValue(QString("/dev/ttyS0")));
    //comboBoxPortName->addItem("/dev/ttyS1", QVariant::fromValue(QString("/dev/ttyS1")));
//    comboBoxPortName->addItem("ttyS0", QVariant::fromValue(QString("/dev/s3c2410_serial0")));
//    comboBoxPortName->addItem("ttyS1", QVariant::fromValue(QString("/dev/s3c2410_serial1")));
//    comboBoxPortName->addItem("ttyS2", QVariant::fromValue(QString("/dev/s3c2410_serial2")));
    comboBoxPortName->setCurrentIndex(1); //COM1

    comboBoxBaudRate->addItem("110", QVariant::fromValue(BAUD110));
    comboBoxBaudRate->addItem("300", QVariant::fromValue(BAUD300));
    comboBoxBaudRate->addItem("600", QVariant::fromValue(BAUD600));
    comboBoxBaudRate->addItem("1200", QVariant::fromValue(BAUD1200));
    comboBoxBaudRate->addItem("2400", QVariant::fromValue(BAUD2400));
    comboBoxBaudRate->addItem("4800", QVariant::fromValue(BAUD4800));
    comboBoxBaudRate->addItem("9600", QVariant::fromValue(BAUD9600));
    comboBoxBaudRate->addItem("19200", QVariant::fromValue(BAUD19200));
    comboBoxBaudRate->addItem("38400", QVariant::fromValue(BAUD38400));
    comboBoxBaudRate->addItem("57600", QVariant::fromValue(BAUD57600));
    comboBoxBaudRate->addItem("115200", QVariant::fromValue(BAUD115200));
    comboBoxBaudRate->setCurrentIndex(6); //9600 bauds

    comboBoxDataBits->addItem("5", QVariant::fromValue(DATA_5));
    comboBoxDataBits->addItem("6", QVariant::fromValue(DATA_6));
    comboBoxDataBits->addItem("7", QVariant::fromValue(DATA_7));
    comboBoxDataBits->addItem("8", QVariant::fromValue(DATA_8));
    comboBoxDataBits->setCurrentIndex(3); //8 bit

    comboBoxParity->addItem("None", QVariant::fromValue(PAR_NONE));
    comboBoxParity->addItem("Even", QVariant::fromValue(PAR_EVEN)); //pair
    comboBoxParity->addItem("Odd", QVariant::fromValue(PAR_ODD)); //impair
    comboBoxParity->addItem("Space", QVariant::fromValue(PAR_SPACE));
    comboBoxParity->setCurrentIndex(0); //Parity none

    comboBoxStopBits->addItem("1", QVariant::fromValue(STOP_1));
    comboBoxStopBits->addItem("2", QVariant::fromValue(STOP_2));
    comboBoxStopBits->setCurrentIndex(0); //1 stop bit

    comboBoxFlowControl->addItem("None", QVariant::fromValue(FLOW_OFF));
    comboBoxFlowControl->addItem("Xon/Xoff", QVariant::fromValue(FLOW_XONXOFF));
    comboBoxFlowControl->addItem("Hardware", QVariant::fromValue(FLOW_HARDWARE));
    comboBoxFlowControl->setCurrentIndex(0); //Flow control none

    //Connect
    connect(pushButtonOpen, SIGNAL(clicked()), this, SLOT(slot_openPort()));
    connect(pushButtonClose, SIGNAL(clicked()), this, SLOT(slot_closePort()));
    connect(pushButtonSend, SIGNAL(clicked()), this, SLOT(slot_sendPort()));

    /*Codecs list*/
    QMap<QString, QTextCodec *> codecMap;
    QRegExp iso8859RegExp("ISO[- ]8859-([0-9]+).*");

    foreach (int mib, QTextCodec::availableMibs())
    {
        QTextCodec *codec = QTextCodec::codecForMib(mib);

        QString sortKey = codec->name().toUpper();
        int rank;

        if (sortKey.startsWith("UTF-8"))
        {
            rank = 1;
        }
        else if (sortKey.startsWith("UTF-16"))
        {
            rank = 2;
        }
        else if (iso8859RegExp.exactMatch(sortKey))
        {
            if (iso8859RegExp.cap(1).size() == 1)
                rank = 3;
            else
                rank = 4;
        }
        else
        {
            rank = 5;
        }
        sortKey.prepend(QChar('0' + rank));

        codecMap.insert(sortKey, codec);
    }
    QList<QTextCodec *> codecs = codecMap.values();

    comboBoxCodecs->clear();
    foreach (QTextCodec *codec, codecs)
    comboBoxCodecs->addItem(codec->name(), codec->mibEnum());
    connect(comboBoxCodecs, SIGNAL(activated(int)),this, SLOT(updatetextEditReceive()));

    comboBoxCodecs->setCurrentIndex(comboBoxCodecs->findText("System")); //By default, codec used is the codec of the system.
}

QSerialPortTerminal::~QSerialPortTerminal()
{
    delete serialPort;
    serialPort = NULL;
}
/*
QTextCodecs can be used as follows to convert some locally encoded string to Unicode. Suppose you have some string encoded in Russian KOI8-R encoding, and want to convert it to Unicode. The simple way to do it is like this:

 QByteArray encodedString = "...";
 QTextCodec *codec = QTextCodec::codecForName("KOI8-R");
 QString string = codec->toUnicode(encodedString);
After this, string holds the text converted to Unicode. Converting a string from Unicode to the local encoding is just as easy:

 QString string = "...";
 QTextCodec *codec = QTextCodec::codecForName("KOI8-R");
 QByteArray encodedString = codec->fromUnicode(string);
*/
void QSerialPortTerminal::updatetextEditReceive()
{
    int mib = comboBoxCodecs->itemData(comboBoxCodecs->currentIndex()).toInt();
    QTextCodec *codec = QTextCodec::codecForMib(mib);
   // QTextCodec *codec = QTextCodec::codecForName("UTF-8");

    QTextStream in(allDataReceived);
    in.setAutoDetectUnicode(false);
    in.setCodec(codec);
    QString decodedStr = in.readAll();

    textEditReceive->setPlainText(decodedStr);
}

void QSerialPortTerminal::slot_openPort()
{
    groupBoxSettings->setEnabled(false);
    pushButtonOpen->setEnabled(false);
    pushButtonClose->setEnabled(true);
    pushButtonSend->setEnabled(true);

    if (serialPort->isOpen())
        serialPort->close();

    //Settings parameters
    QVariant temp;

    temp = comboBoxPortName->itemData(comboBoxPortName->currentIndex());
    serialPort->setPort(temp.value<QString>()); //Port

    temp = comboBoxBaudRate->itemData(comboBoxBaudRate->currentIndex());
    serialPort->setBaudRate(temp.value<BaudRateType>()); //BaudRate

    temp = comboBoxDataBits->itemData(comboBoxDataBits->currentIndex());
    serialPort->setDataBits(temp.value<DataBitsType>()); //DataBits

    temp = comboBoxParity->itemData(comboBoxParity->currentIndex());
    serialPort->setParity(temp.value<ParityType>()); //Parity

    temp = comboBoxStopBits->itemData(comboBoxStopBits->currentIndex());
    serialPort->setStopBits(temp.value<StopBitsType>()); //StopBits

    temp = comboBoxFlowControl->itemData(comboBoxFlowControl->currentIndex());
    serialPort->setFlowControl(temp.value<FlowType>()); //FlowControl

    serialPort->setTimeout(0, 10);
    serialPort->enableSending();
    serialPort->enableReceiving();

    serialPort->open();
    serialPort->receiveData();
};


void QSerialPortTerminal::slot_closePort()
{
    serialPort->close();

    groupBoxSettings->setEnabled(true);
    pushButtonOpen->setEnabled(true);
    pushButtonClose->setEnabled(false);
    pushButtonSend->setEnabled(false);
};

void QSerialPortTerminal::slot_sendPort()
{
    QString Message;
    Message = lineEditSend->text();

    //Retour a la ligne
    if (checkBoxCR->checkState() == Qt::Checked)
        Message += "\x0D";

    //Saut de ligne
    if (checkBoxLF->checkState() == Qt::Checked)
        Message += "\x0A";

    QByteArray temp(Message.toUtf8());
    serialPort->sendData(temp);

    lineEditSend->clear();
}

void  QSerialPortTerminal::slot_newDataReceived(const QByteArray &dataReceived)
{
    allDataReceived += dataReceived;

    textEditReceive->moveCursor(QTextCursor::End,  QTextCursor::MoveAnchor);

    int mib = comboBoxCodecs->itemData(comboBoxCodecs->currentIndex()).toInt();
    QTextCodec *codec = QTextCodec::codecForMib(mib);

    QTextStream in(dataReceived);
    in.setAutoDetectUnicode(false);
    in.setCodec(codec);
    QString decodedStr = in.readAll();

    textEditReceive->insertPlainText(decodedStr);
}

