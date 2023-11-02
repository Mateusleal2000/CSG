#include "World.hpp"
#include <iostream>

void World::setMembership(const Ray &ray, VertexList &vl)
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