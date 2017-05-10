#include "dialog.h"
#include "ui_dialog.h"
#include "QDateTime"
#include "QLinkedList"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle("多通道采集系统");

    serialPort = new QSerialPort;

    serialPort->setBaudRate(QSerialPort::Baud115200);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);
    connect(serialPort,SIGNAL(readyRead()),this,SLOT(RxData()));

    /* Init value */
    bool_a_editAreaEnable   =   false;

    bool_b_editAreaEnable   =   false;
    ui->button_start_a->setEnabled(true);
    ui->button_stop_a->setEnabled(false);
    ui->button_stop_b->setEnabled(false);
    ui->button_start_b ->setEnabled(true);
    ui->button_start_device->setEnabled(true);
    ui->button_close_device->setEnabled(false);

    ui->radiobutton_adc_no->setChecked(true);
    ui->radiobutton_adc_no->setChecked(false);
    ui->radiobutton_adc_yes->setChecked(true);
    ui->radiobutton_a_uart->setChecked(true);
    ui->radiobutton_b_uart->setChecked(false);
    ui->radiobutton_soc_no->setChecked(true);
    ui->radiobutton_soc_yes->setChecked(false);
}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_button_start_device_clicked()
{
    bool soc_yes, adc_yes, uart_yes;


    QString lineInput;
    /* Check the lineEdits empty. */
    lineInput = ui->lineedit_a_peakvalue->text();
    if( lineInput.isEmpty()  == true ) {
         QMessageBox::warning(this, "Empty Warning","The A PeakValue is empty!!");
         return;
    }
    lineInput = ui->lineedit_a_samplerate->text();
    if( lineInput.isEmpty() == true ) {
        QMessageBox::warning(this, "Empty Warning","The A SampleRate is empty!!");
        return;
    }
    lineInput = ui->lineedit_b_peakvalue->text();
    if( lineInput.isEmpty()  == true ) {
         QMessageBox::warning(this, "Empty Warning","The B PeakValue is empty!!");
         return;
    }
    lineInput = ui->lineedit_b_samplerate->text();
    if( lineInput.isEmpty() == true ) {
        QMessageBox::warning(this, "Empty Warning","The B SampleRate is empty!!");
        return;
    }
    // Check the ratioButtons.
    if( ui->radiobutton_adc_no->isChecked() == true ) {
        adc_yes =   false;
    }else {
        adc_yes =   true;
    }
    if( ui->radiobutton_soc_no->isChecked() == true ) {
        soc_yes =   false;
    }else {
        soc_yes =   true;
    }
    if( ui->radiobutton_a_uart->isChecked() == true ) {
        uart_yes    =   true;
    }else {
        uart_yes    =   false;
    }

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        QSerialPort serial;
        serial.setPort(info);
        if (serial.open(QIODevice::ReadWrite))
        {
            serialPort->setPortName(info.portName());

            serial.close();

        }
    }
    if (!serialPort->open(QIODevice::ReadWrite))
    {
        QMessageBox::warning(this,"Warring","Open serial port failed!");
    }
    else
    {


        qDebug()<<"Open COM port succuss!";
        ui->button_start_device->setEnabled(false);
        ui->button_close_device->setEnabled(true);

        // Insert code of
        //ByteDtat.append(0xAA);       //head1
        //ByteDtat.append(0xBB);       //head2
        //ByteDtat.append(0xAC);       //cmd
        //ByteDtat.append((char)0x00);//data
        //uchar checkSum = 0xAA ^ 0xBB ^ 0xAC ^ 0x00;
        //ByteDtat.append(checkSum);   //check
        //serialPort->write(ByteDtat); //send data
    }
}



void Dialog::RxData()
{

    QByteArray ByteRxData = serialPort->readAll();

    if( count % 2 == 0 ) {
        if( bool_a_editAreaEnable   ==  true ) {
            ui->textedit_a_area->append(ByteRxData);
        }
    }else if( count % 2 == 1 ) {
        if( bool_b_editAreaEnable   ==  true ) {
            ui->textedit_b_area->append(ByteRxData);
        }
    }

    count ++;
}
void Dialog::on_button_start_a_clicked()
{
    bool_a_editAreaEnable   =   true;
    ui->button_stop_a->setEnabled(true);
    ui->button_start_a->setEnabled(false);
    ui->textedit_a_area->append(tr("System-> The A channel has been enabled!!  "));
}
void Dialog::on_button_stop_a_clicked()
{
    bool_a_editAreaEnable   =   false;
    ui->button_stop_a->setEnabled(false);
    ui->button_start_a->setEnabled(true);
    ui->textedit_a_area->append(tr("System-> The A channel has been Disabled!!  "));
}

void Dialog::on_button_clear_a_clicked()
{
    ui->textedit_a_area->clear();
}


void Dialog::on_button_save_a_clicked()
{

}

void Dialog::on_button_start_b_clicked()
{
    bool_b_editAreaEnable   =   true;
    ui->button_stop_b->setEnabled(true);
    ui->button_start_b->setEnabled(false);
    ui->textedit_b_area->append(tr("System-> The B channel has been Enable!!  "));
}

void Dialog::on_button_stop_b_clicked()
{
    bool_b_editAreaEnable   =   false;
    ui->button_stop_b->setEnabled(false);
    ui->button_start_b->setEnabled(true);
    ui->textedit_b_area->append(tr("System-> The B channel has been Disable!!  "));
}

void Dialog::on_button_clear_b_clicked()
{
    ui->textedit_b_area->clear();
}

void Dialog::on_button_close_device_clicked()
{
    ui->button_start_device->setEnabled(true);
    ui->button_close_device->setEnabled(false);
    serialPort->close();
}

void Dialog::on_button_exit_clicked()
{
    serialPort->close();
    QApplication::exit();
}

void Dialog::on_button_link_serial_clicked()
{

}
