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

// bool canInsert(Interval a, Interval b)
// {
//     if ()
//     {
//         return true;
//     }
//     return false;
// }

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

void VertexList::addInterval(Interval *interval)
{
    for (int i = 0; i < intervalList->size(); i++)
    {
        if (intervalList->at(i).getInitial() > interval->getInitial())
        {
            this->intervalList->insert(intervalList->begin() + i, *interval);
            return;
        }
    }
    this->intervalList->push_back(*interval);
    return;
}

void VertexList::removeInterval(Interval &interval)
{

    return;
}

void VertexList::removeInterval(int idx)
{
    intervalList->erase(intervalList->begin() + idx);
    return;
}

void VertexList::refactorIntervals()
{
    for (int i = 0; i < intervalList->size() - 1; i++)
    {
        if (intervalList->at(i).getState() == intervalList->at(i + 1).getState())
        {
            Interval *newInterval = new Interval(intervalList->at(i).getInitial(), intervalList->at(i + 1).getFinal(), intervalList->at(i).getState());
            removeInterval(i);
            removeInterval(i + 1);
            addInterval(newInterval);
        }
    }
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
