#include "SolidNode.hpp"

SolidNode::SolidNode(Solid* solid)
{
  this->solid = solid;
}

Solid *SolidNode::getSolid()
{
  return this->solid;
}

void SolidNode::setSolid(Solid *solid)
{
  this->solid = solid;
}

void SolidNode::_print()
{
  std::cout<<"SolidNode\n";
}
