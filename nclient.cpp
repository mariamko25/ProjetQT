#include "nclient.h"
#include "ui_nclient.h"

NClient::NClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NClient)
{
    ui->setupUi(this);
    setWindowTitle("Create a new client");
}

NClient::~NClient()
{
    delete ui;
}

void NClient::addClient(QString Fname, QString name, QString addr, QString city, QString cp, QString number)
{
    ui->PostalCode->setText(cp);
    ui->LastName->setText(name);
    ui->City->setText(city);
    ui->Adress->setText(addr);
    ui->FirstName->setText(Fname);
    ui->PhoneNumber->setText(number);
}


void NClient::on_Ok_clicked()
{
    accept();
    Created.clear();
    Created="Client created";
}

void NClient::on_Cancel_clicked()
{
    accept();
    Created.clear();
}


