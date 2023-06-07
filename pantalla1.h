#ifndef PANTALLA1_H
#define PANTALLA1_H

#include <QMainWindow>
#include "pantalla2.h"
QT_BEGIN_NAMESPACE
namespace Ui { class pantalla1; }
QT_END_NAMESPACE

class pantalla1 : public QMainWindow
{
    Q_OBJECT
public:
    pantalla1(QWidget *parent = nullptr);
    ~pantalla1();

private slots:
    void on_pushButton_clicked();

private:
    Ui::pantalla1 *ui;
    pantalla2 *pn2;
};

#endif // PANTALLA1_H
