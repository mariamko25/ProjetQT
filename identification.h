#ifndef IDENTIFICATION_H
#define IDENTIFICATION_H

#include <QDialog>
#include <QMessageBox>
namespace Ui {
class Identification;
}

class Identification : public QDialog
{
    Q_OBJECT

public:
    explicit Identification(QWidget *parent = 0);
    ~Identification();

private slots:
    void on_Connection_clicked();

    void on_cancel_clicked();

    bool verification_login_password(QString log,QString pass);


private:
    Ui::Identification *ui;
    QString login;
    QString password;
};

#endif // IDENTIFICATION_H
