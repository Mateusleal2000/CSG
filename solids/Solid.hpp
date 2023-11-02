#ifndef SOLID_H
#define SOLID_H

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include "../VertexList.hpp"
#include "../tracer/Ray.hpp"

class VertexList;
class Solid
{

public:
    virtual ~Solid() {}
    virtual void setMembership(const Ray &ray, VertexList &vl, const glm::mat4 &modelMatrix, const glm::mat4 &modelMatrixInv) = 0;
    // Material *getMaterial();

protected:
    // Material *material;
};

// inline Material *Solid::getMaterial()
// {
//     return material;
// }

// inline void Solid::setColor(glm::vec3 color)
//{
//     this->color = color;
// }

#endif // SOLID_H