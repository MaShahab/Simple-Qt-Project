#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlQueryModel>

#include <QPushButton>

#include <qdebug.h>


#include <QNetworkReply>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:\\Users\\mah\\Desktop\\my_db.db");
    db.open();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_read_btn_clicked()
{
    QSqlQuery q;
    q.exec("SELECT * FROM persons");
    QSqlQueryModel *m = new QSqlQueryModel;
    m->setQuery(q);
    qDebug() << m->data(m->index(1,1)).toString();
    ui->tableView->setModel(m);

}


void MainWindow::on_write_btn_clicked()
{
    qDebug() << "writing ... ";
    QSqlQuery q;
    q.exec("INSERT INTO persons(name) VALUES ('saman')");
}


void MainWindow::on_update_btn_clicked()
{
    QSqlQuery q;
    // q.exec("UPDATE persons SET name = reza, column2 = value2...., columnN = valueN WHERE [condition];");
    q.exec("UPDATE persons SET name = 'reza' WHERE id = 1");
}



void MainWindow::on_delete_btn_clicked()
{
    QSqlQuery q;
    q.exec("DELETE FROM persons WHERE id = 7");
}


void MainWindow::on_pushButton_clicked()
{
    QNetworkAccessManager Manager;

    QByteArray dataPayload = "{\"ip\":\"1.1.1.1\"}";
    QByteArray dataSize = QByteArray::number(dataPayload.size());

    QUrl APIurl("http://195.248.242.169/api/white_ip");
    QNetworkRequest request(APIurl);

    request.setRawHeader("Authorization", "Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ0b2tlbl90eXBlIjoiYWNjZXNzIiwiZXhwIjoxNzI4MTIwMTg1LCJpYXQiOjE3MjgxMTk4ODUsImp0aSI6IjMyNDFkMWYyZWQ1ODQwNDRhMTBmMTAzOWUwZTQzOTk4IiwidXNlcl9pZCI6MX0.lN3X0AffQF3dfi-dgyEAG82XmE3ZGtd0GzO8wa-UBOU");
    request.setRawHeader("User-Agent", "My app name v0.1");
    request.setRawHeader("X-Custom-User-Agent", "My app name v0.1");
    request.setRawHeader("Content-Type", "application/json");
    request.setRawHeader("Content-Length", dataSize);

    QNetworkReply * reply = Manager.get(request, dataPayload);
    // QNetworkReply* reply = Manager.put(request, someData);
    // QNetworkReply *reply = Manager.get(request);


    QEventLoop *loop;
    loop = new QEventLoop;
    connect(reply, &QNetworkReply::finished, loop, &QEventLoop::quit);
    loop->exec();

    if (reply->error() == QNetworkReply::NoError)
    {
        qDebug() << "Error : " << reply->errorString();
        QString Response = reply->readAll();
        qDebug() << "Api Response : " << Response;
    }
    else{
        qDebug() << "Error : " << reply->errorString();
    }
}

void MainWindow::on_post_api_clicked()
{
    QNetworkAccessManager Manager;

    QByteArray jsonString = "{\"ip\":\"1.1.1.1\"}";
    QByteArray postDataSize = QByteArray::number(jsonString.size());

    QUrl APIurl("http://195.248.242.169/api/white_ip");
    QNetworkRequest request(APIurl);

    request.setRawHeader("Authorization", "Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ0b2tlbl90eXBlIjoiYWNjZXNzIiwiZXhwIjoxNzI4MTEwNjMxLCJpYXQiOjE3MjgxMTAzMzEsImp0aSI6IjdmYzFkYWZmNDgyOTRiMDRiNTg5MTdhYWFkMGQwYTM0IiwidXNlcl9pZCI6MX0.r4jKg6cyQnb_prTrgN-9Uhf2-_JILNmmG-AfWzEWiro");
    request.setRawHeader("User-Agent", "My app name v0.1");
    request.setRawHeader("X-Custom-User-Agent", "My app name v0.1");
    request.setRawHeader("Content-Type", "application/json");
    request.setRawHeader("Content-Length", postDataSize);

    QNetworkReply * reply = Manager.post(request, jsonString);
    // QNetworkReply* reply = Manager.put(request, someData);
    // QNetworkReply *reply = Manager.get(request);


    QEventLoop *loop;
    loop = new QEventLoop;
    connect(reply, &QNetworkReply::finished, loop, &QEventLoop::quit);
    loop->exec();

    if (reply->error() == QNetworkReply::NoError)
    {
        qDebug() << "Error : " << reply->errorString();
        QString Response = reply->readAll();
        qDebug() << "Api Response : " << Response;
    }
    else{
        qDebug() << "Error : " << reply->errorString();
    }
}


