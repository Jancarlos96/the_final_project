#include "juego.h"
#include "ui_juego.h"
#include <QMessageBox>

Juego::Juego(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Juego)
{
    ui->setupUi(this);
    mn=new View;
    setWindowTitle(tr("The media killer"));
    setWindowIcon(QPixmap(":/Sprite/game_objects/icon.jpg"));

    /* Initialize graphicsview and game scene */
    ui->graphicsView->setStyleSheet("QGraphicsView {border: none;}");// Bode
    ui->graphicsView->setBackgroundBrush(Qt::black); //Fondo del Mapa
    ui->graphicsView->setFocusPolicy(Qt::NoFocus);

    int map_height = 20, map_width = 29;            // 20x29 game map
    int x = 50, y = 50;                             // x y in mainwindow
    int w = (map_width * GameObject::Width);
    int h = (map_height * GameObject::Width);

    ui->graphicsView->setGeometry(x, y, w, h);
    game = new Game(x, y, map_width, map_height, ":/Sprite/game_objects/map.txt");
    ui->graphicsView->setScene(game);
    initLabels();
    game->start();
}


/* Initialize UI */
void Juego::initLabels()
{


    score_timer = new QTimer(this);
    score_timer->start(25);
    connect(score_timer, SIGNAL(timeout()), this , SLOT(update_score()));
}


/* Update score UI */
void Juego::update_score()
{

    if (game->stat == Game::Win) {
        mn->show();

        score_timer->stop();
    } else if (game->stat == Game::Lose) {
        msgBox.setWindowTitle("Juego terminado");
        msgBox.setWindowIcon(QPixmap(":/Sprite/game_objects/icon.jpg"));
        QPixmap iconPixmap(":/Sprite/game_objects/icon.jpg");
        iconPixmap = iconPixmap.scaled(64, 64);
        msgBox.setIconPixmap(iconPixmap);
        msgBox.setStandardButtons(QMessageBox::Yes);
        msgBox.addButton(QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::Yes);
        msgBox.setEscapeButton(QMessageBox::No);
        msgBox.setText("¡Perdiste! \n¿Volver a jugar?");
        if (QMessageBox::Yes == msgBox.exec()) {
            restartGame();  // Reiniciar el juego si se selecciona "Yes"
        } else {
            QCoreApplication::quit();  // Salir de la aplicación si se selecciona "No"
        }
        score_timer->stop();
    }
}


void Juego::keyPressEvent(QKeyEvent *e) {
    switch (e->key()) {
    case Qt::Key_W:
        game->next_direction(GameObject::Up);
        break;
    case Qt::Key_A:
        game->next_direction(GameObject::Left);
        break;
    case Qt::Key_S:
        game->next_direction(GameObject::Down);
        break;
    case Qt::Key_D:
        game->next_direction(GameObject::Right);
        break;
    }
}


void Juego::restartGame()
{
    game->stop(); // Detiene el juego actual

    // Elimina el juego actual y crea uno nuevo
    delete game;
    game = new Game(50, 50, 29, 20, ":/Sprite/game_objects/map.txt");
    ui->graphicsView->setScene(game);

    initLabels(); // Vuelve a inicializar las etiquetas de puntuación
    game->start(); // Inicia el nuevo juego
}




Juego::~Juego()
{
    delete ui;
    delete mn;
}

