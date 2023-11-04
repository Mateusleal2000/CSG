#ifndef POINT_LIGHT_H
#define POINT_LIGHT_H

#include "Light.hpp"
#include <glm/geometric.hpp>

class PointLight : public Light{
  public:
  PointLight(glm::vec3 _intensity = glm::vec3(0.));
  ~PointLight() = default;
  glm::vec3 shade(const Vertex & v) override;

  private:
  glm::vec3 position;



};



#endif //POINT_LIGHT_H