#include "InputWidget.hpp"
#include <iostream>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include <QSpacerItem>
#include <QSizePolicy>

InputWidget::InputWidget(QWidget *parent) : QWidget(parent)
{
    setFixedSize(400, 600);
    setContentsMargins(0,0,0,0);
    layout = new QGridLayout(this);
    layout->setSpacing(0);
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
    QLabel *label = new QLabel("Available Operations", this);
    QPushButton *buttonAdd = new QPushButton("Add Solid", this);
    QPushButton *buttonTransform = new QPushButton("Transform", this);
    QPushButton *buttonOperation = new QPushButton("Boolean Operation", this);
    // QObject::connect(buttonAdd, &QPushButton::clicked, addSolidScreen);
    // connect(m_button, &QPushButton::released, this, &MainWindow::handleButton);
    QPushButton::connect(buttonAdd, &QPushButton::clicked, this, &InputWidget::addSolidScreen);
    layout->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    
    layout->setVerticalSpacing(2);
    layout->addWidget(label, 0, 0, 1, 1);
    layout->addWidget(buttonAdd, 2, 0, 1, 2);
    layout->addWidget(buttonTransform, 3, 0, 1, 2);
    layout->addWidget(buttonOperation, 4, 0, 1, 2);
}

void InputWidget::addSolidScreen()
{
    cleanLayout();
    QPushButton *buttonReturn = new QPushButton("Return", this);
    QPushButton *buttonConfirm = new QPushButton("Add", this);
    QLineEdit *qlineedit1 = new QLineEdit(this);
    QLineEdit *qlineedit2 = new QLineEdit(this);
    QLineEdit *qlineedit3 = new QLineEdit(this);
    QLineEdit *qlineedit4 = new QLineEdit(this);
    QLineEdit *qlineedit5 = new QLineEdit(this);
    QLineEdit *qlineedit6 = new QLineEdit(this);
    QComboBox *solidsList = new QComboBox(this);

    //QSpacerItem * spacer  = new QSpacerItem();

    solidsList->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);


    //solidsList->setMaximumSize(300,30);
    
    qlineedit1->setVisible(false);
    qlineedit2->setVisible(false);
    qlineedit3->setVisible(false);
    qlineedit4->setVisible(false);
    qlineedit5->setVisible(false);
    qlineedit6->setVisible(false);
    solidsList->addItem(QString(""));
    solidsList->addItem(QString("Sphere"));
    solidsList->addItem(QString("Block"));
    QComboBox::connect(solidsList, &QComboBox::activated, this, [=,this] (int i) -> void
                       {if (solidsList->currentText().toStdString() == "Sphere")
                       {
                        qlineedit1->setVisible(true);
                        qlineedit2->setVisible(true);
                        qlineedit3->setVisible(true);
                        qlineedit4->setVisible(true);
                       }
                        setNewInputs(solidsList->currentText()); });
    QPushButton::connect(buttonConfirm, &QPushButton::clicked, this, [this, solidsList]
                         { confirmSolidSelection(solidsList->currentText()); });
    QPushButton::connect(buttonReturn, &QPushButton::clicked, this, &InputWidget::mainScreen);

    //Still struggling with gridlayout 


    //layout->addItem(spacer,     9, 0, 1 , 10);
    layout->addWidget(solidsList, 0, 0, 1, 2);
    layout->addWidget(qlineedit1, 2, 2, 1, 2);
    layout->addWidget(qlineedit2, 3, 2, 1, 2);
    layout->addWidget(qlineedit3, 4, 2, 1, 2);
    layout->addWidget(qlineedit4, 5, 2, 1, 2);
    layout->addWidget(qlineedit5, 6, 2, 1, 2);
    layout->addWidget(qlineedit6, 7, 2, 1, 2);
    layout->addWidget(buttonConfirm, 8, 0, 1, 2);
    layout->addWidget(buttonReturn, 8, 3, 1, 1);


    // layout->addWidget();
}

void InputWidget::confirmSolidSelection(QString solidType)
{
    // cleanLayout();
    if (solidType.toStdString() == "")
    {
        std::cout << "Are you trying to break our program?... shame on you >:(\n";
        return;
    }
    std::cout << "Adding a " << solidType.toStdString() << "\n";
}

void InputWidget::setNewInputs(QString solidType)
{
    if (solidType.toStdString() == "Sphere")
    {
        std::cout << "Sphere selected\n";
        // QLabel *radiusLabel = new QLabel("Radius", this);
        // QLineEdit *radius = new QLineEdit(this);
        // layout->addWidget(radius, 2, 2, 2, 2);
        // layout->addWidget(radiusLabel, 2, 1, 2, 2);
        return;
    }
    else if (solidType.toStdString() == "Block")
    {
        std::cout << "Block selected\n";
        return;
    }
    std::cout << "Adding a " << solidType.toStdString() << "\n";
    return;
}
