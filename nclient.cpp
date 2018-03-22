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

void NClient::addClient(CClient customer)
{
    //ui->NClient.FirstName->insert(&customer.getPrenom());
    //ui->NClient.LastName->insert(&customer.getNom());
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


