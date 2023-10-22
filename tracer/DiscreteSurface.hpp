#ifndef DISCRETE_SURFACE_H
#define DISCRETE_SURFACE_H
#include "Sampler.hpp"
#include <glm/vec3.hpp>
#include <vector>

class DiscreteSurface
{
private:
public:
    ~DiscreteSurface();

protected:
    virtual void calcPointsInsideRect(glm::vec3 P0, float s1, float s2, glm::vec3 d0, glm::vec3 d1, int qtde, std::vector<glm::vec3> &Pvec)
    { // pvec precisa ter o tamanho ja alocado
        float pixeldx = s1 / (float)qtde;
        float pixeldy = s2 / (float)qtde;
        for (int i = 0; i < qtde; i++)
        {
            P0 = P0 + pixeldy * d1;
            for (int j = 0; j < qtde; j++)
            {
                glm::vec3 Pnext = P0 + j * pixeldx * d0;
                glm::vec3 Pn = Sampler::getSample(0, 1) * (Pnext + d0) + Sampler::getSample(0, 1) * (Pnext + d1);
                Pvec.emplace_back(Pn);
            }
        }
    }
};

DiscreteSurface::~DiscreteSurface()
{
}

#endif // DISCRETE_SURFACE_H