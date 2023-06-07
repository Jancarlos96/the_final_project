#ifndef PANTALLA2_H
#define PANTALLA2_H

#include <QMainWindow>
#include "juego.h"
QT_BEGIN_NAMESPACE
namespace Ui { class pantalla2; }
QT_END_NAMESPACE

class pantalla2 : public QMainWindow
{
    Q_OBJECT
public:
    pantalla2(QWidget *parent = nullptr);
    ~pantalla2();

private slots:
    void on_pushButton_clicked();

private:
    Ui::pantalla2 *ui;
    Juego *pn3;
};

#endif // PANTALLA2_H
