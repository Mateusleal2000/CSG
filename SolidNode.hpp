#ifndef SOLIDNODE_HPP
#define SOLIDNODE_HPP

#include "Node.hpp"
#include "Solid.hpp"

class SolidNode : public Node
{
public:
    SolidNode(Solid* solid);
    Solid *getSolid();
    void setSolid(Solid *solid);
    State setMembership(Point3 edgeMin, Point3 edgeMax) override;
    void _print() override;
private:
    Solid *solid;
};

#endif // SOLIDNODE_HPP