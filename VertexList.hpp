#ifndef VERTEXLIST_HPP
#define VERTEXLIST_HPP
#include "Interval.hpp"
#include "Vertex.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
class VertexList
{
public:
    VertexList(glm::vec3 eyePoint = glm::vec3(0.0));
    // adiciona ordenadamente
    void addVertex(Vertex &v);
    // remove por indice
    void removeVertex(const int idx);
    // remove por vértice
    void removeVertex(Vertex &v);
    std::vector<Vertex> *getVertexList();
    Vertex &firstVertex();
    Vertex &lastVertex();

    void addInterval(Interval *interval);
    void removeInterval(Interval &interval);
    void removeInterval(int idx);
    void refactorIntervals();
    void _print();

private:
    std::vector<Vertex> *vertexList;
    std::vector<Interval> *intervalList;
};

#endif // VERTEXLIST_HPP