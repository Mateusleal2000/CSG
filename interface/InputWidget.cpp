#include "InputWidget.hpp"
#include "definitions.hpp"
#include <iostream>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include <QSpacerItem>
#include <QSizePolicy>

InputWidget::InputWidget(QWidget *parent) : QWidget(parent)
{
    setFixedSize(Definitions::MAIN_WIDTH / 3, Definitions::MAIN_HEIGHT);
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
    QPushButton::connect(buttonOperation, &QPushButton::clicked, this, &InputWidget::operationScreen);
    layout->setAlignment(Qt::AlignTop | Qt::AlignLeft);

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
    QLineEdit *treeName = new QLineEdit(this);
    treeName->setPlaceholderText(QString("Tree Name"));
    QLineEdit *qlineedit1 = new QLineEdit(this);
    qlineedit1->setPlaceholderText(QString("X value"));
    QLineEdit *qlineedit2 = new QLineEdit(this);
    qlineedit2->setPlaceholderText(QString("Y value"));
    QLineEdit *qlineedit3 = new QLineEdit(this);
    qlineedit3->setPlaceholderText(QString("Z value"));
    QLineEdit *qlineedit4 = new QLineEdit(this);
    qlineedit4->setPlaceholderText(QString("Height"));
    QLineEdit *qlineedit5 = new QLineEdit(this);
    qlineedit5->setPlaceholderText(QString("Length"));
    QLineEdit *qlineedit6 = new QLineEdit(this);
    qlineedit6->setPlaceholderText(QString("Width"));
    QComboBox *solidsList = new QComboBox(this);
    QComboBox *treesList = new QComboBox(this);

    solidsList->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    solidsList->setMaximumSize(Definitions::MAIN_WIDTH / 4, Definitions::MAIN_HEIGHT / 20);

    qlineedit1->setVisible(false);
    qlineedit2->setVisible(false);
    qlineedit3->setVisible(false);
    qlineedit4->setVisible(false);
    qlineedit5->setVisible(false);
    qlineedit6->setVisible(false);
    solidsList->addItem(QString(""));
    solidsList->addItem(QString("Sphere"));
    solidsList->addItem(QString("Block"));
    treesList->addItem(QString("Create New Tree"));
    treesList->addItem(QString("Tree 1"));
    treesList->addItem(QString("Tree 2"));
    QComboBox::connect(solidsList, &QComboBox::activated, this, [=, this](int i) -> void
                       {if (solidsList->currentText().toStdString() == "Sphere")
                       {
                        qlineedit1->setVisible(true);
                        qlineedit2->setVisible(true);
                        qlineedit3->setVisible(true);
                        qlineedit4->setVisible(true);
                        qlineedit4->setPlaceholderText(QString("Radius"));
                        qlineedit5->setVisible(false);
                        qlineedit6->setVisible(false);
                       }
                       if (solidsList->currentText().toStdString() == "Block")
                       {
                        qlineedit1->setVisible(true);
                        qlineedit2->setVisible(true);
                        qlineedit3->setVisible(true);
                        qlineedit4->setVisible(true);
                        qlineedit4->setPlaceholderText(QString("Height"));
                        qlineedit5->setVisible(true);
                        qlineedit6->setVisible(true);
                       }
                        setNewInputs(solidsList->currentText()); });

    QComboBox::connect(treesList, &QComboBox::activated, this, [=, this](int i) -> void
                       {if (treesList->currentText().toStdString() == "Create New Tree")
                       {
                        treeName->setVisible(true);
                       }
                       else
                       {
                        treeName->setVisible(false);
                       } });
    QPushButton::connect(buttonConfirm, &QPushButton::clicked, this, [=, this](int i) -> void
                         {if (treesList->currentText().toStdString() == "Create New Tree")
                        {
                            std::cout << "Create a new tree called " << treeName->text().toStdString() << " and add the " << solidsList->currentText().toStdString()<< "\n";
                        }
                        else{
                            std::cout << "Add the " << solidsList->currentText().toStdString() << " to " << treesList->currentText().toStdString() << "\n";
                            }
                            /*confirmSolidSelection(solidsList->currentText(), treesList->currentText());*/ });
    QPushButton::connect(buttonReturn, &QPushButton::clicked, this, &InputWidget::mainScreen);

    layout->addRow(solidsList);
    layout->addRow(treesList);
    layout->addRow(treeName);
    layout->addRow(qlineedit1);
    layout->addRow(qlineedit2);
    layout->addRow(qlineedit3);
    layout->addRow(qlineedit4);
    layout->addRow(qlineedit5);
    layout->addRow(qlineedit6);
    layout->addRow(buttonConfirm);
    layout->addRow(buttonReturn);
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
    QComboBox *transformationList = new QComboBox(this);

    solidsList->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    transformationList->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    solidsList->setMaximumSize(Definitions::MAIN_WIDTH / 4, Definitions::MAIN_HEIGHT / 20);
    transformationList->setMaximumSize(Definitions::MAIN_WIDTH / 4, Definitions::MAIN_HEIGHT / 20);

    qlineedit1->setVisible(true);
    qlineedit2->setVisible(true);
    qlineedit3->setVisible(true);
    // solidsList->addItem(QString(""));
    // Antes de fazer o addItem(), precisamos pegar as primitivas disponíveis, então temos que descobrir como fazer isso ainda
    solidsList->addItem(QString("Primitive 1"));
    solidsList->addItem(QString("Primitive 2"));
    solidsList->addItem(QString("Primitive 3"));
    transformationList->addItem(QString("Scale"));
    transformationList->addItem(QString("Translation"));
    // QComboBox::connect(solidsList, &QComboBox::activated, this, [=, this](int i) -> void
    //                    { setNewInputs(solidsList->currentText()); });
    QPushButton::connect(buttonTransform, &QPushButton::clicked, this, [=, this](int i) -> void
                         { std::cout << "Performing a " << transformationList->currentText().toStdString() << " to " << solidsList->currentText().toStdString() << "\n"; });
    QPushButton::connect(buttonReturn, &QPushButton::clicked, this, &InputWidget::mainScreen);

    layout->addRow(transformationList);
    layout->addRow(solidsList);
    layout->addRow(qlineedit1);
    layout->addRow(qlineedit2);
    layout->addRow(qlineedit3);
    layout->addRow(buttonTransform);
    layout->addRow(buttonReturn);
}

