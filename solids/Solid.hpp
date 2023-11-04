#ifndef SOLID_H
#define SOLID_H

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include "../VertexList.hpp"
#include "../tracer/Ray.hpp"

class VertexList;
class Solid
{

public:
    virtual ~Solid() {}
    virtual void setMembership(const Ray &ray, VertexList &vl, const glm::mat4 &modelMatrix, const glm::mat4 &modelMatrixInv) = 0;
    glm::vec3 getKD();
    glm::vec3 getKE();
    float getShininess();

    void setKD(glm::vec3 KD);
    void setKE(glm::vec3 KE);
    void setShininess(float _shininess);

protected:
    glm::vec3 kd{0., 0., 0.};
    glm::vec3 ke{0., 0., 0.};
    float shininess;
};

inline glm::vec3 Solid::getKD()
{
    return kd;
}

inline glm::vec3 Solid::getKE()
{
    return ke;
}

inline float Solid::getShininess()
{
    return shininess;
}

inline void Solid::setKD(glm::vec3 _kd)
{
    kd = _kd;
}

inline void Solid::setKE(glm::vec3 _ke)
{
    ke = _ke;
}

inline void Solid::setShininess(float _shininess)
{
    shininess = _shininess;
}

#endif // SOLID_H