#ifndef GL_VIEW_H
#define GL_VIEW_H

#include <QOpenGLWidget>
#include <QOpenGLVersionFunctionsFactory>
#include <QOpenGLContext>
#include <QOpenGLFunctions_3_3_Core>
#include "Canvas.hpp"

class GLView : public QOpenGLWidget{
public:
  GLView(QWidget * parent = nullptr);
  ~GLView();
  void paintGL() override;
  void resizeGL(int w,int h) override;
  void initializeGL() override;
private:
  QOpenGLFunctions_3_3_Core * f;
  Canvas * canvas;
};

#endif