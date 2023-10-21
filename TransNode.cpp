#include "TransNode.hpp"
#include <iostream>

TransNode::TransNode()
{
    this->transVec = std::vector<Transformation>();
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

void TransNode::addTransformation(Transformation trans)
{
    transVec.push_back(trans);
}

void TransNode::_print()
{
    std::cout << "====TransNode====\n";
    this->getChild(0)->_print();
    std::cout << "====end of TransNode====\n";
}

// Node *TransNode::getChild(int idx)
// {
//     return this->child;
// }

State TransNode::setMembership(glm::vec3 edgeMin, glm::vec3 edgeMax)
{
    return State::OUT;
}