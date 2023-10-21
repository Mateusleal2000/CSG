#ifndef TRANSLATION_H
#define TRANSLATION_H
#include "Transformation.hpp"

class Translation : public Transformation
{
public:
    Translation(float x = 0, float y = 0, float z = 0);
    ~Translation();
};

#endif // TRANSLATION_H