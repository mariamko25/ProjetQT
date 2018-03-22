#include "db_manager.h"


DB_manager::DB_manager()
{
    //model= QSqlQueryModel();
}

bool DB_manager::deleteClient(QTableView *tableView, QSqlQueryModel* myModel)
{
    bool succes;

    //on récupère l id du client sélectionné
    int id=myModel->index(tableView->currentIndex().row(),0).data().toInt();
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




