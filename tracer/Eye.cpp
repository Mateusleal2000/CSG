#include "Eye.hpp"

Eye::Eye(glm::vec3 position)
{
    pos = position;
}

Eye::~Eye() {}

glm::vec3 Eye::getPos() const
{
    return pos;
}

Ray Eye::castRay(glm::vec3 destination) const
{
    glm::vec3 dir = glm::normalize(destination - pos);
    return Ray(pos, dir);
}