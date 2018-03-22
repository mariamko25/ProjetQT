#include <mainwindow.h>
#include <ui_mainwindow.h>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->showMessage("Connected");
    createActions();
    createMenus();

    //on initialise les modeles avec la fenetre pour parent
    myModel=new QSqlQueryModel(this);
    ModelPlanning=new QSqlQueryModel(this);
    modelTreePersonnel= new QStandardItemModel(this);

    //on relie les modèles aux  tableview/treeview
    ui->tableView->setModel(myModel);
     ui->treeView->setModel(modelTreePersonnel);
     ui->TABV_Planning->setModel(ModelPlanning);



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
    db.researchClient(myModel,ui->LE_Firstname->text(),ui->LE_Lastname->text(),
                      ui->LE_ID->text(),ui->dateEdit->date(),ui->dateEdit_2->date());
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

   NClient *interfaceClient=new NClient(this); ;
   DB_manager db;
   db.connection();
  // db.modifyClient(ui->tableView,myModel, interfaceClient);
   interfaceClient->exec();
   ui->statusbar->showMessage(interfaceClient->Created);
  db.deconnection();


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

void MainWindow::on_pushButton_3_clicked()
{
    nPersonnel *interfPersonnel=new nPersonnel(this); ;
    DB_manager db;
    db.connection();
    db.modifPersonnel(ui->treeView,interfPersonnel);
    interfPersonnel->exec();
    ui->statusbar->showMessage(interfPersonnel->Created);
   db.deconnection();


}

void MainWindow::on_btnPlanning_clicked()
{
    //on prepare le chemin pour enregistrer le fichier
    QString fileName=QFileDialog::getSaveFileName(
                    this, QDir::currentPath(),"C://", "Text files (*.txt)");
        QFile file(fileName);
           if(!file.open(QFile::WriteOnly | QFile::Text))
           {
               QMessageBox box;
               box.setText("erreur d'ouverture du fichier");
               box.exec();
           }
    QTextStream  out(&file);
     DB_manager db;
    db.connection();
    db.planning(ModelPlanning, ui->DE_PlanningDate,&out);
    db.deconnection();
    file.flush();
    file.close();

}
