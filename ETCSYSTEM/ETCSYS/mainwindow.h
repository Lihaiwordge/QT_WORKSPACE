#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include <QDebug>
#include "carinfo.h"
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    void DisplayToUI( class CarInfo *info, class CarStation *station );
    void Chongzhi(void);
    CarStation *carStation;
    CarInfo *carInfo1;
    CarInfo *carInfo2;
    CarInfo *carInfo3;
    CarInfo *carInfo4;
    CarInfo *carInfo5;
    CarInfo *carInfo6;
    CarInfo *blankCarInfo;
    ~MainWindow();
    int currentChe;
private slots:
    void on_startSystem_clicked();

    void on_openDoorButton_clicked();

    void on_closeDoorButton_clicked();

    void RxData();

    void on_clear_button_clicked();

    void on_chongzhiButton_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort *serialPort;
    QSqlQuery qer;
    QString dkahao;
    float dyue;
    QString cmd1;
    QString cmd2;
    QString cmd3;
    QString  cmd4;
    QString cmd5;
    QString cmd;

};



#endif // MAINWINDOW_H
