#ifndef NODE_H
#define NODE_H

#include <glm/vec3.hpp>
#include "Solid.hpp"
class Node
{
public:
    virtual ~Node() {}
    void setColor(glm::vec3 color);
    glm::vec3 getColor();
    Node *getParent();
    void setParent(Node *parent);
    virtual void setChild(Node *node) = 0;
    virtual Node *getChild(int idx) = 0;
    virtual State setMembership(glm::vec3 edgeMin, glm::vec3 edgeMax) = 0;
    virtual void _print() = 0;

private:
    Node *parent;
    glm::vec3 color;
};

inline void Node::setParent(Node *parent)
{
    this->parent = parent;
}

inline Node *Node::getParent()
{
    return this->parent;
}

inline glm::vec3 Node::getColor()
{
    return this->color;
}

inline void Node::setColor(glm::vec3 color)
{
    this->color = color;
}

#endif // NODE_H