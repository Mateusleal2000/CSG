#ifndef CSG_TREE_H
#define CSG_TREE_H

#include "nodes/OpNode.hpp"
#include "nodes/TransNode.hpp"
#include "nodes/SolidNode.hpp"
#include "nodes/World.hpp"
#include "tracer/Ray.hpp"
// headers para métodos de teste
#include "solids/Sphere.hpp"
#include "solids/Plane.hpp"
#include "solids/Cylinder.hpp"
#include <string>
class CSGTree
{
    // convenção: Toda árvore possui um nó World como filho da direita do nó raiz.
public:
    CSGTree();
    ~CSGTree();
    void setRoot(OpNode *root);
    OpNode *getRoot();
    void setMembership(const Ray &ray, VertexList &vl);
    void swapRoot(Node *substituteForWorldNode);
    void add(Operation *op, TransNode *node);
    void add(Operation *op, OpNode *node);
    void _initTest();
    void _print();
    void setName(std::string _name);
    std::string getName();

    // void addOperation();
    // void addTransformation();
private:
    OpNode *root;
    std::string name;
};

#endif // CSG_TREE_H
