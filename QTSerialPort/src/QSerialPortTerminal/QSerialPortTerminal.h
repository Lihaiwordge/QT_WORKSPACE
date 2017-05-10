/********************************************************************************************************
* PROGRAM      : QSerialPortTerminal
* DATE - TIME  : mardi 04 mars 2008 - 11h20
* AUTHOR       : VIANNEY-LIAUD Philippe ( philippe.vianney.liaud@gmail.com )
* FILENAME     : QSerialPortTerminal.h
* LICENSE      : GPL
* COMMENTARY   : Manage qExtSerialPort
********************************************************************************************************/
#ifndef QSERIALPORTTERMINAL_H
#define QSERIALPORTTERMINAL_H
//
#include <QMainWindow>
#include "ui_QSerialPortTerminal.h"
#include  "src/SerialPort/ManageSerialPort.h"

class QextSerialPort;

class QSerialPortTerminal : public QMainWindow, public Ui::QSerialPortTerminal
{
    Q_OBJECT

public:
    QSerialPortTerminal( QWidget* = 0 );
    ~QSerialPortTerminal();

private slots:
    //General
    void updatetextEditReceive();
    void slot_openPort();
    void slot_closePort();
    void slot_sendPort();

    //SerialPort
    void slot_newDataReceived(const QByteArray &dataReceived);

private:
    ManageSerialPort *serialPort;
    QByteArray allDataReceived;
};

#endif // QSERIALPORTTERMINAL_H
