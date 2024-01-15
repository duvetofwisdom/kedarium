#include "Kedarium/Solids.hpp"

GLuint cubeIndices[] = {
  0, 1, 3,
  0, 3, 2,
  1, 5, 7,
  1, 7, 3,
  5, 4, 6,
  5, 6, 7,
  4, 0, 2,
  4, 2, 6,
  2, 3, 7,
  2, 7, 6,
  4, 5, 1,
  4, 1, 0,
};

kdr::Solids::Cube::Cube(const kdr::Space::Vec3& position, const float edgeLength) : kdr::Solids::Solid(position)
{
  GLfloat cubeVertices[] = {
    -(edgeLength / 2.f), -(edgeLength / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f,
     (edgeLength / 2.f), -(edgeLength / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f,
    -(edgeLength / 2.f),  (edgeLength / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f,
     (edgeLength / 2.f),  (edgeLength / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f,
    -(edgeLength / 2.f), -(edgeLength / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f,
     (edgeLength / 2.f), -(edgeLength / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f,
    -(edgeLength / 2.f),  (edgeLength / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f,
     (edgeLength / 2.f),  (edgeLength / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f,
  };
  
  this->VAO = new kdr::Graphics::VAO();
  this->VBO = new kdr::Graphics::VBO(cubeVertices, sizeof(cubeVertices));
  this->EBO = new kdr::Graphics::EBO(cubeIndices, sizeof(cubeIndices));

  this->VAO->Bind();
  this->VBO->Bind();
  this->EBO->Bind();

  this->VAO->LinkAttrib(*this->VBO, 0, 3, GL_FLOAT, 6 * sizeof(GLfloat), (void*)0);
  this->VAO->LinkAttrib(*this->VBO, 1, 3, GL_FLOAT, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));

  this->VAO->Unbind();
  this->VBO->Unbind();
  this->EBO->Unbind();
}

void kdr::Solids::Cube::render()
{
  this->VAO->Bind();
  glDrawElements(GL_TRIANGLES, sizeof(cubeIndices) / sizeof(GLuint), GL_UNSIGNED_INT, NULL);
  this->VAO->Unbind();
}
