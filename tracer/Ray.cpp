#include "Ray.hpp"

Ray::Ray(glm::vec3 point, glm::vec3 direction)
{
    p = point;
    dir = direction;
    unitDir = glm::normalize(p + dir);
}

Ray::~Ray() {}

glm::vec3 Ray::getUnitDir() const
{
    return this->unitDir;
}

glm::vec3 Ray::getPoint() const
{
    return p;
}

glm::vec3 Ray::getDir() const
{
    return dir;
}
