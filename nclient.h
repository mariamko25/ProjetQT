#ifndef NCLIENT_H
#define NCLIENT_H

#include <QDialog>
#include "c_ressource.h"
#include<cclient.h>
#include"nclient.h"
#include<db_manager.h>
namespace Ui {
class NClient;
}

class NClient : public QDialog
{
    Q_OBJECT

public:
    explicit NClient(QWidget *parent = 0);
    QString Created;
    QVector<int> ress;
    ~NClient();
    void addClient(QString Fname, QString name,QString addr,QString city, QString cp,QString number );


private slots:

    void on_Ok_clicked();

    void on_Cancel_clicked();

private:
    Ui::NClient *ui;
    DB_manager db;


};

#endif // NCLIENT_H
