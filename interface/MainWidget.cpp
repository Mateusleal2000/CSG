#include "MainWidget.hpp"
#include "definitions.hpp"

MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    layout = new QHBoxLayout(this);
    inputWidget = new InputWidget(this);
    inputWidget->setTrees(&trees);
    setFixedSize(Definitions::MAIN_WIDTH, Definitions::MAIN_HEIGHT);
    setContentsMargins(0, 0, 0, 0);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    glview = new GLView(this);
    layout->addWidget(glview);
    layout->addWidget(inputWidget);
    setLayout(layout);
    connect(&timer, &QTimer::timeout, this, &MainWidget::checkTreeSize);
    timer.setInterval(2000);
    timer.start();
    show();
}

MainWidget::~MainWidget()
{
    delete inputWidget;
    delete glview;
}

void MainWidget::checkTreeSize()
{
    if (trees.size() > 0)
    {
        std::cout << "Size: " << trees.size() << "Last Name: " << trees.back().getName() << "\n";
    }
    else
    {
        std::cout << "Vazio\n";
    }
}