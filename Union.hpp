#ifndef UNION_H
#define UNION_H

#include "Operation.hpp"
#include "vec3.hpp"

class Union : public Operation
{
public:
    Union();
    State setMembership(Point3 edgeMin, Point3 edgeMax) override;
};

#endif // UNION_H