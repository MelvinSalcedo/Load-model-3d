#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <myglwidget.h>
#include <QMap>
#include <string>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int arrayTemporal[2];

    void ChangeScale(int value);
    void LoadModelsInGLWidget();
    void OcultarPrimerNivel();

    //SQL
    void CrearTablaUsuarios();
    void InsertarUsuario();
    void Mostrardatos();

    void modificarDatos(string tipoPersonaje, string tipoArmadura);

private slots:
    void on_actionOpen_Model_triggered(QString nombreOBJ, int numeroPersonaje);
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_equipar1_clicked();

    void on_equipar2_clicked();

    void on_equipart3_clicked();

    void on_reinicar_clicked();

private:
    Ui::MainWindow *ui;
    QMap<QString, QString> map_classify;

    MyGLWidget *glwidget;
    MyGLWidget *glwidget2;
    MyGLWidget *glwidget3;
    MyGLWidget *glwidget4;
    string name_object;


    //base de datos
    QSqlDatabase db;

};

#endif // MAINWINDOW_H
