#ifndef OPNODE_HPP
#define OPNODE_HPP

#include "Operation.hpp"
#include "Node.hpp"

class OpNode : public Node
{
public:
  template <class T>
    requires isOpNode<T> || isTransNode<T> || isWorld<T>
  T *getChild(int idx);

  template <class T>
    requires isOpNode<T> || isTransNode<T> || isWorld<T>
  void setChild(T *node, int idx);

  State setMembership(Point3 edgeMin, Point3 edgeMax) override;

private:
  Node *left;
  Node *right;
};

#endif // OPNODE_HPP

// concept isTransform
// concept isOp
// concept isSolid

// class Op -> addChild -> constraint isTransform || isOp