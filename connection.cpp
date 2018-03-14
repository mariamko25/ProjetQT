#include "connection.h"

QSqlDatabase Connection::getDb() const
{
    return db;
}

void Connection::setDb(const QSqlDatabase &value)
{
    db = value;
}

Connection::Connection()
{
     db = QSqlDatabase::addDatabase("QSQLITE");
    if(db.isValid())
    {
        db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("password");

    if(QFile::exists("base_tmp.sqli"))
        QFile::remove("base_tmp.sqli");

    db.setDatabaseName("base_tmp.sqli");}
}

Connection::open()
{
    if(db.isValid())
    {
        db.open();
    }

}

Connection::close(){

    if(db.isValid())
    {db.close();
    db.removeDatabase("QSQLITE");
    }
}

