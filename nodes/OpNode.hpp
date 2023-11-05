#ifndef OPNODE_HPP
#define OPNODE_HPP

#include "../operations/Union.hpp"
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
  void setMembership(const Ray &ray, VertexList &vl) override;
  void transformationRequest(glm::vec3 t, glm::vec3 s, int axis, float angle) override;

private:
  Node *left;
  Node *right;
  Operation *op;
};

#endif // OPNODE_HPP
