#ifndef CCLIENT_H
#define CCLIENT_H
#include <QString>
#include <QVector>
#include<QDate>

class CClient
{
private:
    QString nom;
    QString prenom;
    QString adresse;
    QString ville;
    QString commentaire;
    int telephone;
    int codePostal;
    int dureeConsultation;
    int priorite;
    int indice;
    QVector<int> listRessource;
    QDate date;
public:
    //constructeur
    CClient();
    CClient(QString nm, QString pr);
    CClient(QString nm, QString pr,int prior, int duree, QVector<int> ress);
    //méthode
    QString getNom() const;
    void setNom(const QString &value);
    QString getPrenom() const;
    void setPrenom(const QString &value);
    QString getAdresse() const;
    void setAdresse(const QString &value);
    QString getVille() const;
    void setVille(const QString &value);
    QString getCommentaire() const;
    void setCommentaire(const QString &value);
    int getTelephone() const;
    void setTelephone(int value);
    int getCodePostal() const;
    void setCodePostal(int value);
    int getDureeConsultation() const;
    void setDureeConsultation(int value);
    int getPriorite() const;
    void setPriorite(int value);
    QVector<int> getListRessource() const;
    void setListRessource(const QVector<int> &value);
    void addRessource(int id);
    void removeRessource(int id);
    int getIndice() const;
    void setIndice(int value);
    QDate getDate() const;
    void setDate(const QDate &value);
};

#endif // CCLIENT_H
