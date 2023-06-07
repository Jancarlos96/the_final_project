#include "pantalla1.h"
#include "ui_pantalla1.h"
#include <QMainWindow>
pantalla1::pantalla1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::pantalla1)
{
    ui->setupUi(this);
    setWindowTitle("THE MEDIA KILLER");
    setWindowIcon(QPixmap(":/Sprite/game_objects/icon.jpg"));
    setFixedSize(800,600);
    pn2=new pantalla2;
}

pantalla1::~pantalla1()
{
    delete ui;
    delete pn2;
}

void pantalla1::on_pushButton_clicked()
{
    pn2->show();
    close();
}
