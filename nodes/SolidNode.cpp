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

void SolidNode::setMembership(glm::vec3 eye, glm::vec3 D, VertexList &vl, glm::mat4 scaleMatrix, glm::mat4 translationMatrix, glm::mat4 rotationMatrix)
{
  Solid *solid = getSolid();
  // solid->applyTransformations(scaleMatrix, translationMatrix, rotationMatrix);
  solid->setMembership(eye, D, vl);
}

void SolidNode::setMembership(glm::vec3 eye, glm::vec3 D, VertexList &vl)
{
  std::cout << "Chamada de Função setMembership não utilizável do SolidNode!!\n";
  exit(-1);
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
