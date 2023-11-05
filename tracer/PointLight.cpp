#include "PointLight.hpp"

PointLight::PointLight(glm::vec3 _intensity, glm::vec3 _position)
{
  intensity = _intensity;
  position = _position;
}

glm::vec3 PointLight::shade(const Vertex &v)
{
  glm::vec3 i(0.,0.,0.);
  glm::vec3 L(position - v.getPoint());
  //glm::vec3 L(v.getPoint() - position);
  glm::normalize(L);
  float n_dot_l = glm::dot(v.getNormal(), L);
  if (n_dot_l > 0)
  {
    i = i + (intensity * v.getSolid()->getKD() * n_dot_l);
  }
  glm::vec3 R = (v.getNormal() * 2.0f * n_dot_l) - L;
  glm::normalize(R);
  //glm::vec3 V = (v.getPoint()-v.getEyePoint()); // talvez o inverso
  glm::vec3 V = (v.getEyePoint() - v.getPoint()); // talvez o inverso
  glm::normalize(V);
  float r_dot_v = glm::dot(R, V);
  if (r_dot_v > 0)
  {
    i = i + (this->intensity * (v.getSolid()->getKE()) * std::pow(r_dot_v, v.getSolid()->getShininess()));
  }

  return i;

}

void PointLight::setPosition(glm::vec3 _position)
{
  position = _position;
}

glm::vec3 PointLight::getPosition()
{
  return position;
}