#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "QSqlQueryModel"
#include <QMainWindow>
#include "nclient.h"
#include "npersonnel.h"
#include "sabout.h"
#include <QMenu>
#include <QMenuBar>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void createMenus();
    void createActions();
    void CClient();
    void QExit();
    void CPersonnel();
    void slotAbout();
    void on_Btn_Load_clicked();

   // void on_pushButton_3_clicked();

    void on_Btn_ResearchBy_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QMenu *File;
     QMenu *Add;
    QMenu *Toolbar;
     QAction *Quit;
    QAction *Client;
    QAction *Personnel;
    QAction *aAbout;
    QAction *ClientTool;
    QAction *PersonnelTool;
    QSqlQueryModel *myModel;



};

#endif // MAINWINDOW_H
