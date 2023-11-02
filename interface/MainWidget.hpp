#ifndef MAIN_WIDGET_H
#define MAIN_WIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include "InputWidget.hpp"
#include "../tracer/GLView.hpp"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();

    QHBoxLayout *layout;

private:
    InputWidget *inputWidget;
    GLView *glview;
};

#endif // MAIN_WIDGET_H