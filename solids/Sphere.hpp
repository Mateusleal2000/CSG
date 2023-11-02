#ifndef SPHERE_H
#define SPHERE_H

#include "Solid.hpp"
#include "../tracer/Ray.hpp"
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

class Sphere : public Solid
{
public:
    Sphere();
    void setMembership(const Ray &ray, VertexList &vl, const glm::mat4 &modelMatrix, const glm::mat4 &modelMatrixInv) override;

private:
};

#endif // SPHERE_H