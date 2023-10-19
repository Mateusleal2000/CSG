#include "OpNode.hpp"

OpNode::OpNode(Operation* op){
  this->op = op;
}

Operation* OpNode::getOperation(){
  return this->op;
}

void OpNode::setOperation(Operation* op){
  this->op = op;
}

// template <class T>
//   requires isOpNode<T> || isTransNode<T> || isWorld<T>
// T *OpNode::getChild(int idx){
Node *OpNode::getChild(int idx){
  if (idx == 0){
    return left;
  } 
  if (idx == 1) {
    return right;
  }
}

template <class T>
  requires isOpNode<T> || isTransNode<T> || isWorld<T>
void OpNode::setChild(T *node, int idx){
  if (idx == 0){
    node->setParent(this);
    this->left = node;
    return;
  } 
  if (idx == 1) {
    node->setParent(this);
    this->right = node;
    return;
  }
}

void OpNode::_print()
{
  std::cout<<"=======OpNode======\n";
  std::cout<<"=======left child======\n";
  this->getChild(0)->_print();
  std::cout<<"=======right child======\n";
  this->getChild(1)->_print();
  std::cout<<"=======End of OpNode======\n";
}

State OpNode::setMembership(Point3 edgeMin, Point3 edgeMax){

}
