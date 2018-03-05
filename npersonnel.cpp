#include "npersonnel.h"
#include "ui_npersonnel.h"

nPersonnel::nPersonnel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nPersonnel)
{
    ui->setupUi(this);
    setWindowTitle("Create a new personnel");

}

nPersonnel::~nPersonnel()
{
    delete ui;
}

void nPersonnel::on_Ok_clicked()
{
    accept();
    Created.clear();
    Created="Personnel created";
}

void nPersonnel::on_Cancel_clicked()
{
    accept();
    Created.clear();
}
