#ifndef SCALE_HPP
#define SCALE_HPP

#include "Solid.hpp"
#include "matrix.hpp"
class Scale
{
public:
    virtual ~Scale();
    virtual State setMembership(Point3 edgeMin, Point3 edgeMax);

private:
    Matrix<float, 4, 4> *matrix;
    Solid *tranformedSolid;
};

#endif // SCALE_HPP