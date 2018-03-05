#ifndef SABOUT_H
#define SABOUT_H

#include <QDialog>

namespace Ui {
class sAbout;
}

class sAbout : public QDialog
{
    Q_OBJECT

public:
    explicit sAbout(QWidget *parent = 0);
    ~sAbout();

private:
    Ui::sAbout *ui;
};

#endif // SABOUT_H
