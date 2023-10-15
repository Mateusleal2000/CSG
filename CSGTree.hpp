#ifndef CSG_TREE_H
#define CSG_TREE_H

#include "OpNode.hpp"
#include "TransNode.hpp"
#include "SolidNode.hpp"
#include "World.hpp"
class CSGTree
{
public:
    CSGTree(OpNode *root = nullptr);
    ~CSGTree();
    void setRoot(OpNode *root);
    void add(Operation op, Node *node);
    // void addOperation();
    // void addTransformation();

private:
    OpNode *root;
};

#endif // CSG_TREE_H
