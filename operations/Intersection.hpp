
#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "Operation.hpp"
#include <glm/vec3.hpp>

class Intersection : public Operation
{
public:
    Intersection() {}
    void apply(VertexList &vlist1, VertexList &vlist2, VertexList &result) override;
    State classify(State &s1, State &s2, Solid *l1, Solid *l2);
};

#endif // UNION_H