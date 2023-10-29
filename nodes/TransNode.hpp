#ifndef TRANSNODE_HPP
#define TRANSNODE_HPP

#include "../transformations/Translation.hpp"
#include "../transformations/Rotation.hpp"
#include "../transformations/Scale.hpp"
#include "SolidNode.hpp"
#include <vector>
class TransNode : public Node
{
public:
    TransNode();

    void setChild(Node *node);
    Node *getChild(int idx);
    void addRotation(Rotation trans);
    void addScale(Scale trans);
    void addTranslation(Translation trans);
    glm::mat4 getScaleMatrix();
    glm::mat4 getTranslationMatrix();
    glm::mat4 getRotationMatrix();
    glm::mat4 getTransformMatrix();
    void setMembership(glm::vec3 eye, glm::vec3 D, VertexList &vl) override;
    void _print() override;
    // void get

private:
    Node *child;
    Solid *transformedSolid;
    std::vector<Translation> translationVec;
    std::vector<Rotation> rotationVec;
    std::vector<Scale> scaleVec;
};

#endif // TRANSNODE_HPP