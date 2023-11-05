#ifndef UNION_H
#define UNION_H

#include "Operation.hpp"
#include <glm/vec3.hpp>

class Union : public Operation
{
public:
    Union() {}
    void apply(VertexList &vlist1, VertexList &vlist2, VertexList &result) override;
    State classify(State &s1, State &s2);
};

#endif // UNION_H