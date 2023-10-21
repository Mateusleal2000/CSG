#include "Translation.hpp"

Translation::Translation(float x, float y, float z)
{
    matrix = glm::translate(matrix, glm::vec3(x, y, z));
}

Translation::~Translation() {}