#include "SolidNode.hpp"
#include <iostream>

SolidNode::SolidNode(Solid *solid)
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

State SolidNode::setMembership(glm::vec3 edgeMin, glm::vec3 edgeMax, glm::mat4 trans)
{
  return State::IN;
}

State SolidNode::setMembership(glm::vec3 edgeMin, glm::vec3 edgeMax)
{
  return State::IN;
}

void SolidNode::_print()
{
  std::cout << "SolidNode\n";
}

void SolidNode::setChild(Node *node)
{
  std::cout << "SOLIDO NAO PODE TER FILHOS!\n";
  exit(-1);
}

Node *SolidNode::getChild(int idx)
{
  std::cout << "SOLIDO NAO PODE TER FILHOS!\n";
  exit(-1);
}
