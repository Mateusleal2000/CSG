#include "Camera.hpp"
#include <iostream>

Camera::Camera()
{
}

Camera::~Camera() {}

void Camera::init(float _fov, float _near, float _far, int _viewPortWidth, int _viewPortHeight)
{
    viewPortWidth = _viewPortWidth;
    viewPortHeight = _viewPortHeight;
    near = _near;
    fov = _fov;
    far = _far;
    foward = glm::vec3(0., 0., -1.);
    pos = glm::vec3(0.);
    up = glm::vec3(0., 1., 0.);

    viewMatrix = glm::mat4(1.0);
    invViewMatrix = glm::mat4(1.0);
    invProjMatrix = glm::mat4(1.0);
    projMatrix = glm::mat4(1.0);
    updateCamera();
}

glm::vec3 Camera::getPos() const
{
    return pos;
}

Ray Camera::computeRayDir(int x, int y)
{
    float ndcX = (float)x / (float)viewPortWidth;
    float ndcY = (float)y / (float)viewPortHeight;
    float screenX = ndcX * 2.0 - 1.;
    float screenY = (ndcY * 2.0) - 1.;
    glm::vec4 screenPoint(screenX, screenY, 1., 1.);
    screenPoint = invProjMatrix * screenPoint;
    return Ray(pos, pos + glm::vec3(invViewMatrix * glm::vec4((glm::vec3(screenPoint) / screenPoint.w), 0.)));
}

void Camera::updateCamera()
{
    viewMatrix = glm::lookAtRH(pos, pos + foward, up);
    invViewMatrix = glm::inverse(viewMatrix);
    projMatrix = glm::perspectiveFov(glm::radians(fov), (float)viewPortWidth, (float)viewPortHeight, near, far);
    invProjMatrix = glm::inverse(projMatrix);
}

void Camera::setFoward(glm::vec3 _foward)
{
    foward = _foward;
}

void Camera::setPos(glm::vec3 _pos)
{
    pos = _pos;
}