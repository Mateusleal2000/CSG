#ifndef MAIN_WIDGET_H
#define MAIN_WIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include "InputWidget.hpp"
#include "../tracer/GLView.hpp"
#include "../CSGTree.hpp"
#include <QTimer>

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();
public slots:
    void checkTreeSize();

private:
    InputWidget *inputWidget;
    QHBoxLayout *layout;
    GLView *glview;
    std::vector<CSGTree> trees;
    QTimer timer;
};

#endif // MAIN_WIDGET_H