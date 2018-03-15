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

void NClient::on_Ressource_clicked()
{
    c_ressource ressource;
    ressource.exec();
}
