#include "npersonnel.h"
#include "ui_npersonnel.h"

nPersonnel::nPersonnel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nPersonnel)
{
    ui->setupUi(this);
    setWindowTitle("Personnel");

}

nPersonnel::~nPersonnel()
{
    delete ui;
}


void nPersonnel::addPersonnel( QString name, QString surname, QString Type)
{
    ui->LE_Firstname->setText(name);
    ui->LE_Lastname->setText(surname);
    ui->TypePersonnecomboBox->setEditText(Type);
}


void nPersonnel::on_Ok_clicked()
{
    if(modify==true)
    {
        accept();
        myPersonnel.setFirstname(ui->LE_Firstname->text());
        myPersonnel.setLastname(ui->LE_Lastname->text());
        myPersonnel.setType(ui->TypePersonnecomboBox->currentIndex()+1);
        db.modifPersonnel(myPersonnel);
        modify=false;

    }
    else
    {
        accept();
        Created.clear();
        Created="Personnel created";
        CPersonnel myNewP(ui->LE_Lastname->text(),ui->LE_Firstname->text(),(ui->TypePersonnecomboBox->currentIndex()+1));
        db.addPersonnelTodba(myNewP);
    }

}

void nPersonnel::on_Cancel_clicked()
{
    accept();
    Created.clear();
}
void nPersonnel::setModify(bool mod)
{
    modify=mod;
}

bool nPersonnel::getModify()
{
    return modify;
}

void nPersonnel::setPersonnel(CPersonnel myP)
{
    myPersonnel.setId(myP.getId());
    myPersonnel.setFirstname(myP.getFirstname());
    myPersonnel.setLastname(myP.getLastname());
    myPersonnel.setType(myP.getType());
}

CPersonnel nPersonnel::getPersonnel()
{
    return myPersonnel;
}

