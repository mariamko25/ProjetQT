#include "db_manager.h"

/**
 * @brief DB_manager::deleteClient méthode qui supprime un client
 * @param tableView
 * @param myModel
 * @return
 */
DB_manager::DB_manager()
{

}

bool DB_manager::deleteClient(QTableView *tableView, QSqlQueryModel* myModel)
{
    bool succes;
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


bool DB_manager::deletePersonnel(QTreeView *tableView, QStandardItemModel *myModel)
{

    bool succes;
    //on récupère le nom de la ressource sélectionnée
    QString name=tableView->currentIndex().data(0).toString();
    QString id= name.at(0);
   // qDebug() << name;

    //on crée la requete
    QSqlQuery query(db);

    //on fait un prepare pour ajouter l'id à la requête
    query.prepare("DELETE FROM TRessource WHERE Id = ?");
    query.addBindValue(id);
    succes=query.exec();

    if(!succes)
    {
       qDebug() << query.lastError().text();
        qDebug() << "erreur sur la requête !\n";
        return false;
    }
    //on réactualise le model
    loadPersonnel(myModel);
    return succes;
}

/**
 * @brief DB_manager::modifyClient on supprime puis on crée un nouveau client
 * @param tableView
 * @param myModel
 * @return
 */
bool DB_manager::modifyClient(CClient myclient)
{
    connection();
    QSqlQuery query(db);
    if(!db.isOpen())
    {
        qDebug() << db.lastError().text();
        qDebug() << "Erreur à louverture de la base !\n";
        return false;
    }

    QString id= QString("%1").arg(myclient.getIndice());
    QString myquery="UPDATE TClient  SET ";
    myquery+="Nom='"+myclient.getNom()+"',";
    myquery+="Prenom='"+myclient.getPrenom()+"',";
    myquery+="Adresse='"+myclient.getAdresse()+"',";
    myquery+="Ville='"+myclient.getVille()+"',";
    myquery+="CP='"+QString("%1").arg(myclient.getCodePostal())+"',";
    myquery+="Commentaire='"+myclient.getCommentaire()+"',";
    myquery+="Tel='"+QString("%1").arg(myclient.getTelephone())+"',";
    myquery+="DateRdv='"+myclient.getDate().toString()+"',";
    myquery+="DureeRdv='"+QString("%1").arg(myclient.getDureeConsultation())+"',";
    myquery+="Priorite='"+QString("%1").arg(myclient.getPriorite())+"' WHERE Id='"+id+"';";
    bool test=query.exec(myquery);
    if(test)
    {

    }
    else{
        qDebug() << query.lastError().text();
        qDebug() << "client non modifie !\n";
        return false;
    }
    deconnection();
    return test;
}

bool DB_manager::modifPersonnel(CPersonnel Pers)
{

    connection();

    if(!db.isOpen())
    {
        qDebug() << db.lastError().text();
        qDebug() << "Erreur à louverture de la base !\n";
        return false;
    }

    QSqlQuery query(db);
    QString id= QString("%1").arg(Pers.getId());
    QString myquery="UPDATE TRessource  SET ";
    myquery+="Nom='"+Pers.getLastname()+"',";
    myquery+="Prenom='"+Pers.getFirstname()+"',";
    myquery+="IdType='"+QString("%1").arg(Pers.getType())+"' WHERE Id='"+id+"';";
    bool test=query.exec(myquery);
    if(test)
    {

    }
    else{
        qDebug() << query.lastError().text();
        qDebug() << "personnel non modifie !\n";
        return false;
    }
    deconnection();
    return test;
}



/**
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

/**
 * @brief DB_manager::loadPersonnel
 * @param model
 * @return
 */
bool DB_manager::loadPersonnel(QStandardItemModel * model)
{
    //on nettoie le modèle pour ne pas avoir deux arbres
    model->clear();
    QSqlQuery query(db);
    QSqlQuery query2(db);

    query.exec("select Distinct id,Label from TType");
     query2.prepare("select Id,Nom from TRessource where IdType=? ");

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
                           QString idStaff=query2.value(0).toString();
                          QString name = query2.value(1).toString();//On récupère dans un QString la valeur que retourne la requête
                          QStandardItem * itemId = new QStandardItem(idStaff+" "+name);
                           //QStandardItem * itemName = new QStandardItem(name);

                          parentItem->appendRow(itemId);
                         // parentItem->appendRow(itemName);
                      }
               parentItem=parentItem2;

           }
    return true;
}


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

    if(date1!=tempDate && date2!=tempDate )
    {
      request.append(" and DateRdv BETWEEN '"+date1.toString("yyyy-MM-dd")+"'  AND  '"+date2.toString("yyyy-MM-dd")+"' ");
    }

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


