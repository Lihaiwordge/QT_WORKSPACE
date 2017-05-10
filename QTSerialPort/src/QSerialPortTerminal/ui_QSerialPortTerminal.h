/********************************************************************************
** Form generated from reading ui file 'QSerialPortTerminal.ui'
**
** Created: Mon Dec 22 20:23:46 2008
**      by: Qt User Interface Compiler version 4.3.5
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_QSERIALPORTTERMINAL_H
#define UI_QSERIALPORTTERMINAL_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QCheckBox>
#include < QComboBox>
#include < QFrame>
#include < QGridLayout>
#include < QGroupBox>
#include < QHBoxLayout>
#include < QLabel>
#include < QLineEdit>
#include < QMainWindow>
#include < QPushButton>
#include < QSpacerItem>
#include < QTextEdit>
#include < QVBoxLayout>
#include < QWidget>

class Ui_QSerialPortTerminal
{
public:
    QWidget *centralwidget;
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout;
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
    QGridLayout *gridLayout1;
    QLabel *labelCodec;
    QComboBox *comboBoxCodecs;
    QSpacerItem *spacerItem;
    QFrame *frame_2;
    QVBoxLayout *vboxLayout1;
    QHBoxLayout *hboxLayout1;
    QPushButton *pushButtonOpen;
    QSpacerItem *spacerItem1;
    QPushButton *pushButtonClose;
    QTextEdit *textEditReceive;
    QHBoxLayout *hboxLayout2;
    QLineEdit *lineEditSend;
    QCheckBox *checkBoxCR;
    QCheckBox *checkBoxLF;
    QPushButton *pushButtonSend;

    void setupUi(QMainWindow *QSerialPortTerminal)
    {
    if (QSerialPortTerminal->objectName().isEmpty())
        QSerialPortTerminal->setObjectName(QString::fromUtf8("QSerialPortTerminal"));
    QSerialPortTerminal->resize(480, 289);
    QFont font;
    font.setFamily(QString::fromUtf8("Wenquanyi Bitmap Song"));
    font.setPointSize(12);
    QSerialPortTerminal->setFont(font);
    centralwidget = new QWidget(QSerialPortTerminal);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    hboxLayout = new QHBoxLayout(centralwidget);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    vboxLayout = new QVBoxLayout();
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    groupBoxSettings = new QGroupBox(centralwidget);
    groupBoxSettings->setObjectName(QString::fromUtf8("groupBoxSettings"));
    gridLayout = new QGridLayout(groupBoxSettings);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    labelPort = new QLabel(groupBoxSettings);
    labelPort->setObjectName(QString::fromUtf8("labelPort"));
    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(labelPort->sizePolicy().hasHeightForWidth());
    labelPort->setSizePolicy(sizePolicy);

    gridLayout->addWidget(labelPort, 0, 0, 1, 1);

    comboBoxPortName = new QComboBox(groupBoxSettings);
    comboBoxPortName->setObjectName(QString::fromUtf8("comboBoxPortName"));

    gridLayout->addWidget(comboBoxPortName, 0, 1, 1, 1);

    labelBaudRate = new QLabel(groupBoxSettings);
    labelBaudRate->setObjectName(QString::fromUtf8("labelBaudRate"));
    sizePolicy.setHeightForWidth(labelBaudRate->sizePolicy().hasHeightForWidth());
    labelBaudRate->setSizePolicy(sizePolicy);

    gridLayout->addWidget(labelBaudRate, 1, 0, 1, 1);

    comboBoxBaudRate = new QComboBox(groupBoxSettings);
    comboBoxBaudRate->setObjectName(QString::fromUtf8("comboBoxBaudRate"));

    gridLayout->addWidget(comboBoxBaudRate, 1, 1, 1, 1);

    labelData = new QLabel(groupBoxSettings);
    labelData->setObjectName(QString::fromUtf8("labelData"));
    sizePolicy.setHeightForWidth(labelData->sizePolicy().hasHeightForWidth());
    labelData->setSizePolicy(sizePolicy);

    gridLayout->addWidget(labelData, 2, 0, 1, 1);

    comboBoxDataBits = new QComboBox(groupBoxSettings);
    comboBoxDataBits->setObjectName(QString::fromUtf8("comboBoxDataBits"));

    gridLayout->addWidget(comboBoxDataBits, 2, 1, 1, 1);

    labelParity = new QLabel(groupBoxSettings);
    labelParity->setObjectName(QString::fromUtf8("labelParity"));
    sizePolicy.setHeightForWidth(labelParity->sizePolicy().hasHeightForWidth());
    labelParity->setSizePolicy(sizePolicy);

    gridLayout->addWidget(labelParity, 3, 0, 1, 1);

    comboBoxParity = new QComboBox(groupBoxSettings);
    comboBoxParity->setObjectName(QString::fromUtf8("comboBoxParity"));

    gridLayout->addWidget(comboBoxParity, 3, 1, 1, 1);

    labelStop = new QLabel(groupBoxSettings);
    labelStop->setObjectName(QString::fromUtf8("labelStop"));
    sizePolicy.setHeightForWidth(labelStop->sizePolicy().hasHeightForWidth());
    labelStop->setSizePolicy(sizePolicy);

    gridLayout->addWidget(labelStop, 4, 0, 1, 1);

    comboBoxStopBits = new QComboBox(groupBoxSettings);
    comboBoxStopBits->setObjectName(QString::fromUtf8("comboBoxStopBits"));

    gridLayout->addWidget(comboBoxStopBits, 4, 1, 1, 1);

    labelFlowControl = new QLabel(groupBoxSettings);
    labelFlowControl->setObjectName(QString::fromUtf8("labelFlowControl"));
    sizePolicy.setHeightForWidth(labelFlowControl->sizePolicy().hasHeightForWidth());
    labelFlowControl->setSizePolicy(sizePolicy);

    gridLayout->addWidget(labelFlowControl, 5, 0, 1, 1);

    comboBoxFlowControl = new QComboBox(groupBoxSettings);
    comboBoxFlowControl->setObjectName(QString::fromUtf8("comboBoxFlowControl"));

    gridLayout->addWidget(comboBoxFlowControl, 5, 1, 1, 1);


    vboxLayout->addWidget(groupBoxSettings);

    groupBoxOptions = new QGroupBox(centralwidget);
    groupBoxOptions->setObjectName(QString::fromUtf8("groupBoxOptions"));
    groupBoxOptions->setEnabled(true);
    gridLayout1 = new QGridLayout(groupBoxOptions);
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    gridLayout1->setHorizontalSpacing(5);
    gridLayout1->setVerticalSpacing(4);
    gridLayout1->setContentsMargins(-1, 4, -1, 4);
    labelCodec = new QLabel(groupBoxOptions);
    labelCodec->setObjectName(QString::fromUtf8("labelCodec"));

    gridLayout1->addWidget(labelCodec, 0, 0, 1, 1);

    comboBoxCodecs = new QComboBox(groupBoxOptions);
    comboBoxCodecs->setObjectName(QString::fromUtf8("comboBoxCodecs"));

    gridLayout1->addWidget(comboBoxCodecs, 0, 1, 1, 1);

    spacerItem = new QSpacerItem(20, 17, QSizePolicy::Minimum, QSizePolicy::Expanding);

    gridLayout1->addItem(spacerItem, 1, 1, 1, 1);


    vboxLayout->addWidget(groupBoxOptions);


    hboxLayout->addLayout(vboxLayout);

    frame_2 = new QFrame(centralwidget);
    frame_2->setObjectName(QString::fromUtf8("frame_2"));
    frame_2->setFrameShape(QFrame::NoFrame);
    frame_2->setFrameShadow(QFrame::Raised);
    vboxLayout1 = new QVBoxLayout(frame_2);
    vboxLayout1->setSpacing(4);
    vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
    vboxLayout1->setContentsMargins(0, 9, 0, 0);
    hboxLayout1 = new QHBoxLayout();
    hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
    pushButtonOpen = new QPushButton(frame_2);
    pushButtonOpen->setObjectName(QString::fromUtf8("pushButtonOpen"));

    hboxLayout1->addWidget(pushButtonOpen);

    spacerItem1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout1->addItem(spacerItem1);

    pushButtonClose = new QPushButton(frame_2);
    pushButtonClose->setObjectName(QString::fromUtf8("pushButtonClose"));
    pushButtonClose->setEnabled(false);

    hboxLayout1->addWidget(pushButtonClose);


    vboxLayout1->addLayout(hboxLayout1);

    textEditReceive = new QTextEdit(frame_2);
    textEditReceive->setObjectName(QString::fromUtf8("textEditReceive"));
    textEditReceive->setReadOnly(true);

    vboxLayout1->addWidget(textEditReceive);

    hboxLayout2 = new QHBoxLayout();
    hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
    lineEditSend = new QLineEdit(frame_2);
    lineEditSend->setObjectName(QString::fromUtf8("lineEditSend"));

    hboxLayout2->addWidget(lineEditSend);

    checkBoxCR = new QCheckBox(frame_2);
    checkBoxCR->setObjectName(QString::fromUtf8("checkBoxCR"));

    hboxLayout2->addWidget(checkBoxCR);

    checkBoxLF = new QCheckBox(frame_2);
    checkBoxLF->setObjectName(QString::fromUtf8("checkBoxLF"));

    hboxLayout2->addWidget(checkBoxLF);


    vboxLayout1->addLayout(hboxLayout2);

    pushButtonSend = new QPushButton(frame_2);
    pushButtonSend->setObjectName(QString::fromUtf8("pushButtonSend"));
    pushButtonSend->setEnabled(false);

    vboxLayout1->addWidget(pushButtonSend);


    hboxLayout->addWidget(frame_2);

    QSerialPortTerminal->setCentralWidget(centralwidget);

    retranslateUi(QSerialPortTerminal);

    QMetaObject::connectSlotsByName(QSerialPortTerminal);
    } // setupUi

    void retranslateUi(QMainWindow *QSerialPortTerminal)
    {
    QSerialPortTerminal->setWindowTitle(QApplication::translate("QSerialPortTerminal", "QSerialPortTerminal", 0, QApplication::UnicodeUTF8));
    groupBoxSettings->setTitle(QApplication::translate("QSerialPortTerminal", "\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
    labelPort->setText(QApplication::translate("QSerialPortTerminal", "\347\253\257\345\217\243 :", 0, QApplication::UnicodeUTF8));
    labelBaudRate->setText(QApplication::translate("QSerialPortTerminal", "\346\263\242\347\211\271\347\216\207 :", 0, QApplication::UnicodeUTF8));
    labelData->setText(QApplication::translate("QSerialPortTerminal", "\346\225\260\346\215\256\344\275\215 :", 0, QApplication::UnicodeUTF8));
    labelParity->setText(QApplication::translate("QSerialPortTerminal", "\346\240\241\351\252\214\344\275\215 :", 0, QApplication::UnicodeUTF8));
    labelStop->setText(QApplication::translate("QSerialPortTerminal", "\345\201\234\346\255\242\344\275\215 :", 0, QApplication::UnicodeUTF8));
    labelFlowControl->setText(QApplication::translate("QSerialPortTerminal", "\346\265\201\346\216\247\345\210\266 :", 0, QApplication::UnicodeUTF8));
    groupBoxOptions->setTitle(QApplication::translate("QSerialPortTerminal", "\351\200\211\351\241\271", 0, QApplication::UnicodeUTF8));
    labelCodec->setText(QApplication::translate("QSerialPortTerminal", "\347\274\226\347\240\201 :", 0, QApplication::UnicodeUTF8));
    pushButtonOpen->setText(QApplication::translate("QSerialPortTerminal", "\346\211\223\345\274\200\347\253\257\345\217\243", 0, QApplication::UnicodeUTF8));
    pushButtonClose->setText(QApplication::translate("QSerialPortTerminal", "\345\205\263\351\227\255\347\253\257\345\217\243", 0, QApplication::UnicodeUTF8));
    checkBoxCR->setText(QApplication::translate("QSerialPortTerminal", "CR", 0, QApplication::UnicodeUTF8));
    checkBoxLF->setText(QApplication::translate("QSerialPortTerminal", "LF", 0, QApplication::UnicodeUTF8));
    pushButtonSend->setText(QApplication::translate("QSerialPortTerminal", "\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(QSerialPortTerminal);
    } // retranslateUi

};

namespace Ui {
    class QSerialPortTerminal: public Ui_QSerialPortTerminal {};
} // namespace Ui

#endif // UI_QSERIALPORTTERMINAL_H
