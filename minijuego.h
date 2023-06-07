#ifndef MINIJUEGO_H
#define MINIJUEGO_H

#include <QWidget>

namespace Ui {
class minijuego;
}

class minijuego : public QWidget
{
    Q_OBJECT

public:
    explicit minijuego(QWidget *parent = nullptr);
    ~minijuego();

private:
    Ui::minijuego *ui;
};

#endif // MINIJUEGO_H
