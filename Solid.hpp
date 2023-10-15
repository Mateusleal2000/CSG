#ifndef SOLID_H
#define SOLID_H

#include "vec3.hpp"

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
    virtual State setMembership(Point3 edgeMin, Point3 edgeMax);
    void setColor(RGBcolor color);

private:
    RGBcolor color;
};

inline void Solid::setColor(RGBcolor color)
{
    this->color = color;
}

#endif // SOLID_H