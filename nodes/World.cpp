#include "World.hpp"
#include <iostream>

void World::setMembership(glm::vec3 eye, glm::vec3 D, VertexList &vl)
{
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