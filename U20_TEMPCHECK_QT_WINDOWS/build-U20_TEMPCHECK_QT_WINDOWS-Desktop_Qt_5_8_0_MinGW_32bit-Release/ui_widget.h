/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_title;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QTextBrowser *textBrowser;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_6;
    QLCDNumber *lcdNumber;
    QCheckBox *checkBox;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QComboBox *DeviceList;
    QPushButton *pushButton_startDevice;
    QPushButton *pushButton_stopDevice;
    QPushButton *pushButton_light;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_diatemp;
    QDial *dial;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QCustomPlot *plot;
    QLabel *label_currentTemp;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1007, 684);
        verticalLayout_5 = new QVBoxLayout(Widget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_title = new QLabel(Widget);
        label_title->setObjectName(QStringLiteral("label_title"));

        verticalLayout_4->addWidget(label_title);

        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_4->addWidget(label);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        textBrowser = new QTextBrowser(groupBox);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"font: 8pt \"\351\273\221\344\275\223\";\n"
"color: rgb(85, 255, 0);"));

        horizontalLayout->addWidget(textBrowser);


        horizontalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_7 = new QVBoxLayout(groupBox_2);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        lcdNumber = new QLCDNumber(groupBox_2);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setMinimumSize(QSize(220, 80));
        lcdNumber->setMaximumSize(QSize(220, 80));
        lcdNumber->setDigitCount(8);

        verticalLayout_6->addWidget(lcdNumber);

        checkBox = new QCheckBox(groupBox_2);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        verticalLayout_6->addWidget(checkBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        DeviceList = new QComboBox(groupBox_2);
        DeviceList->setObjectName(QStringLiteral("DeviceList"));

        verticalLayout->addWidget(DeviceList);

        pushButton_startDevice = new QPushButton(groupBox_2);
        pushButton_startDevice->setObjectName(QStringLiteral("pushButton_startDevice"));
        pushButton_startDevice->setMinimumSize(QSize(100, 30));
        pushButton_startDevice->setMaximumSize(QSize(100, 40));

        verticalLayout->addWidget(pushButton_startDevice);

        pushButton_stopDevice = new QPushButton(groupBox_2);
        pushButton_stopDevice->setObjectName(QStringLiteral("pushButton_stopDevice"));
        pushButton_stopDevice->setMinimumSize(QSize(100, 30));
        pushButton_stopDevice->setMaximumSize(QSize(100, 40));

        verticalLayout->addWidget(pushButton_stopDevice);

        pushButton_light = new QPushButton(groupBox_2);
        pushButton_light->setObjectName(QStringLiteral("pushButton_light"));
        pushButton_light->setMinimumSize(QSize(100, 30));
        pushButton_light->setMaximumSize(QSize(100, 40));

        verticalLayout->addWidget(pushButton_light);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_diatemp = new QLabel(groupBox_2);
        label_diatemp->setObjectName(QStringLiteral("label_diatemp"));
        label_diatemp->setMinimumSize(QSize(100, 30));
        label_diatemp->setMaximumSize(QSize(100, 30));

        verticalLayout_2->addWidget(label_diatemp);

        dial = new QDial(groupBox_2);
        dial->setObjectName(QStringLiteral("dial"));
        dial->setMinimum(100);
        dial->setMaximum(500);

        verticalLayout_2->addWidget(dial);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_6->addLayout(horizontalLayout_2);


        verticalLayout_7->addLayout(verticalLayout_6);


        horizontalLayout_3->addWidget(groupBox_2);


        verticalLayout_4->addLayout(horizontalLayout_3);

        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        plot = new QCustomPlot(groupBox_3);
        plot->setObjectName(QStringLiteral("plot"));
        plot->setMinimumSize(QSize(950, 250));
        plot->setMaximumSize(QSize(820, 250));
        label_currentTemp = new QLabel(plot);
        label_currentTemp->setObjectName(QStringLiteral("label_currentTemp"));
        label_currentTemp->setGeometry(QRect(810, 20, 121, 20));

        verticalLayout_3->addWidget(plot);


        verticalLayout_4->addWidget(groupBox_3);


        verticalLayout_5->addLayout(verticalLayout_4);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label_title->setText(QApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:28pt; font-weight:600;\">\346\270\251\345\272\246\346\243\200\346\265\213\347\263\273\347\273\237</span></p></body></html>", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "MULTIBEANS\346\212\200\346\234\257\346\224\257\346\214\201\357\274\232QQ380499998\357\274\233\346\257\225\344\270\232\350\256\276\350\256\241\344\273\243\345\201\232\357\274\233\350\256\272\346\226\207\345\217\221\350\241\250\357\274\233", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Widget", "\344\277\241\346\201\257\346\217\220\347\244\272\357\274\232", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("Widget", "\346\216\247\345\210\266\346\230\276\347\244\272", Q_NULLPTR));
        checkBox->setText(QApplication::translate("Widget", "\346\270\251\345\272\246\350\241\245\345\201\277", Q_NULLPTR));
        DeviceList->clear();
        DeviceList->insertItems(0, QStringList()
         << QApplication::translate("Widget", "\350\207\252\345\212\250\350\277\236\346\216\245", Q_NULLPTR)
         << QString()
        );
        pushButton_startDevice->setText(QApplication::translate("Widget", "\345\274\200\345\220\257\350\256\276\345\244\207", Q_NULLPTR));
        pushButton_stopDevice->setText(QApplication::translate("Widget", "\345\205\263\351\227\255\350\256\276\345\244\207", Q_NULLPTR));
        pushButton_light->setText(QApplication::translate("Widget", "\346\214\207\347\244\272\347\201\257", Q_NULLPTR));
        label_diatemp->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("Widget", "\347\273\230\345\233\276", Q_NULLPTR));
        label_currentTemp->setText(QApplication::translate("Widget", "0.0\342\204\203", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
