#ifndef NPERSONNEL_H
#define NPERSONNEL_H

#include <QDialog>

namespace Ui {
class nPersonnel;
}

class nPersonnel : public QDialog
{
    Q_OBJECT

public:
    explicit nPersonnel(QWidget *parent = 0);
    QString Created;
    ~nPersonnel();

private slots:
    void on_Ok_clicked();

    void on_Cancel_clicked();

private:
    Ui::nPersonnel *ui;
};

#endif // NPERSONNEL_H
