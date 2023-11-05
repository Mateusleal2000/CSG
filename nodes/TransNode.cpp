#include "TransNode.hpp"
#include <iostream>

TransNode::TransNode()
{
    this->scaleVec = std::vector<Scale>();
    this->rotationVec = std::vector<Rotation>();
    this->translationVec = std::vector<Translation>();
}

Node *TransNode::getChild(int idx)
{
    return this->child;
}

void TransNode::setChild(Node *node)
{
    // node->setParent(this);
    // this->child = node;
}

void TransNode::setChild(SolidNode *node)
{
    // std::cout << "SetChild solidnode\n";
    // node->setParent(this);
    this->child = node;
}

void TransNode::addRotation(Rotation trans)
{
    rotationVec.push_back(trans);
}

void TransNode::addScale(Scale trans)
{
    scaleVec.push_back(trans);
}

void TransNode::addTranslation(Translation trans)
{

    translationVec.push_back(trans);
}

glm::mat4 TransNode::getScaleMatrix()
{
    glm::mat4 resultScale(1.);
    for (int i = scaleVec.size() - 1; i >= 0; i--)
    {
        resultScale = resultScale * scaleVec.at(i).getMatrix();
    }

    return resultScale;
}

glm::mat4 TransNode::getTranslationMatrix()
{
    glm::mat4 resultTranslation(1.);
    for (int i = translationVec.size() - 1; i >= 0; i--)
    {
        resultTranslation = resultTranslation * translationVec.at(i).getMatrix();
    }

    return resultTranslation;
}

glm::mat4 TransNode::getRotationMatrix()
{
    glm::mat4 resultRotation(1.);
    for (int i = rotationVec.size() - 1; i >= 0; i--)
    {
        resultRotation = resultRotation * rotationVec.at(i).getMatrix();
    }

    return resultRotation;
}

glm::mat4 TransNode::getModelMatrix()
{
    auto scale = getScaleMatrix();
    auto translate = getTranslationMatrix();
    auto rotation = getRotationMatrix();
    return translate * scale * rotation;
}

glm::mat4 TransNode::getModelMatrixInv()
{
    return glm::inverse(getModelMatrix());
}

void TransNode::setMembership(const Ray &ray, VertexList &vl)
{
    // std::cout << "UM NO TRANS KKKKK\n";

    // SolidNode *sn = dynamic_cast<SolidNode *>(this->getChild(0));

    // std::cout << "Depois de fazer um cast\n";

    child->setMembership(ray, vl, getModelMatrix(), getModelMatrixInv());

    // std::cout << "completou o sms do NO TRANS\n";
}

void TransNode::_print()
{
    std::cout << "====TransNode====\n";
    this->getChild(0)->_print();
    std::cout << "====end of TransNode====\n";
}

void TransNode::transformationRequest(glm::vec3 t, glm::vec3 s, int axis, float angle)
{
    addTranslation(Translation(t.x, t.y, t.z));
    addRotation(Rotation(axis, angle));
    addScale(Scale(s.x, s.y, s.z));
}
