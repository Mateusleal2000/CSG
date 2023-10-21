#include "CSGTree.hpp"
// headers para métodos de teste
#include "Sphere.hpp"

CSGTree::CSGTree(OpNode *root) : root(root)
{
    this->root->setChild(new World(), 1);
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
template <class T>
    requires isTransNode<T>
void CSGTree::add(Operation op, T *node)
{
    swapRoot(node);
    return;
}

// adiciona subárvore
// subárvore: adiciona o nó raiz, discartando a união com o mundo
// a convenção é que toda árvore tem um nó World como filho da direita
template <class T>
    requires isOpNode<T>
void CSGTree::add(Operation op, T *node)
{
    auto OtherLeftChild = node->getChild(0);
    swapRoot(OtherLeftChild);
    return;
}

template <class T>
    requires isOpNode<T> || isTransNode<T>
void CSGTree::swapRoot(T *substituteForWorldNode)
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
    Sphere *sphere = new Sphere(1., Point3(0., 0., 0.));
    SolidNode *sphereNode = new SolidNode(sphere);
    TransNode *sphereTransNode = new TransNode();
    sphereTransNode->setChild(sphereNode);
    this->add(Union(), sphereTransNode);
}

void CSGTree::_print()
{
    std::cout << "CSGTree\n";
    this->getRoot()->_print();
}
// void CSGTree::addOperation()
// {
//     return;
// }
// void CSGTree::addTransformation()
// {
//     return;
// }
