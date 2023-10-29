#ifndef CSG_TREE_H
#define CSG_TREE_H

#include "OpNode.hpp"
#include "TransNode.hpp"
#include "SolidNode.hpp"
#include "World.hpp"
// headers para métodos de teste
#include "Sphere.hpp"
class CSGTree
{
    // convenção: Toda árvore possui um nó World como filho da direita do nó raiz.
public:
    CSGTree(OpNode *root = nullptr);
    ~CSGTree();
    void setRoot(OpNode *root);
    OpNode *getRoot();
    void setMembership(glm::vec3 eye, glm::vec3 D, VertexList &vl);
    void swapRoot(Node *substituteForWorldNode);
    void add(Operation *op, TransNode *node);
    void add(Operation *op, OpNode *node);
    void _initTest();
    void _print();

    // void addOperation();
    // void addTransformation();
private:
    OpNode *root;
};

#endif // CSG_TREE_H
