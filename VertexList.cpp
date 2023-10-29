#include "VertexList.hpp"
#include <iostream>

VertexList::VertexList(glm::vec3 eyePoint)
{
    this->vertexList = new std::vector<Vertex>();
    Vertex initialVertex = Vertex(nullptr, eyePoint);
    initialVertex.setEyePoint(eyePoint);
    this->vertexList->push_back(initialVertex);
}
// adiciona ordenadamente
void VertexList::addVertex(Vertex &v)
{
    auto it = std::upper_bound(this->vertexList->cbegin(), this->vertexList->cend(), v);
    v.setEyePoint(firstVertex().getPoint());
    this->vertexList->insert(it, v);
    return;
}

// remove por indice
void VertexList::removeVertex(const int idx)
{
    this->vertexList->erase(vertexList->begin() + idx);
    return;
}

bool checkEquals(Vertex a, Vertex b)
{
    if ((a.getPoint() == b.getPoint()) && (a.getNormal() == b.getNormal()))
    {
        return true;
    }
    return false;
}

// remove por vértice
void VertexList::removeVertex(Vertex &v)
{
    for (int i = 0; i < vertexList->size(); i++)
    {
        if (checkEquals(vertexList->at(i), v))
        {
            vertexList->erase(vertexList->begin() + i);
            return;
        }
    }
    return;
}

std::vector<Vertex> *VertexList::getVertexList()
{
    return this->vertexList;
}

Vertex &VertexList::firstVertex()
{
    return this->vertexList->front();
}

Vertex &VertexList::lastVertex()
{
    return this->vertexList->at(this->vertexList->size() - 1);
}

// remover vértices que são IN/IN e OUT/OUT
void VertexList::refactorIntervals()
{
    // std::vector<Vertex> newVertexList = {};

    // for (int i = 0; i < vertexList->size(); i++)
    // {
    //     if (vertexList->at(i).getSmsPair()->second)
    //     {
    //     }
    // }
}

void VertexList::_print()
{
    std::cout << "VertexList\n";
    for (auto elem : *(this->getVertexList()))
    {
        std::cout << elem.getPoint()[0] << std::endl
                  << elem.getPoint()[1] << std::endl
                  << elem.getPoint()[2] << std::endl
                  << std::endl;
    }
}
