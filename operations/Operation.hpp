#ifndef OPERATION_H
#define OPERATION_H

#include "../VertexList.hpp"

class Operation
{
public:
    virtual ~Operation() {}
    virtual void apply(VertexList &vlist1, VertexList &vlist2, VertexList &result) = 0;
};

#endif // OPERATION_H