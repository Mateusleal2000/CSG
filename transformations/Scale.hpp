#ifndef SCALE_HPP
#define SCALE_HPP

#include "Transformation.hpp"
class Scale : public Transformation
{
public:
    Scale(float v = 0);
    ~Scale() = default;
};
#endif // SCALE_HPP