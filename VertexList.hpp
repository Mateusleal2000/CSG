#ifndef VERTEXLIST_HPP
#define VERTEXLIST_HPP
#include "Vertex.hpp"
#include <vector>
#include <algorithm>
#include <iostream>

class Vertex;
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
    int getVertexListSize();

    void refactorIntervals();
    void _print();

private:
    std::vector<Vertex> *vertexList;
};

#endif // VERTEXLIST_HPP