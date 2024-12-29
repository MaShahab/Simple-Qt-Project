#include "mainwindow.h"
#include <QApplication>
#include <qdebug.h>

#include <QPushButton>

// #include <QCoreApplication>
#include <QtCore>

#include "person.h"
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Hello World");
    qDebug() << "Hello there!";
    // w.show();

    person p1;
    p1.name = "ali";
    p1.age = 29;

    qDebug() << p1.age;

    // btn1.show();

    return a.exec();
}
