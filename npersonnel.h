#ifndef NPERSONNEL_H
#define NPERSONNEL_H
#include"cpersonnel.h"
#include <QDialog>
#include "db_manager.h"

namespace Ui {
class nPersonnel;
}

class nPersonnel : public QDialog
{
    Q_OBJECT

public:
    explicit nPersonnel(QWidget *parent = 0);
    QString Created;
    ~nPersonnel();
    void addPersonnel(QString id, QString name, QString surname,QString Type);
    bool getModify();

    void setModify(bool modify);

    CPersonnel getPersonnel();

    void setPersonnel(CPersonnel personnel);
    void addPersonnel( QString name, QString surname,QString Type);

private slots:
    void on_Ok_clicked();

    void on_Cancel_clicked();

private:
    Ui::nPersonnel *ui;
    bool modify;
    CPersonnel myPersonnel;
    DB_manager db;
};

#endif // NPERSONNEL_H
