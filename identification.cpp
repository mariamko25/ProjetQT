#include "identification.h"
#include "ui_identification.h"

Identification::Identification(QWidget *parent) :QDialog(parent),ui(new Ui::Identification)
{
    ui->setupUi(this);
}

Identification::~Identification()
{
    delete ui;
}

void Identification::on_Connection_clicked()
{

    if(verification_login_password("admin","root"))
    {
        accept();

    }
    else
    {
        ui->login->clear();
        ui->password->clear();
        QMessageBox box;
        box.setText("Login or Password are incorrect");
        box.exec();
    }


}

void Identification::on_cancel_clicked()
{
    this->close();
}

bool Identification::verification_login_password(QString log,QString pass)
{
    QString login= ui->login->text();
    QString password=ui->password->text();
    if(login.compare(log)==0 && password.compare(pass)==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


