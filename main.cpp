#include <QApplication>
#include "identification.h"
#include "mainwindow.h"
#include "c_init_bd.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


 //Identification id;
   /* if(id.exec()==QDialog::Accepted)
    {
        w.show();
        return a.exec();
    }
    return 0;*/

    C_INIT_BD bd;
    bd.Creation_BD();


    MainWindow w;
    w.show();
    return a.exec();


}

















/**
#include "mainwindow.h"
#include <QApplication>
#include"cressource.h"
#include"cclient.h"
#include"ctriclient.h"
#include"qdebug.h"

 * @brief tri les clients par indice de priorité
 * @param listRessource
 * @param listClient
 *
void tri(QMap<int, CRessource>*listRessource, QVector<CClient> *listClient)
{
    //on calcule l'indice de priorité pour chaque client
    for(QVector<CClient>::iterator it=listClient->begin(); it!=listClient->end();it++)
    {
        it->setIndice((it->getPriorite() * 100) + (it->getListRessource().size() * 10) + it->getDureeConsultation());
    }
    //on trie le vecteur de clients en fonction de l'indice de priorité
    std::sort(listClient->begin(), listClient->end(), CTriClient());
}


 * @brief arrondi au quart d'heure
 * @param time
 *
QTime arrondi(QTime time)
{
    if(time.minute()<15)
    {
        time.setHMS(time.hour(),15,0);
    }
    else if(15<time.minute() && time.minute()<30)
    {
        time.setHMS(time.hour(),30,0);
    }
    else if(30<time.minute() && time.minute()<45)
    {
        time.setHMS(time.hour(),45,0);
    }
    else if(45<time.minute() )
    {
        time.setHMS(time.hour()+1,0,0);
    }
    QTime temp=time;
    return temp;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();

    //clients
    CClient c1("mitch","el",1,25,{1,3});
    CClient c2("ronaldo","christiano",3,31,{2,1});
    CClient c3("nadal","rafael",5,50,{3,1});
    CClient c4("messi","lionel",6,40,{1,3});
    CClient c5("carmelo","anthony",1,15,{3});

    //liste des clients
    QVector<CClient> listClient;
    listClient.push_back(c3);
    listClient.push_back(c2);
    listClient.push_back(c1);
    listClient.push_back(c4);
    listClient.push_back(c5);


    //ressources
    CRessource r1(1,"docteur");
    CRessource r2(2,"banquier");
     CRessource r3(3,"assureur");

    //liste des ressouces
    QMap<int, CRessource>listRessource;
    listRessource.insert(r1.getId(),r1);
    listRessource.insert(r2.getId(),r2);
    listRessource.insert(r3.getId(),r3);

    //on trie par ordre de priorité
    tri(&listRessource,&listClient);

    // algorithme de création d'agenda
    int idRess;
    CClient clientTemp;



    for(QVector<CClient>::reverse_iterator it=listClient.rbegin(); it!=listClient.rend();++it)
    {
        //on déclare le rendez-vous courant
        CRdv rdvCrt;

        qDebug()<<it->getNom()<< " " <<it->getPrenom() <<": "<< it->getIndice()<<endl;

         clientTemp=*it;
        QVector<int> listRessTemp=clientTemp.getListRessource();

        int dureeRDV=(clientTemp.getDureeConsultation())/(clientTemp.getListRessource().size());


        //on initialise l heure de fin et on ajoute le nom et prenom du client lié au rendez vous
        //rdvCrt.setHbegin(QTime (8,0,0));
        rdvCrt.setHend(rdvCrt.getHbegin().addSecs(dureeRDV*60));
        rdvCrt.setNomPrenom(clientTemp.getNom()+" "+clientTemp.getPrenom());
        bool rdvPris=false;

        for(QVector<int>::iterator itR=listRessTemp.begin(); itR!=listRessTemp.end();itR++)
        {
            rdvPris=false;
             idRess=*itR;
             CRessource ressourceCrt=*listRessource.find(idRess);

                if(!ressourceCrt.getAgenda().empty() )//&& arrondi(ressourceCrt.getAgenda().begin()->getHbegin()) <=rdvCrt.getHend()
                {
                   //s'il ya d la place au début on y insère le rendez vous
                    if( ressourceCrt.getAgenda().begin()->getHbegin() >rdvCrt.getHend())
                    {
                       //on insère le rendez vous tel qu'il est dans l agenda ça veut dire qu on a choix l agenda est vide le rdv rentre au début de l agenda
                       rdvPris=true;
                   }
                    QMap<QTime, CRdv> agenda=ressourceCrt.getAgenda();
                        for(QMap<QTime, CRdv>::iterator itrdv=agenda.begin(); itrdv!=agenda.end();itrdv++)
                        {
                            //si l'heure de début correspond à une heure qui existe déjà
                            if(arrondi(rdvCrt.getHbegin())==arrondi(itrdv->getHbegin()))
                            {
                                    rdvCrt.setHbegin(arrondi(itrdv->getHend()));
                                   rdvCrt.setHend(rdvCrt.getHbegin().addSecs(dureeRDV*60));
                                }
                            //si l ecart entre la fin et le debut d un rendez vous est assez grand // arrondir (itrdv)->getHend()

                              if(arrondi(rdvCrt.getHbegin())<=arrondi(itrdv->getHend()) && arrondi(((itrdv)->getHend())).addSecs(dureeRDV*60)<=((itrdv+1)->getHbegin()))
                              {


                                   rdvCrt.setHbegin(arrondi(itrdv->getHend()));
                                  rdvCrt.setHend(rdvCrt.getHbegin().addSecs(dureeRDV*60));
                                  rdvPris=true;
                                  break;
                              }
                               else
                                {
                                      //  on ajoute le rdv à la fin
                                      if(itrdv+1==ressourceCrt.getAgenda().end() && rdvPris==false)
                                      {


                                          //heure debut= de fin du dernier arrondi
                                          rdvCrt.setHbegin(arrondi(itrdv->getHend()));
                                          rdvCrt.setHend(rdvCrt.getHbegin().addSecs(dureeRDV*60));
                                          rdvPris=true;
                                          break;
                                      }
                                 }
                        }
                }
                else if(ressourceCrt.getAgenda().empty() || ressourceCrt.getAgenda().begin()->getHbegin() >rdvCrt.getHend())
                {
                   //on insère le rendez vous tel qu'il est dans l agenda ça veut dire qu on a choix l agenda est vide le rdv rentre au début de l agenda
                   rdvPris=true;

                }

                listRessource.find(idRess)->addToAgenda(rdvCrt);
            //une fois le rdv pris heure de début du prochain c'est l'heure de fin du rdv courant
            rdvCrt.setHbegin(arrondi(rdvCrt.getHend()));
            rdvCrt.setHend(rdvCrt.getHbegin().addSecs(dureeRDV*60));
        }

        }

    for( QMap<int, CRessource>::iterator it=listRessource.begin(); it!=listRessource.end();it++)
    {
         qDebug()<< "agenda de la ressource: " <<it->getId() <<" "<< it->getTitle()<<endl;
        QMap<QTime, CRdv> agenda=it->getAgenda();
        for( QMap<QTime, CRdv>::iterator it2=agenda.begin(); it2!=agenda.end();it2++)
        {
            qDebug()<<it2->getHbegin().toString() <<" "<< it2->getHend().toString()<< " "<< it2->getNomPrenom()<<endl;
        }
    }
}
*/
