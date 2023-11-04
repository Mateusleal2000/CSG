#ifndef LIGHT_H
#define LIGHT_H

#include <glm/vec3.hpp>
#include "../Vertex.hpp"

class Light{
  public:
  virtual ~Light() = default;

  virtual glm::vec3 shade(const Vertex & v) = 0;

  protected:
  glm::vec3 intensity{0.,0.,0.};



};

#endif //LIGHT_H