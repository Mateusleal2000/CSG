#ifndef SPHERE_H
#define SPHERE_H

#include "Solid.hpp"
#include <glm/vec3.hpp>

class Sphere : public Solid
{
public:
    // Sphere();
    Sphere(float rad, glm::vec3 center);
    State setMembership(glm::vec3 edgeMin, glm::vec3 edgeMax) override;
    void setRadius(float rad);
    void setCenter(glm::vec3 center);
    float getRadius();
    glm::vec3 getCenter();

private:
    float radius;
    glm::vec3 center;
};

#endif // SPHERE_H