#include "Rotation.hpp"

Rotation::Rotation(float axis, float angle)
{
    glm::vec3 vec(0.);
    vec[axis] = 1;
    matrix = glm::rotate(matrix, glm::radians(angle), vec);
}