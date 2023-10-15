#ifndef TRANSNODE_HPP
#define TRANSNODE_HPP

#include "Transformation.hpp"
#include "Node.hpp"

class TransNode : public Node
{
public:
    TransNode();
    template <class T>
        requires isSolidNode<T>
    T getChild(int idx);

    template <class T>
        requires isSolidNode<T>
    void setChild(T node);
    State setMembership(Point3 edgeMin, Point3 edgeMax) override;

private:
    Node *child;
    std::vector<Transformation> transVec;
};

#endif // TRANSNODE_HPP