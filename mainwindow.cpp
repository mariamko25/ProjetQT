#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include "QSqlQueryModel"
#include <QVariantList>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->showMessage("Connected");
    createActions();
    createMenus();


}

MainWindow::~MainWindow()
{
    delete ui;
  
}

void MainWindow::QExit()
{
    close();

}

void MainWindow::CClient()
{
    NClient client;
    client.exec();
    ui->statusbar->showMessage(client.Created);

}
void MainWindow::CPersonnel()
{
    //ui->label->setText("Personnel");
    nPersonnel personnel;
    personnel.exec();
    ui->statusbar->showMessage(personnel.Created);
}

void MainWindow::slotAbout()
{
    sAbout about;
    about.exec();
}
void MainWindow::createMenus()
{
    File = ui->menubar->addMenu(tr("&File"));

    Add=File->addMenu(tr("&Add"));
    Add->addAction(Client);
    Add->addAction(Personnel);
    File->addAction(Quit);
    File->addAction(aAbout);
    Toolbar=ui->menubar->addMenu(tr("&Toolbar"));
    Toolbar->addAction(ClientTool);
    Toolbar->addAction(PersonnelTool);

}

void MainWindow::createActions()
{
    Client = new QAction(tr("&Client"), this);
    Client->setStatusTip(tr("Add a new Client"));

    connect(Client, &QAction::triggered, this, &MainWindow::CClient);

    Quit = new QAction(tr("&Exit"), this);
    Quit->setStatusTip(tr("Exit the application"));
    connect( Quit, &QAction::triggered, this, &MainWindow::QExit);

    Personnel = new QAction(tr("&Personnel"), this);
    Personnel->setStatusTip(tr("Add a new Personnel"));

    connect(Personnel, &QAction::triggered, this, &MainWindow::CPersonnel);

    aAbout = new QAction(tr("&About"), this);
    aAbout->setStatusTip(tr("Show information"));
    connect(aAbout, &QAction::triggered, this, &MainWindow::slotAbout);

    ClientTool = new QAction(tr("&Client"), this);
    ClientTool->setStatusTip(tr("Add a new Client"));
    QIcon clientIcon(":clientIcon.jpeg");
    ClientTool->setIcon(clientIcon);
    connect(ClientTool, &QAction::triggered, this, &MainWindow::CClient);

    PersonnelTool = new QAction(tr("&Personnel"), this);
    PersonnelTool->setStatusTip(tr("Add a new Personnel"));
    QIcon personnelIcon(":personnelIcon.jpeg");
    PersonnelTool->setIcon(personnelIcon);
    connect(PersonnelTool, &QAction::triggered, this, &MainWindow::CPersonnel);


}

void MainWindow::on_Btn_Load_clicked()
{
    Connection con= Connection();
    con.open();

    QSqlQueryModel * modal= new QSqlQueryModel();

    QSqlQuery *qry= new QSqlQuery(con.getDb());

    qry->prepare("select* from TClient");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

    con.close();

}

void MainWindow::on_Btn_ResearchBy_clicked()
{
    Connection con= Connection();
      con.open();

      QSqlQueryModel * modal= new QSqlQueryModel();
      QSqlQuery* qry= new QSqlQuery(con.getDb());

      QString combovalue=ui->CBox_ResearchBy->currentText();

      if(combovalue=="Firstname")
      {
          qry->prepare("select* from TClient where UPPER(Prenom)=UPPER(?)");
          qry->addBindValue(ui->LE_Firstname->text());
      }
      else if(combovalue=="Lastname")
      {
          qry->prepare("select* from TClient where upper(Nom)=upper(?)");
          qry->addBindValue(ui->LE_Lastname->text());
      }
      else if(combovalue=="ID")
      {
          qry->prepare("select* from TClient where Id=?");
          qry->addBindValue(ui->LE_ID->text());
      }
      else if(combovalue=="date")
      {
            qry->prepare("select* from TClient where DateRdv BETWEEN '?' AND '?' ");
            qry->addBindValue(ui->dateEdit->text());
            qry->addBindValue(ui->dateEdit_2->text());
      }
      else if(combovalue=="name")
      {
          qry->prepare("select* from TClient where upper(Nom)=upper(?) AND UPPER(Prenom)=UPPER(?) ");
          qry->addBindValue(ui->LE_Firstname->text());
          qry->addBindValue(ui->LE_Lastname->text());

      }


      qry->exec();

      modal->setQuery(*qry);
      ui->tableView->setModel(modal);

      con.close();


}

void MainWindow::on_pushButton_2_clicked()
{
    //int ligne = ui->tableView->currentIndex().row();
    //model->removeRows(ligne,1);
}
