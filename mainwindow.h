#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSqlQueryModel>
#include <QMainWindow>
#include "nclient.h"
#include "npersonnel.h"
#include "sabout.h"
#include "cclient.h"
#include <QMenu>
#include <QMenuBar>
#include<QStandardItemModel>
#include<db_manager.h>
#include<QVariantList>
#include <QDebug>


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
    void cClient();
    void QExit();
    void cPersonnel();
    void slotAbout();
    void on_Btn_Load_clicked();

    void on_Btn_ResearchBy_clicked();

    void on_BtnModifyClient_clicked();

    void on_BTN_LoadPersonnel_clicked();


    void on_BtnDeleteClient_clicked();

    void on_BtnModifyStaff_clicked();

    void on_BtnDeleteStaff_clicked();

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
    QStandardItemModel * modelTreePersonnel;



};

#endif // MAINWINDOW_H
