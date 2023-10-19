#include "TransNode.hpp"

TransNode::TransNode()
{
    this->transVec = std::vector<Transformation>();
}

// template <class T>
//         requires isSolidNode<T>
// T* TransNode::getChild()
Node* TransNode::getChild()
{
    return this->child;
}

template <class T>
    requires isSolidNode<T>
void TransNode::setChild(T* node)
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
    std::cout<<"====TransNode====\n";
    this->getChild()->_print();
    std::cout<<"====end of TransNode====\n";
}