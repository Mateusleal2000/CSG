#ifndef WORLD_HPP
#define WORLD_HPP

#include "Node.hpp"

class World : public Node
{
public:
    World() {}
    ~World() {}
    State setMembership(Point3 edgeMin, Point3 edgeMax) override
    {
        return;
    }

    void _print() override 
    {
        std::cout<<"World\n";
    }
};

#endif // WORLD_HPP