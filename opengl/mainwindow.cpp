#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <QPixmap>
#include <QSlider>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    //****************************
    ui->pushButton->setVisible(false);
    ui->pushButton_2->setVisible(false);
    ui->pushButton_3->setVisible(false);

    ui->Widget3D1->setVisible(false);
    ui->Widget3D2->setVisible(false);
    ui->Widget3D3->setVisible(false);

    ui->Widget3D1_2->setVisible(false);

    ui->equipar1->setVisible(false);
    ui->equipar2->setVisible(false);
    ui->equipart3->setVisible(false);
    //****************************


    glwidget  = new MyGLWidget(ui->Widget3D1);
    glwidget2 = new MyGLWidget(ui->Widget3D2);
    glwidget3 = new MyGLWidget(ui->Widget3D3);

    ///////////////////////////////////////////////
    glwidget4 = new MyGLWidget(ui->Widget3D1_2);


    glwidget2->ChangeScale(25);



    name_object = "data/Male.obj";


    glwidget->loadmodel(name_object);
    glwidget2->loadmodel(name_object);
    glwidget3->loadmodel(name_object);

    ui->namefile1->setText(QString::fromStdString(name_object));
    ui->namefile2->setText(QString::fromStdString(name_object));

    QString fileName =QString::fromStdString(name_object);
    QStringList list = fileName.split("/");

    ui->namefile1->setText(list.last());
    ui->namefile2->setText(list.last());



    //QObject::connect(ui->scaleSlider, &QSlider::valueChanged, this, &MainWindow::ChangeScale);

    //base de datos
    QString nombre;
    nombre.append("BaseDatos.sqlite");
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(nombre);
    //db.open();
    if(db.open()){
       qDebug() <<"base de datos conectada";
    }
    else{
        qDebug() <<"NO CONECCION";
    }
    CrearTablaUsuarios();
    //InsertarUsuario();
    Mostrardatos();

}

void MainWindow::CrearTablaUsuarios(){
       QString consulta;

       consulta.append("CREATE TABLE IF NOT EXISTS usuario("
                       "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                       "nombre VARCHAR(100),"
                       "clasePersonaje INTEGER NOT NULL,"
                       "tipoArmadura INTEGER NOT NULL"
                       ");");
       QSqlQuery crear;
       crear.prepare(consulta);

       if(crear.exec()){
          qDebug() <<"TABLA CREADA";
       }
       else{
           qDebug() <<"ERROR "<<crear.lastError();
       }

}

void MainWindow::InsertarUsuario()
{
    QString consulta;

    consulta.append("INSERT INTO usuario("
                    "nombre,"
                    "clasePersonaje,"
                    "tipoArmadura)"
                    "VALUES("
                    "'uno',"
                    "0,"
                    "0"
                    ");");
    //"'"+ui->lineditTexy->Text()+"'"
    QSqlQuery insertar;
    insertar.prepare(consulta);

    if(insertar.exec()){
       qDebug() <<"USUARIO INSERTADO";
    }
    else{
        qDebug() <<"ERROR "<<insertar.lastError();
    }
}

void  MainWindow::Mostrardatos()
{
    QString qstring;

    qstring.append("SELECT * FROM usuario");

    QSqlQuery consulta;
    consulta.prepare(qstring);

    if(consulta.exec()){
       qDebug() <<"CONSULTA";
    }
    else{
        qDebug() <<"ERROR DE CONSULTA "<<consulta.lastError();
    }

    while(consulta.next()) {

         QString tipoPersonaje = consulta.value(0).toByteArray();
         QString nombre = consulta.value(1).toString();
         int TipoPersonaje = consulta.value(2).toInt();
         int TipoArmadura = consulta.value(3).toInt();
         qDebug() << tipoPersonaje << nombre << TipoPersonaje<< TipoArmadura<<endl;
         if(nombre=="uno"){
             arrayTemporal[0]=TipoPersonaje;
             arrayTemporal[1]=TipoArmadura;
         }
     }

}

void MainWindow::modificarDatos(string tipoPersonaje,string tipoArmadura){
    QString qstring,qstring2;
    string tem=string("UPDATE usuario SET clasePersonaje=")+tipoPersonaje+string(" WHERE id=1");
    string tem2=string("UPDATE usuario SET tipoArmadura="  )+tipoArmadura+string( " WHERE id=1");
    qstring.append(QString::fromStdString(tem));
    qstring2.append(QString::fromStdString(tem2));

    QSqlQuery update;
    QSqlQuery update1;
    update.prepare(qstring);
    update1.prepare(qstring2);

    if(update.exec()){
        update1.exec();
       qDebug() <<"DATOS ACTUALIZADOS";
       Mostrardatos();
    }
    else{
        qDebug() <<"ERROR DE CONSULTA "<<update.lastError();
    }
}

MainWindow::~MainWindow(){
    delete ui;

}

