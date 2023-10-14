#ifndef TRANSNODE_HPP
#define TRANSNODE_HPP

#include "Transformation.hpp"
#include "Node.hpp"

class TransNode : public Node
{
public:
    template <class T>
        requires isSolidNode<T>
    T getChild(int idx);

    template <class T>
        requires isSolidNode<T>
    void setChild(T node);

private:
    Node *child;
};

#endif // TRANSNODE_HPP