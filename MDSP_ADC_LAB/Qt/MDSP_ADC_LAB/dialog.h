#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    QSerialPort *serialPort;
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:


    void on_button_start_device_clicked();

    void on_button_start_a_clicked();

    void on_button_stop_a_clicked();

    void on_button_clear_a_clicked();

    void on_button_save_a_clicked();

    void on_button_start_b_clicked();

    void on_button_stop_b_clicked();

    void on_button_clear_b_clicked();

    void on_button_close_device_clicked();

    void on_button_exit_clicked();

    void RxData( void );
    void on_button_link_serial_clicked();

private:
    Ui::Dialog *ui;

    bool bool_a_editAreaEnable;
    bool bool_b_editAreaEnable;
    int count;
};

#endif // DIALOG_H
