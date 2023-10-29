#ifndef ROTATION_H
#define ROTATION_H
#include "Transformation.hpp"

class Rotation : public Transformation
{
public:
    Rotation(float axis = 0, float angle = 0);
    ~Rotation() = default;
};

#endif // ROTATION_H