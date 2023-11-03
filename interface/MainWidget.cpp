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
    Sphere *sphere = new Sphere();
    SolidNode *sphereNode = new SolidNode(sphere);
    TransNode *sphereTransNode = new TransNode();

    // CSGTree new_csg = CSGTree();
    // Sphere *sphere = new Sphere();
    // SolidNode sphereNode = SolidNode(sphere);
    // TransNode sphereTransNode = TransNode();

    sphereTransNode->setChild(sphereNode);
    sphereTransNode->addScale(Scale(0.5, 0.5, 0.5));
    sphereTransNode->addTranslation(Translation(0., 0., -15.));
    new_csg.add(new Union(), sphereTransNode);
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