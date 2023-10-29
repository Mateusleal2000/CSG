#include "Sphere.hpp"

Sphere::Sphere(float rad, glm::vec3 center) : radius(rad), center(center)
{
}

void Sphere::setMembership(glm::vec3 eye, glm::vec3 D, VertexList &vl)
{
    float r = getRadius();
    glm::vec3 c_minus_o = glm::vec3(eye - getCenter());
    float a = glm::dot(D, D);
    float b = 2 * glm::dot(c_minus_o, D);
    float c = glm::dot(c_minus_o, c_minus_o) - r * r;

    float discriminant = (b * b) - (4 * a * c);

    if (discriminant < 0)
    {
        return;
    }
    else if (discriminant > 0)
    {
        float t1 = (-b + sqrt(discriminant)) / (2 * a);
        float t2 = (-b - sqrt(discriminant)) / (2 * a);
        glm::vec3 p1 = eye + (t1 * D);
        glm::vec3 N1 = (p1 - getCenter());
        glm::vec3 p2 = eye + (t2 * D);
        glm::vec3 N2 = (p2 - getCenter());
        Vertex v1 = Vertex(this, p1, glm::normalize(N1));
        Vertex v2 = Vertex(this, p2, glm::normalize(N2));
        v1.setEyePoint(eye);
        v2.setEyePoint(eye);
        if (v1 < v2)
        {
            v1.setSmsPair(State::OUT, State::IN);
            v2.setSmsPair(State::IN, State::OUT);
        }
        else
        {
            v2.setSmsPair(State::OUT, State::IN);
            v1.setSmsPair(State::IN, State::OUT);
        }
        vl.addVertex(v1);
        vl.addVertex(v2);
    }
    else
    {
        float t1 = (-b) / (2 * a);
        glm::vec3 p1 = eye + (t1 * D);
        glm::vec3 N1 = (p1 - getCenter());
        Vertex v1 = Vertex(this, p1, glm::normalize(N1));
        v1.setEyePoint(eye);
        v1.setSmsPair(State::ON, State::ON);
        vl.addVertex(v1);
    }
    return;
}

void Sphere::setRadius(float rad)
{
    this->radius = rad;
}

void Sphere::setCenter(glm::vec3 center)
{
    this->center = center;
}

float Sphere::getRadius()
{
    return radius;
}

glm::vec3 Sphere::getCenter()
{
    return center;
}

void Sphere::applyTransformations(glm::mat4 scaleMatrix, glm::mat4 translationMatrix, glm::mat4 rotationMatrix)
{
    radius = radius * scaleMatrix[0][0];
    center = glm::vec3(translationMatrix * glm::vec4(center, 1.0));
    return;
}