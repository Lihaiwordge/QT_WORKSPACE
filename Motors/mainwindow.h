#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_Start_clicked();
    void on_dial_1_sliderReleased();

    void on_dial_2_sliderReleased();

    void on_dial_3_sliderReleased();

    void on_dial_4_sliderReleased();

    void on_pushButton_clicked();

    void RxData();

    void on_pushButton_Stop_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();


private:
    Ui::MainWindow *ui;


    QSerialPort *serialPort;
    //QString PortName;


};

#endif // MAINWINDOW_H
