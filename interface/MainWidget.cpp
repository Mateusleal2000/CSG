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
    connect(inputWidget, &InputWidget::callSolidRequest, this, &MainWidget::solidRequest);
    connect(inputWidget, &InputWidget::callOperationRequest, this, &MainWidget::operationRequest);
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

void MainWidget::solidRequest(std::string type, std::string name, glm::vec3 t, glm::vec3 s, int axis, float angle)
{

    CSGTree new_csg = CSGTree();
    new_csg.setName(name);

    if (type == "Sphere")
    {
        Sphere *sphere = new Sphere();
        sphere->setKD(glm::vec3(0.7, 0., 0.));
        sphere->setKE(glm::vec3(0.7, 0., 0.));
        sphere->setShininess(10);
        SolidNode *sphereNode = new SolidNode(sphere);
        TransNode *sphereTransNode = new TransNode();
        sphereTransNode->setChild(sphereNode);
        sphereTransNode->addScale(Scale(s.x, s.y, s.z));
        sphereTransNode->addTranslation(Translation(t.x, t.y, t.z));
        sphereTransNode->addRotation(Rotation(axis, angle));
        new_csg.add(new Union(), sphereTransNode);
    }

    else if (type == "Cylinder")
    {
        Cylinder *cyl = new Cylinder();
        cyl->setKD(glm::vec3(1.0, 0., 0.));
        cyl->setKE(glm::vec3(0.7, 0., 0.));
        cyl->setShininess(50);
        SolidNode *cylNode = new SolidNode(cyl);
        TransNode *cylTransNode = new TransNode();
        cylTransNode->setChild(cylNode);
        cylTransNode->addScale(Scale(s.x, s.y, s.z));
        cylTransNode->addTranslation(Translation(t.x, t.y, t.z));
        cylTransNode->addRotation(Rotation(axis, angle));
        new_csg.add(new Union(), cylTransNode);
    }

    else if (type == "Plane")
    {
        Plane *plane = new Plane();
        plane->setKD(glm::vec3(1.0, 0., 0.));
        plane->setKE(glm::vec3(0.7, 0., 0.));
        plane->setShininess(50);
        SolidNode *planeNode = new SolidNode(plane);
        TransNode *planeTransNode = new TransNode();
        planeTransNode->setChild(planeNode);
        planeTransNode->addScale(Scale(s.x, s.y, s.z));
        planeTransNode->addTranslation(Translation(t.x, t.y, t.z));
        planeTransNode->addRotation(Rotation(axis, angle));
        new_csg.add(new Union(), planeTransNode);
    }
    trees.push_back(new_csg);
    glview->setCurrentCSGTree(new_csg);
}

void MainWidget::operationRequest(std::string name, std::string operation, std::string operandName1, std::string operandName2)
{
    if (operandName1 != operandName2)
    {
        std::cout << "Entrou no if do operation request\n";

        if (operation == "Union")
        {
            std::cout << "Eh uma uniao\n";
            int operand1Index = -1;
            int operand2Index = -1;
            for (int i = 0; i < trees.size(); i++)
            {
                if (trees.at(i).getName() == operandName1)
                {
                    operand1Index = i;
                }
                if (trees.at(i).getName() == operandName2)
                {
                    operand2Index = i;
                }
            }
            trees.at(operand1Index).add(new Union(), trees.at(operand2Index).getRoot());
            trees.at(operand1Index).setName(name);
            trees.erase(trees.begin() + operand2Index);
            glview->setCurrentCSGTree(trees.at(operand1Index));
        }
    }
    else
    {
        return;
    }
}
