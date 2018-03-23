#include<cpersonnel.h>
int CPersonnel::Id=13;

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

CPersonnel::CPersonnel(QString lname, QString fname, int idType)
{
    lastname=lname;
    firstname=fname;
    type=idType;
}

void CPersonnel::setId(int i)
{
    id=i;
}

CPersonnel::CPersonnel(int i, QString lname, QString fname, int idType)
{
    id=i;
    lastname=lname;
    firstname=fname;
    type=idType;
}
