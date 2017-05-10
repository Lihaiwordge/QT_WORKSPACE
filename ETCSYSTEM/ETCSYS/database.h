#ifndef DATABASE
#define DATABASE

#include <QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include "QDebug"

static bool createConnection()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("test.db");


    if( !db.open() ) {
        QMessageBox::critical(0,"Cannot open database",
                              "Unable to establish a database connection."
                              ,QMessageBox::Cancel);
        return false;
    }else{
        qDebug() << "DataBase init ok!!";
    }
   // QSqlQuery query;
    return true;


}



#endif // DATABASE

