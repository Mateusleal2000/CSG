#ifndef CSG_TREE_H
#define CSG_TREE_H

#include "OpNode.hpp"
#include "TransNode.hpp"
#include "SolidNode.hpp"
class CSGTree
{
public:
    CSGTree();
    ~CSGTree();
    void setRoot(OpNode *root);
    void addSolid();
    void addOperation();
    void addTransformation();

private:
    OpNode *root;
};

#endif // CSG_TREE_H
