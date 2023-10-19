#ifndef OPNODE_HPP
#define OPNODE_HPP

#include "Union.hpp"
#include "Node.hpp"

class OpNode : public Node
{
public:

  OpNode(Operation* op);
  ~OpNode();
  Operation* getOperation();
  void setOperation(Operation* op);

  // template <class T>
  //   requires isOpNode<T> || isTransNode<T> || isWorld<T>
  // T *getChild(int idx);
  Node*getChild(int idx);

  template <class T>
    requires isOpNode<T> || isTransNode<T> || isWorld<T>
  void setChild(T *node, int idx);

  void _print() override;
  State setMembership(Point3 edgeMin, Point3 edgeMax) override;

private:
  Node *left;
  Node *right;
  Operation* op;
};

#endif // OPNODE_HPP
