#include "nclient.h"
#include "ui_nclient.h"
#include "cclient.h"
#include <vector>
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
