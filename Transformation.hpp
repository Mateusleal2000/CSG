#ifndef TRANSFORMATION_HPP
#define TRANSFORMATION_HPP

#include "Solid.hpp"
#include "matrix.hpp"
class Transformation
{
public:
    virtual ~Transformation();
    virtual State setMembership(Point3 edgeMin, Point3 edgeMax);

private:
    Matrix<float, 4, 4> *matrix;
    Solid *tranformedSolid;
};

#endif // TRANSFORMATION_HPP