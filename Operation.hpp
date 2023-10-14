#ifndef OPERATION_H
#define OPERATION_H

#include "vec3.hpp"
#include "Solid.hpp"

class Operation
{
public:
    virtual ~Operation();
    virtual State setMembership(Point3 edgeMin, Point3 edgeMax);

private:
    Solid *rightSolid;
    Solid *leftSolid;
};

#endif // OPERATION_H