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
    setContentsMargins(0, 100, 0, 100);
    layout = new QFormLayout(this);
    setFocusPolicy(Qt::TabFocus);
    layout->setSpacing(0);
    layout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
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
    QPushButton *buttonAdd = new QPushButton("Add Solid", this);
    QPushButton *buttonTransform = new QPushButton("Transform", this);
    QPushButton *buttonOperation = new QPushButton("Boolean Operation", this);
    QPushButton *buttonApply = new QPushButton("Apply", this);
    QPushButton::connect(buttonAdd, &QPushButton::clicked, this, &InputWidget::addSolidScreen);
    QPushButton::connect(buttonTransform, &QPushButton::clicked, this, &InputWidget::transformSolidScreen);
    QPushButton::connect(buttonOperation, &QPushButton::clicked, this, &InputWidget::operationScreen);

    QComboBox *chooseState = new QComboBox(this);
    chooseState->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    chooseState->setContentsMargins(0, 0, 0, 0);
    chooseState->setAttribute(Qt::WA_LayoutUsesWidgetRect);
    chooseState->setMaximumSize(Definitions::MAIN_WIDTH / 8, Definitions::MAIN_HEIGHT / 20);
    chooseState->addItem(QString("IN"));
    chooseState->addItem(QString("ON"));

    QLineEdit *chooseDepth = new QLineEdit(this);
    chooseDepth->setVisible(true);
    chooseDepth->setPlaceholderText(QString("Depth"));

    QPushButton::connect(buttonApply, &QPushButton::clicked, this, [=, this]() -> void
                         {
                         if(chooseState->currentText().toStdString() == "ON"){
                            emit callCanvasParameters(State::ON,std::stoi(chooseDepth->text().toStdString()));
                         }
                         else{
                            emit callCanvasParameters(State::IN,std::stoi(chooseDepth->text().toStdString()));
                         } });

    layout->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    layout->addRow(buttonAdd);
    layout->addRow(buttonTransform);
    layout->addRow(buttonOperation);
    layout->addRow(chooseState);
    layout->addRow(chooseDepth);
    layout->addRow(buttonApply);
}

