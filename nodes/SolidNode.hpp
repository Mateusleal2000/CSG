#ifndef SOLIDNODE_HPP
#define SOLIDNODE_HPP

#include "Node.hpp"
#include <glm/mat4x4.hpp>

class SolidNode : public Node
{
public:
    SolidNode(Solid *solid);
    Solid *getSolid();
    void setSolid(Solid *solid);
    void setMembership(const Ray &ray, VertexList &vl, const glm::mat4 &modelMatrix, const glm::mat4 &modelMatrixInv);
    void setMembership(const Ray &ray, VertexList &vl) override;
    void _print() override;
    Node *getChild(int idx) override;
    void setChild(Node *node) override;
    void transformationRequest(glm::vec3 t, glm::vec3 s, int axis, float angle) override;

private:
    Solid *solid;
};

#endif // SOLIDNODE_HPP