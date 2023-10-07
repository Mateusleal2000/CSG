#include "GraphicsViewWidget.hpp"
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