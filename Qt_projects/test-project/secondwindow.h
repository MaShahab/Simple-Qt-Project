#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QWidget>
#include <QGraphicsView>


namespace Ui {
class secondwindow;
}

class secondwindow : public QGraphicsView
{
    Q_OBJECT

public:
    explicit secondwindow(QGraphicsView *parent = nullptr);
    ~secondwindow();

private:
    Ui::secondwindow *ui;
};

#endif // SECONDWINDOW_H
