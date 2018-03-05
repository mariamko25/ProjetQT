#ifndef NCLIENT_H
#define NCLIENT_H

#include <QDialog>

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

private slots:

    void on_Ok_clicked();

    void on_Cancel_clicked();

private:
    Ui::NClient *ui;


};

#endif // NCLIENT_H
