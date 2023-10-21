#include "Ray.hpp"

Ray::Ray(glm::vec3 point, glm::vec3 direction)
{
    p = point;
    dir = direction;
    unitRay = glm::normalize(p + dir);
}

Ray::~Ray() {}

glm::vec3 Ray::getUnitRay() const
{
    return unitRay;
}

glm::vec3 Ray::getPoint() const
{
    return p;
}

glm::vec3 Ray::getDir() const
{
    return dir;
}
