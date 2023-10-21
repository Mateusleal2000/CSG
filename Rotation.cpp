#include "Rotation.hpp"

Rotation::Rotation(float axis, float angle)
{
    glm::vec3 vec;
    vec[axis] = 1;
    matrix = glm::rotate(matrix, angle, vec);
}