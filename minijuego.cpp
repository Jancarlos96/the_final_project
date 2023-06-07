#include "minijuego.h"
#include "ui_minijuego.h"

minijuego::minijuego(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::minijuego)
{
    ui->setupUi(this);
    setWindowTitle("mini juego");
    setWindowIcon(QPixmap(":/Sprite/game_objects/ganador.png"));
}

minijuego::~minijuego()
{
    delete ui;
}
