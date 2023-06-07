#include "play.h"

Play::Play()
{
    Agregar_Jugador();
    scale = 0.3;
    crear_Mapa();
    set_background(":/Sprite/images/Fondoth.png", 0.25);
}

Play::~Play()
{
    delete p_pal;
}

void Play::Agregar_Jugador()
{
    p_pal = new Jugador();
    p_pal->ElegirSprite(0, 0);
    addItem(p_pal);
    p_pal->setZValue(1);
    p_pal->posicionar(40, 540);
    setFocusItem(p_pal);
}

void Play::crear_Mapa()
{
    int ty = 60;
    for (int i = 0; i < 23; i++) {
        homth[i] = new Mapa;
        homth[i]->is_wall(1);
        addItem(homth[i]);
        homth[i]->setPos((ty * i), (620));
    }

    for (int i = 0; i < 23; i++) {
        if ((i < 5) || (i > 14)) {
            homth[i] = new Mapa;
            homth[i]->is_wall(1);
            addItem(homth[i]);
            homth[i]->setPos((ty * i), (380));
        }
    }

    escalas[1] = new Mapa;
    escalas[1]->is_wall(1);
    addItem(escalas[1]);
    escalas[1]->setPos((0), (320));

    escalas[2] = new Mapa;
    escalas[2]->is_wall(1);
    addItem(escalas[2]);
    escalas[2]->setPos((240), (320));

    escalas[3] = new Mapa;
    escalas[3]->is_wall(1);
    addItem(escalas[3]);
    escalas[3]->setPos((900), (320));

    escalas[3] = new Mapa;
    escalas[3]->is_wall(1);
    addItem(escalas[3]);
    escalas[3]->setPos((1290), (320));

    // Premio Final
    escalas[4] = new Mapa;
    escalas[4]->is_wall(1);
    addItem(escalas[4]);
    escalas[4]->setPos((480), (140));

    escalas[5] = new Mapa;
    escalas[5]->is_wall(1);
    addItem(escalas[5]);
    escalas[5]->setPos((540), (140));

    escalas[6] = new Mapa;
    escalas[6]->is_wall(1);
    addItem(escalas[6]);
    escalas[6]->setPos((600), (80));

    escalas[7] = new Mapa;
    escalas[7]->is_wall(1);
    addItem(escalas[7]);
    escalas[7]->setPos((600), (140));

    escalas[8] = new Mapa;
    escalas[8]->is_wall(1);
    addItem(escalas[8]);
    escalas[8]->setPos((420), (140));

    escalas[9] = new Mapa;
    escalas[9]->is_wall(1);
    addItem(escalas[9]);
    escalas[9]->setPos((420), (80));

    escalas[10] = new Mapa;
    escalas[10]->agregarfinal(1);
    addItem(escalas[10]);
    escalas[10]->setPos((500), (65));
}

bool Play::ComprobarColision(QGraphicsItem *item, short dir, int Ancho, int Alto)
{
    unsigned short x = item->x(), y = item->y(), x1, y1;
    bool move = true;

    switch (dir) {
    case 0: // Izquierda
        x -= impx;
        x1 = x;
        y1 = y + Alto * scale - 1;
        break;
    case 1: // Abajo
        y += Alto * scale - 1 + impy;
        x1 = x + Ancho * scale - 1;
        y1 = y;
        break;
    case 2: // Derecha
        x += Ancho * scale - 1 + impx;
        x1 = x;
        y1 = y + Alto * scale - 1;
        break;
    case 3: // Arriba
        y -= impy;
        x1 = x + Ancho * scale - 1;
        y1 = y;
        break;
    default:
        break;
    }


    return move;
}

void Play::set_background(QString name, float scale)
{
    QImage k;
    QBrush n;

    k.load(name);
    setBackgroundBrush(k);
}

void Play::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Space:
        p_pal->ActualizarMovimiento(3);
        if (ComprobarColision(p_pal, 3, Ancho_bloque_1, Alto_bloque_1)) {
            p_pal->move_jugador(3);
        }
        break;
    case Qt::Key_S:
        p_pal->ActualizarMovimiento(1);
        if (ComprobarColision(p_pal, 1, Ancho_bloque_1, Alto_bloque_1)) {
            p_pal->move_jugador(1);
        }
        break;
    case Qt::Key_A:
        p_pal->ActualizarMovimiento(0);
        if (ComprobarColision(p_pal, 0, Ancho_bloque_1, Alto_bloque_1)) {
            p_pal->move_jugador(0);
        }
        break;
    case Qt::Key_D:
        p_pal->ActualizarMovimiento(2);
        if (ComprobarColision(p_pal, 2, Ancho_bloque_1, Alto_bloque_1)) {
            p_pal->move_jugador(2);
        }
        break;
    default:
        break;
    }
}
