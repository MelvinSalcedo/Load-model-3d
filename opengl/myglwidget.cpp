// myglwidget.cpp

#include <QtWidgets>
#include <QtOpenGL>

#include "myglwidget.h"

MyGLWidget::MyGLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    connect(&time,SIGNAL(timeout()),this,SLOT(updateGL()));
    time.start(16);
    xRot = 0;
    yRot = 0;
    zRot = 0;

    //xRot = -1060;
    //yRot = 0;
    //zRot = -2900;

    origin_x = 0;
    origin_y = 0;
    origin_z = 0;
    //scale_val = 1;
    scale_val = 1;//(50.0/100.0*(50.0/10.0));

}

MyGLWidget::~MyGLWidget(){
    BackGround_Color    =QColor::fromRgb(0 ,0 ,0);
    Axis_X_Color        =QColor::fromRgb(255,64  ,64  ,128);   // Color of the X axis : red
    Axis_Y_Color        =QColor::fromRgb(64  ,255,64  ,128);   // Color of the Y axis : green
    Axis_Z_Color        =QColor::fromRgb(64  , 64 ,255,128);  // Color of the Z axis : blue

}

QSize MyGLWidget::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize MyGLWidget::sizeHint() const
{
    return QSize(400, 400);
}

static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360)
        angle -= 360 * 16;
}


void MyGLWidget::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != xRot) {
        xRot = angle;
        updateGL();
    }
}

void MyGLWidget::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != yRot) {
        yRot = angle;
        updateGL();
    }
}

void MyGLWidget::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != zRot) {
        zRot = angle;
        updateGL();
    }
}


void MyGLWidget::initializeGL(){
    qglClearColor(Qt::black);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);


    static GLfloat lightPosition[4] = { origin_x, origin_y, origin_z+10, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
        //glTranslatef(origin_x,origin_y+1,origin_z-10);
}



//refresca constantemente
void MyGLWidget::paintGL(){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        //glColor3f(1,0.6,0);
        glTranslatef(origin_x,origin_y,origin_z-10);

        glRotated(xRot / 16.0, 1.0, 0.0, 0.0);
        glRotated(yRot / 16.0, 0.0, 1.0, 0.0);
        glRotated(zRot / 16.0, 0.0, 0.0, 1.0);
        yRot+=5;
        glDisable(GL_LIGHTING);
        glScalef(scale_val,scale_val,scale_val);
        draw();
        glEnable(GL_LIGHTING);

}

void MyGLWidget::resizeGL(int width, int height)
{


    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-2, +2, -2, +2, 1.0, 15.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void MyGLWidget::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();
    if (event->buttons() & Qt::LeftButton) {
        setXRotation(xRot + 8 * dy);
        setYRotation(yRot + 8 * dx);
    } else if (event->buttons() & Qt::RightButton) {
        setXRotation(xRot + 8 * dy);
        setZRotation(zRot + 8 * dx);
    }
    lastPos = event->pos();
}


void MyGLWidget::loadmodel(string path){

    //clean before object
    obj3D.vetexes.clear();
    obj3D.faces.clear();
    obj3D.readfile(path);
    obj3D.draw();
    updateGL();
}

void MyGLWidget::ChangeScale(float value){

    scale_val =(value/100*(value/10));
    qDebug()<<"SCALE "<<scale_val;
    updateGL();
}


void MyGLWidget::draw(){
    //obj3D.readfile(this->path_obj.c_str());
    obj3D.draw();
}
