#include "World.hpp"
#include <iostream>

void World::setMembership(const Ray &ray, VertexList &vl)
{
    // std::cout << "ENTROU NO SMS DO NO MUNDO\n";
    return;
}

void World::setChild(Node *node)
{
    std::cout << "WORLD NAO PODE TER FILHOS!\n";
    exit(-1);
}
Node *World::getChild(int idx)
{
    std::cout << "WORLD NAO PODE TER FILHOS!\n";
    exit(-1);
}

void World::_print()
{
    std::cout << "World\n";
}

void World::transformationRequest(glm::vec3 t, glm::vec3 s, int axis, float angle)
{
    return;
}
