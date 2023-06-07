#include "muerte.h"
#include "ui_muerte.h"

muerte::muerte(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::muerte)
{
    ui->setupUi(this);
    setWindowTitle("has perdido");
    setWindowIcon(QPixmap(":/Sprite/game_objects/icon.jpg"));
    setFixedSize(800,600);
}

muerte::~muerte()
{
    delete ui;
}
