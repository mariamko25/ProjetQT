#ifndef CRESSOURCE_H
#define CRESSOURCE_H
#include <QTime>
#include"qmap.h"
#include"CRdv.h"

class CRessource
{
private :
    int id;
    QString title;
    QMap<QTime, CRdv> agenda;

public:
    //contructor
    CRessource();
     CRessource(int i, QString titre);

    //method
    int getId() const;
    QString getTitle() const;
    QMap<QTime, CRdv> getAgenda() const;
    void setAgenda(const QMap<QTime, CRdv> &value);
    void setTitle(const QString &value);
    void addToAgenda (CRdv rdv);
};

#endif // CRESSOURCE_H
