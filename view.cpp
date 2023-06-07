#include "view.h"
#include "ui_view.h"

View::View(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::View)
{
    ui->setupUi(this);
    srand(time(NULL));
    Escenario = new Play;
    setGeometry(0, 0, window_x_size, window_y_size);
    ui->graphicsView->setGeometry(0, 0, window_x_size, window_y_size);
    Escenario->setSceneRect(0, 0, ui->graphicsView->width() - 2, ui->graphicsView->height() - 2);
    ui->graphicsView->setScene(Escenario);
    setWindowTitle("minijuego");
    setWindowIcon(QPixmap(":/Sprite/images/ganador.png"));

}

View::~View()
{
    delete ui;
    delete Escenario;
}

void View::set_window_size()
{
    setMinimumSize(window_x_size, window_y_size);
    setMaximumSize(window_x_size, window_y_size);
}

void View::set_graphiscview_size()
{
    ui->graphicsView->setGeometry(graphics_offset_x, graphics_offset_y,
                                  window_x_size - graphics_offset_x,
                                  window_y_size - graphics_offset_y);
}

