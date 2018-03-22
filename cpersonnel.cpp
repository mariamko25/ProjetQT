#include<cpersonnel.h>

QString CPersonnel::getFirstname() const
{
    return firstname;
}

void CPersonnel::setFirstname(const QString &value)
{
    firstname = value;
}

QString CPersonnel::getLastname() const
{
    return lastname;
}

void CPersonnel::setLastname(const QString &value)
{
    lastname = value;
}

void CPersonnel::setId(int value)
{
    id = value;
}

CPersonnel::CPersonnel()
{
    
}

QString CPersonnel::getTitle() const
{
    return title;
}

QMap<QTime, CRdv> CPersonnel::getAgenda() const
{
    return agenda;
}

void CPersonnel::setAgenda(const QMap<QTime, CRdv> &value)
{
    agenda = value;
}

void CPersonnel::setTitle(const QString &value)
{
    title = value;
}

void CPersonnel::addToAgenda(CRdv rdv)
{
    agenda.insert(rdv.getHbegin(),rdv);
}

CPersonnel::CPersonnel(int i, QString titre)
{
    id=i;
    title=titre;
}

int CPersonnel::getId() const
{
    return id;
}
