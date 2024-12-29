#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QLineEdit"

#include <QPushButton>
#include <QLabel>
#include "secondwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleButton();
    void myRadioListener();

    // void on_actionopen_file_triggered();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    QPushButton *button1 = new QPushButton("One");
    QLabel *my_label = new QLabel();
};
#endif // MAINWINDOW_H
