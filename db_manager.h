#ifndef DB_MANAGER_H
#define DB_MANAGER_H
#include<QSqlDatabase>
#include<QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QFile>
#include<QTableView>
#include "cclient.h"

class DB_manager
{
private:
    QSqlDatabase db;

//constructeur
    public:
    DB_manager();
//méthodes
    bool deleteClient(QTableView *tableView, QSqlQueryModel* myModel);
    bool loadClient(QSqlQueryModel*myModel);
    void connection();
    void deconnection();
    bool addClientTodba(CClient client);
};

#endif // DB_MANAGER_H
