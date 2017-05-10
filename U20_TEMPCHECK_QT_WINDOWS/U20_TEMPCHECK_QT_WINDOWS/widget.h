#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include <QDebug>
#include <QTimer>
#include <QSound>
#include "qcustomplot.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_startDevice_clicked();

    void on_pushButton_stopDevice_clicked();

    void on_dial_valueChanged(int value);

    void RxData();

    void SerialTimeOut();

    void TempCheckTimeOut();

    void on_pushButton_light_clicked();

private:
    Ui::Widget *ui;
    void ProcessData( QString cmd );


public :
    QString rec_cmd;
    QString strWavPath;
    QSound *sound;
    bool playFlag;
    long playTime;
    QCustomPlot *plot;
    long xcount;
    long xrange;
private:
    QSerialPort *serialPort;
    QTimer  *serialTimer;
    QTimer  *tempCheckTimer;
    bool serialRead;
    double ds18b20SensorTemp;
    double lm75aSensorTemp;
    double resSensorTemp;
    float setPloyTemp;

};

#endif // WIDGET_H
