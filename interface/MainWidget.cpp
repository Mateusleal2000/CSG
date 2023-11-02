#include "MainWidget.hpp"
#include "definitions.hpp"

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    layout = new QHBoxLayout(this);
    inputWidget = new InputWidget(this);
    // setFixedSize(800, 600);
    setFixedSize(Definitions::MAIN_WIDTH, Definitions::MAIN_HEIGHT);
    setContentsMargins(0, 0, 0, 0);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    sceneWidget = new GraphicsSceneWidget();
    viewWidget = new GraphicsViewWidget(sceneWidget);
    layout->addWidget(viewWidget);
    layout->addWidget(inputWidget);
    setLayout(layout);
    show();
}

MainWidget::~MainWidget()
{
    delete inputWidget;
    delete sceneWidget;
    delete viewWidget;
}