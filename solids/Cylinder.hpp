#ifndef CYLINDER_H
#define CYLINDER_H

#include "Solid.hpp"
#include "../tracer/Ray.hpp"
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

class Cylinder : public Solid
{

public:
    Cylinder();
    void setMembership(const Ray &ray, VertexList &vl, const glm::mat4 &modelMatrix, const glm::mat4 &modelMatrixInv);
};

#endif // CYLINDER_H