#ifndef EYE_H
#define EYE_H

#include "Ray.hpp"
#include <glm/vec3.hpp>
#include <glm/geometric.hpp>

class Eye
{
public:
    Eye(glm::vec3 pos = glm::vec3());
    ~Eye();
    glm::vec3 getPos() const;
    Ray castRay(glm::vec3 dest) const;

private:
    glm::vec3 pos;
};

#endif // EYE_H