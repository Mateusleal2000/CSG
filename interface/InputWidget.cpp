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
    setContentsMargins(0, 0, 0, 0);
    layout = new QFormLayout(this);
    layout->setSpacing(0);
    layout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
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
    QPushButton::connect(buttonTransform, &QPushButton::clicked, this, &InputWidget::transformSolidScreen);
    // QPushButton::connect(buttonOperation, &QPushButton::clicked, this, &InputWidget::operationSolidScreen);
    layout->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    // layout->setVerticalSpacing(2);
    // layout->addWidget(label, 0, 0, 1, 1);
    // layout->addWidget(buttonAdd, 2, 0, 1, 2);
    // layout->addWidget(buttonTransform, 3, 0, 1, 2);
    // layout->addWidget(buttonOperation, 4, 0, 1, 2);
    layout->addRow(label);
    layout->addRow(buttonAdd);
    layout->addRow(buttonTransform);
    layout->addRow(buttonOperation);
}

void InputWidget::addSolidScreen()
{
    cleanLayout();
    layout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
    QPushButton *buttonReturn = new QPushButton("Return", this);
    QPushButton *buttonConfirm = new QPushButton("Add", this);
    QLineEdit *qlineedit1 = new QLineEdit(this);
    qlineedit1->setPlaceholderText(QString("X value"));
    QLineEdit *qlineedit2 = new QLineEdit(this);
    qlineedit2->setPlaceholderText(QString("Y value"));
    QLineEdit *qlineedit3 = new QLineEdit(this);
    qlineedit3->setPlaceholderText(QString("Z value"));
    QLineEdit *qlineedit4 = new QLineEdit(this);
    qlineedit4->setPlaceholderText(QString("auau"));
    QLineEdit *qlineedit5 = new QLineEdit(this);
    qlineedit5->setPlaceholderText(QString("miau"));
    QLineEdit *qlineedit6 = new QLineEdit(this);
    qlineedit6->setPlaceholderText(QString("moooh"));
    QComboBox *solidsList = new QComboBox(this);

    solidsList->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    solidsList->setMaximumSize(300, 30);

    qlineedit1->setVisible(false);
    qlineedit2->setVisible(false);
    qlineedit3->setVisible(false);
    qlineedit4->setVisible(false);
    qlineedit5->setVisible(false);
    qlineedit6->setVisible(false);
    solidsList->addItem(QString(""));
    solidsList->addItem(QString("Sphere"));
    solidsList->addItem(QString("Block"));
    QComboBox::connect(solidsList, &QComboBox::activated, this, [=, this](int i) -> void
                       {if (solidsList->currentText().toStdString() == "Sphere")
                       {
                        qlineedit1->setVisible(true);
                        qlineedit2->setVisible(true);
                        qlineedit3->setVisible(true);
                        qlineedit4->setVisible(true);
                        qlineedit5->setVisible(false);
                        qlineedit6->setVisible(false);
                       }
                       if (solidsList->currentText().toStdString() == "Block")
                       {
                        qlineedit1->setVisible(true);
                        qlineedit2->setVisible(true);
                        qlineedit3->setVisible(true);
                        qlineedit4->setVisible(true);
                        qlineedit5->setVisible(true);
                        qlineedit6->setVisible(true);
                       }
                        setNewInputs(solidsList->currentText()); });
    QPushButton::connect(buttonConfirm, &QPushButton::clicked, this, [this, solidsList]
                         { confirmSolidSelection(solidsList->currentText()); });
    QPushButton::connect(buttonReturn, &QPushButton::clicked, this, &InputWidget::mainScreen);

    // Still struggling with gridlayout

    // layout->addItem(spacer,     9, 0, 1 , 10);
    // layout->addWidget(solidsList, 0, 0, 1, 1);
    // layout->addWidget(qlineedit1, 1, 2, 1, 2);
    // layout->addWidget(qlineedit2, 2, 2, 1, 2);
    // layout->addWidget(qlineedit3, 3, 2, 1, 2);
    // layout->addWidget(qlineedit4, 4, 2, 1, 2);
    // layout->addWidget(qlineedit5, 5, 2, 1, 2);
    // layout->addWidget(qlineedit6, 6, 2, 1, 2);
    // layout->addWidget(buttonConfirm, 8, 0, 1, 2);
    // layout->addWidget(buttonReturn, 8, 3, 1, 1);
    layout->addRow(solidsList);
    layout->addRow(qlineedit1);
    layout->addRow(qlineedit2);
    layout->addRow(qlineedit3);
    layout->addRow(qlineedit4);
    layout->addRow(qlineedit5);
    layout->addRow(qlineedit6);
    layout->addRow(buttonConfirm);
    layout->addRow(buttonReturn);

    // layout->addWidget();
}

void InputWidget::transformSolidScreen()
{
    cleanLayout();
    layout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
    QPushButton *buttonReturn = new QPushButton("Return", this);
    QPushButton *buttonTransform = new QPushButton("Transform", this);
    QLineEdit *qlineedit1 = new QLineEdit(this);
    qlineedit1->setPlaceholderText(QString("X value"));
    QLineEdit *qlineedit2 = new QLineEdit(this);
    qlineedit2->setPlaceholderText(QString("Y value"));
    QLineEdit *qlineedit3 = new QLineEdit(this);
    qlineedit3->setPlaceholderText(QString("Z value"));
    QComboBox *solidsList = new QComboBox(this);

    // QSpacerItem * spacer  = new QSpacerItem();

    solidsList->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    solidsList->setMaximumSize(300, 30);

    qlineedit1->setVisible(true);
    qlineedit2->setVisible(true);
    qlineedit3->setVisible(true);
    solidsList->addItem(QString(""));
    // Antes de fazer o addItem(), precisamos pegar as primitivas disponíveis, então temos que descobrir como fazer isso ainda
    solidsList->addItem(QString("Primitive 1"));
    solidsList->addItem(QString("Primitive 2"));
    solidsList->addItem(QString("Primitive 3"));
    QComboBox::connect(solidsList, &QComboBox::activated, this, [=, this](int i) -> void
                       { setNewInputs(solidsList->currentText()); });
    QPushButton::connect(buttonTransform, &QPushButton::clicked, this, [this, solidsList]
                         { confirmSolidTransform(solidsList->currentText()); });
    QPushButton::connect(buttonReturn, &QPushButton::clicked, this, &InputWidget::mainScreen);

    layout->addRow(solidsList);
    layout->addRow(qlineedit1);
    layout->addRow(qlineedit2);
    layout->addRow(qlineedit3);
    layout->addRow(buttonTransform);
    layout->addRow(buttonReturn);

    // layout->addWidget();
}

void InputWidget::confirmSolidSelection(QString solidType)
{
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

void InputWidget::confirmSolidTransform(QString solidName)
{
    std::cout << "Transforming " << solidName.toStdString() << "\n";
}
