#include "Scale.hpp"
Scale::Scale(float v)
{
    matrix = glm::scale(matrix, glm::vec3(v, v, v));
}