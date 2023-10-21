#ifndef UNION_H
#define UNION_H

#include "Operation.hpp"
#include <glm/vec3.hpp>

class Union : public Operation
{
public:
    Union();
    State setMembership(glm::vec3 edgeMin, glm::vec3 edgeMax) override;
};

#endif // UNION_H