void MainWindow::on_actionOpen_Model_triggered(QString nombreOBJ,int numeroPersonaje){
    //qDebug() << "OPENING MODEL 3D";
    QString fileName = nombreOBJ;//"yoshi1.obj";//QFileDialog::getOpenFileName(this, tr("Open File"), QString(),tr("Obj Files (*.obj);;"));
    //qDebug() <<"-......- " + fileName;
    QStringList list = fileName.split("/");
    ui->namefile1->setText(list.last());

    if(numeroPersonaje==1){
        glwidget->loadmodel(fileName.toStdString());
    }else if(numeroPersonaje==2){
        //glwidget2->ChangeScale(8);
        glwidget2->loadmodel(fileName.toStdString());
    }
    else if(numeroPersonaje==3){
        glwidget3->loadmodel(fileName.toStdString());
    }
    else{
        glwidget4->loadmodel(fileName.toStdString());
    }

    name_object = fileName.toStdString();
}

//cambiar escala del modelo 3d
void MainWindow::ChangeScale(int value){
    //qDebug() << "CHANGE SCALE "<<value;
    glwidget->ChangeScale(value);
    //ui->btn_classify->setEnabled(false);
}


void MainWindow::LoadModelsInGLWidget(){

        on_actionOpen_Model_triggered("yoshi1.obj",1);
        on_actionOpen_Model_triggered("teddy.obj",2);
        on_actionOpen_Model_triggered("Mario2.obj",3);
}

void MainWindow::on_pushButton_clicked(){

    modificarDatos("1","100");
    qDebug() <<"********";
    on_actionOpen_Model_triggered("yoshi1.obj",4);
    OcultarPrimerNivel();
}

void MainWindow::on_pushButton_2_clicked(){
    modificarDatos("2","100");
    on_actionOpen_Model_triggered("teddy.obj",4);
    OcultarPrimerNivel();
}


void MainWindow::on_pushButton_3_clicked(){
    modificarDatos("3","100");
    on_actionOpen_Model_triggered("Mario2.obj",4);
    OcultarPrimerNivel();
}

void MainWindow::OcultarPrimerNivel(){

    ui->pushButton->setVisible(false);
    ui->pushButton_2->setVisible(false);
    ui->pushButton_3->setVisible(false);
    ui->namefile1->setVisible(false);
    ui->namefile2->setVisible(false);
    ui->namefile3->setVisible(false);
    ui->Widget3D1->setVisible(false);
    ui->Widget3D2->setVisible(false);
    ui->Widget3D3->setVisible(false);
    ui->Widget3D1_2->setVisible(true);

    QPixmap pix(":/Resources/a.png");
    ui->label1->setPixmap(pix);
    QPixmap pix2(":/Resources/b.png");
    ui->label2->setPixmap(pix2);

    QPixmap pix3(":/Resources/c.png");
    ui->label3->setPixmap(pix3);
    //botones de equpar objeto0s

    ui->equipar1->setVisible(true);
    ui->equipar2->setVisible(true);
    ui->equipart3->setVisible(true);
}

void MainWindow::on_pushButton_4_clicked(){
    if(arrayTemporal[0]==0 && arrayTemporal[1]==0){
        LoadModelsInGLWidget();
        ui->pushButton->setVisible(true);
        ui->pushButton_2->setVisible(true);
        ui->pushButton_3->setVisible(true);
        ui->Widget3D1->setVisible(true);
        ui->Widget3D2->setVisible(true);
        ui->Widget3D3->setVisible(true);

        ui->pushButton_4->setVisible(false);
    }
    else {
        OcultarPrimerNivel();
        if(arrayTemporal[1]==1){
            on_actionOpen_Model_triggered("arma1.obj",4);
        }
        if(arrayTemporal[1]==2){
            on_actionOpen_Model_triggered("arma2.obj",4);
        }
        if(arrayTemporal[1]==3){
            on_actionOpen_Model_triggered("arma3.obj",4);
        }
    }


}

void MainWindow::on_equipar1_clicked()
{
        qDebug() <<"----- "<<arrayTemporal[0];

        string s = std::to_string(arrayTemporal[0]);
        modificarDatos(s,"1");
        if(arrayTemporal[0]==1){
            on_actionOpen_Model_triggered("arma1.obj",4);
        }
        if(arrayTemporal[0]==2){
            on_actionOpen_Model_triggered("teddy.obj",4);
        }
        if(arrayTemporal[0]==3){
            on_actionOpen_Model_triggered("Mario2.obj",4);
        }
}

void MainWindow::on_equipar2_clicked()
{
    string s = std::to_string(arrayTemporal[0]);
    modificarDatos(s,"2");
    if(arrayTemporal[0]==1){
        on_actionOpen_Model_triggered("arma2.obj",4);
    }
    if(arrayTemporal[0]==2){
        on_actionOpen_Model_triggered("teddy.obj",4);
    }
    if(arrayTemporal[0]==3){
        on_actionOpen_Model_triggered("Mario2.obj",4);
    }

}

void MainWindow::on_equipart3_clicked()
{
    string s = std::to_string(arrayTemporal[0]);
    modificarDatos(s,"3");

    if(arrayTemporal[0]==1){
        on_actionOpen_Model_triggered("arma3.obj",4);
    }
    if(arrayTemporal[0]==2){
        on_actionOpen_Model_triggered("teddy.obj",4);
    }
    if(arrayTemporal[0]==3){
        on_actionOpen_Model_triggered("Mario2.obj",4);
    }
}

void MainWindow::on_reinicar_clicked()
{
    modificarDatos("0","0");
}
