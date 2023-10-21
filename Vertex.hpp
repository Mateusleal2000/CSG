#ifndef VERTEX_H
#define VERTEX_H
#include <glm/vec3.hpp>
#include "tracer/Material.hpp"
#include "Solid.hpp"

class Vertex
{
public:
    Vertex(Solid *solid);
    ~Vertex() = default;

private:
    glm::vec3 point;
    glm::vec3 normal;
    Solid *solid;
};

#endif // VERTEX_H
