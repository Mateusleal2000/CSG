#ifndef NODE_H
#define NODE_H
#include <vec3.hpp>
#include <concepts>

template<class T>
concept hasLeftChild = requires(T a){
    a.child(0); // child(0) precisa ser permitido
};

template<class T>
concept hasRightChild = requires(T a){
    a.child(1); // child(1) precisa ser permitido
};

template<class T>
concept hasOneChild = requires(T a){
    a.child(); // child() precisa ser permitido
};

template<class T>
concept isNode = (hasLeftChild<T> && hasRightChild<T>) || hasOneChild<T>;





class Node
{
    public:
        virtual ~Node() {}
        void setColor(RGBcolor color);
        RGBcolor getColor();
        Node* getParent();
        virtual Node* child();
    private:
        Node* parent;
        RGBcolor color; 
};


inline Node* Node::getParent()
{
    return this->parent;
}

inline RGBcolor Node::getColor()
{
    return this->color;
}

inline void Node::setColor(RGBcolor color)
{
  this->color = color;
}

#endif // NODE_H