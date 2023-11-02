#ifndef MAIN_WIDGET_H
#define MAIN_WIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include "InputWidget.hpp"
#include "../tracer/GLView.hpp"
#include "../CSGTree.hpp"

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
    std::vector<CSGTree> trees;
};

#endif // MAIN_WIDGET_H