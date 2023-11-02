#ifndef CAMERA_H
#define CAMERA_H

#include "Ray.hpp"
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <glm/mat4x4.hpp>
#include <glm/geometric.hpp>
#include <glm/ext.hpp>

class Camera
{
public:
    Camera();
    ~Camera();
    glm::vec3 getPos() const;
    void setPos(glm::vec3 _pos);
    void setFoward(glm::vec3 _lookAt);
    Ray computeRayDir(int x, int y);
    void init(float _fov = 90., float _near = 0.1, float _far = 100., int _viewPortWidth = 0, int _viewPortHeight = 0);

private:
    glm::vec3 pos;
    glm::vec3 foward;
    glm::vec3 up;
    int viewPortWidth;
    int viewPortHeight;
    float fov;
    float near;
    float far;
    glm::mat4 viewMatrix;
    glm::mat4 invViewMatrix;
    glm::mat4 projMatrix;
    glm::mat4 invProjMatrix;

private:
    void updateCamera();
};

#endif // EYE_H