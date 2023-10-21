#ifndef SOLIDNODE_HPP
#define SOLIDNODE_HPP

#include "Node.hpp"

class SolidNode : public Node
{
public:
    SolidNode(Solid *solid);
    Solid *getSolid();
    void setSolid(Solid *solid);
    State setMembership(glm::vec3 edgeMin, glm::vec3 edgeMax) override;
    void _print() override;
    Node *getChild(int idx) override;
    void setChild(Node *node) override;

private:
    Solid *solid;
};

#endif // SOLIDNODE_HPP