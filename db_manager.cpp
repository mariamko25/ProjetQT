#include "db_manager.h"


<<<<<<< HEAD

DB_manager::DB_manager()
{

}

/**
 * @brief DB_manager::deleteClient méthode qui supprime un client
 * @param tableView
 * @param myModel
 * @return
 */
bool DB_manager::deleteClient(QTableView *tableView, QSqlQueryModel* myModel)
{
    bool succes;
    //on récupère l id du client sélectionné
=======
DB_manager::DB_manager()
{
    //model= QSqlQueryModel();
}

bool DB_manager::deleteClient(QTableView *tableView, QSqlQueryModel* myModel)
{
    bool succes;

    //on récupère l id du client sélectionné
   // int id=myModel->index(tableView->currentIndex().row(),0).data().toInt();
>>>>>>> 92f75da1ebc1d3ea34a9fe6dc0dbdf28d34ccf42
     QString id=myModel->index(tableView->currentIndex().row(),0).data().toString();
    //qDebug() << ui->tableView->currentIndex().row()+1 << id;

    //on crée la requete
    QSqlQuery query(db);

    //on fait un prepare pour ajouter l'id à la requête
    query.prepare("DELETE FROM TClient WHERE Id = ?");
    query.addBindValue(id);
    succes=query.exec();

    if(!succes)
    {
       qDebug() << query.lastError().text();
        qDebug() << "erreur sur la requête !\n";
        return false;
    }
      myModel->setQuery(query);
    loadClient(myModel);
    return succes;
}

/**
<<<<<<< HEAD
 * @brief DB_manager::deletePersonnel
 * @param tableView
 * @param myModel
 * @return
 */
bool DB_manager::deletePersonnel(QTreeView *tableView, QStandardItemModel *myModel)
{
    bool succes;
    //on récupère le nom de la ressource sélectionnée
    QString name=tableView->currentIndex().data(0).toString();
   // qDebug() << name;

    //on crée la requete
    QSqlQuery query(db);

    //on fait un prepare pour ajouter l'id à la requête
    query.prepare("DELETE FROM TRessource WHERE Nom = ?");
    query.addBindValue(name);
    succes=query.exec();

    if(!succes)
    {
       qDebug() << query.lastError().text();
        qDebug() << "erreur sur la requête !\n";
        return false;
    }
      //myModel->set(query);
    //loadPersonnel(myModel);
    return succes;
}

/**
 * @brief DB_manager::modifyClient on supprime puis on crée un nouveau client
 * @param tableView
 * @param myModel
 * @return
 */
bool DB_manager::modifyClient(QTableView *tableView, QSqlQueryModel *myModel)
{
    deleteClient(tableView,myModel);
}

/**
=======
>>>>>>> 92f75da1ebc1d3ea34a9fe6dc0dbdf28d34ccf42
 * @brief DB_manager::loadClient affiche tous les clients de la base de données
 * @param myModel
 * @return
 */
bool DB_manager::loadClient(QSqlQueryModel* myModel)
{
    bool succes=true;
    //requête à exécuter lié à database
    QSqlQuery query(db);
    //exec de query return vrai ou faux si la requete a abouti ou pas
    succes=query.exec("select* from TClient");
   //si la requete n a pas abouti on affiche un erreur
    if(!succes)
    {
        qDebug() << query.lastError().text();
        qDebug() << "erreur sur la requête !\n";
        return false;
    }
      myModel->setQuery(query);
      return succes;
}
<<<<<<< HEAD
/**
 * @brief DB_manager::loadPersonnel
 * @param model
 * @return
 */
bool DB_manager::loadPersonnel(QStandardItemModel * model)
{

    QSqlQuery query(db);
    QSqlQuery query2(db);

    query.exec("select Distinct id,Label from TType");
     query2.prepare("select Nom from TRessource where IdType=? ");

     QStandardItem *parentItem = model->invisibleRootItem();
      QStandardItem *parentItem2=parentItem;

    //on liste les titres
    while(query.next())
           {
               QString title = query.value(1).toString();//On récupère dans un QString la valeur que retourne la requête
               QString id = query.value(0).toString();

               QStandardItem *item = new QStandardItem(title);
               parentItem->appendRow(item);
               parentItem = item;

               //pour chaque titre on cherche les noms associés
               query2.addBindValue(id);
               query2.exec();
               while(query2.next())
                      {

                          QString name = query2.value(0).toString();//On récupère dans un QString la valeur que retourne la requête
                      item = new QStandardItem(name);
                          parentItem->appendRow(item);
                      }
               parentItem=parentItem2;

           }

      //model->setQuery(query);
      //return succes;




    //connection treeview et methode clicked
   // connect(treeView, SIGNAL(clicked(QModelIndex)),
     //       this, SLOT(clicked(QModelIndex)));
    //méthode cliked
    /*void MyWidget::clicked(const QModelIndex &index)
    {
        QStandardItem *item = myStandardItemModel->itemFromIndex(index);
        // Do stuff with the item ...
    }*/
}
=======
>>>>>>> 92f75da1ebc1d3ea34a9fe6dc0dbdf28d34ccf42

bool DB_manager::researchClient(QSqlQueryModel* myModel,QString Firstname,
                                QString Lastname, QString id,QDate date1, QDate date2)
{
    bool succes=true;
    QSqlQuery qry(db);
    QString request="select* from TClient where 1 ";

    //requete en fonction des champs sélectionnés
    if(!Firstname.isNull() && Firstname!="" )
    {
        request.append(" and upper(Prenom)=upper('"+Firstname+"') ");
    }
    if(!Lastname.isNull() && Lastname!="" )
    {
         request.append(" and upper(Nom)=upper('"+Lastname+"' )");
    }

    if(!id.isNull() && id!="")
    {
         request.append("and Id='"+id+"' ");
    }
     QDate tempDate(2000, 01, 01);
<<<<<<< HEAD
    if(date1!=tempDate && date2!=tempDate )
    {
      request.append(" and DateRdv BETWEEN '"+date1.toString("yyyy-MM-dd")+"'  AND  '"+date2.toString("yyyy-MM-dd")+"' ");
    }
        //qDebug()<<date1.toString("yyyy-MM-dd");
=======
    if(tempDate!=date1 && date2!=tempDate )
    {
         //request.append(" and DateRdv BETWEEN '"+date1.toString("YYYY-MM-DD")+"'  AND  '"+date2.toString("YYYY-MM-DD")+"' ");
    }

>>>>>>> 92f75da1ebc1d3ea34a9fe6dc0dbdf28d34ccf42
    succes=qry.exec(request);
    if(!succes)
    {
        qDebug() << qry.lastError().text();
        qDebug() << "erreur sur la requête !\n";
        return false;
    }
      myModel->setQuery(qry);
      return succes;
}
<<<<<<< HEAD
/**
 * @brief DB_manager::connection connecte à la base de donnée
 */
=======

>>>>>>> 92f75da1ebc1d3ea34a9fe6dc0dbdf28d34ccf42
void DB_manager::connection()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
   if(db.isValid())
   {
   db.setHostName("localhost");
   db.setUserName("root");
   db.setPassword("password");
<<<<<<< HEAD
=======
   //if(QFile::exists("base_tmp.sqli"))
      // QFile::remove("base_tmp.sqli");
>>>>>>> 92f75da1ebc1d3ea34a9fe6dc0dbdf28d34ccf42
   db.setDatabaseName("base_tmp.sqli");}

   if(db.isValid())
   {
       db.open();
   }

}
<<<<<<< HEAD
/**
 * @brief DB_manager::deconnection
 */
=======
>>>>>>> 92f75da1ebc1d3ea34a9fe6dc0dbdf28d34ccf42

void DB_manager::deconnection()
{
    if(db.isValid())
    {
        db.close();
        db.removeDatabase("QSQLITE");
    }
}

<<<<<<< HEAD
=======



>>>>>>> 92f75da1ebc1d3ea34a9fe6dc0dbdf28d34ccf42
