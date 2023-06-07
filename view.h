#ifndef VIEW_H
#define VIEW_H

#define window_x_size 1366
#define window_y_size 756
#define graphics_offset_x 0
#define graphics_offset_y 48

#include "play.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class View; }
QT_END_NAMESPACE

class View : public QMainWindow
{
    Q_OBJECT

public:
    View(QWidget *parent = nullptr);
    ~View();
private:
    void set_window_size();
    void set_graphiscview_size();
    Ui::View *ui;
    Play *Escenario;

};
#endif // VIEW_H
