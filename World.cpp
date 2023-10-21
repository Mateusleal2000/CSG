#include "World.hpp"
#include <iostream>

State World::setMembership(glm::vec3 edgeMin, glm::vec3 edgeMax)
{
    getParent();
    return State::OUT;
}

// Node *World::getChild(int idx)
//{
//     std::cout << "World Error\n";
//     exit(-1);
// }

void World::setChild(Node *node)
{
    return;
}
Node *World::getChild(int idx)
{
    // auto node = new Node();
    return child;
}

void World::_print()
{
    std::cout << "World\n";
}