#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "httprequestworker.h"

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
    void on_read_btn_clicked();

    void on_write_btn_clicked();

    void on_update_btn_clicked();

    void on_delete_btn_clicked();

    void on_pushButton_clicked();
    void handle_result(HttpRequestWorker *worker);

    void on_get_api_clicked();

    void on_post_api_clicked();

    void on_put_api_clicked();

    void on_del_api_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
