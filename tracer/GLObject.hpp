#ifndef GL_OBJECT_H
#define GL_OBJECT_H

#include <stdlib.h>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLContext>
#include "GLProgram.hpp"
#include <vector>
#include <QObject>
#include <QImage>
#include <QDir>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <iostream>



struct Vertex{
  glm::vec3 position;
  glm::vec3 color;
  glm::vec2 tex;
};

class GLObject : public QObject{
  Q_OBJECT
  public:
  GLObject() : QObject(){}
  virtual ~GLObject() = default;
  void loadTexture(QString filePath);

  protected:
  std::vector<GLProgram> program;
  QOpenGLFunctions_3_3_Core * f;
  std::vector<uint> VBO;
  std::vector<uint> VAO;
  std::vector<uint> EBO;
  QImage * texImage;
  std::vector<Vertex> vertexVector;
  std::vector<uint> indiciesVector;
  std::vector<uint> textures;
  QOpenGLContext * currentContext;

  protected slots:
  virtual void draw() = 0;
  

};

inline void GLObject::loadTexture(QString filePath){
  QDir dir(QDir::currentPath());
  dir.cdUp();
  dir.cd("textures");
  std::cout<<dir.absolutePath().toStdString()<<std::endl;
  texImage = new QImage(dir.absolutePath().append ("/"+ filePath.toStdString()));
  texImage->convertTo(QImage::Format_RGB888);

}

#endif