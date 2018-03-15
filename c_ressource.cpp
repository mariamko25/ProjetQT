#include "c_ressource.h"

c_ressource::c_ressource(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::c_ressource)
{
    ui->setupUi(this);
    setWindowTitle("Select a ressource for your client");
}

c_ressource::~c_ressource()
{
    delete ui;
}



void c_ressource::on_Cancel_clicked()
{
    accept();
}

void c_ressource::on_Ok_clicked()
{
    accept();
}



void c_ressource::on_Load_clicked()
{
    Connection con= Connection();
    con.open();

    QSqlQueryModel * modal= new QSqlQueryModel();

    QSqlQuery *qry= new QSqlQuery(con.getDb());

    qry->prepare("select* from TRessource");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

    con.close();
}
