#ifndef OPERATION_H
#define OPERATION_H

#include <glm/vec3.hpp>
#include "Solid.hpp"

class Operation
{
public:
    virtual ~Operation() {}
    virtual State setMembership(glm::vec3 edgeMin, glm::vec3 edgeMax) = 0;
};

#endif // OPERATION_H