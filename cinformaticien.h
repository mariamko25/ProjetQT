#ifndef CINFORMATICIEN_H
#define CINFORMATICIEN_H
#include "cpersonnel.h"

class CInformaticien : CPersonnel
{
private:
    QString login;
    QString password;
public:
    CInformaticien();
};

#endif // CINFORMATICIEN_H
