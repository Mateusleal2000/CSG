#include "Plane.hpp"

Plane::Plane()
{
}

void Plane::setMembership(const Ray &ray, VertexList &vl, const glm::mat4 &modelMatrix, const glm::mat4 &modelMatrixInv)
{
    glm::vec3 end = ray.getPoint() + ray.getUnitDir();
    glm::vec3 eye = ray.getPoint();
    glm::vec4 end_aux = glm::vec4(end, 1.0);
    glm::vec4 eye_aux = glm::vec4(eye, 1.0);
    eye = modelMatrixInv * eye_aux;
    glm::vec3 D = glm::normalize(glm::vec3((modelMatrixInv * end_aux) - glm::vec4(eye, 1.0)));

    if (fabs(D.z) >= 1e-21f)
    {
        float t = eye.z / -D.z;
        if (t > 0.0)
        {
            float u = eye.x + (D.x * t);
            float v = eye.y + (D.y * t);

            if (fabs(u) <= 1.0 && fabs(v) <= 1.0)
            {
                if (fabs(fabs(u) - 1.0) <= 1e-2 || fabs(fabs(v) - 1.0) <= 1e-2)
                {
                    glm::vec3 p = eye + (t * D);
                    p = glm::vec3(modelMatrix * glm::vec4(p, 1.0));
                    glm::vec3 localNormal = glm::vec3(0., 0., -1.0);
                    glm::vec3 globalNormal = glm::vec3(modelMatrix * glm::vec4(localNormal, 1.0)) - p;
                    // Talvez seja melhor trocar essa normal who knows...
                    Vertex v = Vertex(this, p, globalNormal);
                    v.setEyePoint(eye);
                    v.setSmsPair(State::ON, State::ON);
                    vl.addVertex(v);
                }
                else
                {
                    glm::vec3 p = eye + (t * D);
                    p = glm::vec3(modelMatrix * glm::vec4(p, 1.0));
                    glm::vec3 localNormal = glm::vec3(0., 0., -1.0);
                    glm::vec3 globalNormal = glm::vec3(modelMatrix * glm::vec4(localNormal, 1.0)) - p;
                    // Talvez seja melhor trocar essa normal who knows...
                    Vertex v = Vertex(this, p, globalNormal);
                    v.setEyePoint(ray.getPoint());
                    v.setSmsPair(State::IN, State::IN);
                    vl.addVertex(v);
                }
            }
        }
        else
        {
            return;
        }
    }
    else
    {
        return;
    }

    return;
}
