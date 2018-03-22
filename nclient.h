#ifndef NCLIENT_H
#define NCLIENT_H

#include <QDialog>
#include "c_ressource.h"
#include "db_manager.h"
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

private slots:

    void on_Ok_clicked();

    void on_Cancel_clicked();

    void on_Ressource_clicked();

private:
    Ui::NClient *ui;
    DB_manager db;


};

#endif // NCLIENT_H
