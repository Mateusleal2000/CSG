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
    void setMembership(glm::vec3 eye, glm::vec3 D, VertexList &vl, glm::mat4 scaleMatrix, glm::mat4 translationMatrix, glm::mat4 rotationMatrix);
    void setMembership(glm::vec3 eye, glm::vec3 D, VertexList &vl) override;
    void _print() override;
    Node *getChild(int idx) override;
    void setChild(Node *node) override;

private:
    Solid *solid;
};

#endif // SOLIDNODE_HPP