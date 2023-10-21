#ifndef TRANSFORMATION_HPP
#define TRANSFORMATION_HPP

#include "Solid.hpp"
#include <glm/mat4x4.hpp>
class Transformation
{
public:
    virtual ~Transformation() {}

private:
    glm::mat4x4 matrix;
};

#endif // TRANSFORMATION_HPP