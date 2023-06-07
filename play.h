#ifndef PLAY_H
#define PLAY_H

#define Ancho_Mapa 1344
#define Alto_Mapa 756
#define total_x_bloques 20
#define total_y_bloques 16

#include "jugador.h"
#include "mapas.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <QVector>
#include <QGraphicsView>
#include <QObject>
#include <cstdlib>

class Play : public QGraphicsScene
{
    Q_OBJECT
public:
    Play();
    ~Play();
private:
    Jugador *p_pal;
    Mapa *homth[100];
    Mapa *escalas[100];
    qreal scale;
    void Agregar_Jugador();
    void crear_Mapa();
    void centerViewOn(QGraphicsItem *item);
    bool ComprobarColision(QGraphicsItem *item, short dir, int Ancho, int Alto);
    void set_background(QString name, float scale);
public slots:
    void keyPressEvent(QKeyEvent *event);
};

#endif // PLAY_H
