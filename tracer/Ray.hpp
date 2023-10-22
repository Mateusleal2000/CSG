#ifndef RAY_H
#define RAY_H

#include <glm/vec3.hpp>
#include <glm/geometric.hpp>

class Ray
{
public:
    Ray(glm::vec3 point = glm::vec3(), glm::vec3 direction = glm::vec3());
    ~Ray();

    glm::vec3 getPoint() const;
    glm::vec3 getDir() const;
    glm::vec3 getUnitDir() const;

private:
    glm::vec3 p;
    glm::vec3 dir;
    glm::vec3 unitDir;
};

#endif // RAY_H