#include "Ray.hpp"

Ray::Ray(Point3 point, Vec3 direction)
{
    p = point;
    dir = direction;
    unitRay = unit(p + dir);
}

Ray::~Ray() {}

Vec3 Ray::getUnitRay() const
{
    return unitRay;
}

Point3 Ray::getPoint() const
{
    return p;
}

Vec3 Ray::getDir() const
{
    return dir;
}
