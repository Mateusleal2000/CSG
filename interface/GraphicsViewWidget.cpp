#include "GraphicsViewWidget.hpp"
#include "definitions.hpp"
#include <fstream>
#include <iostream>

GraphicsViewWidget::GraphicsViewWidget(QGraphicsScene *parent) : QGraphicsView(parent)
{

    image = nullptr;
    pixmap = nullptr;
    currentPixmapItem = nullptr;
    QDir dir(QDir::currentPath());
    dir.cdUp();
    std::string fileName = "/interface/Doctor_Eggman.png";
    QString path = dir.path();
    QString s = path + QString(fileName.c_str());
    std::cout << s.toStdString() << "\n";
    // setFixedSize((Definitions::MAIN_WIDTH / 1.875), (Definitions::MAIN_HEIGHT / 1.666666667));
    // std::cout << "width: " << width() << " height" << height() << std::endl;
    // setContentsMargins(0., 0., 0., 0.);
    // setFrameShape(QFrame::NoFrame);
    showImage(s);
}

GraphicsViewWidget::~GraphicsViewWidget()
{
    delete image;
}

void GraphicsViewWidget::showImage(QString filename)
{
    scene()->clear();
    resetTransform();

    image = new QImage(filename);
    pixmap = new QPixmap(QPixmap::fromImage(*image));
    currentPixmapItem = scene()->addPixmap(*pixmap);
    scene()->update();
    setSceneRect(pixmap->rect());
}