#ifndef SOLID_H
#define SOLID_H

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include "../VertexList.hpp"

class VertexList;
class Solid
{

public:
    virtual ~Solid() {}
    virtual void setMembership(glm::vec3 eye, glm::vec3 D, VertexList &vl) = 0;
    // Material *getMaterial();
    virtual void applyTransformations(glm::mat4 scaleMatrix, glm::mat4 translationMatrix, glm::mat4 rotationMatrix) = 0;

private:
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