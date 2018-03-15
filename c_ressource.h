#ifndef C_RESSOURCE_H
#define C_RESSOURCE_H

#include <QDialog>
#include "ui_c_ressource.h"
#include <QSqlQuery>
#include "QSqlQueryModel"
#include "connection.h"
namespace Ui {
class c_ressource;
}

class c_ressource : public QDialog
{
    Q_OBJECT

public:
    explicit c_ressource(QWidget *parent = 0);
    ~c_ressource();

private slots:

    void on_Cancel_clicked();

    void on_Ok_clicked();


    void on_Load_clicked();

private:
    Ui::c_ressource *ui;
};

#endif // C_RESSOURCE_H
