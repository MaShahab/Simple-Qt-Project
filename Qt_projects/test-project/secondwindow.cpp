#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <QPushButton>

secondwindow::secondwindow(QGraphicsView *parent) :
    QGraphicsView(parent),
    ui(new Ui::secondwindow)
{
    ui->setupUi(this);
    QGraphicsScene *s;
    s = new QGraphicsScene(this);
    this->setScene(s);
    // this->setBackgroundBrush(QBrush(Qt::red, Qt::SolidPattern));
    this->setStyleSheet("background-image : url('cars.png ')");

    int rc;
}

secondwindow::~secondwindow()
{
    delete ui;
}