void InputWidget::operationScreen()
{
    cleanLayout();
    layout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
    QPushButton *buttonReturn = new QPushButton("Return", this);
    QPushButton *buttonConfirmOp = new QPushButton("Confirm Operation", this);
    QComboBox *operation = new QComboBox(this);
    QComboBox *treeOperand1 = new QComboBox(this);
    QComboBox *treeOperand2 = new QComboBox(this);

    operation->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    treeOperand1->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    treeOperand2->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    operation->setMaximumSize(Definitions::MAIN_WIDTH / 4, Definitions::MAIN_HEIGHT / 20);
    treeOperand1->setMaximumSize(Definitions::MAIN_WIDTH / 4, Definitions::MAIN_HEIGHT / 20);
    treeOperand2->setMaximumSize(Definitions::MAIN_WIDTH / 4, Definitions::MAIN_HEIGHT / 20);

    operation->addItem(QString("Union"));

    treeOperand1->addItem(QString(""));
    treeOperand2->addItem(QString(""));
    // Antes de fazer o addItem(), precisamos pegar as primitivas disponíveis, então temos que descobrir como fazer isso ainda
    treeOperand1->addItem(QString("Tree 1"));
    treeOperand1->addItem(QString("Tree 2"));
    treeOperand1->addItem(QString("Tree 3"));
    treeOperand2->addItem(QString("Tree 1"));
    treeOperand2->addItem(QString("Tree 2"));
    treeOperand2->addItem(QString("Tree 3"));
    // QComboBox::connect(solidOperand1, &QComboBox::activated, this, [=, this](int i) -> void
    //                    { setNewInputs(solidsList->currentText()); });
    QPushButton::connect(buttonConfirmOp, &QPushButton::clicked, this, [this, treeOperand1, treeOperand2]
                         { confirmSolidUnion(treeOperand1->currentText(), treeOperand2->currentText()); });
    QPushButton::connect(buttonReturn, &QPushButton::clicked, this, &InputWidget::mainScreen);

    layout->addRow(QString("Operation "), operation);
    layout->addRow(QString("Operand 1 "), treeOperand1);
    layout->addRow(QString("Operand 2 "), treeOperand2);
    layout->addRow(buttonConfirmOp);
    layout->addRow(buttonReturn);
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

void InputWidget::confirmSolidUnion(QString solidName1, QString solidName2)
{
    if (solidName1.toStdString() != solidName2.toStdString())
    {
        std::cout << solidName1.toStdString() << " Union " << solidName2.toStdString() << "\n";
        return;
    }
    else
    {
        std::cout << "Not a valid operation\n";
        return;
    }
}
