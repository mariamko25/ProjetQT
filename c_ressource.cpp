#include "c_ressource.h"

int c_ressource::Id=7;

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
    Id++;


}



void c_ressource::on_Load_clicked()
{
    DB_manager dbmnger;
    dbmnger.connection();
    QSqlQueryModel * modal= new QSqlQueryModel();

    QSqlQuery *qry= new QSqlQuery(dbmnger.getDb());

    qry->prepare("select Id from TRessource");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

    dbmnger.deconnection();
}

void c_ressource::on_Add_clicked()
{
     QString s=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),ui->tableView->currentIndex().column())).toString();
     ress.append(s.toInt());
}
