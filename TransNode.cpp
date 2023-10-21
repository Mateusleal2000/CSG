#include "TransNode.hpp"
#include <iostream>

TransNode::TransNode()
{
    this->scaleVec = std::vector<Scale>();
    this->rotationVec = std::vector<Rotation>();
    this->translationVec = std::vector<Translation>();
}

// template <class T>
//     requires isSolidNode<T>
Node *TransNode::getChild(int idx)
{
    return this->child;
}

// template <class T>
//     requires isSolidNode<T>
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

void TransNode::_print()
{
    std::cout << "====TransNode====\n";
    this->getChild(0)->_print();
    std::cout << "====end of TransNode====\n";
}

glm::mat4 TransNode::getTransformMatrix()
{
    // temporario
    return glm::mat4(1.0);
}

// Node *TransNode::getChild(int idx)
// {
//     return this->child;
// }

State TransNode::setMembership(glm::vec3 edgeMin, glm::vec3 edgeMax)
{
    SolidNode *sn = dynamic_cast<SolidNode *>(this->getChild(0));
    State set = sn->setMembership(edgeMin, edgeMax, this->getTransformMatrix());
    return set;
}