#include "OpNode.hpp"

OpNode::OpNode(Operation *op)
{
  this->op = op;
}

Operation *OpNode::getOperation()
{
  return this->op;
}

void OpNode::setOperation(Operation *op)
{
  this->op = op;
}

Node *OpNode::getChild(int idx)
{
  if (idx == 0)
  {
    return left;
  }
  if (idx == 1)
  {
    return right;
  }
  else
  {
    std::cout << "Not a valid index\n";
    return right;
  }
}

void OpNode::setChild(Node *node, int idx)
{
  if (idx == 0)
  {
    node->setParent(this);
    this->left = node;
    return;
  }
  if (idx == 1)
  {
    node->setParent(this);
    this->right = node;
    return;
  }
}

void OpNode::setChild(Node *node)
{
  return;
}

void OpNode::_print()
{
  std::cout << "=======OpNode======\n";
  std::cout << "=======left child======\n";
  this->getChild(0)->_print();
  std::cout << "=======right child======\n";
  this->getChild(1)->_print();
  std::cout << "=======End of OpNode======\n";
}

void OpNode::setMembership(const Ray &ray, VertexList &vl)
{
  VertexList vl1 = VertexList(ray.getPoint());
  VertexList vl2 = VertexList(ray.getPoint());
  this->getChild(0)->setMembership(ray, vl1);
  this->getChild(1)->setMembership(ray, vl2);
  this->getOperation()->apply(vl1, vl2, vl);
}
