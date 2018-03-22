#ifndef CRDV_H
#define CRDV_H
#include"QTime"

class CRdv
{

    QTime hbegin;
    QTime hend;
    QString nomPrenom;
public:
    static int Id;
    //constructeur
CRdv();
CRdv(QTime hb, QTime hen, QString name);
//méthode
QTime getHbegin() const;
void setHbegin(const QTime &value);
QTime getHend() const;
void setHend(const QTime &value);
QString getNomPrenom() const;
void setNomPrenom(const QString &value);
};

#endif // CRDV_H
