#ifndef SCALE_HPP
#define SCALE_HPP

#include "Transformation.hpp"
class Scale
{
public:
    virtual ~Scale();
    virtual State setMembership(glm::vec3 edgeMin, glm::vec3 edgeMax);

private:
    glm::mat4 *matrix;
    Solid *tranformedSolid;
};

#endif // SCALE_HPP