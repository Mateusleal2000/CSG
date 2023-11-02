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

void SolidNode::setMembership(const Ray &ray, VertexList &vl, const glm::mat4 &modelMatrix, const glm::mat4 &modelMatrixInv)
{
  Solid *solid = getSolid();
  solid->setMembership(ray, vl, modelMatrix, modelMatrixInv);
}

void SolidNode::setMembership(const Ray &ray, VertexList &vl)
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
