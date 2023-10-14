#ifndef TRANSFORMATION_HPP
#define TRANSFORMATION_HPP

#include "Solid.hpp"
class Transformation
{
public:
    virtual ~Transformation();
    virtual State setMembership(Point3 edgeMin, Point3 edgeMax);

private:
    Solid *solid;
};

#endif // TRANSFORMATION_HPP