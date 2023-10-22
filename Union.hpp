#ifndef UNION_H
#define UNION_H

#include "Operation.hpp"
#include <glm/vec3.hpp>

class Union : public Operation
{
public:
    Union() {}
    void apply(VertexList &vlist1, VertexList &vlist2, VertexList &result);
};

#endif // UNION_H