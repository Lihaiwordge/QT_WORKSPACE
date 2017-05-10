/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGroupBox *groupBox;
    QLabel *label_3;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *button_start_a;
    QPushButton *button_stop_a;
    QPushButton *button_clear_a;
    QPushButton *button_save_a;
    QTextEdit *textedit_a_area;
    QGroupBox *groupBox_2;
    QLabel *label_2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QPushButton *button_start_b;
    QPushButton *button_stop_b;
    QPushButton *button_clear_b;
    QPushButton *button_save_b;
    QTextEdit *textedit_b_area;
    QLabel *label;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_10;
    QRadioButton *radiobutton_a_uart;
    QRadioButton *radiobutton_b_uart;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineedit_a_samplerate;
    QLineEdit *lineedit_b_samplerate;
    QLineEdit *lineedit_a_peakvalue;
    QLineEdit *lineedit_b_peakvalue;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_9;
    QRadioButton *radiobutton_adc_yes;
    QRadioButton *radiobutton_adc_no;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout;
    QLabel *label_8;
    QRadioButton *radiobutton_soc_yes;
    QRadioButton *radiobutton_soc_no;
    QWidget *layoutWidget6;
    QVBoxLayout *verticalLayout_5;
    QPushButton *button_start_device;
    QPushButton *button_close_device;
    QFrame *line;
    QPushButton *button_exit;
    QFrame *frame;
    QLabel *label_11;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(787, 405);
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 40, 561, 151));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(120, 10, 141, 21));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 21, 77, 121));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        button_start_a = new QPushButton(layoutWidget);
        button_start_a->setObjectName(QStringLiteral("button_start_a"));

        verticalLayout->addWidget(button_start_a);

        button_stop_a = new QPushButton(layoutWidget);
        button_stop_a->setObjectName(QStringLiteral("button_stop_a"));

        verticalLayout->addWidget(button_stop_a);

        button_clear_a = new QPushButton(layoutWidget);
        button_clear_a->setObjectName(QStringLiteral("button_clear_a"));

        verticalLayout->addWidget(button_clear_a);

        button_save_a = new QPushButton(layoutWidget);
        button_save_a->setObjectName(QStringLiteral("button_save_a"));

        verticalLayout->addWidget(button_save_a);

        textedit_a_area = new QTextEdit(groupBox);
        textedit_a_area->setObjectName(QStringLiteral("textedit_a_area"));
        textedit_a_area->setGeometry(QRect(120, 30, 421, 111));
        groupBox_2 = new QGroupBox(Dialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 200, 561, 161));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(120, 20, 141, 21));
        layoutWidget1 = new QWidget(groupBox_2);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 20, 77, 131));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        button_start_b = new QPushButton(layoutWidget1);
        button_start_b->setObjectName(QStringLiteral("button_start_b"));

        verticalLayout_2->addWidget(button_start_b);

        button_stop_b = new QPushButton(layoutWidget1);
        button_stop_b->setObjectName(QStringLiteral("button_stop_b"));

        verticalLayout_2->addWidget(button_stop_b);

        button_clear_b = new QPushButton(layoutWidget1);
        button_clear_b->setObjectName(QStringLiteral("button_clear_b"));

        verticalLayout_2->addWidget(button_clear_b);

        button_save_b = new QPushButton(layoutWidget1);
        button_save_b->setObjectName(QStringLiteral("button_save_b"));

        verticalLayout_2->addWidget(button_save_b);

        textedit_b_area = new QTextEdit(groupBox_2);
        textedit_b_area->setObjectName(QStringLiteral("textedit_b_area"));
        textedit_b_area->setGeometry(QRect(120, 40, 421, 111));
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 370, 241, 31));
        groupBox_3 = new QGroupBox(Dialog);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(590, 40, 181, 321));
        layoutWidget2 = new QWidget(groupBox_3);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 208, 126, 18));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(layoutWidget2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setStyleSheet(QStringLiteral(""));

        horizontalLayout_4->addWidget(label_10);

        radiobutton_a_uart = new QRadioButton(layoutWidget2);
        radiobutton_a_uart->setObjectName(QStringLiteral("radiobutton_a_uart"));

        horizontalLayout_4->addWidget(radiobutton_a_uart);

        radiobutton_b_uart = new QRadioButton(layoutWidget2);
        radiobutton_b_uart->setObjectName(QStringLiteral("radiobutton_b_uart"));

        horizontalLayout_4->addWidget(radiobutton_b_uart);

        layoutWidget3 = new QWidget(groupBox_3);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 30, 161, 102));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_4 = new QLabel(layoutWidget3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QStringLiteral(""));

        verticalLayout_4->addWidget(label_4);

        label_5 = new QLabel(layoutWidget3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QStringLiteral(""));

        verticalLayout_4->addWidget(label_5);

        label_6 = new QLabel(layoutWidget3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setStyleSheet(QStringLiteral(""));

        verticalLayout_4->addWidget(label_6);

        label_7 = new QLabel(layoutWidget3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setStyleSheet(QStringLiteral(""));

        verticalLayout_4->addWidget(label_7);


        horizontalLayout_3->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        lineedit_a_samplerate = new QLineEdit(layoutWidget3);
        lineedit_a_samplerate->setObjectName(QStringLiteral("lineedit_a_samplerate"));

        verticalLayout_3->addWidget(lineedit_a_samplerate);

        lineedit_b_samplerate = new QLineEdit(layoutWidget3);
        lineedit_b_samplerate->setObjectName(QStringLiteral("lineedit_b_samplerate"));

        verticalLayout_3->addWidget(lineedit_b_samplerate);

        lineedit_a_peakvalue = new QLineEdit(layoutWidget3);
        lineedit_a_peakvalue->setObjectName(QStringLiteral("lineedit_a_peakvalue"));

        verticalLayout_3->addWidget(lineedit_a_peakvalue);

        lineedit_b_peakvalue = new QLineEdit(layoutWidget3);
        lineedit_b_peakvalue->setObjectName(QStringLiteral("lineedit_b_peakvalue"));

        verticalLayout_3->addWidget(lineedit_b_peakvalue);


        horizontalLayout_3->addLayout(verticalLayout_3);

        layoutWidget4 = new QWidget(groupBox_3);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 184, 144, 18));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget4);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(label_9);

        radiobutton_adc_yes = new QRadioButton(layoutWidget4);
        radiobutton_adc_yes->setObjectName(QStringLiteral("radiobutton_adc_yes"));

        horizontalLayout_2->addWidget(radiobutton_adc_yes);

        radiobutton_adc_no = new QRadioButton(layoutWidget4);
        radiobutton_adc_no->setObjectName(QStringLiteral("radiobutton_adc_no"));

        horizontalLayout_2->addWidget(radiobutton_adc_no);

        layoutWidget5 = new QWidget(groupBox_3);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(10, 160, 144, 18));
        horizontalLayout = new QHBoxLayout(layoutWidget5);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget5);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(label_8);

        radiobutton_soc_yes = new QRadioButton(layoutWidget5);
        radiobutton_soc_yes->setObjectName(QStringLiteral("radiobutton_soc_yes"));

        horizontalLayout->addWidget(radiobutton_soc_yes);

        radiobutton_soc_no = new QRadioButton(layoutWidget5);
        radiobutton_soc_no->setObjectName(QStringLiteral("radiobutton_soc_no"));

        horizontalLayout->addWidget(radiobutton_soc_no);

        layoutWidget6 = new QWidget(groupBox_3);
        layoutWidget6->setObjectName(QStringLiteral("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(10, 250, 161, 54));
        verticalLayout_5 = new QVBoxLayout(layoutWidget6);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        button_start_device = new QPushButton(layoutWidget6);
        button_start_device->setObjectName(QStringLiteral("button_start_device"));

        verticalLayout_5->addWidget(button_start_device);

        button_close_device = new QPushButton(layoutWidget6);
        button_close_device->setObjectName(QStringLiteral("button_close_device"));

        verticalLayout_5->addWidget(button_close_device);

        line = new QFrame(groupBox_3);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 150, 118, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        button_exit = new QPushButton(Dialog);
        button_exit->setObjectName(QStringLiteral("button_exit"));
        button_exit->setGeometry(QRect(700, 370, 75, 23));
        frame = new QFrame(Dialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(20, 370, 51, 21));
        frame->setStyleSheet(QStringLiteral("background-image: url(:/logo_hui.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_11 = new QLabel(Dialog);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(30, 10, 441, 21));
        label_11->setStyleSheet(QStringLiteral("font: 87 14pt \"Bodoni MT Black\";"));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("Dialog", "A Channel", 0));
        label_3->setText(QApplication::translate("Dialog", "Data receiving area", 0));
        button_start_a->setText(QApplication::translate("Dialog", "Start A", 0));
        button_stop_a->setText(QApplication::translate("Dialog", "Stop A", 0));
        button_clear_a->setText(QApplication::translate("Dialog", "Clear A", 0));
        button_save_a->setText(QApplication::translate("Dialog", "Save A", 0));
        groupBox_2->setTitle(QApplication::translate("Dialog", "B Channel", 0));
        label_2->setText(QApplication::translate("Dialog", "Data receiving area", 0));
        button_start_b->setText(QApplication::translate("Dialog", "Start B", 0));
        button_stop_b->setText(QApplication::translate("Dialog", "Stop B", 0));
        button_clear_b->setText(QApplication::translate("Dialog", "Clear B", 0));
        button_save_b->setText(QApplication::translate("Dialog", "Save B", 0));
        label->setText(QApplication::translate("Dialog", "Multi channel acquisition system.", 0));
        groupBox_3->setTitle(QApplication::translate("Dialog", "Control", 0));
        label_10->setText(QApplication::translate("Dialog", "UAR\351\200\211\346\213\251\357\274\232", 0));
        radiobutton_a_uart->setText(QApplication::translate("Dialog", "A", 0));
        radiobutton_b_uart->setText(QApplication::translate("Dialog", "B", 0));
        label_4->setText(QApplication::translate("Dialog", "A\351\207\207\346\240\267\347\216\207\357\274\232", 0));
        label_5->setText(QApplication::translate("Dialog", "B\351\207\207\346\240\267\347\216\207\357\274\232", 0));
        label_6->setText(QApplication::translate("Dialog", "A\345\263\260\345\200\274\357\274\232", 0));
        label_7->setText(QApplication::translate("Dialog", "B\345\263\260\345\200\274\357\274\232", 0));
        lineedit_a_samplerate->setText(QApplication::translate("Dialog", "16000", 0));
        lineedit_b_samplerate->setText(QApplication::translate("Dialog", "16000", 0));
        lineedit_a_peakvalue->setText(QApplication::translate("Dialog", "3.0", 0));
        lineedit_b_peakvalue->setText(QApplication::translate("Dialog", "3.0", 0));
        label_9->setText(QApplication::translate("Dialog", "ADC\345\220\257\345\212\250\357\274\232", 0));
        radiobutton_adc_yes->setText(QApplication::translate("Dialog", "Yes", 0));
        radiobutton_adc_no->setText(QApplication::translate("Dialog", "No", 0));
        label_8->setText(QApplication::translate("Dialog", "SOC\345\220\257\345\212\250\357\274\232", 0));
        radiobutton_soc_yes->setText(QApplication::translate("Dialog", "Yes", 0));
        radiobutton_soc_no->setText(QApplication::translate("Dialog", "No", 0));
        button_start_device->setText(QApplication::translate("Dialog", "\345\274\200\345\220\257\350\256\276\345\244\207", 0));
        button_close_device->setText(QApplication::translate("Dialog", "\345\205\263\351\227\255\350\256\276\345\244\207", 0));
        button_exit->setText(QApplication::translate("Dialog", "Exit", 0));
        label_11->setText(QApplication::translate("Dialog", "Multi-channel acquisition system", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
