#ifndef MAIN_WIDGET_H
#define MAIN_WIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include "GraphicsSceneWidget.hpp"
#include "GraphicsViewWidget.hpp"
#include "InputWidget.hpp"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();

    QHBoxLayout *layout;

private:
    InputWidget *inputWidget;
    GraphicsSceneWidget *sceneWidget;
    GraphicsViewWidget *viewWidget;
};

#endif // MAIN_WIDGET_H