#include "Scale.hpp"
Scale::Scale(float x, float y, float z)
{
    matrix = glm::scale(matrix, glm::vec3(x, y, z));
}