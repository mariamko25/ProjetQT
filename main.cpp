#include <QApplication>
#include "identification.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   
    
 //Identification id;
   /* if(id.exec()==QDialog::Accepted)
    {
        w.show();
        return a.exec();
    }
    return 0;*/
    MainWindow w;
    w.show();
    return a.exec();
    
    
}
