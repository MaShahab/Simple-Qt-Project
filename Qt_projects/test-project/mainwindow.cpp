#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QAction>
#include <QBrush>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QLabel>
#include <QMap>
#include <QMenu>
#include <QPen>
#include <QPushButton>
#include <qdebug.h>
#include <QStackedWidget>

#include "secondwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    QWidget *window = new QWidget;
    // QPushButton *button1 = new QPushButton("One");
    QPushButton *button2 = new QPushButton("Two");
    QPushButton *button3 = new QPushButton("Three");
    QPushButton *button4 = new QPushButton("Four");
    QPushButton *button5 = new QPushButton("Five");

    my_label->setText("Hello");

    QHBoxLayout *layout = new QHBoxLayout(window);
    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->addWidget(button3);
    layout->addWidget(button4);
    layout->addWidget(button5);
    layout->addWidget(my_label);

    QMenu *my_menu;
    QAction *open_act;
    QAction *save_act;
    QAction *exit_act;

    my_menu = menuBar()->addMenu("ssssssss");
    open_act = new QAction("open", this);
    save_act = new QAction("save", this);
    exit_act = new QAction("exit", this);

    my_menu->addAction(open_act);
    my_menu->addAction(save_act);
    my_menu->addAction(exit_act);

    window->show();

    connect(button1, &QPushButton::clicked, this, &MainWindow::handleButton);
    connect(button5, &QPushButton::clicked, this, &MainWindow::on_pushButton_6_clicked);
    connect(ui->rad1, &QRadioButton::clicked, this, &MainWindow::myRadioListener);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::on_pushButton_6_clicked);

    QMap<QString, QString> my_map;

    my_map["iran"] = "tehran";
    my_map["united states"] = "washington";
    my_map["germany"] = "berlin";

    QMap<QString, QString>::const_iterator i;
    for (i = my_map.constBegin(); i != my_map.constEnd(); i++) {
        qDebug() << i.key() << ":" << i.value();
    }

    QGraphicsScene *s;
    s = new QGraphicsScene(this);
    ui->graphicsView->setScene(s);
    QBrush b(Qt::green);
    QPen p(Qt::black);

    QGraphicsRectItem *rect;
    rect = s->addRect(20, 20, 100, 50, p, b);

    rect->setFlag(QGraphicsItem::ItemIsMovable);
}



void MainWindow::handleButton() {
    qDebug() << "salam";
    qDebug() << my_label->text();

    // qDebug() << my_line_edit->text();
    // my_btn->setText("Example");
    // my_btn->resize(100,100);
}

void MainWindow::on_pushButton_6_clicked()
{
    // window->hide();
    secondwindow *my_second_window = new secondwindow();
    my_second_window->setWindowTitle("mypl");
    my_second_window->show();
}

void MainWindow::myRadioListener() { qDebug() << "radio clicked"; }

MainWindow::~MainWindow() { delete ui; }

