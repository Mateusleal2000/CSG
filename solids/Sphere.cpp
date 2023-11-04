#include "Sphere.hpp"

Sphere::Sphere()
{
}

void Sphere::setMembership(const Ray &ray, VertexList &vl, const glm::mat4 &modelMatrix, const glm::mat4 &modelMatrixInv)
{
    glm::vec3 end = ray.getPoint() + ray.getUnitDir();
    glm::vec3 eye = ray.getPoint();
    glm::vec4 eye_aux(eye, 1.);
    glm::vec4 end_aux(end, 1.);
    eye = modelMatrixInv * eye_aux;
    glm::vec3 D = glm::normalize(glm::vec3((modelMatrixInv * end_aux) - glm::vec4(eye, 1.0)));

    float b = 2.0 * glm::dot(eye, D);
    float c = glm::dot(eye, eye) - 1.;

    float discriminant = (b * b) - (4.0f * c);

    if (discriminant < 0)
    {
        return;
    }
    else if (discriminant > 10e-2)
    {
        float t1 = (-b + sqrt(discriminant)) / (2.0f);
        float t2 = (-b - sqrt(discriminant)) / (2.0f);
        glm::vec3 p1 = glm::vec3(modelMatrix * glm::vec4(eye + (t1 * D), 1.));
        glm::vec3 N1 = (p1 - glm::vec3(modelMatrix * glm::vec4(0., 0., 0., 1.)));
        glm::vec3 p2 = glm::vec3(modelMatrix * glm::vec4(eye + (t2 * D), 1.));
        glm::vec3 N2 = (p2 - glm::vec3(modelMatrix * glm::vec4(0., 0., 0., 1.)));
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
        float t1 = (-b) / (2.);
        glm::vec3 p1 = glm::vec3(modelMatrix * glm::vec4(eye + (t1 * D), 1.));
        glm::vec3 N1 = (p1 - glm::vec3(modelMatrix * glm::vec4(0., 0., 0., 1.)));
        Vertex v1 = Vertex(this, p1, glm::normalize(N1));
        v1.setEyePoint(ray.getPoint());
        v1.setSmsPair(State::ON, State::ON);
        vl.addVertex(v1);
    }
    return;
}
