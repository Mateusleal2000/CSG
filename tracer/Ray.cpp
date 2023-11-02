#include "Ray.hpp"

Ray::Ray(glm::vec3 point, glm::vec3 _end)
{
    begin = point;
    end = _end;
    unitDir = glm::normalize(end - begin);
}

Ray::~Ray() {}

glm::vec3 Ray::getUnitDir() const
{
    return this->unitDir;
}

glm::vec3 Ray::getPoint() const
{
    return begin;
}

glm::vec3 Ray::getDir() const
{
    return unitDir;
}
