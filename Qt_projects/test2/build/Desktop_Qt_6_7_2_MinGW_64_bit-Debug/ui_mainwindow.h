/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableView *tableView;
    QPushButton *read_btn;
    QPushButton *write_btn;
    QPushButton *update_btn;
    QPushButton *delete_btn;
    QPushButton *pushButton;
    QPushButton *post_api;
    QPushButton *put_api;
    QPushButton *del_api;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(90, 120, 411, 261));
        read_btn = new QPushButton(centralwidget);
        read_btn->setObjectName("read_btn");
        read_btn->setGeometry(QRect(570, 80, 141, 51));
        write_btn = new QPushButton(centralwidget);
        write_btn->setObjectName("write_btn");
        write_btn->setGeometry(QRect(570, 170, 141, 51));
        update_btn = new QPushButton(centralwidget);
        update_btn->setObjectName("update_btn");
        update_btn->setGeometry(QRect(570, 260, 141, 51));
        delete_btn = new QPushButton(centralwidget);
        delete_btn->setObjectName("delete_btn");
        delete_btn->setGeometry(QRect(570, 360, 141, 51));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 460, 171, 51));
        post_api = new QPushButton(centralwidget);
        post_api->setObjectName("post_api");
        post_api->setGeometry(QRect(210, 460, 171, 51));
        put_api = new QPushButton(centralwidget);
        put_api->setObjectName("put_api");
        put_api->setGeometry(QRect(400, 460, 171, 51));
        del_api = new QPushButton(centralwidget);
        del_api->setObjectName("del_api");
        del_api->setGeometry(QRect(590, 460, 171, 51));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        read_btn->setText(QCoreApplication::translate("MainWindow", "Read", nullptr));
        write_btn->setText(QCoreApplication::translate("MainWindow", "Write", nullptr));
        update_btn->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
        delete_btn->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Call api (GET)", nullptr));
        post_api->setText(QCoreApplication::translate("MainWindow", "Call api (POST)", nullptr));
        put_api->setText(QCoreApplication::translate("MainWindow", "Call api (PUT)", nullptr));
        del_api->setText(QCoreApplication::translate("MainWindow", "Call api (DEL)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
