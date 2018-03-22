#include "nclient.h"
#include "ui_nclient.h"

#include <iostream>
using namespace std;

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

/*void NClient::addClient(QString Fname, QString name, QString addr, QString city, QString cp, QString number)
{
    ui->PostalCode->setText(cp);
    ui->LastName->setText(name);
    ui->City->setText(city);
    ui->Adress->setText(addr);
    ui->FirstName->setText(Fname);
    ui->PhoneNumber->setText(number);
}*/


void NClient::on_Ok_clicked()
{
    accept();
    Created.clear();
    Created="Client created";
    CClient myNewClient(ui->LastName->text(),ui->FirstName->text(),ui->Adress->text(),ui->City->text(),ui->PostalCode->text().toInt(),ui->PhoneNumber->text().toInt(),ui->AppointmentDate->date(),ui->Priority->currentIndex(),ui->AppointmentDuration->time().hour(),ress,ui->AdditionalInformation->toPlainText());
    db.addClientTodba(myNewClient);
}

void NClient::on_Cancel_clicked()
{
    accept();
    Created.clear();
}


void NClient::on_Ressource_clicked()
{
    c_ressource ressource;
    ressource.exec();
    ress=ressource.ress;
    for(QVector<int>::iterator i =ressource.ress.begin(); i != ressource.ress.end(); i++)
    {
        cout << " [" << *i << "]";
    }
}

