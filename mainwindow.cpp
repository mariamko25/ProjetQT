#include <mainwindow.h>
#include <ui_mainwindow.h>
#include<QVariantList>
#include <QDebug>
#include<db_manager.h>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->showMessage("Connected");
    createActions();
    createMenus();

    //on initialise les modeles avec la fenetre pour parent
    myModel=new QSqlQueryModel(this);
    modelTreePersonnel= new QStandardItemModel(this);

    //on relie le modèle à la tableview
    ui->tableView->setModel(myModel);
    ui->treeView->setModel(modelTreePersonnel);


}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::QExit()
{
    close();

}

/**
 * @brief MainWindow::CClient création d'un nouveau client à partir de l'interface
 */
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

}

void MainWindow::on_pushButton_2_clicked()
{
    DB_manager db;
    db.connection();
    db.deleteClient(ui->tableView, myModel);
   db.deconnection();
}



void MainWindow::on_BtnModifyClient_clicked()
{
    DB_manager db;
    db.connection();
    db.modifyClient(ui->tableView, myModel);
    //on ouvre l interface de création d'un nouveau client avec la méthode cclient de mainwindows
    CClient();
    //cette méthode peut retouner un client pour actualiser la statut de la creation
    //ui->statusbar->showMessage(client.Created);
   db.deconnection();

}

void MainWindow::on_pushButton_clicked()
{
    //ui->treeView->ser
}

void MainWindow::on_BTN_LoadPersonnel_clicked()
{
    DB_manager db;
    db.connection();
    db.loadPersonnel(modelTreePersonnel);
   db.deconnection();
}

void MainWindow::on_pushButton_4_clicked()
{
    DB_manager db;
    db.connection();
    db.deletePersonnel(ui->treeView, modelTreePersonnel);
   db.deconnection();
}
