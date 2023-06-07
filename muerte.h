#ifndef MUERTE_H
#define MUERTE_H
#include <QWidget>
namespace Ui {
class muerte;
}

class muerte : public QWidget
{
    Q_OBJECT

public:
    explicit muerte(QWidget *parent = nullptr);
    ~muerte();

private:
    Ui::muerte *ui;
};

#endif // MUERTE_H
