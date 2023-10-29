#ifndef OPNODE_HPP
#define OPNODE_HPP

#include "Union.hpp"
#include "Node.hpp"
#include <iostream>
class OpNode : public Node
{
public:
  OpNode(Operation *op);
  Operation *getOperation();
  void setOperation(Operation *op);

  Node *getChild(int idx);
  void setChild(Node *) override;
  void setChild(Node *node, int idx);
  void _print() override;
  void setMembership(glm::vec3 eye, glm::vec3 D, VertexList &vl) override;

private:
  Node *left;
  Node *right;
  Operation *op;
};

#endif // OPNODE_HPP
