#ifndef UNION_H
#define UNION_H

#include "Operation.hpp"
#include "vec3.hpp"

class Union : public Operation
{
public:
    Union();
    Union(Solid *RightSolid, Solid *LeftSolid);
    State setMembership(Point3 edgeMin, Point3 edgeMax) override;

private:
    Solid *RightSolid;
    Solid *LeftSolid;
};

#endif // UNION_H