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
    connect(inputWidget, &InputWidget::callSolidOrder, this, &MainWidget::solidOrder);
    connect(inputWidget, &InputWidget::callOperationOrder, this, &MainWidget::operationOrder);

    CSGTree new_csg = CSGTree();

    // Sphere *sphere = new Sphere();
    // SolidNode *sphereNode = new SolidNode(sphere);
    // TransNode *sphereTransNode = new TransNode();
    // sphereTransNode->setChild(sphereNode);
    // sphereTransNode->addScale(Scale(4.0, 4.0, 4.0));
    // sphereTransNode->addTranslation(Translation(0., 0., -15.));

    // Plane *plane = new Plane();
    // SolidNode *planeNode = new SolidNode(plane);
    // TransNode *planeTransNode = new TransNode();
    // planeTransNode->setChild(planeNode);
    // planeTransNode->addScale(Scale(8.0, 5.0, 5.0));
    // planeTransNode->addTranslation(Translation(0., 0., -15.));

    // Cylinder *cyl = new Cylinder();
    // SolidNode *cylNode = new SolidNode(cyl);
    // TransNode *cylTransNode = new TransNode();
    // cylTransNode->setChild(cylNode);
    // cylTransNode->addScale(Scale(5.0, 5.0, 5.0));
    // cylTransNode->addTranslation(Translation(0., 0., -15.));
    // cylTransNode->addRotation(Rotation(0, 90.));

    // CSGTree new_csg = CSGTree();
    // Sphere *sphere = new Sphere();
    // SolidNode sphereNode = SolidNode(sphere);
    // TransNode sphereTransNode = TransNode();

    // new_csg.add(new Union(), cylTransNode);
    // new_csg.setName("Name");
    // glview->setCurrentCSGTree(new_csg);

    // connect(&timer, &QTimer::timeout, this, &MainWidget::checkTreeSize);
    // timer.setInterval(2000);
    // timer.start();
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

void MainWidget::solidOrder(std::string type, std::string name, glm::vec3 t, glm::vec3 s, int axis, float angle)
{

    CSGTree new_csg = CSGTree();
    new_csg.setName(name);

    if (type == "Sphere")
    {
        Sphere *sphere = new Sphere();
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

void MainWidget::operationOrder(std::string operation, std::string operandName1, std::string operandName2)
{
    // if (operation == "Union")
    // {
    //     CSGTree operand1;
    //     CSGTree operand2;
    //     for (int i = 0; i < trees.size(); i++)
    //     {
    //         if()
    //     }
    // }
    return;
}
