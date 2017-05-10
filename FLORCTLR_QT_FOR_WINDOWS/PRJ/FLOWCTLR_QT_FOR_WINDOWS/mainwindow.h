#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include <QDebug>
#include <qtimer.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    volatile bool flag_cyc_rec_ok;
    volatile bool flag_sin_rec_ok;
    QSerialPort *serialPort;
    Ui::MainWindow *ui;
    quint8 time;
    QTimer *qTimer;
    QTimer *qTimer0;
    QString comStr;


    void connectCmdBytes( double f_data, QByteArray *qb);
    void protocalProcess( QString str );

private slots:
    void RxData();

    void on_pushButton_setLink_clicked();
    void on_pushButton_disLink_clicked();
    void on_pushButton_cyc_yx_clicked();
    void on_pushButton_cyc_zt_clicked();
    void on_pushButton_cyc_tz_clicked();
    void on_pushButton_cyc_csbc_clicked();
    void on_pushButton_cyc_qksj_clicked();
    void on_pushButton_cyc_xrsj_clicked();
    void on_pushButton_sin_yx_clicked();
    void on_pushButton_sin_zt_clicked();
    void on_pushButton_sin_tz_clicked();
    void on_pushButton_sin_xrsj_clicked();
    void on_pushButton_sin_csbc_clicked();
    void on_pushButton_sin_qksj_clicked();
    void on_pushButton_all_setTemp_clicked();
    void timerOut();
    void timer0Out();
    void on_pushButton_sin_extract_clicked();
    void on_comboBox_sin_zsqbh_currentIndexChanged(int index);
};

#endif // MAINWINDOW_H
