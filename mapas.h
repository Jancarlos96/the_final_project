#ifndef MAPA_H
#define MAPA_H

#define Ancho_bloque_1 41
#define Alto_bloque_1 38

#include <QGraphicsScene>
#include <vector>
#include <QGraphicsRectItem>

class Mapa : public QObject, public QGraphicsPixmapItem
{
public:
    Mapa();
    ~Mapa();
    void CrearMuros(int Nivel);
    void is_wall(int x);
    bool is_muro();
    void agregarfinal( int x);

private:
    int numPlantas, alturaPlanta, is_a_wall, agregar_final;
    QPixmap *mapth;
    QPixmap *Fondo1;
    QPixmap *Final;
    void setImagen();
    void setFinal();
    qreal scale;
};

#endif // MAPA_H