void MainWindow::on_put_api_clicked()
{
    QNetworkAccessManager Manager;

    QByteArray jsonString = "{\"id\":\"5\",\"ip\":\"8.8.8.8\"}";
    QByteArray postDataSize = QByteArray::number(jsonString.size());

    QUrl APIurl("http://195.248.242.169/api/white_ip");
    QNetworkRequest request(APIurl);

    request.setRawHeader("Authorization", "Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ0b2tlbl90eXBlIjoiYWNjZXNzIiwiZXhwIjoxNzI4MTEwNjMxLCJpYXQiOjE3MjgxMTAzMzEsImp0aSI6IjdmYzFkYWZmNDgyOTRiMDRiNTg5MTdhYWFkMGQwYTM0IiwidXNlcl9pZCI6MX0.r4jKg6cyQnb_prTrgN-9Uhf2-_JILNmmG-AfWzEWiro");
    request.setRawHeader("User-Agent", "My app name v0.1");
    request.setRawHeader("X-Custom-User-Agent", "My app name v0.1");
    request.setRawHeader("Content-Type", "application/json");
    request.setRawHeader("Content-Length", postDataSize);

    QNetworkReply * reply = Manager.put(request, jsonString);
    // QNetworkReply* reply = Manager.put(request, someData);
    // QNetworkReply *reply = Manager.get(request);


    QEventLoop *loop;
    loop = new QEventLoop;
    connect(reply, &QNetworkReply::finished, loop, &QEventLoop::quit);
    loop->exec();

    if (reply->error() == QNetworkReply::NoError)
    {
        qDebug() << "Error : " << reply->errorString();
        QString Response = reply->readAll();
        qDebug() << "Api Response : " << Response;
    }
    else{
        qDebug() << "Error : " << reply->errorString();
    }
}





void MainWindow::on_del_api_clicked()
{
    QNetworkAccessManager Manager;

    QByteArray jsonString = "{\"id\":\"2\"}";
    QByteArray postDataSize = QByteArray::number(jsonString.size());

    QUrl APIurl("http://195.248.242.169/api/white_ip");
    QNetworkRequest request(APIurl);

    request.setRawHeader("Authorization", "Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ0b2tlbl90eXBlIjoiYWNjZXNzIiwiZXhwIjoxNzI4MTE0OTU3LCJpYXQiOjE3MjgxMTQ2NTcsImp0aSI6IjRiMjQ5ZWY1MzU5NDQyNjM4OTBhNGNjMDQwMTUyMjRiIiwidXNlcl9pZCI6MX0.GW0DhhJff9DG76ScqrYashQGiJxOh5N8jhmZOfkxM-E");
    request.setRawHeader("User-Agent", "My app name v0.1");
    request.setRawHeader("X-Custom-User-Agent", "My app name v0.1");
    request.setRawHeader("Content-Type", "application/json");
    request.setRawHeader("Content-Length", postDataSize);

    QNetworkReply * reply = Manager.sendCustomRequest(request, "DELETE" , jsonString);
    // QNetworkReply* reply = Manager.put(request, someData);
    // QNetworkReply *reply = Manager.get(request);


    QEventLoop *loop;
    loop = new QEventLoop;
    connect(reply, &QNetworkReply::finished, loop, &QEventLoop::quit);
    loop->exec();

    if (reply->error() == QNetworkReply::NoError)
    {
        qDebug() << "Error : " << reply->errorString();
        QString Response = reply->readAll();
        qDebug() << "Api Response : " << Response;
    }
    else{
        qDebug() << "Error : " << reply->errorString();
    }
}

