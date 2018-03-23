#include "cplanning.h"

CPlanning::CPlanning()
{

}
/**
 * @brief tri
 * on trie le vecteur de clients en fonction de l'indice de priorité
 * @param listRessource
 * @param listClient
 */
void CPlanning::tri(QMap<int, CPersonnel>*listRessource, QVector<CClient> *listClient)
{
    //on calcule l'indice de priorité pour chaque client
    for(QVector<CClient>::iterator it=listClient->begin(); it!=listClient->end();it++)
    {
        it->setIndice((it->getPriorite() * 100) + (it->getListRessource().size() * 10) + it->getDureeConsultation());
    }
    //on trie le vecteur de clients en fonction de l'indice de priorité
    std::sort(listClient->begin(), listClient->end(), CTriClient());
}



/**
 * @brief arrondi arrondi un qtime  au quart d'heure
 * @param time
 * @return
 */
QTime CPlanning::arrondi(QTime time)
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



/**
 * @brief CPlanning::planning
 * fais le planning de la liste en paramètre
 * @param listClient
 * @param listRessource
 */
void CPlanning::planning(QVector<CClient> listClient, QMap<int, CPersonnel>listRessource, QTextStream* out)
{

    //on trie par ordre de priorité
    tri(&listRessource, &listClient);

    // algorithme de création d'agenda
    int idRess;
    CClient clientTemp;
    //on parcourt par ordre de priorité les clients
    for(QVector<CClient>::reverse_iterator it=listClient.rbegin(); it!=listClient.rend();++it)
    {
        //on déclare le rendez-vous courant
        CRdv rdvCrt;

       // qDebug()<<it.()<< " " <<it->getPrenom() <<": "<< it->getIndice()<<endl;

         clientTemp=*it;
        QVector<int> listRessTemp=clientTemp.getListRessource();
        int dureeRDV;
        if(clientTemp.getListRessource().size()!=0 )
        {
             dureeRDV=(clientTemp.getDureeConsultation())/(clientTemp.getListRessource().size());

        }


        //on initialise l heure de fin et on ajoute le nom et prenom du client lié au rendez vous
        //rdvCrt.setHbegin(QTime (8,0,0));
        rdvCrt.setHend(rdvCrt.getHbegin().addSecs(dureeRDV*60));
        rdvCrt.setNomPrenom(clientTemp.getNom()+" "+clientTemp.getPrenom());
        bool rdvPris=false;

        for(QVector<int>::iterator itR=listRessTemp.begin(); itR!=listRessTemp.end();itR++)
        {
            rdvPris=false;
             idRess=*itR;
             CPersonnel ressourceCrt=*listRessource.find(idRess);

                if(!ressourceCrt.getAgenda().empty() )// on vérifie que la ressource n'est pas vide
                {
                   //s'il ya de la place au début on y insère le rendez vous
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
    //on affiche le planning
    printPlanning(listRessource, out);

}



/**
 * @brief CPlanning::printPlanning
 * affiche les rdv
 * @param listRessource
 * @param out
 */
void CPlanning::printPlanning(QMap<int, CPersonnel> listRessource, QTextStream* out)
{


    for( QMap<int, CPersonnel>::iterator it=listRessource.begin(); it!=listRessource.end();it++)
    {
         (*out)<< "agenda de la ressource: " <<it->getId() <<" "<< it->getTitle()<<endl;

        QMap<QTime, CRdv> agenda=it->getAgenda();
        for( QMap<QTime, CRdv>::iterator it2=agenda.begin(); it2!=agenda.end();it2++)
        {
            (*out) << it2->getHbegin().toString() <<" "<< it2->getHend().toString()<< " "<< it2->getNomPrenom()<<endl;

        }
        *out<<"\n";
    }
      out->flush();
}
