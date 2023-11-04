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

    CSGTree new_csg = CSGTree();

    // Sphere *sphere = new Sphere();
    // SolidNode *sphereNode = new SolidNode(sphere);
    // TransNode *sphereTransNode = new TransNode();
    // sphereTransNode->setChild(sphereNode);
    // sphereTransNode->addScale(Scale(4.0, 4.0, 4.0));
    // sphereTransNode->addTranslation(Translation(0., 0., -15.));

    Plane *plane = new Plane();
    SolidNode *planeNode = new SolidNode(plane);
    TransNode *planeTransNode = new TransNode();
    planeTransNode->setChild(planeNode);
    planeTransNode->addScale(Scale(8.0, 5.0, 5.0));
    planeTransNode->addTranslation(Translation(0., 0., -15.));

    // CSGTree new_csg = CSGTree();
    // Sphere *sphere = new Sphere();
    // SolidNode sphereNode = SolidNode(sphere);
    // TransNode sphereTransNode = TransNode();

    new_csg.add(new Union(), planeTransNode);
    new_csg.setName("Name");
    glview->setCurrentCSGTree(new_csg);

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