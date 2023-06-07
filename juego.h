#ifndef JUEGO_H
#define JUEGO_H

#include <QMainWindow>
#include <QLabel>
#include <QKeyEvent>
#include <QTimer>
#include "game.h"
#include "minijuego.h"
#include "muerte.h"
#include <QMessageBox>
#include "play.h"
#include "view.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Juego; }
QT_END_NAMESPACE

class Juego : public QMainWindow
{
    Q_OBJECT

public:
    Juego(QWidget *parent = nullptr);
    ~Juego();
    void initLabels();
    void keyPressEvent(QKeyEvent*) override;
    QMessageBox msgBox;

public slots:
    void update_score();
    void restartGame();

private:
    Ui::Juego *ui;
    QLabel *score_title, *score;
    QTimer *score_timer;
    Game *game;
    View *mn;
};

#endif // JUEGO_H

