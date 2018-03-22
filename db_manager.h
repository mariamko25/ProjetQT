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
#include<nclient.h>
#include<QStandardItemModel>
#include<QTreeView>
#include<cpersonnel.h>
#include<npersonnel.h>
#include<nclient.h>

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
    bool modifyClient(QTableView *tableView,QSqlQueryModel* myModel, NClient *interfaceClient);
    bool modifPersonnel(QTreeView* treeview, nPersonnel* perso);
    bool loadClient(QSqlQueryModel*myModel);
    bool loadPersonnel( QStandardItemModel * model);
    bool researchClient(QSqlQueryModel* myModel,QString Firstname,QString Lastname,
                                        QString id,QDate date1, QDate date2);
    void connection();
    void deconnection();
};


#endif // DB_MANAGER_H
