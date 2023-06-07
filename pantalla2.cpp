#include "pantalla2.h"
#include "ui_pantalla2.h"

pantalla2::pantalla2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::pantalla2)
{
    ui->setupUi(this);
    setWindowTitle("THE MEDIA KILLER");
    setWindowIcon(QPixmap(":/Sprite/game_objects/icon.jpg"));
    setFixedSize(800,600);
    pn3=new Juego;
}

pantalla2::~pantalla2()
{
    delete pn3;
}

void pantalla2::on_pushButton_clicked()
{
    pn3->show();
    close();
}
