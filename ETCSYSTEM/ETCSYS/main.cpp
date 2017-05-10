#include "mainwindow.h"
#include <QApplication>
#include "carinfo.h"
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include "database.h"
#include "QVariant"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    if( !createConnection() )
        return 1;

    QSqlQuery qm;
    qm.exec("select*from mo");
    qDebug() <<"reading database....";
    while(qm.next()){
        qDebug() << qm.value(0).toString() << "|" << qm.value(1).toFloat();
    }
    MainWindow w;
    w.show();

    return a.exec();
}


