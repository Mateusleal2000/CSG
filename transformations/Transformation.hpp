#ifndef TRANSFORMATION_HPP
#define TRANSFORMATION_HPP

#include "../solids/Solid.hpp"
#include <iostream>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
class Transformation
{
public:
    Transformation() { matrix = glm::mat4(1.0); }
    virtual ~Transformation() {}
    glm::mat4x4 getMatrix();

    virtual void printTransform();

protected:
    glm::mat4x4 matrix;
};

inline void Transformation::printTransform()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cout << matrix[j][i] << " ";
        }
        std::cout << "\n";
    }
}

inline glm::mat4x4 Transformation::getMatrix()
{
    return matrix;
}

#endif // TRANSFORMATION_HPP