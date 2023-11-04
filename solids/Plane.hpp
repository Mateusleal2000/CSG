#ifndef PLANE_H
#define PLANE_H

#include "Solid.hpp"
#include "../tracer/Ray.hpp"
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

class Plane : public Solid
{

public:
    Plane();
    void setMembership(const Ray &ray, VertexList &vl, const glm::mat4 &modelMatrix, const glm::mat4 &modelMatrixInv);
};

#endif // PLANE_H