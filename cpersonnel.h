#ifndef CRESSOURCE_H
#define CRESSOURCE_H
#include <QTime>
#include"qmap.h"
#include"CRdv.h"

class CPersonnel
{
private :
    int id;
    int type;
    QString title;
    QString firstname;
    QString lastname;
    QMap<QTime, CRdv> agenda;

public:
    //contructor
    CPersonnel();
     CPersonnel(int i, QString titre);

    //method
    int getId() const;
    QString getTitle() const;
    QMap<QTime, CRdv> getAgenda() const;
    void setAgenda(const QMap<QTime, CRdv> &value);
    void setTitle(const QString &value);
    void addToAgenda (CRdv rdv);
    QString getFirstname() const;
    void setFirstname(const QString &value);
    QString getLastname() const;
    void setLastname(const QString &value);
    void setId(int value);
};

#endif // CRESSOURCE_H
