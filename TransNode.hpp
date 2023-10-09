#ifndef TRANSNODE_HPP
#define TRANSNODE_HPP

#include <Transformation.hpp>
#include <Node.hpp>

class TransNode : public Node{
  public:
    hasOneChild auto child(int idx);
    
  private:
    Node * child;
};

#endif // TRANSNODE_HPP