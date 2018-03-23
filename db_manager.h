#ifndef DB_MANAGER_H
#define DB_MANAGER_H
#include<QSqlDatabase>
#include<QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QFile>
#include<QTableView>
#include<QDate>
#include<QQueue>
#include<QStandardItemModel>
#include<QTreeView>
#include "cpersonnel.h"
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
    bool deletePersonnel(QTreeView *tableView, QStandardItemModel* myModel);
    CClient getClientFromdba(QTableView *tableView,QSqlQueryModel* myModel);
    CPersonnel getPersonnelFromdba(QTreeView *tableView);
    bool modifyClient(CClient myclient);
    bool modifPersonnel(CPersonnel myPersonnel);
    bool loadClient(QSqlQueryModel*myModel);
    bool loadPersonnel( QStandardItemModel * model);
    bool researchClient(QSqlQueryModel* myModel,QString Firstname,QString Lastname,
                                        QString id,QDate date1, QDate date2);
    void connection();
    void deconnection();
    bool addClientTodba(CClient client);
    bool addPersonnelTodba(CPersonnel personnel);
    QSqlDatabase getDb();
};


#endif // DB_MANAGER_H
