#include "GLView.hpp"
#include <iostream>

GLView::GLView(QWidget *parent) : QOpenGLWidget(parent)
{
  setFixedSize(640, 480);
  light = new PointLight(glm::vec3(0.7, 0.7, 0.7), glm::vec3(0, 10, -10));
  // timer.setInterval(1000);
  // QEventLoop loop;
  // connect(&timer, &QTimer::timeout, this, &GLView::updateCanvas);
  // timer.start();
  // loop.exec();
}

GLView::~GLView()
{
  delete canvas;
  delete camera;
}

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
  camera = new Camera();
  camera->init(90.0f, 0.1f, 100.0f, width(), height());
  canvas->init();
}

void GLView::resizeGL(int w, int h) {}

void GLView::paintGL()
{
  canvas->draw();
}

void GLView::updateCanvas()
{
  canvas->clearCanvas();

  for (int y = 0; y < height(); y++)
  {
    for (int x = 0; x < width(); x++)
    {
      Ray r = camera->computeRayDir(x, y);
      VertexList list = VertexList(camera->getPos());
      // std::cout << r.getUnitDir().x << r.getUnitDir().y << r.getUnitDir().z << "\n";
      currentCSGTree.setMembership(r, list);
      if (list.getVertexListSize() == 3)
      // if(list.getVertexList()->back().getSmsPair()->first == State::ON)
      {
        glm::vec3 color = light->shade(list.getVertexList()->at(1));
        if (std::max({color.x, color.y, color.z}) > 1)
        {
          float maxc = std::max({color.x, color.y, color.z});
          color.x /= maxc;
          color.y /= maxc;
          color.z /= maxc;
        }
        color *= 255.0f;
        canvas->addColor(color.x, color.y, color.z);
      }
      else
      {
        canvas->addColor(0, 0, 0);
      }
    }
  }
  update();
  return;
}

void GLView::setCurrentCSGTree(CSGTree &tree)
{
  currentCSGTree = tree;
  updateCanvas();
}