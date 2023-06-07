#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include <QPair>
#include "GameObject.h"


/* Changeable game options */
#define GHOST_SCORE     50          // score of ghosts
#define INTERVAL        10          // move interval of pacman
#define NORMAL_INTERVAL 10          // move interval of normal ghosts
#define FLASH_INTERVAL 200          // flash interval of powerballs

/* Game control class */
class Game : public QGraphicsScene
{
    Q_OBJECT

public:
    enum GameStatus {Playing, Win, Lose, Pause};
    Game(int, int, int, int, QString);
    ~Game();
    void start();
    void stop();
    void next_direction(GameObject::Dir);
    int get_score();

    GameObject ***map;              // Inicializacion del MAPA
    GameObject *objeto;               // //puntero de la puerta de la jaula de los fantasmas
    Personaje *jugador;                 // pointer of personaje
    Ghost *ghost[Ghost::GhostNum];  // pointers of ghosts
    QVector<GameObject*> powerball; // pointers of powerball
    GameStatus stat;



    friend class Personaje;
    friend class Ghost;


private slots:
    void pacman_handler();
    void powerball_flash();
    void ghost_handler(int);

private:
    int map_height, map_width;      // game map (20 x 29 in this app)
    int map_size;                   // map_width * map_height
    int ball_num, eat_num, score;
    int geo_x, geo_y;               // geometric coordinate

    QTimer *ghost_timer[Ghost::GhostNum];
    QTimer *personaje_timer;
    QTimer *powerball_flash_timer;
    bool flash_tick;

};

#endif // GAME_H
