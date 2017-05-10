/********************************************************************************************************
* PROGRAM      : QSerialPortTerminal
* DATE - TIME  : mardi 04 mars 2008 - 11h19
* AUTHOR       : VIANNEY-LIAUD Philippe ( philippe.vianney.liaud@gmail.com )
* FILENAME     : main.cpp
* LICENSE      : GPL
* COMMENTARY   :
********************************************************************************************************/
#include <QApplication>
#include "QSerialPortTerminal.h"
#include <QtCore/QTextCodec>

int main( int argc, char ** argv )
{
    QApplication app( argc, argv );
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf-8"));
    QFont font("wenquanyi", 12); 
    app.setFont(font);
    QSerialPortTerminal window;
    window.show();

    return app.exec();
}
