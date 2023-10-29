#include "CSGTree.hpp"

CSGTree::CSGTree(OpNode *root) : root(root)
{
    this->root->setChild(new World(), 0);
    this->root->setChild(new World(), 1);
    // if (root != nullptr)
    // {
    //     this->root->setChild(new World(), 1);
    // }
    // else
    // {
    //     Operation *op = new Union();
    //     this->root = new OpNode(op);
    //     this->root->setChild(new World(), 1);
    // }
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
    swapRoot(node);
    return;
}

// adiciona subárvore
// subárvore: adiciona o nó raiz, discartando a união com o mundo
// a convenção é que toda árvore tem um nó World como filho da direita

void CSGTree::add(Operation *op, OpNode *node)
{
    std::cout << "Adding a OpNode\n";
    auto OtherLeftChild = node->getChild(0);
    swapRoot(OtherLeftChild);
    return;
}

void CSGTree::swapRoot(Node *substituteForWorldNode)
{
    this->getRoot()->setChild(substituteForWorldNode, 1);
    OpNode *newRoot = new OpNode(new Union());
    newRoot->setChild(this->getRoot(), 0);
    newRoot->setChild(new World(), 1);
    this->setRoot(newRoot);
    return;
}

// metodo teste para criar uma árvore com uma esfera.
void CSGTree::_initTest()
{
    Sphere *sphere = new Sphere(1.0, glm::vec3(0., 0., 0.));
    SolidNode *sphereNode = new SolidNode(sphere);
    TransNode *sphereTransNode = new TransNode();
    sphereTransNode->setChild(sphereNode);
    OpNode *opNode = new OpNode(new Union());
    opNode->setChild(sphereTransNode, 0);
    opNode->setChild(new World(), 1);
    this->add(new Union(), opNode);
    this->add(new Union(), opNode);
}

void CSGTree::_print()
{
    std::cout << "CSGTree\n";
    this->getRoot()->_print();
}

void CSGTree::setMembership(glm::vec3 eye, glm::vec3 D, VertexList &vl)
{
    this->getRoot()->setMembership(eye, D, vl);
}
// void CSGTree::addOperation()
// {
//     return;
// }
// void CSGTree::addTransformation()
// {
//     return;
// }