void DB_manager::connection()
{
   db = QSqlDatabase::addDatabase("QSQLITE");
   if(db.isValid())
   {
   db.setHostName("localhost");
   db.setUserName("root");
   db.setPassword("password");
   db.setDatabaseName("base_tmp.sqli");}

   if(db.isValid())
   {
       db.open();
   }

}

bool DB_manager::addPersonnelTodba(CPersonnel personnel)
{
    connection();
    if(!db.isOpen())
    {
        qDebug() << db.lastError().text();
        qDebug() << "Erreur à louverture de la base !\n";
        return false;
    }
     QSqlQuery query(db);
     QString id= QString("%1").arg(personnel.Id);
     QString myquery="INSERT INTO TRessource VALUES (";
      myquery+="'"+id+"',";
      myquery+="'"+personnel.getLastname()+"',";
      myquery+="'"+personnel.getFirstname()+"',";

      myquery+="'"+ QString("%1").arg(personnel.getType())+"');";
      bool test=query.exec(myquery);
      if(test)
      {
          personnel.Id++;
      }
      else{
          qDebug() << query.lastError().text();
          qDebug() << "personnel non cree !\n";
          return false;
      }
      deconnection();
      return test;
}
bool DB_manager::addClientTodba(CClient client)
{
    connection();
    QSqlQuery query(db);
    if(!db.isOpen())
    {
        qDebug() << db.lastError().text();
        qDebug() << "Erreur à louverture de la base !\n";
        return false;
    }
    QString id= QString("%1").arg(client.Id);
    QString myquery="INSERT INTO TClient  VALUES (";
    myquery+="'"+id+"',";
    myquery+="'"+client.getNom()+"',";
    myquery+="'"+client.getPrenom()+"',";
    myquery+="'"+client.getAdresse()+"',";
    myquery+="'"+client.getVille()+"',";
    myquery+="'"+QString("%1").arg(client.getCodePostal())+"',";
    myquery+="'"+client.getCommentaire()+"',";
    myquery+="'"+QString("%1").arg(client.getTelephone())+"',";
    myquery+="'"+client.getDate().toString()+"',";
    myquery+="'"+QString("%1").arg(client.getDureeConsultation())+"',";
    myquery+="'"+QString("%1").arg(client.getPriorite())+"');";
    bool test=query.exec(myquery);
    if(test)
    {
        client.Id++;
    }
    else{
        qDebug() << query.lastError().text();
        qDebug() << "client non cree !\n";
        return false;
    }
    deconnection();
    return test;
}
void DB_manager::deconnection()
{
    if(db.isValid())
    {
        db.close();
        db.removeDatabase("QSQLITE");
    }
}

QSqlDatabase DB_manager::getDb()
{
    return db;
}

CClient DB_manager::getClientFromdba(QTableView *tableView, QSqlQueryModel *myModel)
{
    bool succes;
     QString id=myModel->index(tableView->currentIndex().row(),0).data().toString();
    //on crée la requete
    QSqlQuery query(db);

    //on fait un prepare pour ajouter l'id à la requête
    query.prepare("select * FROM TClient WHERE Id = ?");
    query.addBindValue(id);
    succes=query.exec();
    if(!succes)
    {
       qDebug() << query.lastError().text();
        qDebug() << "erreur sur la requête !\n";

    }
    query.next();
    QString fname=query.value(1).toString();
    QString lname=query.value(2).toString();
    QString addr=query.value(3).toString();
    QString city=query.value(4).toString();
    QString cp=query.value(5).toString();
    QString num=query.value(7).toString();
    CClient client(lname,fname,addr,city,cp.toInt(),num.toInt());
    client.setIndice(id.toInt());

    return client;
}

CPersonnel DB_manager::getPersonnelFromdba(QTreeView *tableView)
{
     bool succes;
     QString item=tableView->currentIndex().data(0).toString();
     QString id=item.at(0);
    //on crée la requete
    QSqlQuery query(db);

    //on fait un prepare pour ajouter l'id à la requête
    query.prepare("select * FROM TRessource WHERE Id = ?");
    query.addBindValue(id);
    succes=query.exec();
    if(!succes)
    {
       qDebug() << query.lastError().text();
        qDebug() << "erreur sur la requête !\n";

    }
    query.next();
    QString lname=query.value(1).toString();
    QString fname=query.value(2).toString();
    QString IdType=query.value(3).toString();
    CPersonnel p(id.toInt(),lname,fname,IdType.toInt());

    return p;
}
