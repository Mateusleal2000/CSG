#include "GLView.hpp"
#include <iostream>

GLView::GLView(QWidget *parent) : QOpenGLWidget(parent)
{
  setFixedSize(640, 480);
}

GLView::~GLView() {}

void GLView::initializeGL()
{

  f = QOpenGLVersionFunctionsFactory::get<QOpenGLFunctions_3_3_Core>(context());
  f->initializeOpenGLFunctions();
  f->glEnable(GL_DEPTH_TEST);
  f->glEnable(GL_DEPTH_CLAMP);
  f->glEnable(GL_BLEND);
  f->glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  f->glEnable(GL_LINE_SMOOTH);
  f->glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
  f->glEnable(GL_PROGRAM_POINT_SIZE);
  f->glPointSize(2);
  f->glLineWidth(1);
  f->glClearColor(219 / 255.0, 182 / 255.0, 182 / 255.0, 1.0f);

  canvas = new Canvas(context());
  canvas->init();
}

void GLView::resizeGL(int w, int h) {}

void GLView::paintGL()
{
  canvas->draw();
}
