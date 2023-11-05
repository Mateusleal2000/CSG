#ifndef GL_VIEW_H
#define GL_VIEW_H

#include <QOpenGLWidget>
#include <QOpenGLVersionFunctionsFactory>
#include <QOpenGLContext>
#include <QOpenGLFunctions_3_3_Core>
#include <QTimer>
#include <QEventLoop>
#include "Canvas.hpp"
#include "Sampler.hpp"
#include "Camera.hpp"
#include "../CSGTree.hpp"

// class Camera;
// class Canvas;
class GLView : public QOpenGLWidget
{
  Q_OBJECT
public:
  GLView(QWidget *parent = nullptr);
  ~GLView();
  void paintGL() override;
  void resizeGL(int w, int h) override;
  void initializeGL() override;
public slots:
  void updateCanvas();
  void setCurrentCSGTree(CSGTree &csgtree);

private:
  QOpenGLFunctions_3_3_Core *f;
  Canvas *canvas;
  Camera *camera;
  QTimer timer;
  PointLight *light;
  CSGTree currentCSGTree;
};

#endif // GL_VIEW_H