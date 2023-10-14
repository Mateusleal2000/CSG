#ifndef NODE_H
#define NODE_H

#include <vec3.hpp>
#include "NodeConcepts.hpp"
class Node
{
public:
    virtual ~Node() {}
    void setColor(RGBcolor color);
    RGBcolor getColor();
    Node *getParent();
    void setParent(Node *parent);
    virtual Node *child();

private:
    Node *parent;
    RGBcolor color;
};

inline void Node::setParent(Node *parent)
{
    this->parent = parent;
}

inline Node *Node::getParent()
{
    return this->parent;
}

inline RGBcolor Node::getColor()
{
    return this->color;
}

inline void Node::setColor(RGBcolor color)
{
    this->color = color;
}

#endif // NODE_H