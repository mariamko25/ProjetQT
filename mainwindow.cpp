#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QVariantList>
#include <QDebug>
#include<db_manager.h>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->showMessage("Connected");
    createActions();
    createMenus();
    myModel=new QSqlQueryModel(this);
    ui->tableView->setModel(myModel);

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


    DB_manager db;
    db.connection();
    db.loadClient(myModel);
   db.deconnection();

}

void MainWindow::on_Btn_ResearchBy_clicked()
{
    DB_manager db;
    db.connection();
    db.researchClient(myModel,ui->LE_Firstname->text(),ui->LE_Lastname->text(),ui->LE_ID->text(),ui->dateEdit->date(),ui->dateEdit_2->date());
   db.deconnection();
    //QSqlQueryModel* myModel,QString Firstname,QString Lastname, QString id,QDate date1, QDate date2
    /*Connection con= Connection();
      con.open();


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
            ui->dateEdit->setDisplayFormat("YYYY-MM-DD");
            ui->dateEdit_2->setDisplayFormat("YYYY-MM-DD");
            qry->addBindValue(ui->dateEdit->date());
            qry->addBindValue(ui->dateEdit_2->date());
      }
      else if(combovalue=="name")
      {
          qry->prepare("select* from TClient where upper(Nom)=upper(?) AND UPPER(Prenom)=UPPER(?) ");
          qry->addBindValue(ui->LE_Firstname->text());
          qry->addBindValue(ui->LE_Lastname->text());

      }


      qry->exec();
      //model->setQuery(*qry);
      con.close();*/
}

void MainWindow::on_pushButton_2_clicked()
{
    DB_manager db;
    db.connection();
    db.deleteClient(ui->tableView, myModel);
   db.deconnection();
}
