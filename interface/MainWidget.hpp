#ifndef MAIN_WIDGET_H
#define MAIN_WIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include "InputWidget.hpp"
#include "../tracer/GLView.hpp"
#include "../CSGTree.hpp"
#include <QTimer>
#include <glm/vec3.hpp>

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();
public slots:
    void checkTreeSize();
    void solidOrder(std::string type, std::string name, glm::vec3 t, glm::vec3 s, int axis, float angle);
    void operationOrder(std::string operation, std::string operandName1, std::string operandName2);

private:
    InputWidget *inputWidget;
    QHBoxLayout *layout;
    GLView *glview;
    std::vector<CSGTree> trees;
    QTimer timer;
};

#endif // MAIN_WIDGET_H