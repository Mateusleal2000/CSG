#include "Canvas.hpp"
#include <iostream>

Canvas::Canvas(QOpenGLContext *_context) : GLObject()
{
  if (_context != nullptr)
  {
    currentContext = _context;
  }
}

Canvas::~Canvas() {}

void Canvas::init()
{
  f = QOpenGLVersionFunctionsFactory::get<QOpenGLFunctions_3_3_Core>(currentContext);
  if (currentContext == nullptr)
  {
    std::cout << "Context is null\n";
  }

  vertexVector.reserve(4);

  vertexVector.emplace_back(GLVertex{glm::vec3(1.0, 1.0, 0.), glm::vec3(1., 0., 0.), glm::vec2(1., 0.)});
  vertexVector.emplace_back(GLVertex{glm::vec3(1.0, -1.0, 0.), glm::vec3(0., 1., 0.), glm::vec2(1., 1.)});
  vertexVector.emplace_back(GLVertex{glm::vec3(-1.0, -1.0, 0.), glm::vec3(0., 0., 1.), glm::vec2(0., 1.)});
  vertexVector.emplace_back(GLVertex{glm::vec3(-1.0, 1.0, 0.), glm::vec3(1., 1., 0.), glm::vec2(0., 0.)});

  indiciesVector.reserve(6);
  indiciesVector.emplace_back(0);
  indiciesVector.emplace_back(1);
  indiciesVector.emplace_back(3);
  indiciesVector.emplace_back(1);
  indiciesVector.emplace_back(2);
  indiciesVector.emplace_back(3);

  EBO.reserve(1);
  EBO.resize(1);

  VBO.reserve(1);
  VBO.resize(1);

  VAO.reserve(1);
  VAO.resize(1);

  textures.reserve(1);
  textures.resize(1);

  program.reserve(1);
  program.resize(1);

  std::cout << "naoleu\n";

  f->glGenBuffers(1, &VBO[0]);
  f->glGenBuffers(1, &EBO[0]);
  f->glGenVertexArrays(1, &VAO[0]);

  program[0] = GLProgram(currentContext);
  program[0].createShaderFromFile("vert_shader.vert", "frag_shader.frag");

  f->glBindVertexArray(VAO[0]);

  f->glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
  f->glBufferData(GL_ARRAY_BUFFER, sizeof(GLVertex) * vertexVector.size(), vertexVector.data(), GL_DYNAMIC_DRAW);

  f->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO[0]);
  f->glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint) * indiciesVector.size(), indiciesVector.data(), GL_DYNAMIC_DRAW);

  GLint pos_attrib = f->glGetAttribLocation(program[0].getProgramId(), "position");
  GLint color_attrib = f->glGetAttribLocation(program[0].getProgramId(), "color_a");
  GLint tex_attrib = f->glGetAttribLocation(program[0].getProgramId(), "text");

  f->glVertexAttribPointer(pos_attrib, 3, GL_FLOAT, GL_FALSE, sizeof(GLVertex), 0);
  f->glEnableVertexAttribArray(pos_attrib);

  f->glVertexAttribPointer(color_attrib, 3, GL_FLOAT, GL_FALSE, sizeof(GLVertex), (void *)sizeof(glm::vec3));
  f->glEnableVertexAttribArray(color_attrib);

  f->glVertexAttribPointer(tex_attrib, 2, GL_FLOAT, GL_FALSE, sizeof(GLVertex), (void *)(2 * sizeof(glm::vec3)));
  f->glEnableVertexAttribArray(tex_attrib);

  f->glBindBuffer(GL_ARRAY_BUFFER, 0);         // unbid current VBO
  f->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); // unbid current EBO
  f->glBindVertexArray(0);                     // unbind current VAO

  loadTexture("container.jpg");
  std::cout << "Leu\n";

  for (int i = 0; i < 640 * 480; i++)
  {
    v.push_back(150);
    v.push_back(150);
    v.push_back(150);
  }

  uchar *data = v.data(); // texImage->bits();

  f->glGenTextures(1, &textures[0]);
  // f->glActiveTexture(GL_TEXTURE0);
  f->glBindTexture(GL_TEXTURE_2D, textures[0]);

  f->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
  f->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

  f->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  f->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  int width = texImage->width();
  int height = texImage->height();

  if (data != nullptr)
  {
    f->glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    f->glGenerateMipmap(GL_TEXTURE_2D);
  }
  else
  {
    std::cout << "Erro! nullimage\n";
    exit(-1);
  }
  f->glUseProgram(program[0].getProgramId());
  f->glUniform1i(f->glGetUniformLocation(program[0].getProgramId(), "text"), 0);
}

void Canvas::draw()
{

  std::cout << "Desenhando\n";

  f->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  f->glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

  f->glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 640, 480, 0, GL_RGB, GL_UNSIGNED_BYTE, v.data());

  f->glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
  f->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO[0]);

  f->glActiveTexture(GL_TEXTURE0);
  f->glBindTexture(GL_TEXTURE_2D, textures[0]);

  f->glUseProgram(program[0].getProgramId());

  f->glBindVertexArray(VAO[0]);

  f->glDrawElements(GL_TRIANGLES, indiciesVector.size(), GL_UNSIGNED_INT, indiciesVector.data());

  f->glBindVertexArray(0);
  f->glBindBuffer(GL_ARRAY_BUFFER, 0);
  f->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Canvas::updateColor(int c1, int c2, int c3)
{
  v.clear();
  for (int i = 0; i < 640 * 480; i++)
  {
    v.push_back(c1);
    v.push_back(c2);
    v.push_back(c3);
  }
  std::cout << "Timer tick\n";
  return;
}
