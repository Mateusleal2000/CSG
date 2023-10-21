#include "Vertex.hpp"
#include <iostream>

Vertex::Vertex(Solid *solid)
{
    solid = solid;
    point = glm::vec3(0.);
    normal = glm::vec3(0.);

    std::cout << "Construido\n";
}