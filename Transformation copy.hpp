#ifndef TRANSFORMATION_HPP
#define TRANSFORMATION_HPP

#include "Solid.hpp"
#include "matrix.hpp"
class Transformation
{
public:
    virtual ~Transformation();

private:
    Matrix<float, 4, 4> *matrix;
};

#endif // TRANSFORMATION_HPP