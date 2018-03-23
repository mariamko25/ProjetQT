#include "nclient.h"
#include "ui_nclient.h"

#include <iostream>
using namespace std;

NClient::NClient(QWidget *parent) :QDialog(parent),ui(new Ui::NClient)
{
    ui->setupUi(this);
    setWindowTitle("Client");

}

NClient::~NClient()
{
    delete ui;
}




void NClient::on_Ok_clicked()
{
    if(modify==true)
    {

        myClient.setPrenom(ui->FirstName->text());
        myClient.setNom(ui->LastName->text());
        myClient.setAdresse(ui->Adress->text());
        myClient.setVille(ui->City->text());
        myClient.setCodePostal(ui->PostalCode->text().toInt());
        myClient.setCommentaire(ui->AdditionalInformation->toPlainText());
        myClient.setTelephone(ui->PhoneNumber->text().toInt());
        myClient.setDate(ui->AppointmentDate->date());
        myClient.setDureeConsultation(ui->AppointmentDuration->time().hour());
        myClient.setPriorite(ui->Priority->currentIndex());
        db.modifyClient(myClient);
        accept();
        modify=false;

    }
    else
    {
        accept();
        Created.clear();
        Created="Client created";
        CClient myNewClient(ui->LastName->text(),ui->FirstName->text(),ui->Adress->text(),ui->City->text(),ui->PostalCode->text().toInt(),ui->PhoneNumber->text().toInt(),ui->AppointmentDate->date(),ui->Priority->currentIndex(),ui->AppointmentDuration->time().hour(),ress,ui->AdditionalInformation->toPlainText());
        db.addClientTodba(myNewClient);
    }

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

void NClient::setModify(bool mod)
{
    modify=mod;
}

bool NClient::getModify()
{
    return modify;
}

void NClient::setMyClient(CClient client)
{
    myClient.setIndice(client.getIndice());
    myClient.setNom(client.getNom());
    myClient.setPrenom(client.getPrenom());
    myClient.setAdresse(client.getAdresse());
    myClient.setVille(client.getVille());
    myClient.setCodePostal(client.getCodePostal());
    myClient.setTelephone(client.getTelephone());
    myClient.setDate(client.getDate());
    myClient.setPriorite(client.getPriorite());
    myClient.setDureeConsultation(client.getDureeConsultation());
    myClient.setCommentaire(client.getCommentaire());
    myClient.setListRessource(client.getListRessource());
}

CClient NClient::getMyClient()
{
    return myClient;
}
