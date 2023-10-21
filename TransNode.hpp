#ifndef TRANSNODE_HPP
#define TRANSNODE_HPP

#include "Transformation.hpp"
#include "Node.hpp"
#include <vector>
class TransNode : public Node
{
public:
    TransNode();

    void setChild(Node *node);
    // {
    //     node->setParent(this);
    //     this->child = node;
    // }

    Node *getChild(int idx);
    // {
    //     return this->child;
    // }

    void addTransformation(Transformation trans);
    State setMembership(glm::vec3 edgeMin, glm::vec3 edgeMax) override;
    void _print() override;

private:
    Node *child;
    std::vector<Transformation> transVec;
};

#endif // TRANSNODE_HPP