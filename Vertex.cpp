#include "Vertex.hpp"
#include <iostream>

Vertex::Vertex(Solid *_solid, glm::vec3 _point, glm::vec3 _normal)
{
    solid = _solid;
    point = _point;
    normal = _normal;
}

void Vertex::setPoint(glm::vec3 point)
{
    this->point = point;
}

void Vertex::setNormal(glm::vec3 normal)
{
    this->normal = normal;
}

void Vertex::setSolid(Solid *solid)
{
    this->solid = solid;
}

void Vertex::setEyePoint(glm::vec3 _eyePoint)
{
    eyePoint = _eyePoint;
}

glm::vec3 Vertex::getPoint() const
{
    return this->point;
}

glm::vec3 Vertex::getNormal() const
{
    return this->normal;
}

Solid *Vertex::getSolid()
{
    return this->solid;
}
