#ifndef CTRICLIENT_H
#define CTRICLIENT_H
#include"cclient.h"

class CTriClient
{
public:
  CTriClient();


  bool operator()(const CClient & c1,const CClient & c2)
  {
     return (c1.getIndice()< c2.getIndice());
  }
};

#endif // CTRICLIENT_H
