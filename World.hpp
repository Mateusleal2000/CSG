#ifndef WORLD_HPP
#define WORLD_HPP

#include "Node.hpp"

class World : public Node
{
public:
    World() {}
    ~World() {}
    void setChild(Node *node) override;
    Node *getChild(int idx) override;
    State setMembership(glm::vec3 edgeMin, glm::vec3 edgeMax) override;
    void _print() override;

private:
    Node *child;
};

#endif // WORLD_HPP