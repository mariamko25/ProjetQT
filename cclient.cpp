#include "cclient.h"

QDate CClient::getDate() const
{
    return date;
}
void CClient::setDate(const QDate &value)
{
    date = value;
}

CClient::CClient()
{
    dureeConsultation=60;
}


QString CClient::getNom() const
{
    return nom;
}

void CClient::setNom(const QString &value)
{
    nom = value;
}

QString CClient::getPrenom() const
{
    return prenom;
}

void CClient::setPrenom(const QString &value)
{
    prenom = value;
}

QString CClient::getAdresse() const
{
    return adresse;
}

void CClient::setAdresse(const QString &value)
{
    adresse = value;
}

QString CClient::getVille() const
{
    return ville;
}

void CClient::setVille(const QString &value)
{
    ville = value;
}

QString CClient::getCommentaire() const
{
    return commentaire;
}

void CClient::setCommentaire(const QString &value)
{
    commentaire = value;
}

int CClient::getTelephone() const
{
    return telephone;
}

void CClient::setTelephone(int value)
{
    telephone = value;
}

int CClient::getCodePostal() const
{
    return codePostal;
}

void CClient::setCodePostal(int value)
{
    codePostal = value;
}

int CClient::getDureeConsultation() const
{
    return dureeConsultation;
}

void CClient::setDureeConsultation(int value)
{
    dureeConsultation = value;
}

int CClient::getPriorite() const
{
    return priorite;
}

void CClient::setPriorite(int value)
{
    priorite = value;
}

QVector<int> CClient::getListRessource() const
{
    return listRessource;
}

void CClient::setListRessource(const QVector<int> &value)
{
    listRessource = value;
}

void CClient::addRessource(int id)
{
    listRessource.push_back(id);
}

void CClient::removeRessource(int id)
{
    if(listRessource.contains(id))
    {
        listRessource.remove(listRessource.indexOf(id));
    }

}

int CClient::getIndice() const
{
    return indice;
}

void CClient::setIndice(int value)
{
    indice = value;
}



CClient::CClient(QString nm, QString pr)
{
    nom=nm;
    prenom=pr;
    dureeConsultation=60;
}

CClient::CClient(QString nm, QString pr, int prior, int duree, QVector<int> ress)
{
    nom=nm;
    prenom=pr;
    priorite=prior;
    dureeConsultation= duree;
    listRessource=ress;

}
