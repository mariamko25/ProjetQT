#ifndef CONNECTION_H
#define CONNECTION_H
#include"QSqlDatabase"
#include "QFile"
#include <QSqlError>
#include"QSqlQuery"
#include <QDebug>

class Connection
{
private:
    QSqlDatabase db;
public:
    Connection();
    open();
    close();
    QSqlDatabase getDb() const;
    void setDb(const QSqlDatabase &value);
};

#endif // CONNECTION_H
