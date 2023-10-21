#ifndef TRANSNODE_HPP
#define TRANSNODE_HPP

#include "Translation.hpp"
#include "Rotation.hpp"
#include "Scale.hpp"
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
    glm::mat4 getTransformMatrix();
    State setMembership(glm::vec3 edgeMin, glm::vec3 edgeMax) override;
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