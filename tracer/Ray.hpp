#ifndef RAY_H
#define RAY_H

#include "../vec3.hpp"

class Ray
{
public:
    Ray(Point3 point = Point3(), Vec3 direction = Vec3());
    ~Ray();

    Point3 getPoint() const;
    Vec3 getDir() const;
    Vec3 getUnitRay() const;

private:
    Point3 p;
    Vec3 dir;
    Vec3 unitRay;
};

#endif