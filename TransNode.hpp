#ifndef TRANSNODE_HPP
#define TRANSNODE_HPP

#include "Transformation.hpp"
#include "Node.hpp"

class TransNode : public Node
{
public:
    TransNode();
    ~TransNode();
    // template <class T>
    //     requires isSolidNode<T>
    // T* getChild();
    Node* getChild();
    template <class T>
        requires isSolidNode<T>
    void setChild(T* node);
    void addTransformation(Transformation trans);
    State setMembership(Point3 edgeMin, Point3 edgeMax) override;
    void _print() override;
private:
    Node *child;
    std::vector<Transformation> transVec;
};

#endif // TRANSNODE_HPP