#include "db_manager.h"


DB_manager::DB_manager()
{
    //model= QSqlQueryModel();
}

bool DB_manager::deleteClient(QTableView *tableView, QSqlQueryModel* myModel)
{
    bool succes;

    //on récupère l id du client sélectionné
   // int id=myModel->index(tableView->currentIndex().row(),0).data().toInt();
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
    if(tempDate!=date1 && date2!=tempDate )
    {
         //request.append(" and DateRdv BETWEEN '"+date1.toString("YYYY-MM-DD")+"'  AND  '"+date2.toString("YYYY-MM-DD")+"' ");
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
   //if(QFile::exists("base_tmp.sqli"))
      // QFile::remove("base_tmp.sqli");
   db.setDatabaseName("base_tmp.sqli");}

   if(db.isValid())
   {
       db.open();
   }

}

void DB_manager::deconnection()
{
    if(db.isValid())
    {
        db.close();
        db.removeDatabase("QSQLITE");
    }
}




