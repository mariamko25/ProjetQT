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
        db.setDatabaseName("base_tmp.sqli");}
}

void Connection::open()
{
    if(db.isValid())
    {
        db.open();
    }

}

void Connection::close(){

    if(db.isValid())
    {
        db.close();
        db.removeDatabase("QSQLITE");
    }
}

