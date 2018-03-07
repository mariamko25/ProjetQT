#include "CRdv.h"


QTime CRdv::getHbegin() const
{
    return hbegin;
}

void CRdv::setHbegin(const QTime &value)
{
    hbegin = value;
}

QTime CRdv::getHend() const
{
    return hend;
}

void CRdv::setHend(const QTime &value)
{
    hend = value;
}

QString CRdv::getNomPrenom() const
{
    return nomPrenom;
}

void CRdv::setNomPrenom(const QString &value)
{
    nomPrenom = value;
}

CRdv::CRdv()
{
    hbegin=QTime (8, 0, 0);
    hend= QTime(8, 0, 0);
    nomPrenom = " ";
}

CRdv::CRdv(QTime hb, QTime hen,QString name)
{
    hbegin=hb;
    hend=hen;
    nomPrenom=name;
}
