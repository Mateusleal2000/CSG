#ifndef SPHERE_H
#define SPHERE_H

#include "Solid.hpp"
#include <glm/vec3.hpp>

class Sphere : public Solid
{
public:
    Sphere(float rad, glm::vec3 center);
    void setMembership(glm::vec3 eye, glm::vec3 D, VertexList &vl) override;
    void setRadius(float rad);
    void setCenter(glm::vec3 center);
    float getRadius();
    void applyTransformations(glm::mat4 scaleMatrix, glm::mat4 translationMatrix, glm::mat4 rotationMatrix) override;
    glm::vec3 getCenter();

private:
    float radius;
    glm::vec3 center;
};

#endif // SPHERE_H