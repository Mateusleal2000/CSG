#include "CSGTree.hpp"

CSGTree::CSGTree(OpNode *root) : root(root)
{
    root->setChild(new World(), 1);
}

CSGTree::~CSGTree()
{
}

void CSGTree::setRoot(OpNode *root)
{
    this->root = root;
    return;
}

// adiciona uma primitiva ou uma árvore
// primitiva: deve ser adicionado um nó TransNode com a primitiva
// árvore: adiciona o nó raiz, discartando a união com o mundo
void CSGTree::add(Operation op, Node *node)
{
    // temporário

    return;
}
// void CSGTree::addOperation()
// {
//     return;
// }
// void CSGTree::addTransformation()
// {
//     return;
// }
