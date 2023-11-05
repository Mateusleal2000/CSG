#ifndef MAIN_WIDGET_H
#define MAIN_WIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include "InputWidget.hpp"
#include "../tracer/GLView.hpp"
#include "../CSGTree.hpp"
#include <QTimer>
#include <QThread>
#include <glm/vec3.hpp>

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();
public slots:
    void checkTreeSize();
    void solidRequest(std::string type, std::string name, glm::vec3 t, glm::vec3 s, int axis, float angle);
    void operationRequest(std::string name, std::string operation, std::string operandName1, std::string operandName2);
    void transformationRequest(std::string name, glm::vec3 t, glm::vec3 s, int axis, float angle);

private:
    InputWidget *inputWidget;
    QHBoxLayout *layout;
    GLView *glview;
    std::vector<CSGTree> trees;
    QTimer timer;
    QThread *thread;
};

#endif // MAIN_WIDGET_H