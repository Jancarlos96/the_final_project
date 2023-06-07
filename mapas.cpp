#include "mapas.h"

Mapa::Mapa()
{
    mapth = new QPixmap;
    Fondo1 = new QPixmap;
    Final = new QPixmap;
    is_a_wall = -1;
    scale = 2; //Cambiar la Escala
}

Mapa::~Mapa()
{
    delete mapth;
    delete Fondo1;
    delete Final;
}

void Mapa::is_wall(int x)
{
    is_a_wall = x;
    setImagen();
}

bool Mapa::is_muro()
{
    return is_a_wall != -1;
}

void Mapa::agregarfinal(int x)
{
    agregar_final=x;
    setFinal();
}

void Mapa::setImagen()
{
    if(is_a_wall==1){
        mapth->load(":/Sprite/images/bloque12.png");
    }

    setPixmap(mapth->scaled(mapth->width() * scale,
                                   mapth->height() * scale));
}

void Mapa::setFinal()
{
    if(agregar_final==1){
        Final->load(":/Sprite/images/ganador.png");
    }

    setPixmap(Final->scaled(Final->width() * scale,
                                   Final->height() * scale));
}
