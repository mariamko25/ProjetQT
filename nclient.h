#ifndef NCLIENT_H
#define NCLIENT_H

#include <QDialog>
#include<cclient.h>

namespace Ui {
class NClient;
}

class NClient : public QDialog
{
    Q_OBJECT

public:
    explicit NClient(QWidget *parent = 0);
    QString Created;
    ~NClient();
    void addClient(QString Fname, QString name,QString addr,QString city, QString cp,QString number );


private slots:

    void on_Ok_clicked();

    void on_Cancel_clicked();

private:
    Ui::NClient *ui;


};

#endif // NCLIENT_H
