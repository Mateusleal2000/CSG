#ifndef CANVAS_H
#define CANVAS_H

#include "GLObject.hpp"
#include <QImage>

class Canvas : public GLObject
{
  Q_OBJECT
public:
  Canvas(QOpenGLContext *_context = 0);
  ~Canvas();
  void init();

public slots:
  void draw() override;
};

#endif