/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "myglwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *namefile1;
    MyGLWidget *Widget3D1;
    QPushButton *pushButton;
    MyGLWidget *Widget3D2;
    QPushButton *pushButton_2;
    QLabel *namefile2;
    MyGLWidget *Widget3D3;
    QLabel *namefile3;
    QPushButton *pushButton_3;
    MyGLWidget *Widget3D1_2;
    QPushButton *pushButton_4;
    QLabel *label2;
    QLabel *label1;
    QPushButton *equipar1;
    QPushButton *equipar2;
    QPushButton *equipart3;
    QLabel *label3;
    QPushButton *reinicar;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1274, 829);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        namefile1 = new QLabel(centralWidget);
        namefile1->setObjectName(QString::fromUtf8("namefile1"));
        namefile1->setGeometry(QRect(90, 10, 161, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Mono"));
        font.setPointSize(14);
        font.setBold(false);
        font.setWeight(50);
        namefile1->setFont(font);
        Widget3D1 = new MyGLWidget(centralWidget);
        Widget3D1->setObjectName(QString::fromUtf8("Widget3D1"));
        Widget3D1->setGeometry(QRect(10, 40, 401, 361));
        Widget3D1->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(0, 0, 0);"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 440, 93, 28));
        Widget3D2 = new MyGLWidget(centralWidget);
        Widget3D2->setObjectName(QString::fromUtf8("Widget3D2"));
        Widget3D2->setGeometry(QRect(430, 40, 401, 361));
        Widget3D2->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(0, 0, 0);"));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(590, 430, 93, 28));
        namefile2 = new QLabel(centralWidget);
        namefile2->setObjectName(QString::fromUtf8("namefile2"));
        namefile2->setGeometry(QRect(490, 10, 161, 20));
        namefile2->setFont(font);
        Widget3D3 = new MyGLWidget(centralWidget);
        Widget3D3->setObjectName(QString::fromUtf8("Widget3D3"));
        Widget3D3->setGeometry(QRect(840, 40, 401, 361));
        Widget3D3->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(0, 0, 0);"));
        namefile3 = new QLabel(centralWidget);
        namefile3->setObjectName(QString::fromUtf8("namefile3"));
        namefile3->setGeometry(QRect(940, 10, 161, 20));
        namefile3->setFont(font);
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(1010, 430, 93, 28));
        Widget3D1_2 = new MyGLWidget(centralWidget);
        Widget3D1_2->setObjectName(QString::fromUtf8("Widget3D1_2"));
        Widget3D1_2->setGeometry(QRect(10, 120, 471, 451));
        Widget3D1_2->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(0, 0, 0);"));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(510, 680, 241, 71));
        QFont font1;
        font1.setPointSize(15);
        pushButton_4->setFont(font1);
        label2 = new QLabel(centralWidget);
        label2->setObjectName(QString::fromUtf8("label2"));
        label2->setGeometry(QRect(770, 440, 150, 150));
        label1 = new QLabel(centralWidget);
        label1->setObjectName(QString::fromUtf8("label1"));
        label1->setGeometry(QRect(550, 440, 150, 150));
        equipar1 = new QPushButton(centralWidget);
        equipar1->setObjectName(QString::fromUtf8("equipar1"));
        equipar1->setGeometry(QRect(580, 600, 93, 28));
        equipar2 = new QPushButton(centralWidget);
        equipar2->setObjectName(QString::fromUtf8("equipar2"));
        equipar2->setGeometry(QRect(810, 600, 93, 28));
        equipart3 = new QPushButton(centralWidget);
        equipart3->setObjectName(QString::fromUtf8("equipart3"));
        equipart3->setGeometry(QRect(1050, 610, 93, 28));
        label3 = new QLabel(centralWidget);
        label3->setObjectName(QString::fromUtf8("label3"));
        label3->setGeometry(QRect(1020, 450, 150, 150));
        reinicar = new QPushButton(centralWidget);
        reinicar->setObjectName(QString::fromUtf8("reinicar"));
        reinicar->setGeometry(QRect(950, 730, 321, 31));
        reinicar->setFont(font1);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1274, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        namefile1->setText(QCoreApplication::translate("MainWindow", "NameObject", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Selecionar", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Selecionar", nullptr));
        namefile2->setText(QCoreApplication::translate("MainWindow", "NameObject", nullptr));
        namefile3->setText(QCoreApplication::translate("MainWindow", "NameObject", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Selecionar", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "CARGAR", nullptr));
        label2->setText(QString());
        label1->setText(QString());
        equipar1->setText(QCoreApplication::translate("MainWindow", "equipar", nullptr));
        equipar2->setText(QCoreApplication::translate("MainWindow", "equipar", nullptr));
        equipart3->setText(QCoreApplication::translate("MainWindow", "Equipar", nullptr));
        label3->setText(QString());
        reinicar->setText(QCoreApplication::translate("MainWindow", "reiniciar base de datos", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
