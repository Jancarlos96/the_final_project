#include "game.h"


QPair<int, int> strategy1(Ghost* ghost) {
    Personaje *jugador = ghost->game->jugador;
    int dist_x = jugador->get_x() - ghost->get_x();
    int dist_y = jugador->get_y() - ghost->get_y();
    return QPair<int, int>(dist_x, dist_y);
}

QPair<int, int> strategy2(Ghost* ghost) {
    Personaje *jugador = ghost->game->jugador;
    int dist_x = jugador->get_x() - ghost->get_x();
    int dist_y = jugador->get_y() - ghost->get_y();
    switch(jugador->get_dir()) {
    case GameObject::Up:
        dist_y-=4;
        break;
    case GameObject::Down:
        dist_y+=4;
        break;
    case GameObject::Left:
        dist_x-=4;
        break;
    case GameObject::Right:
        dist_x+=4;
        break;
    default:
        break;
    }
    return QPair<int, int>(dist_x, dist_y);
}

QPair<int, int> strategy3(Ghost* ghost) {
    Personaje *jugador = ghost->game->jugador;
    Ghost *red_ghost = ghost->game->ghost[Ghost::Azul];
    int dist_x = (jugador->get_x() - red_ghost->get_x()) * 2 - ghost->get_x();
    int dist_y = (jugador->get_y() - red_ghost->get_y()) * 2 - ghost->get_y();
    return QPair<int, int>(dist_x, dist_y);
}

QPair<int, int> strategy4(Ghost* ghost) {
    Personaje *jugador = ghost->game->jugador;
    int dist_x = jugador->get_x() - ghost->get_x();
    int dist_y = jugador->get_y() - ghost->get_y();
    if (dist_x * dist_x + dist_y * dist_y < 64) {
        dist_x = 2 - ghost->get_x();
        dist_y = 2 - ghost->get_y();
    }
    return QPair<int, int>(dist_x, dist_y);
}
