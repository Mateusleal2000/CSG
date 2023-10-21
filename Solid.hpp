#ifndef SOLID_H
#define SOLID_H

#include <glm/vec3.hpp>
#include "tracer/Material.hpp"
//// #include "State.hpp"

// esse enum é relativo à aresta passada como argumento do setMembership
// pode mudar pra estar em outra classe caso necessario
enum State
{
    IN = 0,
    ON = 1,
    OUT = 2
};

class Solid
{

public:
    virtual ~Solid() {}
    virtual State setMembership(glm::vec3 edgeMin, glm::vec3 edgeMax) = 0;
    virtual Material *getMaterial();

private:
    Material *material;
};

inline Material *Solid::getMaterial()
{
    return material;
}

// inline void Solid::setColor(glm::vec3 color)
//{
//     this->color = color;
// }

#endif // SOLID_H