#include "model3d.h"
obj3dmodel::obj3dmodel(QWidget *parent) :QGLWidget(parent)
{
}


//vector<string>
string mysplit(string sv1){
    string pv1;
    for(int i=0; i<sv1.length(); i++){
        if(sv1[i]!='/'){
            pv1 += sv1[i];
        }
        else
            break;
    }
    return pv1;
}





void obj3dmodel::readfile(string filename){
    QString myfile = QString::fromStdString(filename);
    QFile file(myfile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        //qDebug()<< line;
        QStringList l2 = line.split(' ', QString::KeepEmptyParts);
        //line.split
        //qDebug()<< l2;
        if (l2[0]== "v"){
            vertex v;
            v.x = l2[1].toFloat();
            v.y = l2[2].toFloat();
            v.z = l2[3].toFloat();
            //printf("%f %f %f",v.x,v.y,v.z);
            this->vetexes.push_back(v);
        }else if ( l2[0]=="f"){
            face f;
            f.v1 = l2[1].toFloat();
            f.v2 = l2[2].toFloat();
            f.v3 = l2[3].toFloat();
            faces.push_back(f);
        }
    }
    file.close();
}

void obj3dmodel::draw(){
   glBegin(GL_TRIANGLES);
   for(int i=0;i<faces.size();i++){
       if(i%2==0){
              qglColor(Qt::blue);
       }
       else{
              qglColor(Qt::gray);
       }

      vertex v1= vetexes[faces[i].v1-1];
      vertex v2=vetexes[faces[i].v2-1];
      vertex v3=vetexes[faces[i].v3-1];

      glNormal3f(0.0f, 1.0f, 1.0f);
      glVertex3f(v1.x,v1.y,v1.z);
      //glNormal3f(v2.x,v2.y,v2.z);
      glNormal3f(0.0f, 1.0f, 1.0f);
      glVertex3f(v2.x,v2.y,v2.z);
      glNormal3f(0.0f, 1.0f, 1.0f);
      //glNormal3f(v3.x,v3.y,v3.z);
      glVertex3f(v3.x,v3.y,v3.z);
   }
   glEnd();
 }
