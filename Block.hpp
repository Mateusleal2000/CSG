#ifndef BLOCK_H
#define BLOCK_H

#include "Solid.hpp"

class Block : public Solid
{
public:
    Block();
    Block(glm::vec3 p_min, float size_x, float size_y, float size_z);
    State setMembership(glm::vec3 edgeMin, glm::vec3 edgeMax) override;
    // Point3 getCenter();

private:
    float size_x;
    float size_y;
    float size_z;
    glm::vec3 p_min;
};

#endif // BLOCK_H