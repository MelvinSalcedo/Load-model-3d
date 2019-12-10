#ifndef MODEL3D_H
#define MODEL3D_H

#include <QGLWidget>
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include <string>
#include <stdio.h>
#include <string.h>
#include <cstdlib>

#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>


#include <QOpenGLWidget>
#include <QOpenGLFunctions>

#include <QGLFramebufferObjectFormat>


#include <iostream>

using namespace std;

class obj3dmodel : public QGLWidget
{
   class vertex{
   public:
        float x;
        float y;
        float z;
   };
   class face{
   public:
         unsigned int v1,v2,v3;
   };


public:
   explicit obj3dmodel(QWidget *parent = 0);

  void readfile(string filename);
  void readfile2(string filename);
  void draw();
  std::vector<vertex> vetexes;
  std::vector<face> faces;
};


#endif // MODEL3D_H