void InputWidget::addSolidScreen()
{
    cleanLayout();
    layout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
    QPushButton *buttonReturn = new QPushButton("Return", this);
    QPushButton *buttonConfirm = new QPushButton("Create new Tree", this);
    QLineEdit *treeName = new QLineEdit(this);
    treeName->setPlaceholderText(QString("Tree Name"));
    treeName->setVisible(true);
    QComboBox *solidsList = new QComboBox(this);

    QLineEdit *qlineedit1 = new QLineEdit(this);
    qlineedit1->setVisible(true);
    qlineedit1->setPlaceholderText(QString("Translate X"));
    QLineEdit *qlineedit2 = new QLineEdit(this);
    qlineedit2->setVisible(true);
    qlineedit2->setPlaceholderText(QString("Translate Y"));
    QLineEdit *qlineedit3 = new QLineEdit(this);
    qlineedit3->setVisible(true);
    qlineedit3->setPlaceholderText(QString("Translate Z"));
    QLineEdit *qlineedit4 = new QLineEdit(this);
    qlineedit4->setVisible(true);
    qlineedit4->setPlaceholderText(QString("Scale X"));
    QLineEdit *qlineedit5 = new QLineEdit(this);
    qlineedit5->setVisible(true);
    qlineedit5->setPlaceholderText(QString("Scale Y"));
    QLineEdit *qlineedit6 = new QLineEdit(this);
    qlineedit6->setVisible(true);
    qlineedit6->setPlaceholderText(QString("Scale Z"));
    QLineEdit *qlineedit7 = new QLineEdit(this);
    qlineedit7->setVisible(true);
    qlineedit7->setPlaceholderText(QString("Axis(0=x, 1=y or 2=z)"));
    QLineEdit *qlineedit8 = new QLineEdit(this);
    qlineedit8->setVisible(true);
    qlineedit8->setPlaceholderText(QString("Angle"));

    solidsList->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

    solidsList->setMaximumSize(Definitions::MAIN_WIDTH / 4, Definitions::MAIN_HEIGHT / 20);

    solidsList->addItem(QString("Sphere"));
    solidsList->addItem(QString("Cylinder"));
    solidsList->addItem(QString("Plane"));
    // QComboBox::connect(solidsList, &QComboBox::activated, this, [=, this](int i) -> void
    //                    {if (solidsList->currentText().toStdString() == "Sphere")
    //                    {
    //                     // Adiciona esfera
    //                     std::cout<<"Adiciona esfera\n";
    //                    }
    //                    if (solidsList->currentText().toStdString() == "Block")
    //                    {
    //                     // Adiciona bloco
    //                     std::cout<<"Adiciona bloco\n";
    //                    }
    //                     setNewInputs(solidsList->currentText()); });

    QPushButton::connect(buttonConfirm, &QPushButton::clicked, this, [=, this]() -> void
                         { 
                         glm::vec3 t(std::stof(qlineedit1->text().toStdString()), std::stof(qlineedit2->text().toStdString()), std::stof(qlineedit3->text().toStdString()));
                         glm::vec3 s(std::stof(qlineedit4->text().toStdString()), std::stof(qlineedit5->text().toStdString()), std::stof(qlineedit6->text().toStdString()));
                         int axis = std::stoi(qlineedit7->text().toStdString());
                         float angle = std::stof(qlineedit8->text().toStdString());
                         emit callSolidRequest(solidsList->currentText().toStdString(), treeName->text().toStdString(), t,s,axis, angle); });

    QPushButton::connect(buttonReturn, &QPushButton::clicked, this, &InputWidget::mainScreen);

    layout->addRow(solidsList);
    layout->addRow(treeName);
    layout->addRow(qlineedit1);
    layout->addRow(qlineedit2);
    layout->addRow(qlineedit3);
    layout->addRow(qlineedit4);
    layout->addRow(qlineedit5);
    layout->addRow(qlineedit6);
    layout->addRow(qlineedit7);
    layout->addRow(qlineedit8);
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
    QLineEdit *treeName = new QLineEdit(this);
    treeName->setPlaceholderText(QString("Tree Name"));
    treeName->setVisible(true);
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

    // QComboBox::connect(treeOperand1, &QComboBox::create);

    // Antes de fazer o addItem(), precisamos pegar as primitivas disponíveis, então temos que descobrir como fazer isso ainda

    for (int i = 0; i < trees->size(); i++)
    {
        treeOperand1->addItem(QString::fromStdString(trees->at(i).getName()));
        treeOperand2->addItem(QString::fromStdString(trees->at(i).getName()));
    }

    QPushButton::connect(buttonConfirmOp, &QPushButton::clicked, this, [this, treeName, operation, treeOperand1, treeOperand2]
                         {  
                            std::string to1 = treeOperand1->currentText().toStdString();
                            std::string to2 = treeOperand2->currentText().toStdString();
                            treeOperand1->addItem(treeName->text());
                            treeOperand2->addItem(treeName->text());
                            treeOperand1->removeItem(treeOperand2->currentIndex());
                            treeOperand2->removeItem(treeOperand2->currentIndex());
                            emit callOperationRequest(treeName->text().toStdString(), operation->currentText().toStdString(), to1, to2); });
    QPushButton::connect(buttonReturn, &QPushButton::clicked, this, &InputWidget::mainScreen);

    layout->addRow(QString("Operation "), operation);
    layout->addRow(treeName);
    layout->addRow(QString("Operand 1 "), treeOperand1);
    layout->addRow(QString("Operand 2 "), treeOperand2);
    layout->addRow(buttonConfirmOp);
    layout->addRow(buttonReturn);
}

void InputWidget::changeCameraScreen()
{
    cleanLayout();

    QPushButton *buttonReturn = new QPushButton("Return", this);
    QPushButton *buttonConfirm = new QPushButton("Create new Tree", this);

    QLineEdit *qlineedit1 = new QLineEdit(this);
    qlineedit1->setVisible(true);
    qlineedit1->setPlaceholderText(QString("Position X"));
    QLineEdit *qlineedit2 = new QLineEdit(this);
    qlineedit2->setVisible(true);
    qlineedit2->setPlaceholderText(QString("Position Y"));
    QLineEdit *qlineedit3 = new QLineEdit(this);
    qlineedit3->setVisible(true);
    qlineedit3->setPlaceholderText(QString("Position Z"));
    QLineEdit *qlineedit4 = new QLineEdit(this);
    qlineedit4->setVisible(true);
    qlineedit4->setPlaceholderText(QString("Direction X"));
    QLineEdit *qlineedit5 = new QLineEdit(this);
    qlineedit5->setVisible(true);
    qlineedit5->setPlaceholderText(QString("Direction Y"));
    QLineEdit *qlineedit6 = new QLineEdit(this);
    qlineedit6->setVisible(true);
    qlineedit6->setPlaceholderText(QString("Direction Z"));

    QPushButton::connect(buttonReturn, &QPushButton::clicked, this, &InputWidget::mainScreen);

    layout->addRow(qlineedit1);
    layout->addRow(qlineedit2);
    layout->addRow(qlineedit3);
    layout->addRow(qlineedit4);
    layout->addRow(qlineedit5);
    layout->addRow(qlineedit6);
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

void InputWidget::setTrees(std::vector<CSGTree> *_trees)
{
    trees = _trees;
}
