#include "Vertex.hpp"
#include <iostream>

Vertex::Vertex(Solid *_solid, glm::vec3 _point, glm::vec3 _normal)
{
    solid = _solid;
    point = _point;
    normal = _normal;
    smsPair = std::make_pair(State::NOPE, State::NOPE);
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

void Vertex::setSmsPair(State s1, State s2)
{
    smsPair.first = s1;
    smsPair.second = s2;
}

void Vertex::updateSmsPair(int side, State newState)
{
    side == 1 ? smsPair.first = newState : smsPair.second = newState;
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

std::pair<State, State> *Vertex::getSmsPair()
{
    return &smsPair;
}
