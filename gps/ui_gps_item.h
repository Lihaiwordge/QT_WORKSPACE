/********************************************************************************
** Form generated from reading ui file 'gps_item.ui'
**
** Created: Sun May 16 22:44:55 2010
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_GPS_ITEM_H
#define UI_GPS_ITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gps_item
{
public:
    QLabel *label_1;
    QPushButton *pushButton_up;
    QPushButton *pushButton_down;
    QPushButton *pushButton_left;
    QPushButton *pushButton_right;
    QPushButton *pushButton_goto;
    QPushButton *pushButton_return;
    QLabel *label_2;
    QLabel *label_star;

    void setupUi(QWidget *gps_item)
    {
        if (gps_item->objectName().isEmpty())
            gps_item->setObjectName(QString::fromUtf8("gps_item"));
        gps_item->resize(320, 240);
        label_1 = new QLabel(gps_item);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(0, 0, 321, 241));
        pushButton_up = new QPushButton(gps_item);
        pushButton_up->setObjectName(QString::fromUtf8("pushButton_up"));
        pushButton_up->setGeometry(QRect(290, 10, 31, 31));
        pushButton_down = new QPushButton(gps_item);
        pushButton_down->setObjectName(QString::fromUtf8("pushButton_down"));
        pushButton_down->setGeometry(QRect(290, 50, 31, 31));
        pushButton_left = new QPushButton(gps_item);
        pushButton_left->setObjectName(QString::fromUtf8("pushButton_left"));
        pushButton_left->setGeometry(QRect(290, 90, 31, 31));
        pushButton_right = new QPushButton(gps_item);
        pushButton_right->setObjectName(QString::fromUtf8("pushButton_right"));
        pushButton_right->setGeometry(QRect(290, 130, 31, 31));
        pushButton_goto = new QPushButton(gps_item);
        pushButton_goto->setObjectName(QString::fromUtf8("pushButton_goto"));
        pushButton_goto->setGeometry(QRect(290, 170, 31, 31));
        pushButton_return = new QPushButton(gps_item);
        pushButton_return->setObjectName(QString::fromUtf8("pushButton_return"));
        pushButton_return->setGeometry(QRect(290, 210, 31, 31));
        label_2 = new QLabel(gps_item);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 321, 241));
        label_star = new QLabel(gps_item);
        label_star->setObjectName(QString::fromUtf8("label_star"));
        label_star->setGeometry(QRect(250, 100, 14, 14));

        retranslateUi(gps_item);

        QMetaObject::connectSlotsByName(gps_item);
    } // setupUi

    void retranslateUi(QWidget *gps_item)
    {
        gps_item->setWindowTitle(QApplication::translate("gps_item", "gps_item", 0));
        label_1->setText(QString());
        pushButton_up->setText(QString());
        pushButton_down->setText(QString());
        pushButton_left->setText(QString());
        pushButton_right->setText(QString());
        pushButton_goto->setText(QString());
        pushButton_return->setText(QString());
        label_2->setText(QString());
        label_star->setText(QString());
        Q_UNUSED(gps_item);
    } // retranslateUi

};

namespace Ui {
    class gps_item: public Ui_gps_item {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GPS_ITEM_H
