#include "TransNode.hpp"

TransNode::TransNode()
{
    this->transVec = std::vector<Transformation>;
    transVec.push_back(Scale());
}