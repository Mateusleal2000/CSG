#ifndef VIEW_WIDGET_H
#define VIEW_WIDGET_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QImage>
#include <QDir>
#include <QString>
#include <fstream>
#include <QGraphicsPixmapItem>
#include <QPixmap>

class GraphicsViewWidget : public QGraphicsView
{
private:
    QImage *image;
    QPixmap *pixmap;
    QGraphicsPixmapItem *currentPixmapItem;

public:
    GraphicsViewWidget(QGraphicsScene *parent = 0);
    ~GraphicsViewWidget();

public slots:
    void showImage(QString filename);
};

#endif // VIEW_WIDGET_H