#ifndef SOLIDNODE_HPP
#define SOLIDNODE_HPP

#include "Node.hpp"
#include "Solid.hpp"

class SolidNode : public Node
{
public:
    Solid *getSolid();
    void setSolid(Solid *solid);

private:
    Solid *solid;
};

#endif // SOLIDNODE_HPP