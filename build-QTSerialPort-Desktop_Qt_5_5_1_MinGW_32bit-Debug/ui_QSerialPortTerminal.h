/********************************************************************************
** Form generated from reading UI file 'QSerialPortTerminal.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QSERIALPORTTERMINAL_H
#define UI_QSERIALPORTTERMINAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QSerialPortTerminal
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBoxSettings;
    QGridLayout *gridLayout;
    QLabel *labelPort;
    QComboBox *comboBoxPortName;
    QLabel *labelBaudRate;
    QComboBox *comboBoxBaudRate;
    QLabel *labelData;
    QComboBox *comboBoxDataBits;
    QLabel *labelParity;
    QComboBox *comboBoxParity;
    QLabel *labelStop;
    QComboBox *comboBoxStopBits;
    QLabel *labelFlowControl;
    QComboBox *comboBoxFlowControl;
    QGroupBox *groupBoxOptions;
    QGridLayout *gridLayout_2;
    QLabel *labelCodec;
    QComboBox *comboBoxCodecs;
    QSpacerItem *verticalSpacer;
    QFrame *frame_2;
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QPushButton *pushButtonOpen;
    QSpacerItem *spacerItem;
    QPushButton *pushButtonClose;
    QTextEdit *textEditReceive;
    QHBoxLayout *hboxLayout1;
    QLineEdit *lineEditSend;
    QCheckBox *checkBoxCR;
    QCheckBox *checkBoxLF;
    QPushButton *pushButtonSend;

    void setupUi(QMainWindow *QSerialPortTerminal)
    {
        if (QSerialPortTerminal->objectName().isEmpty())
            QSerialPortTerminal->setObjectName(QStringLiteral("QSerialPortTerminal"));
        QSerialPortTerminal->resize(480, 289);
        QFont font;
        font.setFamily(QStringLiteral("Wenquanyi Bitmap Song"));
        font.setPointSize(12);
        QSerialPortTerminal->setFont(font);
        centralwidget = new QWidget(QSerialPortTerminal);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBoxSettings = new QGroupBox(centralwidget);
        groupBoxSettings->setObjectName(QStringLiteral("groupBoxSettings"));
        gridLayout = new QGridLayout(groupBoxSettings);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labelPort = new QLabel(groupBoxSettings);
        labelPort->setObjectName(QStringLiteral("labelPort"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelPort->sizePolicy().hasHeightForWidth());
        labelPort->setSizePolicy(sizePolicy);

        gridLayout->addWidget(labelPort, 0, 0, 1, 1);

        comboBoxPortName = new QComboBox(groupBoxSettings);
        comboBoxPortName->setObjectName(QStringLiteral("comboBoxPortName"));

        gridLayout->addWidget(comboBoxPortName, 0, 1, 1, 1);

        labelBaudRate = new QLabel(groupBoxSettings);
        labelBaudRate->setObjectName(QStringLiteral("labelBaudRate"));
        sizePolicy.setHeightForWidth(labelBaudRate->sizePolicy().hasHeightForWidth());
        labelBaudRate->setSizePolicy(sizePolicy);

        gridLayout->addWidget(labelBaudRate, 1, 0, 1, 1);

        comboBoxBaudRate = new QComboBox(groupBoxSettings);
        comboBoxBaudRate->setObjectName(QStringLiteral("comboBoxBaudRate"));

        gridLayout->addWidget(comboBoxBaudRate, 1, 1, 1, 1);

        labelData = new QLabel(groupBoxSettings);
        labelData->setObjectName(QStringLiteral("labelData"));
        sizePolicy.setHeightForWidth(labelData->sizePolicy().hasHeightForWidth());
        labelData->setSizePolicy(sizePolicy);

        gridLayout->addWidget(labelData, 2, 0, 1, 1);

        comboBoxDataBits = new QComboBox(groupBoxSettings);
        comboBoxDataBits->setObjectName(QStringLiteral("comboBoxDataBits"));

        gridLayout->addWidget(comboBoxDataBits, 2, 1, 1, 1);

        labelParity = new QLabel(groupBoxSettings);
        labelParity->setObjectName(QStringLiteral("labelParity"));
        sizePolicy.setHeightForWidth(labelParity->sizePolicy().hasHeightForWidth());
        labelParity->setSizePolicy(sizePolicy);

        gridLayout->addWidget(labelParity, 3, 0, 1, 1);

        comboBoxParity = new QComboBox(groupBoxSettings);
        comboBoxParity->setObjectName(QStringLiteral("comboBoxParity"));

        gridLayout->addWidget(comboBoxParity, 3, 1, 1, 1);

        labelStop = new QLabel(groupBoxSettings);
        labelStop->setObjectName(QStringLiteral("labelStop"));
        sizePolicy.setHeightForWidth(labelStop->sizePolicy().hasHeightForWidth());
        labelStop->setSizePolicy(sizePolicy);

        gridLayout->addWidget(labelStop, 4, 0, 1, 1);

        comboBoxStopBits = new QComboBox(groupBoxSettings);
        comboBoxStopBits->setObjectName(QStringLiteral("comboBoxStopBits"));

        gridLayout->addWidget(comboBoxStopBits, 4, 1, 1, 1);

        labelFlowControl = new QLabel(groupBoxSettings);
        labelFlowControl->setObjectName(QStringLiteral("labelFlowControl"));
        sizePolicy.setHeightForWidth(labelFlowControl->sizePolicy().hasHeightForWidth());
        labelFlowControl->setSizePolicy(sizePolicy);

        gridLayout->addWidget(labelFlowControl, 5, 0, 1, 1);

        comboBoxFlowControl = new QComboBox(groupBoxSettings);
        comboBoxFlowControl->setObjectName(QStringLiteral("comboBoxFlowControl"));

        gridLayout->addWidget(comboBoxFlowControl, 5, 1, 1, 1);


        verticalLayout->addWidget(groupBoxSettings);

        groupBoxOptions = new QGroupBox(centralwidget);
        groupBoxOptions->setObjectName(QStringLiteral("groupBoxOptions"));
        groupBoxOptions->setEnabled(true);
        gridLayout_2 = new QGridLayout(groupBoxOptions);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(5);
        gridLayout_2->setVerticalSpacing(4);
        gridLayout_2->setContentsMargins(-1, 4, -1, 4);
        labelCodec = new QLabel(groupBoxOptions);
        labelCodec->setObjectName(QStringLiteral("labelCodec"));

        gridLayout_2->addWidget(labelCodec, 0, 0, 1, 1);

        comboBoxCodecs = new QComboBox(groupBoxOptions);
        comboBoxCodecs->setObjectName(QStringLiteral("comboBoxCodecs"));

        gridLayout_2->addWidget(comboBoxCodecs, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 1, 1, 1);


        verticalLayout->addWidget(groupBoxOptions);


        horizontalLayout->addLayout(verticalLayout);

        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Raised);
        vboxLayout = new QVBoxLayout(frame_2);
        vboxLayout->setSpacing(4);
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        vboxLayout->setContentsMargins(0, 9, 0, 0);
        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        pushButtonOpen = new QPushButton(frame_2);
        pushButtonOpen->setObjectName(QStringLiteral("pushButtonOpen"));

        hboxLayout->addWidget(pushButtonOpen);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        pushButtonClose = new QPushButton(frame_2);
        pushButtonClose->setObjectName(QStringLiteral("pushButtonClose"));
        pushButtonClose->setEnabled(false);

        hboxLayout->addWidget(pushButtonClose);


        vboxLayout->addLayout(hboxLayout);

        textEditReceive = new QTextEdit(frame_2);
        textEditReceive->setObjectName(QStringLiteral("textEditReceive"));
        textEditReceive->setReadOnly(true);

        vboxLayout->addWidget(textEditReceive);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName(QStringLiteral("hboxLayout1"));
        lineEditSend = new QLineEdit(frame_2);
        lineEditSend->setObjectName(QStringLiteral("lineEditSend"));

        hboxLayout1->addWidget(lineEditSend);

        checkBoxCR = new QCheckBox(frame_2);
        checkBoxCR->setObjectName(QStringLiteral("checkBoxCR"));

        hboxLayout1->addWidget(checkBoxCR);

        checkBoxLF = new QCheckBox(frame_2);
        checkBoxLF->setObjectName(QStringLiteral("checkBoxLF"));

        hboxLayout1->addWidget(checkBoxLF);


        vboxLayout->addLayout(hboxLayout1);

        pushButtonSend = new QPushButton(frame_2);
        pushButtonSend->setObjectName(QStringLiteral("pushButtonSend"));
        pushButtonSend->setEnabled(false);

        vboxLayout->addWidget(pushButtonSend);

        textEditReceive->raise();
        pushButtonSend->raise();

        horizontalLayout->addWidget(frame_2);

        QSerialPortTerminal->setCentralWidget(centralwidget);

        retranslateUi(QSerialPortTerminal);

        QMetaObject::connectSlotsByName(QSerialPortTerminal);
    } // setupUi

    void retranslateUi(QMainWindow *QSerialPortTerminal)
    {
        QSerialPortTerminal->setWindowTitle(QApplication::translate("QSerialPortTerminal", "QSerialPortTerminal", 0));
        groupBoxSettings->setTitle(QApplication::translate("QSerialPortTerminal", "\350\256\276\347\275\256", 0));
        labelPort->setText(QApplication::translate("QSerialPortTerminal", "\347\253\257\345\217\243 :", 0));
        labelBaudRate->setText(QApplication::translate("QSerialPortTerminal", "\346\263\242\347\211\271\347\216\207 :", 0));
        labelData->setText(QApplication::translate("QSerialPortTerminal", "\346\225\260\346\215\256\344\275\215 :", 0));
        labelParity->setText(QApplication::translate("QSerialPortTerminal", "\346\240\241\351\252\214\344\275\215 :", 0));
        labelStop->setText(QApplication::translate("QSerialPortTerminal", "\345\201\234\346\255\242\344\275\215 :", 0));
        labelFlowControl->setText(QApplication::translate("QSerialPortTerminal", "\346\265\201\346\216\247\345\210\266 :", 0));
        groupBoxOptions->setTitle(QApplication::translate("QSerialPortTerminal", "\351\200\211\351\241\271", 0));
        labelCodec->setText(QApplication::translate("QSerialPortTerminal", "\347\274\226\347\240\201 :", 0));
        pushButtonOpen->setText(QApplication::translate("QSerialPortTerminal", "\346\211\223\345\274\200\347\253\257\345\217\243", 0));
        pushButtonClose->setText(QApplication::translate("QSerialPortTerminal", "\345\205\263\351\227\255\347\253\257\345\217\243", 0));
        checkBoxCR->setText(QApplication::translate("QSerialPortTerminal", "CR", 0));
        checkBoxLF->setText(QApplication::translate("QSerialPortTerminal", "LF", 0));
        pushButtonSend->setText(QApplication::translate("QSerialPortTerminal", "\345\217\221\351\200\201", 0));
    } // retranslateUi

};

namespace Ui {
    class QSerialPortTerminal: public Ui_QSerialPortTerminal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QSERIALPORTTERMINAL_H
