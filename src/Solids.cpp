#include "Kedarium/Solids.hpp"

void kdr::Solids::Solid::initializeMembers(GLfloat vertices[], GLsizeiptr verticesSize, GLuint indices[], GLsizeiptr indicesSize)
{
  this->VAO = new kdr::Graphics::VAO();
  this->VBO = new kdr::Graphics::VBO(vertices, verticesSize);
  this->EBO = new kdr::Graphics::EBO(indices, indicesSize);

  this->VAO->Bind();
  this->VBO->Bind();
  this->EBO->Bind();

  this->VAO->LinkAttrib(*this->VBO, 0, 3, GL_FLOAT, 11 * sizeof(GLfloat), (void*)0);
  this->VAO->LinkAttrib(*this->VBO, 1, 3, GL_FLOAT, 11 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
  this->VAO->LinkAttrib(*this->VBO, 2, 2, GL_FLOAT, 11 * sizeof(GLfloat), (void*)(6 * sizeof(GLfloat)));
  this->VAO->LinkAttrib(*this->VBO, 3, 3, GL_FLOAT, 11 * sizeof(GLfloat), (void*)(8 * sizeof(GLfloat)));

  this->VAO->Unbind();
  this->VBO->Unbind();
  this->EBO->Unbind();
}

GLuint cuboidIndices[] = {
  0, 3, 9,    // Front
  0, 9, 6,    // Front
  4, 15, 22,  // Right
  4, 22, 10,  // Right
  16, 13, 19, // Back
  16, 19, 21, // Back
  12, 1, 7,   // Left
  12, 7, 18,  // Left
  8, 11, 23,  // Top
  8, 23, 20,  // Top
  14, 17, 5,  // Bottom
  14, 5, 2,   // Bottom
};

kdr::Solids::Cube::Cube(const kdr::Space::Vec3& position, const float edgeLength) : kdr::Solids::Solid(position)
{
  GLfloat cubeVertices[] = {
    -(edgeLength / 2.f), -(edgeLength / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f, 0.f,  0.f,  0.f,  1.f, // 0  000 Front
    -(edgeLength / 2.f), -(edgeLength / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f, 0.f, -1.f,  0.f,  0.f, // 1  000 Left
    -(edgeLength / 2.f), -(edgeLength / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f, 1.f,  0.f, -1.f,  0.f, // 2  000 Bottom
     (edgeLength / 2.f), -(edgeLength / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f, 0.f,  0.f,  0.f,  1.f, // 3  100 Front
     (edgeLength / 2.f), -(edgeLength / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f, 0.f,  1.f,  0.f,  0.f, // 4  100 Right
     (edgeLength / 2.f), -(edgeLength / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f, 1.f,  0.f, -1.f,  0.f, // 5  100 Bottom
    -(edgeLength / 2.f),  (edgeLength / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f, 1.f,  0.f,  0.f,  1.f, // 6  010 Front
    -(edgeLength / 2.f),  (edgeLength / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f, 1.f, -1.f,  0.f,  0.f, // 7  010 Left
    -(edgeLength / 2.f),  (edgeLength / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f, 0.f,  0.f,  1.f,  0.f, // 8  010 Top
     (edgeLength / 2.f),  (edgeLength / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f, 1.f,  0.f,  0.f,  1.f, // 9  110 Front
     (edgeLength / 2.f),  (edgeLength / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f, 1.f,  1.f,  0.f,  0.f, // 10 110 Right
     (edgeLength / 2.f),  (edgeLength / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f, 1.f,  0.f,  1.f,  0.f, // 11 110 Top
    -(edgeLength / 2.f), -(edgeLength / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f, 0.f, -1.f,  0.f,  0.f, // 12 001 Left
    -(edgeLength / 2.f), -(edgeLength / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f, 0.f,  0.f,  0.f, -1.f, // 13 001 Back
    -(edgeLength / 2.f), -(edgeLength / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f, 0.f,  0.f, -1.f,  0.f, // 14 001 Bottom
     (edgeLength / 2.f), -(edgeLength / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f, 0.f,  1.f,  0.f,  0.f, // 15 101 Right
     (edgeLength / 2.f), -(edgeLength / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f, 0.f,  0.f,  0.f, -1.f, // 16 101 Back
     (edgeLength / 2.f), -(edgeLength / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f, 0.f,  0.f, -1.f,  0.f, // 17 101 Bottom
    -(edgeLength / 2.f),  (edgeLength / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f, 1.f, -1.f,  0.f,  0.f, // 18 011 Left
    -(edgeLength / 2.f),  (edgeLength / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f, 1.f,  0.f,  0.f, -1.f, // 19 011 Back
    -(edgeLength / 2.f),  (edgeLength / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f, 1.f,  0.f,  1.f,  0.f, // 20 011 Top
     (edgeLength / 2.f),  (edgeLength / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f, 1.f,  0.f,  0.f, -1.f, // 21 111 Back
     (edgeLength / 2.f),  (edgeLength / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f, 1.f,  1.f,  0.f,  0.f, // 22 111 Right
     (edgeLength / 2.f),  (edgeLength / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f, 1.f,  0.f,  1.f,  0.f, // 23 111 Top
  };
  this->initializeMembers(cubeVertices, sizeof(cubeVertices), cuboidIndices, sizeof(cuboidIndices));
}

void kdr::Solids::Cube::render()
{
  this->VAO->Bind();
  glDrawElements(GL_TRIANGLES, sizeof(cuboidIndices) / sizeof(GLuint), GL_UNSIGNED_INT, NULL);
  this->VAO->Unbind();
}

kdr::Solids::Cuboid::Cuboid(const kdr::Space::Vec3& position, const float length, const float height, const float width) : kdr::Solids::Solid(position)
{
  GLfloat cuboidVertices[] = {
    -(length / 2.f), -(height / 2.f),  (width / 2.f), 1.f, 1.f, 1.f, 0.f, 0.f,  0.f,  0.f,  1.f, // 0  000 Front
    -(length / 2.f), -(height / 2.f),  (width / 2.f), 1.f, 1.f, 1.f, 1.f, 0.f, -1.f,  0.f,  0.f, // 1  000 Left
    -(length / 2.f), -(height / 2.f),  (width / 2.f), 1.f, 1.f, 1.f, 1.f, 1.f,  0.f, -1.f,  0.f, // 2  000 Bottom
     (length / 2.f), -(height / 2.f),  (width / 2.f), 1.f, 1.f, 1.f, 1.f, 0.f,  0.f,  0.f,  1.f, // 3  100 Front
     (length / 2.f), -(height / 2.f),  (width / 2.f), 1.f, 1.f, 1.f, 0.f, 0.f,  1.f,  0.f,  0.f, // 4  100 Right
     (length / 2.f), -(height / 2.f),  (width / 2.f), 1.f, 1.f, 1.f, 0.f, 1.f,  0.f, -1.f,  0.f, // 5  100 Bottom
    -(length / 2.f),  (height / 2.f),  (width / 2.f), 1.f, 1.f, 1.f, 0.f, 1.f,  0.f,  0.f,  1.f, // 6  010 Front
    -(length / 2.f),  (height / 2.f),  (width / 2.f), 1.f, 1.f, 1.f, 1.f, 1.f, -1.f,  0.f,  0.f, // 7  010 Left
    -(length / 2.f),  (height / 2.f),  (width / 2.f), 1.f, 1.f, 1.f, 0.f, 0.f,  0.f,  1.f,  0.f, // 8  010 Top
     (length / 2.f),  (height / 2.f),  (width / 2.f), 1.f, 1.f, 1.f, 1.f, 1.f,  0.f,  0.f,  1.f, // 9  110 Front
     (length / 2.f),  (height / 2.f),  (width / 2.f), 1.f, 1.f, 1.f, 0.f, 1.f,  1.f,  0.f,  0.f, // 10 110 Right
     (length / 2.f),  (height / 2.f),  (width / 2.f), 1.f, 1.f, 1.f, 0.f, 1.f,  0.f,  1.f,  0.f, // 11 110 Top
    -(length / 2.f), -(height / 2.f), -(width / 2.f), 1.f, 1.f, 1.f, 0.f, 0.f, -1.f,  0.f,  0.f, // 12 001 Left
    -(length / 2.f), -(height / 2.f), -(width / 2.f), 1.f, 1.f, 1.f, 1.f, 0.f,  0.f,  0.f, -1.f, // 13 001 Back
    -(length / 2.f), -(height / 2.f), -(width / 2.f), 1.f, 1.f, 1.f, 1.f, 0.f,  0.f, -1.f,  0.f, // 14 001 Bottom
     (length / 2.f), -(height / 2.f), -(width / 2.f), 1.f, 1.f, 1.f, 1.f, 0.f,  1.f,  0.f,  0.f, // 15 101 Right
     (length / 2.f), -(height / 2.f), -(width / 2.f), 1.f, 1.f, 1.f, 0.f, 0.f,  0.f,  0.f, -1.f, // 16 101 Back
     (length / 2.f), -(height / 2.f), -(width / 2.f), 1.f, 1.f, 1.f, 0.f, 0.f,  0.f, -1.f,  0.f, // 17 101 Bottom
    -(length / 2.f),  (height / 2.f), -(width / 2.f), 1.f, 1.f, 1.f, 0.f, 1.f, -1.f,  0.f,  0.f, // 18 011 Left
    -(length / 2.f),  (height / 2.f), -(width / 2.f), 1.f, 1.f, 1.f, 1.f, 1.f,  0.f,  0.f, -1.f, // 19 011 Back
    -(length / 2.f),  (height / 2.f), -(width / 2.f), 1.f, 1.f, 1.f, 0.f, 1.f,  0.f,  1.f,  0.f, // 20 011 Top
     (length / 2.f),  (height / 2.f), -(width / 2.f), 1.f, 1.f, 1.f, 0.f, 1.f,  0.f,  0.f, -1.f, // 21 111 Back
     (length / 2.f),  (height / 2.f), -(width / 2.f), 1.f, 1.f, 1.f, 1.f, 1.f,  1.f,  0.f,  0.f, // 22 111 Right
     (length / 2.f),  (height / 2.f), -(width / 2.f), 1.f, 1.f, 1.f, 1.f, 1.f,  0.f,  1.f,  0.f, // 23 111 Top
  };
  this->initializeMembers(cuboidVertices, sizeof(cuboidVertices), cuboidIndices, sizeof(cuboidIndices));
}

void kdr::Solids::Cuboid::render()
{
  this->VAO->Bind();
  glDrawElements(GL_TRIANGLES, sizeof(cuboidIndices) / sizeof(GLuint), GL_UNSIGNED_INT, NULL);
  this->VAO->Unbind();
}

GLuint pyramidIndices[] = {
  6, 9, 3,   // Bottom
  6, 3, 0,   // Bottom
  1, 4, 12,  // Front
  5, 11, 13, // Right
  10, 7, 14, // Back
  8, 2, 15,  // Left
};

kdr::Solids::Pyramid::Pyramid(const kdr::Space::Vec3& position, const float edgeLength, const float height) : kdr::Solids::Solid(position)
{
  const kdr::Space::Vec3 nFront = kdr::Space::normalize(kdr::Space::cross(
    {0.f, height, edgeLength / 2.f},
    {1.f, 0.f, 0.f}
  ));
  const kdr::Space::Vec3 nLeft = kdr::Space::normalize(kdr::Space::cross(
    {-edgeLength / 2.f, height, 0.f},
    {0.f, 0.f, 1.f}
  ));

  GLfloat pyramidVertices[] = {
    -(edgeLength / 2.f), -(height / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f,  1.f,   0.f,      -1.f,       0.f,      // 0  00 Bottom
    -(edgeLength / 2.f), -(height / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f,  0.f,   nFront.x,  nFront.y,  nFront.z, // 1  00 Front
    -(edgeLength / 2.f), -(height / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f,  0.f,   nLeft.x,   nLeft.y,   nLeft.z,  // 2  00 Left
     (edgeLength / 2.f), -(height / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f,  1.f,   0.f,      -1.f,       0.f,      // 3  10 Bottom
     (edgeLength / 2.f), -(height / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f,  0.f,   nFront.x,  nFront.y,  nFront.z, // 4  10 Front
     (edgeLength / 2.f), -(height / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f,  0.f,  -nLeft.x,   nLeft.y,   nLeft.z,  // 5  10 Right
    -(edgeLength / 2.f), -(height / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f,  0.f,   0.f,      -1.f,       0.f,      // 6  01 Bottom
    -(edgeLength / 2.f), -(height / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f,  0.f,   nFront.x,  nFront.y, -nFront.z, // 7  01 Back
    -(edgeLength / 2.f), -(height / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f,  0.f,   nLeft.x,   nLeft.y,   nLeft.z,  // 8  01 Left
     (edgeLength / 2.f), -(height / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f,  0.f,   0.f,      -1.f,       0.f,      // 9  11 Bottom
     (edgeLength / 2.f), -(height / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f,  0.f,   nFront.x,  nFront.y, -nFront.z, // 10 11 Back
     (edgeLength / 2.f), -(height / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f,  0.f,  -nLeft.x,   nLeft.y,   nLeft.z,  // 11 11 Right
     0.f,                 (height / 2.f),  0.f,                1.f, 1.f, 1.f, 0.5f, 0.5f,  nFront.x,  nFront.y,  nFront.z, // 12    Top Front
     0.f,                 (height / 2.f),  0.f,                1.f, 1.f, 1.f, 0.5f, 0.5f, -nLeft.x,   nLeft.y,   nLeft.z,  // 13    Top Right
     0.f,                 (height / 2.f),  0.f,                1.f, 1.f, 1.f, 0.5f, 0.5f,  nFront.x,  nFront.y, -nFront.z, // 14    Top Back
     0.f,                 (height / 2.f),  0.f,                1.f, 1.f, 1.f, 0.5f, 0.5f,  nLeft.x,   nLeft.y,   nLeft.z,  // 15    Top Left
  };
  this->initializeMembers(pyramidVertices, sizeof(pyramidVertices), pyramidIndices, sizeof(pyramidIndices));
}

void kdr::Solids::Pyramid::render()
{
  this->VAO->Bind();
  glDrawElements(GL_TRIANGLES, sizeof(pyramidIndices) / sizeof(GLuint), GL_UNSIGNED_INT, NULL);
  this->VAO->Unbind();
}

GLuint planeIndices[] = {
  0, 1, 3, // Top
  0, 3, 2, // Top
};

kdr::Solids::Plane::Plane(const kdr::Space::Vec3& position, const float length, const float width) : kdr::Solids::Solid(position)
{
  GLfloat planeVertices[] = {
    -(length / 2.f), 0.f,  (width / 2.f), 1.f, 1.f, 1.f, 0.f,    0.f,   0.f, 1.f, 0.f, // 0 00
     (length / 2.f), 0.f,  (width / 2.f), 1.f, 1.f, 1.f, length, 0.f,   0.f, 1.f, 0.f, // 1 10
    -(length / 2.f), 0.f, -(width / 2.f), 1.f, 1.f, 1.f, 0.f,    width, 0.f, 1.f, 0.f, // 2 01
     (length / 2.f), 0.f, -(width / 2.f), 1.f, 1.f, 1.f, length, width, 0.f, 1.f, 0.f, // 3 11
  };
  this->initializeMembers(planeVertices, sizeof(planeVertices), planeIndices, sizeof(planeIndices));
}

void kdr::Solids::Plane::render()
{
  this->VAO->Bind();
  glDrawElements(GL_TRIANGLES, sizeof(planeIndices) / sizeof(GLuint), GL_UNSIGNED_INT, NULL);
  this->VAO->Unbind();
}

GLuint octahedronIndices[] = {
  0, 4, 16,  // Front T
  6, 12, 17, // Right T
  14, 8, 18, // Back  T
  10, 2, 19, // Left  T
  5, 1, 20,  // Front B
  13, 7, 21, // Right B
  9, 15, 22, // Back  B
  3, 11, 23, // Left  B
};

kdr::Solids::Octahedron::Octahedron(const kdr::Space::Vec3& position, const float edgeLength, const float height) : kdr::Solids::Solid(position)
{
  const kdr::Space::Vec3 ntFront = kdr::Space::normalize(kdr::Space::cross(
    {0.f, height, edgeLength / 2.f},
    {1.f, 0.f, 0.f}
  ));
  const kdr::Space::Vec3 ntLeft = kdr::Space::normalize(kdr::Space::cross(
    {-edgeLength / 2.f, height, 0.f},
    {0.f, 0.f, 1.f}
  ));

  GLfloat octahedronVertices[] = {
    -(edgeLength / 2.f),  0.f,             (edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f,  0.f,  ntFront.x,  ntFront.y,  ntFront.z, // 0  00 Front  T
    -(edgeLength / 2.f),  0.f,             (edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f,  0.f,  ntFront.x, -ntFront.y,  ntFront.z, // 1  00 Front  B
    -(edgeLength / 2.f),  0.f,             (edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f,  0.f,  ntLeft.x,   ntLeft.y,   ntLeft.z,  // 2  00 Left   T
    -(edgeLength / 2.f),  0.f,             (edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f,  0.f,  ntLeft.x,  -ntLeft.y,   ntLeft.z,  // 3  00 Left   B
     (edgeLength / 2.f),  0.f,             (edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f,  0.f,  ntFront.x,  ntFront.y,  ntFront.z, // 4  10 Front  T
     (edgeLength / 2.f),  0.f,             (edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f,  0.f,  ntFront.x, -ntFront.y,  ntFront.z, // 5  10 Front  B
     (edgeLength / 2.f),  0.f,             (edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f,  0.f, -ntLeft.x,   ntLeft.y,   ntLeft.z,  // 6  10 Right  T
     (edgeLength / 2.f),  0.f,             (edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f,  0.f, -ntLeft.x,  -ntLeft.y,   ntLeft.z,  // 7  10 Right  B
    -(edgeLength / 2.f),  0.f,            -(edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f,  0.f,  ntFront.x,  ntFront.y, -ntFront.z, // 8  01 Back   T
    -(edgeLength / 2.f),  0.f,            -(edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f,  0.f,  ntFront.x, -ntFront.z, -ntFront.z, // 9  01 Back   B
    -(edgeLength / 2.f),  0.f,            -(edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f,  0.f,  ntLeft.x,   ntLeft.y,   ntLeft.z,  // 10 01 Left   T
    -(edgeLength / 2.f),  0.f,            -(edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f,  0.f,  ntLeft.x,  -ntLeft.y,   ntLeft.z,  // 11 01 Left   B
     (edgeLength / 2.f),  0.f,            -(edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f,  0.f, -ntLeft.x,   ntLeft.y,   ntLeft.z,  // 12 11 Right  T
     (edgeLength / 2.f),  0.f,            -(edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f,  0.f, -ntLeft.x,  -ntLeft.y,   ntLeft.z,  // 13 11 Right  B
     (edgeLength / 2.f),  0.f,            -(edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f,  0.f,  ntFront.x,  ntFront.y, -ntFront.z, // 14 11 Back   T
     (edgeLength / 2.f),  0.f,            -(edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f,  0.f,  ntFront.x, -ntFront.z, -ntFront.z, // 15 11 Back   B
     0.f,                 (height / 2.f),  0.f,                1.f, 1.f, 1.f, 0.5f, 1.f,  0.f,        1.f,        0.f,       // 16    Top    F
     0.f,                 (height / 2.f),  0.f,                1.f, 1.f, 1.f, 0.5f, 1.f,  0.f,        1.f,        0.f,       // 17    Top    R
     0.f,                 (height / 2.f),  0.f,                1.f, 1.f, 1.f, 0.5f, 1.f,  0.f,        1.f,        0.f,       // 18    Top    B
     0.f,                 (height / 2.f),  0.f,                1.f, 1.f, 1.f, 0.5f, 1.f,  0.f,        1.f,        0.f,       // 19    Top    L
     0.f,                -(height / 2.f),  0.f,                1.f, 1.f, 1.f, 0.5f, 1.f,  0.f,       -1.f,        0.f,       // 20    Bottom F
     0.f,                -(height / 2.f),  0.f,                1.f, 1.f, 1.f, 0.5f, 1.f,  0.f,       -1.f,        0.f,       // 21    Bottom R
     0.f,                -(height / 2.f),  0.f,                1.f, 1.f, 1.f, 0.5f, 1.f,  0.f,       -1.f,        0.f,       // 22    Bottom B
     0.f,                -(height / 2.f),  0.f,                1.f, 1.f, 1.f, 0.5f, 1.f,  0.f,       -1.f,        0.f,       // 23    Bottom L
  };
  this->initializeMembers(octahedronVertices, sizeof(octahedronVertices), octahedronIndices, sizeof(octahedronIndices));
}

void kdr::Solids::Octahedron::render()
{
  this->VAO->Bind();
  glDrawElements(GL_TRIANGLES, sizeof(octahedronIndices) / sizeof(GLuint), GL_UNSIGNED_INT, NULL);
  this->VAO->Unbind();
}
