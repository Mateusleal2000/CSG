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
    void setMembership(const Ray &ray, VertexList &vl) override;
    void transformationRequest(glm::vec3 t, glm::vec3 s, int axis, float angle) override;
    void _print() override;

private:
    Node *child;
};

#endif // WORLD_HPP