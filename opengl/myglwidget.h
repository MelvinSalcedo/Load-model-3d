// myglwidget.h

#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>
#include <model3d.h>
#include <iostream>
#include <QDebug>
#include <QGLWidget>
#include <iostream>
#include <QDebug>
#include <QTimer>
#include <iostream>
using namespace std;


class MyGLWidget : public QGLWidget
{

    Q_OBJECT
public:
    explicit MyGLWidget(QWidget *parent = 0);
    ~MyGLWidget();
signals:

public slots:

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

public slots:
    // slots for xyz-rotation slider
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);



signals:
    // signaling rotation from mouse movement
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);

public:
    QTimer time;
    string path_obj;
    void loadmodel(string path);
    void ChangeScale(float value);


private:
    obj3dmodel obj3D;
    void draw();
    int xRot;
    int yRot;
    int zRot;

    float scale_val;

    float origin_x;
    float origin_y;
    float origin_z;

    QPoint lastPos;

    QColor     BackGround_Color;                   // Color of the background
    QColor     Axis_X_Color;                       // X axis's color
    QColor     Axis_Y_Color;                       // Y axis's color
    QColor     Axis_Z_Color;                       // Z axis's color
    //QColor     Points_Color;                       // Z axis's color
};

#endif // MYGLWIDGET_H

