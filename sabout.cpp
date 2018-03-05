#include "sabout.h"
#include "ui_sabout.h"

sAbout::sAbout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sAbout)
{
    ui->setupUi(this);
    QPixmap pict(":logo.jpg");
    ui->logo->setPixmap(pict);
}

sAbout::~sAbout()
{
    delete ui;
}
