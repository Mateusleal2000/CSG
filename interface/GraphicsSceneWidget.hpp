#ifndef SCENE_WIDGET_H
#define SCENE_WIDGET_H
#include <QGraphicsScene>
#include <QObject>
class GraphicsSceneWidget : public QGraphicsScene
{
private:
    /* data */
public:
    GraphicsSceneWidget(QObject *parent = 0);
    ~GraphicsSceneWidget();
};

#endif // SCENE_WIDGET_H
