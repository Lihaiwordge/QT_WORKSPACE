/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *importLable;
    QGroupBox *groupBox;
    QPushButton *clear_button;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *jiluhao;
    QLineEdit *chexing;
    QLineEdit *cheqing;
    QLineEdit *chepaihao;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_12;
    QLineEdit *shijian;
    QLabel *label_11;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *shoufeizhan;
    QLineEdit *chedao;
    QLineEdit *shoufeiyuan;
    QLineEdit *chewei;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_16;
    QGroupBox *groupBox_3;
    QFrame *line;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *kazhong;
    QLineEdit *kahao;
    QLineEdit *chikaren;
    QLineEdit *koufei;
    QLineEdit *yue;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_13;
    QLabel *kaho_l;
    QLabel *label_3;
    QLabel *label_14;
    QLabel *label_7;
    QWidget *layoutWidget6;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout;
    QLabel *label_15;
    QLineEdit *chongzhi;
    QPushButton *chongzhiButton;
    QGroupBox *groupBox_4;
    QWidget *layoutWidget7;
    QVBoxLayout *verticalLayout_8;
    QTextBrowser *infodisp;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *startSystem;
    QPushButton *closeDoorButton;
    QPushButton *openDoorButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(756, 414);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        importLable = new QLabel(centralWidget);
        importLable->setObjectName(QStringLiteral("importLable"));
        importLable->setGeometry(QRect(230, 10, 361, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277 Light"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        importLable->setFont(font);
        importLable->setStyleSheet(QStringLiteral(""));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 50, 221, 151));
        clear_button = new QPushButton(groupBox);
        clear_button->setObjectName(QStringLiteral("clear_button"));
        clear_button->setGeometry(QRect(390, 200, 75, 23));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 30, 135, 100));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        jiluhao = new QLineEdit(layoutWidget);
        jiluhao->setObjectName(QStringLiteral("jiluhao"));

        verticalLayout->addWidget(jiluhao);

        chexing = new QLineEdit(layoutWidget);
        chexing->setObjectName(QStringLiteral("chexing"));

        verticalLayout->addWidget(chexing);

        cheqing = new QLineEdit(layoutWidget);
        cheqing->setObjectName(QStringLiteral("cheqing"));

        verticalLayout->addWidget(cheqing);

        chepaihao = new QLineEdit(layoutWidget);
        chepaihao->setObjectName(QStringLiteral("chepaihao"));

        verticalLayout->addWidget(chepaihao);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 30, 50, 101));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_2->addWidget(label_4);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_2->addWidget(label_5);

        label_12 = new QLabel(layoutWidget1);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout_2->addWidget(label_12);

        shijian = new QLineEdit(centralWidget);
        shijian->setObjectName(QStringLiteral("shijian"));
        shijian->setGeometry(QRect(60, 330, 681, 20));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 330, 54, 20));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 190, 221, 131));
        layoutWidget2 = new QWidget(groupBox_2);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(60, 20, 135, 100));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        shoufeizhan = new QLineEdit(layoutWidget2);
        shoufeizhan->setObjectName(QStringLiteral("shoufeizhan"));

        verticalLayout_3->addWidget(shoufeizhan);

        chedao = new QLineEdit(layoutWidget2);
        chedao->setObjectName(QStringLiteral("chedao"));

        verticalLayout_3->addWidget(chedao);

        shoufeiyuan = new QLineEdit(layoutWidget2);
        shoufeiyuan->setObjectName(QStringLiteral("shoufeiyuan"));

        verticalLayout_3->addWidget(shoufeiyuan);

        chewei = new QLineEdit(layoutWidget2);
        chewei->setObjectName(QStringLiteral("chewei"));

        verticalLayout_3->addWidget(chewei);

        layoutWidget3 = new QWidget(groupBox_2);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 21, 50, 101));
        verticalLayout_4 = new QVBoxLayout(layoutWidget3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget3);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_4->addWidget(label_8);

        label_9 = new QLabel(layoutWidget3);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_4->addWidget(label_9);

        label_10 = new QLabel(layoutWidget3);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_4->addWidget(label_10);

        label_16 = new QLabel(layoutWidget3);
        label_16->setObjectName(QStringLiteral("label_16"));

        verticalLayout_4->addWidget(label_16);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(240, 50, 211, 271));
        line = new QFrame(groupBox_3);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 170, 181, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        layoutWidget4 = new QWidget(groupBox_3);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(60, 30, 135, 126));
        verticalLayout_5 = new QVBoxLayout(layoutWidget4);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        kazhong = new QLineEdit(layoutWidget4);
        kazhong->setObjectName(QStringLiteral("kazhong"));

        verticalLayout_5->addWidget(kazhong);

        kahao = new QLineEdit(layoutWidget4);
        kahao->setObjectName(QStringLiteral("kahao"));

        verticalLayout_5->addWidget(kahao);

        chikaren = new QLineEdit(layoutWidget4);
        chikaren->setObjectName(QStringLiteral("chikaren"));

        verticalLayout_5->addWidget(chikaren);

        koufei = new QLineEdit(layoutWidget4);
        koufei->setObjectName(QStringLiteral("koufei"));

        verticalLayout_5->addWidget(koufei);

        yue = new QLineEdit(layoutWidget4);
        yue->setObjectName(QStringLiteral("yue"));

        verticalLayout_5->addWidget(yue);

        layoutWidget5 = new QWidget(groupBox_3);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(10, 30, 50, 121));
        verticalLayout_6 = new QVBoxLayout(layoutWidget5);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(layoutWidget5);
        label_13->setObjectName(QStringLiteral("label_13"));

        verticalLayout_6->addWidget(label_13);

        kaho_l = new QLabel(layoutWidget5);
        kaho_l->setObjectName(QStringLiteral("kaho_l"));

        verticalLayout_6->addWidget(kaho_l);

        label_3 = new QLabel(layoutWidget5);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_6->addWidget(label_3);

        label_14 = new QLabel(layoutWidget5);
        label_14->setObjectName(QStringLiteral("label_14"));

        verticalLayout_6->addWidget(label_14);

        label_7 = new QLabel(layoutWidget5);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_6->addWidget(label_7);

        layoutWidget6 = new QWidget(groupBox_3);
        layoutWidget6->setObjectName(QStringLiteral("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(10, 190, 181, 53));
        verticalLayout_7 = new QVBoxLayout(layoutWidget6);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_15 = new QLabel(layoutWidget6);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout->addWidget(label_15);

        chongzhi = new QLineEdit(layoutWidget6);
        chongzhi->setObjectName(QStringLiteral("chongzhi"));

        horizontalLayout->addWidget(chongzhi);


        verticalLayout_7->addLayout(horizontalLayout);

        chongzhiButton = new QPushButton(layoutWidget6);
        chongzhiButton->setObjectName(QStringLiteral("chongzhiButton"));

        verticalLayout_7->addWidget(chongzhiButton);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(460, 50, 281, 271));
        layoutWidget7 = new QWidget(groupBox_4);
        layoutWidget7->setObjectName(QStringLiteral("layoutWidget7"));
        layoutWidget7->setGeometry(QRect(10, 24, 258, 221));
        verticalLayout_8 = new QVBoxLayout(layoutWidget7);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        infodisp = new QTextBrowser(layoutWidget7);
        infodisp->setObjectName(QStringLiteral("infodisp"));

        verticalLayout_8->addWidget(infodisp);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        startSystem = new QPushButton(layoutWidget7);
        startSystem->setObjectName(QStringLiteral("startSystem"));
        startSystem->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 0);"));

        horizontalLayout_2->addWidget(startSystem);

        closeDoorButton = new QPushButton(layoutWidget7);
        closeDoorButton->setObjectName(QStringLiteral("closeDoorButton"));

        horizontalLayout_2->addWidget(closeDoorButton);

        openDoorButton = new QPushButton(layoutWidget7);
        openDoorButton->setObjectName(QStringLiteral("openDoorButton"));

        horizontalLayout_2->addWidget(openDoorButton);


        verticalLayout_8->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 756, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        importLable->setText(QApplication::translate("MainWindow", "\347\247\221\351\231\242\345\201\234\350\275\246\345\234\272\350\275\246\350\276\206\344\277\241\346\201\257\347\256\241\347\220\206\347\263\273\347\273\237", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "\350\275\246\350\276\206\344\277\241\346\201\257", 0));
        clear_button->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272", 0));
        label_2->setText(QApplication::translate("MainWindow", "\350\256\260\345\275\225\345\217\267\357\274\232", 0));
        label_4->setText(QApplication::translate("MainWindow", "\350\275\246\345\236\213\357\274\232", 0));
        label_5->setText(QApplication::translate("MainWindow", "\350\275\246\346\203\205\357\274\232", 0));
        label_12->setText(QApplication::translate("MainWindow", "\350\275\246\347\211\214\345\217\267\357\274\232", 0));
        label_11->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264\357\274\232", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\346\224\266\350\264\271\347\253\231\344\277\241\346\201\257", 0));
        label_8->setText(QApplication::translate("MainWindow", "\346\224\266\350\264\271\347\253\231\357\274\232", 0));
        label_9->setText(QApplication::translate("MainWindow", "\350\275\246\351\201\223\357\274\232", 0));
        label_10->setText(QApplication::translate("MainWindow", "\346\224\266\350\264\271\345\221\230\357\274\232", 0));
        label_16->setText(QApplication::translate("MainWindow", "\350\275\246\344\275\215\357\274\232", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\350\256\260\350\264\246\345\215\241\344\277\241\346\201\257", 0));
        label_13->setText(QApplication::translate("MainWindow", "\345\215\241\347\247\215\357\274\232", 0));
        kaho_l->setText(QApplication::translate("MainWindow", "\345\215\241\345\217\267\357\274\232", 0));
        label_3->setText(QApplication::translate("MainWindow", "\346\214\201\345\215\241\344\272\272\357\274\232", 0));
        label_14->setText(QApplication::translate("MainWindow", "\346\211\243\350\264\271\357\274\232", 0));
        label_7->setText(QApplication::translate("MainWindow", "\344\275\231\351\242\235\357\274\232", 0));
        label_15->setText(QApplication::translate("MainWindow", "\345\205\205\345\200\274\357\274\232 ", 0));
        chongzhiButton->setText(QApplication::translate("MainWindow", "\345\205\205\345\200\274", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\344\277\241\346\201\257\346\230\276\347\244\272\345\214\272\345\237\237", 0));
        startSystem->setText(QApplication::translate("MainWindow", "\345\220\257\345\212\250\347\263\273\347\273\237", 0));
        closeDoorButton->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\270\351\227\250", 0));
        openDoorButton->setText(QApplication::translate("MainWindow", "\345\274\200\351\227\270\351\227\250", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
