#ifndef EYE_H
#define EYE_H

#include "Ray.hpp"

class Eye
{
public:
    Eye(Point3 pos = Point3());
    ~Eye();
    Point3 getPos() const;
    Ray castRay(Point3 dest) const;

private:
    Point3 pos;
};

#endif // EYE_H