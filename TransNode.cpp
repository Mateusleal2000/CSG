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
    node->setParent(this);
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
    glm::mat4 resultScale;
    for (int i = 0; i < scaleVec.size(); i++)
    {
        resultScale = resultScale * scaleVec.at(i).getMatrix();
    }

    return resultScale;
}

glm::mat4 TransNode::getTranslationMatrix()
{
    glm::mat4 resultTranslation;
    for (int i = 0; i < translationVec.size(); i++)
    {
        resultTranslation = resultTranslation * translationVec.at(i).getMatrix();
    }

    return resultTranslation;
}

glm::mat4 TransNode::getRotationMatrix()
{
    glm::mat4 resultRotation;
    for (int i = 0; i < rotationVec.size(); i++)
    {
        resultRotation = resultRotation * rotationVec.at(i).getMatrix();
    }

    return resultRotation;
}

void TransNode::setMembership(glm::vec3 eye, glm::vec3 D, VertexList &vl)
{
    SolidNode *sn = dynamic_cast<SolidNode *>(this->getChild(0));
    sn->setMembership(eye, D, vl, getScaleMatrix(), getTranslationMatrix(), getRotationMatrix());
}

void TransNode::_print()
{
    std::cout << "====TransNode====\n";
    this->getChild(0)->_print();
    std::cout << "====end of TransNode====\n";
}
