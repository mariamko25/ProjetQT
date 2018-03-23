#ifndef CPLANNING_H
#define CPLANNING_H
#include<cpersonnel.h>
#include"cclient.h"
#include<algorithm>
#include"ctriclient.h"
#include<qdebug.h>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include <QFileDialog>

class CPlanning
{
public:
    CPlanning();
    void planning(QVector<CClient> listClient, QMap<int, CPersonnel>listRessource,QTextStream *out);
    QTime arrondi(QTime time);
    void printPlanning(QMap<int, CPersonnel>listRessource, QTextStream *out);
    void tri(QMap<int, CPersonnel>*listRessource, QVector<CClient> *listClient);
};

#endif // CPLANNING_H
