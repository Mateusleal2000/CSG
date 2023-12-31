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
  void addColor(int c1, int c2, int c3);
  void clearCanvas();

public slots:
  void draw() override;

private:
  std::vector<uchar> v;
};

#endif