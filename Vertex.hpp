#ifndef VERTEX_H
#define VERTEX_H
#include <glm/vec3.hpp>
#include <glm/geometric.hpp>
#include <utility>
#include "tracer/Material.hpp"
#include "Solid.hpp"
#include "State.hpp"

class Solid;
class Vertex
{
public:
    Vertex(Solid *_solid = nullptr, glm::vec3 _point = glm::vec3(0.), glm::vec3 _normal = glm::vec3(0.));
    ~Vertex() = default;
    void setPoint(glm::vec3 point);
    void setNormal(glm::vec3 normal);
    void setSolid(Solid *solid);
    void setEyePoint(glm::vec3 eyePoint);
    void setSmsPair(State s1, State s2);
    void updateSmsPair(int point, State newState);
    glm::vec3 getPoint() const;
    glm::vec3 getNormal() const;
    Solid *getSolid();
    std::pair<State, State> *getSmsPair();
    bool operator<(const Vertex &a) const
    {
        float thisDist = glm::length(this->point - eyePoint);
        float otherDist = glm::length(a.getPoint() - eyePoint);
        return thisDist < otherDist;
    }

    bool operator>(const Vertex &a) const
    {
        float thisDist = glm::length(this->point - eyePoint);
        float otherDist = glm::length(a.getPoint() - eyePoint);
        return thisDist > otherDist;
    }

    bool operator<=(const Vertex &a) const
    {
        float thisDist = glm::length(this->point - eyePoint);
        float otherDist = glm::length(a.getPoint() - eyePoint);
        return thisDist <= otherDist;
    }

    bool operator>=(const Vertex &a) const
    {
        float thisDist = glm::length(this->point - eyePoint);
        float otherDist = glm::length(a.getPoint() - eyePoint);
        return thisDist >= otherDist;
    }

private:
    glm::vec3 point;
    glm::vec3 normal;
    glm::vec3 eyePoint;
    std::pair<State, State> smsPair;
    Solid *solid;
};

#endif // VERTEX_H
