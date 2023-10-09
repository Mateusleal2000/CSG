#ifndef OPNODE_HPP
#define OPNODE_HPP

#include <Operation.hpp>
#include <Node.hpp>

class OpNode : public Node{
  public:
    isNode auto child(int idx);

  private:
    Node * left;
    Node * right;
};

#endif //OPNODE_HPP