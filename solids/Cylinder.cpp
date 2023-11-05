#include "Cylinder.hpp"
#include <cmath>

Cylinder::Cylinder()
{
}

void Cylinder::setMembership(const Ray &ray, VertexList &vl, const glm::mat4 &modelMatrix, const glm::mat4 &modelMatrixInv)
{
    glm::vec3 end = ray.getPoint() + ray.getUnitDir();
    glm::vec3 eye = ray.getPoint();
    glm::vec4 eye_aux(eye, 1.);
    glm::vec4 end_aux(end, 1.);
    eye = modelMatrixInv * eye_aux;
    glm::vec3 D = glm::normalize(glm::vec3((modelMatrixInv * end_aux) - glm::vec4(eye, 1.0)));

    float a = (D.x * D.x) + (D.y * D.y);
    float b = 2 * ((eye.x * D.x) + (eye.y * D.y));
    float c = (eye.x * eye.x) + (eye.y * eye.y) - 1;

    float delta = std::sqrt((b * b) - (4 * a * c));
    std::vector<float> t = {0.0, 0.0, 0.0, 0.0};
    std::vector<glm::vec3> poi = {glm::vec3(0.), glm::vec3(0.), glm::vec3(0.), glm::vec3(0.)};
    // O valor inteiro no par representa se a interseção é com cilindro ou com a tampa
    std::vector<std::pair<float, int>> intersectPair = {};
    // bool t1Valid, t2Valid, t3Valid, t4Valid;
    if (delta > 0.5)
    {
        float t0 = (-b + delta) / (2 * a);
        float t1 = (-b - delta) / (2 * a);

        glm::vec3 poi0 = eye + (D * t0);
        glm::vec3 poi1 = eye + (D * t1);

        if ((t0 > 0.0) && (fabs(poi0.z) < 1.0))
        {
            std::pair t1 = std::make_pair(t0, 0);
            intersectPair.push_back(t1);
        }
        if ((t1 > 0.0) && (fabs(poi1.z) < 1.0))
        {
            std::pair t2 = std::make_pair(t1, 0);
            intersectPair.push_back(t2);
        }
    }

    if (fabs(D.z) >= 1e-21f)
    {
        float t2 = (eye.z - 1.0) / (-D.z);
        float t3 = (eye.z + 1.0) / (-D.z);

        glm::vec3 poi2 = eye + (t2 * D);
        glm::vec3 poi3 = eye + (t3 * D);

        if ((t2 > 0.0) && (std::sqrt((poi2.x * poi2.x) + (poi2.y * poi2.y)) <= 1.0))
        {
            std::pair t3 = std::make_pair(t2, 1);
            intersectPair.push_back(t3);
        }

        if ((t3 > 0.0) && (std::sqrt((poi3.x * poi3.x) + (poi3.y * poi3.y)) <= 1.0))
        {
            std::pair t4 = std::make_pair(t3, 1);
            intersectPair.push_back(t4);
        }
    }

    if (intersectPair.size() == 0)
    {
        return;
    }

    if (intersectPair.size() == 1)
    {
        if (intersectPair.at(0).second == 0)
        {
            glm::vec3 poi = eye + (intersectPair.at(0).first * D);
            glm::vec3 poiw = modelMatrix * glm::vec4(poi, 1.0);
            glm::vec3 poip(poi.x, poi.y, 0.0);
            glm::vec3 poipw = modelMatrix * glm::vec4(poip, 1.0);
            glm::vec3 globalOrigin = modelMatrix * glm::vec4(0., 0., 0., 1.0);
            glm::vec3 newNormal = poipw - globalOrigin;
            Vertex v(this, poiw, glm::normalize(newNormal));
            v.setEyePoint(ray.getPoint());
            v.setSmsPair(State::ON, State::ON);
            vl.addVertex(v);
        }
        else
        {
            glm::vec3 poi = eye + (intersectPair.at(0).first * D);
            if (1 - std::sqrt((poi.x * poi.x) + (poi.y * poi.y)) <= 0.01)
            {
                glm::vec3 poiw = modelMatrix * glm::vec4(poi, 1.0);
                glm::vec3 poip(0.0, 0.0, poi.z);
                glm::vec3 poipw = modelMatrix * glm::vec4(poip, 1.0);
                glm::vec3 globalOrigin = modelMatrix * glm::vec4(0., 0., 0., 1.0);
                glm::vec3 newNormal = poipw - globalOrigin;
                Vertex v(this, poiw, glm::normalize(newNormal));
                v.setEyePoint(ray.getPoint());
                v.setSmsPair(State::ON, State::ON);
                vl.addVertex(v);
            }
        }
    }
    else if (intersectPair.size() == 2)
    {
        glm::vec3 poi1 = eye + (intersectPair.at(0).first * D);
        glm::vec3 poi2 = eye + (intersectPair.at(1).first * D);

        if (intersectPair.at(0).second == 0 && intersectPair.at(1).second == 0)
        {
            glm::vec3 poi1w = modelMatrix * glm::vec4(poi1, 1.0);
            glm::vec3 poi1p(poi1.x, poi1.y, 0.0);
            glm::vec3 poi1pw = modelMatrix * glm::vec4(poi1p, 1.0);
            glm::vec3 globalOrigin = modelMatrix * glm::vec4(0., 0., 0., 1.0);
            glm::vec3 newNormal1 = poi1pw - globalOrigin;
            Vertex v1(this, poi1w, glm::normalize(newNormal1));
            v1.setEyePoint(ray.getPoint());

            glm::vec3 poi2w = modelMatrix * glm::vec4(poi2, 1.0);
            glm::vec3 poi2p(poi2.x, poi2.y, 0.0);
            glm::vec3 poi2pw = modelMatrix * glm::vec4(poi2p, 1.0);
            // glm::vec3 globalOrigin = modelMatrix * glm::vec4(0., 0., 0., 1.0);
            glm::vec3 newNormal2 = poi2pw - globalOrigin;
            Vertex v2(this, poi2w, glm::normalize(newNormal2));
            v2.setEyePoint(ray.getPoint());

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
        else if (intersectPair.at(0).second == 1 && intersectPair.at(1).second == 1)
        {
            glm::vec3 poi1w = modelMatrix * glm::vec4(poi1, 1.0);
            glm::vec3 poi1p(0.0, 0.0, poi1.z);
            glm::vec3 poi1pw = modelMatrix * glm::vec4(poi1p, 1.0);
            glm::vec3 globalOrigin = modelMatrix * glm::vec4(0., 0., 0., 1.0);
            glm::vec3 newNormal1 = poi1pw - globalOrigin;
            Vertex v1(this, poi1w, glm::normalize(newNormal1));
            v1.setEyePoint(ray.getPoint());

            glm::vec3 poi2w = modelMatrix * glm::vec4(poi2, 1.0);
            glm::vec3 poi2p(0.0, 0.0, poi2.z);
            glm::vec3 poi2pw = modelMatrix * glm::vec4(poi2p, 1.0);
            // glm::vec3 globalOrigin = modelMatrix * glm::vec4(0., 0., 0., 1.0);
            glm::vec3 newNormal2 = poi2pw - globalOrigin;
            Vertex v2(this, poi2w, glm::normalize(newNormal2));
            v2.setEyePoint(ray.getPoint());

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
            if (intersectPair.at(0).second == 1)
            {
                glm::vec3 poi1w = modelMatrix * glm::vec4(poi1, 1.0);
                glm::vec3 poi1p(0.0, 0.0, poi1.z);
                glm::vec3 poi1pw = modelMatrix * glm::vec4(poi1p, 1.0);
                glm::vec3 globalOrigin = modelMatrix * glm::vec4(0., 0., 0., 1.0);
                glm::vec3 newNormal1 = poi1pw - globalOrigin;
                Vertex v1(this, poi1w, glm::normalize(newNormal1));
                v1.setEyePoint(ray.getPoint());

                glm::vec3 poi2w = modelMatrix * glm::vec4(poi2, 1.0);
                glm::vec3 poi2p(poi2.x, poi2.y, 0.0);
                glm::vec3 poi2pw = modelMatrix * glm::vec4(poi2p, 1.0);
                // glm::vec3 globalOrigin = modelMatrix * glm::vec4(0., 0., 0., 1.0);
                glm::vec3 newNormal2 = poi2pw - globalOrigin;
                Vertex v2(this, poi2w, glm::normalize(newNormal2));
                v2.setEyePoint(ray.getPoint());

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
                glm::vec3 poi2w = modelMatrix * glm::vec4(poi2, 1.0);
                glm::vec3 poi2p(0.0, 0.0, poi2.z);
                glm::vec3 poi2pw = modelMatrix * glm::vec4(poi2p, 1.0);
                glm::vec3 globalOrigin = modelMatrix * glm::vec4(0., 0., 0., 1.0);
                glm::vec3 newNormal2 = poi2pw - globalOrigin;
                Vertex v2(this, poi2w, glm::normalize(newNormal2));
                v2.setEyePoint(ray.getPoint());

                glm::vec3 poi1w = modelMatrix * glm::vec4(poi1, 1.0);
                glm::vec3 poi1p(poi1.x, poi1.y, 0.0);
                glm::vec3 poi1pw = modelMatrix * glm::vec4(poi1p, 1.0);
                // glm::vec3 globalOrigin = modelMatrix * glm::vec4(0., 0., 0., 1.0);
                glm::vec3 newNormal1 = poi1pw - globalOrigin;
                Vertex v1(this, poi1w, glm::normalize(newNormal1));
                v1.setEyePoint(ray.getPoint());

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
        }
    }
}
