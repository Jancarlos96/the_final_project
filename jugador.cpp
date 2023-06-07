#include "jugador.h"
#include <QTimer>

Jugador::Jugador()
{
    Personaje=new QPixmap;
    Movimiento=new QPixmap;

    Personaje->load(":/Sprite/images/direccionesqc.png");
    *Personaje=Personaje->copy(Pos_sprite_Jugador_x,Pos_sprite_Jugador_y,
                     Ancho_jugador*col_sprite,
                     Alto_jugador*filas_sprite);
    cant_sprites=5;
    scale=1;
    velocityY = 0;
    velocityX = 0;
    T=0.2;
    isJumping = false;
    aceleracionx = 0;
    aceleraciony = 0 ;
    delta = 1.5; // Delta de GRAVEDAD

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Jugador::applyGravity);
    timer->start(T*500);
}

Jugador::~Jugador()
{
    delete Personaje;
    delete Movimiento;
    delete timer;
}

void Jugador::move_jugador(int type)
{
    switch (type) {
    case 0:
            aceleracionx = 50;
            velocityX -= impx;
        break;
    case 1:

        //setY(y() + Velocidad_Jugador); // Mover hacia abajo
        break;
    case 2:
        aceleracionx = -50;
        velocityX += impx;
        //setX(x() + Velocidad_Jugador); // Mover hacia la derecha
        break;
    case 3:
        if (!isJumping){
            aceleraciony = 80;
            velocityY -= impy;
            isJumping=true;
        }
        break;
    default:
        break;
    }
}

void Jugador::ElegirSprite(int x, int y)
{
    if(x < col_sprite && y<filas_sprite){
        *Movimiento=Personaje->copy(x*Ancho_jugador,y*Alto_jugador,
                                  Ancho_jugador,Alto_jugador);
    setImage();
    }
}

void Jugador::setImage()
{
    setPixmap(Movimiento->scaled(Movimiento->width()*scale,
                                 Movimiento->height()*scale));
}

void Jugador::posicionar(int x, int y)
{
    setPos(x,y);
    posx=x;
    posy=y;
}

void Jugador::ActualizarMovimiento(int type)
{
    if (type==0){
        if(cant_sprites>=4) cant_sprites=4;
        ElegirSprite(cant_sprites,0);
        cant_sprites--;
        if(cant_sprites==1) cant_sprites = 4;
    }
    else if(type==2){
        if(cant_sprites<=5) cant_sprites=5;
        ElegirSprite(cant_sprites,0);
        cant_sprites++;
        if(cant_sprites==8) cant_sprites = 5;
    }
    else
        ElegirSprite(0,0);
}

void Jugador::cinematica()
{
    velocityX += aceleracionx*T*delta;
    velocityY += aceleraciony*T*delta;
    posx += velocityX*T*delta;
    posy += velocityY*T*delta;
    setPos(posx,posy);
}

void Jugador::applyGravity()
{
    cinematica();
    if((aceleracionx < 0 && velocityX <= 0) || (aceleracionx > 0 && velocityX >= 0 )){
        velocityX =0 ;
        aceleracionx = 0;
    }

    const qreal groundLevel = 540;
    if (y() >= groundLevel) {
        setY(groundLevel);
        velocityY = 0;
        isJumping = false;
    }
}

