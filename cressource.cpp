#include "c.h"

CRessource::CRessource()
{

}

QString CRessource::getTitle() const
{
    return title;
}

QMap<QTime, CRdv> CRessource::getAgenda() const
{
    return agenda;
}

void CRessource::setAgenda(const QMap<QTime, CRdv> &value)
{
    agenda = value;
}

void CRessource::setTitle(const QString &value)
{
    title = value;
}

void CRessource::addToAgenda(CRdv rdv)
{
    agenda.insert(rdv.getHbegin(),rdv);
}

CRessource::CRessource(int i, QString titre)
{
    id=i;
    title=titre;
}

int CRessource::getId() const
{
    return id;
}
