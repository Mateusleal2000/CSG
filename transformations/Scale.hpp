#ifndef SCALE_HPP
#define SCALE_HPP

#include "Transformation.hpp"
class Scale : public Transformation
{
public:
    Scale(float x = 0, float y = 0, float z = 0);
    ~Scale() = default;
};
#endif // SCALE_HPP