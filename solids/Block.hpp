#ifndef BLOCK_H
#define BLOCK_H

#include "Solid.hpp"

class Block : public Solid
{
public:
    Block();
    Block(glm::vec3 p_min, float size_x, float size_y, float size_z);
    void setMembership(const Ray &ray, VertexList &vl, const glm::mat4 &modelMatrix, const glm::mat4 &modelMatrixInv) override;

private:
    float size_x;
    float size_y;
    float size_z;
    glm::vec3 p_min;
};

#endif // BLOCK_H