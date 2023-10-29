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
    void setMembership(glm::vec3 eye, glm::vec3 D, VertexList &vl) override;
    void _print() override;

private:
    Node *child;
};

#endif // WORLD_HPP