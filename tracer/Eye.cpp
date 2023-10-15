#include "Eye.hpp"

Eye::Eye(Point3 position)
{
    pos = position;
}

Eye::~Eye() {}

Point3 Eye::getPos() const
{
    return pos;
}

Ray Eye::castRay(Point3 destination) const
{
    Vec3 dir = unit(destination - pos);
    return Ray(pos, dir);
}