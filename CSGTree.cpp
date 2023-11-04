#include "CSGTree.hpp"

CSGTree::CSGTree()
{
    this->root = nullptr;
}

CSGTree::~CSGTree()
{
}

void CSGTree::setRoot(OpNode *root)
{
    this->root = root;
    return;
}

OpNode *CSGTree::getRoot()
{
    return this->root;
}

// adiciona primitiva
// primitiva: deve ser adicionado um nó TransNode com a primitiva
void CSGTree::add(Operation *op, TransNode *node)
{
    std::cout << "Adding a TransNode\n";
    if (root == nullptr)
    {
        std::cout << "Entrou onde deveria\n";
        auto opnode = new OpNode(new Union());
        opnode->setChild(node, 0);
        opnode->setChild(new World(), 1);
        root = opnode;
        delete op;
    }
    else
    {
        auto root_left = root->getChild(0);
        auto opnode = new OpNode(op);
        opnode->setChild(root_left, 0);
        opnode->setChild(node, 1);
        root->setChild(opnode, 0);
    }
    return;
}

// adiciona subárvore
// subárvore: adiciona o nó raiz, discartando a união com o mundo
// a convenção é que toda árvore tem um nó World como filho da direita
void CSGTree::add(Operation *op, OpNode *node)
{
    std::cout << "Adding an OpNode\n";
    if (root == nullptr)
    {
        root = node;
    }
    else
    {
        auto root_left = root->getChild(0);
        auto node_left = node->getChild(0);
        auto opnode = new OpNode(op);
        opnode->setChild(root_left, 0);
        opnode->setChild(node_left, 1);
        root->setChild(opnode, 0);
        node->setChild(nullptr, 0);
        delete node->getChild(1);
        //  node->setChild(nullptr, 1);
        delete node->getOperation();
        delete node;
    }
    return;
}

// metodo teste para criar uma árvore com uma esfera.
void CSGTree::_initTest()
{
    Sphere *sphere = new Sphere();
    glm::vec3 eye(0.);
    glm::vec3 D = glm::normalize(glm::vec3(0., 0., -1.));
    const Ray ray = Ray(eye, eye + D);
    // std::cout << "DIRECAO " << D.x << " " << D.y << " " << D.z << "\n";

    SolidNode *sphereNode = new SolidNode(sphere);
    TransNode *sphereTransNode = new TransNode();
    sphereTransNode->setChild(sphereNode);
    sphereTransNode->addScale(Scale(4.0));
    sphereTransNode->addTranslation(Translation(0., 0., -10.));
    this->add(new Union(), sphereTransNode);
    this->add(new Union(), sphereTransNode);
    this->add(new Union(), sphereTransNode);
    VertexList vl(eye);
    setMembership(ray, vl);
    vl._print();
}

void CSGTree::_print()
{
    std::cout << "CSGTree\n";
    this->getRoot()->_print();
}

void CSGTree::setMembership(const Ray &ray, VertexList &vl)
{
    // std::cout<<"Before Calling root sms\n";
    this->getRoot()->setMembership(ray, vl);
    // std::cout<<"After Calling root sms\n";
}
// void CSGTree::addOperation()
// {
//     return;
// }
// void CSGTree::addTransformation()
// {
//     return;
// }

void CSGTree::setName(std::string _name)
{
    name = _name;
}

std::string CSGTree::getName()
{
    return name;
}
