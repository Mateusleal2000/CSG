#include "InputWidget.hpp"

InputWidget::InputWidget(QWidget *parent) : QWidget(parent)
{
    setFixedSize(400, 480);
    layout = new QGridLayout(this);
    mainScreen();
    setLayout(layout);
}

InputWidget::~InputWidget()
{
    cleanLayout();
    delete layout;
}

void InputWidget::cleanLayout()
{
    QLayoutItem *child;
    while (layout->count() != 0)
    {
        child = layout->takeAt(0);
        if (child->widget() != 0)
        {
            delete child->widget();
        }

        delete child;
    }
}

void InputWidget::mainScreen()
{
    cleanLayout();
    QLabel *label = new QLabel("MODELAGEM GEOMETRICA", this);
    QPushButton *buttonAdd = new QPushButton("Add Solid", this);
    QPushButton *buttonTransform = new QPushButton("Transform", this);
    QPushButton *buttonOperation = new QPushButton("Operation", this);
    layout->addWidget(label, 0, 0, 3, 2);
    layout->addWidget(buttonAdd, 3, 0, 1, 2);
    layout->addWidget(buttonTransform, 4, 0, 1, 2);
    layout->addWidget(buttonOperation, 5, 0, 1, 2);
}

void InputWidget::addSolidScreen()
{
    cleanLayout();

    // layout->addWidget();
}
