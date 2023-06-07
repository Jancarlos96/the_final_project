#ifndef JUGADOR_H
#define JUGADOR_H

#define Ancho_jugador 100    //Recuadro del Sprite
#define Alto_jugador 100
#define Pos_sprite_Jugador_x 0 // Ubicacion del cuadro del sprite con respecto a la imagen
#define Pos_sprite_Jugador_y 0
#define filas_sprite 1
#define col_sprite 8
#define impx 8 //Velocidad en X
#define impy 280 //Fuerza de salto en Y
#define total_sprites_jugador 3

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class Jugador : public QGraphicsPixmapItem, public QObject
{
public:
    Jugador();
    ~Jugador();
    void move_jugador(int type);
    void ElegirSprite(int x, int y);
    void setImage();
    void posicionar(int x, int y);
    void ActualizarMovimiento(int type);
private:
    QPixmap *Personaje, *Movimiento;
    qreal velocityY;
    qreal velocityX;
    qreal aceleracionx, aceleraciony, posx, posy, T, delta;
    void cinematica();
    bool isJumping;
    void jump();
    int cant_sprites, scale;
    QTimer *timer;
    void applyGravity();
};



#endif // JUGADOR_H
