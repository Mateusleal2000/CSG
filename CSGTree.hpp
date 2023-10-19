#ifndef CSG_TREE_H
#define CSG_TREE_H

#include "OpNode.hpp"
#include "TransNode.hpp"
#include "SolidNode.hpp"
#include "World.hpp"
class CSGTree
{
    //convenção: Toda árvore possui um nó World como filho da direita do nó raiz. 
public:
    CSGTree(OpNode *root = nullptr);
    ~CSGTree();
    void setRoot(OpNode *root);
    OpNode* getRoot();

    template <class T>
        requires isOpNode<T> || isTransNode<T> 
    void swapRoot(T* substituteForWorld);

    template <class T>
        requires isTransNode<T> 
    void add(Operation op, T* node);

    template <class T>
        requires isOpNode<T> 
    void add(Operation op, T* node);

    void _initTest();
    void _print();

    // void addOperation();
    // void addTransformation();
private:
    OpNode *root;
};

#endif // CSG_TREE_H
