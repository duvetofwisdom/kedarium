#include "Kedarium/Solids.hpp"

void kdr::Solids::Solid::initializeMembers(GLfloat vertices[], GLsizeiptr verticesSize, GLuint indices[], GLsizeiptr indicesSize)
{
  this->VAO = new kdr::Graphics::VAO();
  this->VBO = new kdr::Graphics::VBO(vertices, verticesSize);
  this->EBO = new kdr::Graphics::EBO(indices, indicesSize);

  this->VAO->Bind();
  this->VBO->Bind();
  this->EBO->Bind();

  this->VAO->LinkAttrib(*this->VBO, 0, 3, GL_FLOAT, 8 * sizeof(GLfloat), (void*)0);
  this->VAO->LinkAttrib(*this->VBO, 1, 3, GL_FLOAT, 8 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
  this->VAO->LinkAttrib(*this->VBO, 2, 2, GL_FLOAT, 8 * sizeof(GLfloat), (void*)(6 * sizeof(GLfloat)));

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
    -(edgeLength / 2.f), -(edgeLength / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f, 0.f, // 0  000 Front
    -(edgeLength / 2.f), -(edgeLength / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f, 0.f, // 1  000 Left
    -(edgeLength / 2.f), -(edgeLength / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f, 1.f, // 2  000 Bottom
     (edgeLength / 2.f), -(edgeLength / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f, 0.f, // 3  100 Front
     (edgeLength / 2.f), -(edgeLength / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f, 0.f, // 4  100 Right
     (edgeLength / 2.f), -(edgeLength / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f, 1.f, // 5  100 Bottom
    -(edgeLength / 2.f),  (edgeLength / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f, 1.f, // 6  010 Front
    -(edgeLength / 2.f),  (edgeLength / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f, 1.f, // 7  010 Left
    -(edgeLength / 2.f),  (edgeLength / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f, 0.f, // 8  010 Top
     (edgeLength / 2.f),  (edgeLength / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f, 1.f, // 9  110 Front
     (edgeLength / 2.f),  (edgeLength / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f, 1.f, // 10 110 Right
     (edgeLength / 2.f),  (edgeLength / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f, 1.f, // 11 110 Top
    -(edgeLength / 2.f), -(edgeLength / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f, 0.f, // 12 001 Left
    -(edgeLength / 2.f), -(edgeLength / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f, 0.f, // 13 001 Back
    -(edgeLength / 2.f), -(edgeLength / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f, 0.f, // 14 001 Bottom
     (edgeLength / 2.f), -(edgeLength / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f, 0.f, // 15 101 Right
     (edgeLength / 2.f), -(edgeLength / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f, 0.f, // 16 101 Back
     (edgeLength / 2.f), -(edgeLength / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f, 0.f, // 17 101 Bottom
    -(edgeLength / 2.f),  (edgeLength / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f, 1.f, // 18 011 Left
    -(edgeLength / 2.f),  (edgeLength / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f, 1.f, // 19 011 Back
    -(edgeLength / 2.f),  (edgeLength / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f, 1.f, // 20 011 Top
     (edgeLength / 2.f),  (edgeLength / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f, 1.f, // 21 111 Back
     (edgeLength / 2.f),  (edgeLength / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f, 1.f, // 22 111 Right
     (edgeLength / 2.f),  (edgeLength / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f, 1.f, // 23 111 Top
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
    -(length / 2.f), -(height / 2.f),  (width / 2.f), 1.f, 1.f, 1.f, 0.f, 0.f, // 0  000 Front
    -(length / 2.f), -(height / 2.f),  (width / 2.f), 1.f, 1.f, 1.f, 1.f, 0.f, // 1  000 Left
    -(length / 2.f), -(height / 2.f),  (width / 2.f), 1.f, 1.f, 1.f, 1.f, 1.f, // 2  000 Bottom
     (length / 2.f), -(height / 2.f),  (width / 2.f), 1.f, 1.f, 1.f, 1.f, 0.f, // 3  100 Front
     (length / 2.f), -(height / 2.f),  (width / 2.f), 1.f, 1.f, 1.f, 0.f, 0.f, // 4  100 Right
     (length / 2.f), -(height / 2.f),  (width / 2.f), 1.f, 1.f, 1.f, 0.f, 1.f, // 5  100 Bottom
    -(length / 2.f),  (height / 2.f),  (width / 2.f), 1.f, 1.f, 1.f, 0.f, 1.f, // 6  010 Front
    -(length / 2.f),  (height / 2.f),  (width / 2.f), 1.f, 1.f, 1.f, 1.f, 1.f, // 7  010 Left
    -(length / 2.f),  (height / 2.f),  (width / 2.f), 1.f, 1.f, 1.f, 0.f, 0.f, // 8  010 Top
     (length / 2.f),  (height / 2.f),  (width / 2.f), 1.f, 1.f, 1.f, 1.f, 1.f, // 9  110 Front
     (length / 2.f),  (height / 2.f),  (width / 2.f), 1.f, 1.f, 1.f, 0.f, 1.f, // 10 110 Right
     (length / 2.f),  (height / 2.f),  (width / 2.f), 1.f, 1.f, 1.f, 0.f, 1.f, // 11 110 Top
    -(length / 2.f), -(height / 2.f), -(width / 2.f), 1.f, 1.f, 1.f, 0.f, 0.f, // 12 001 Left
    -(length / 2.f), -(height / 2.f), -(width / 2.f), 1.f, 1.f, 1.f, 1.f, 0.f, // 13 001 Back
    -(length / 2.f), -(height / 2.f), -(width / 2.f), 1.f, 1.f, 1.f, 1.f, 0.f, // 14 001 Bottom
     (length / 2.f), -(height / 2.f), -(width / 2.f), 1.f, 1.f, 1.f, 1.f, 0.f, // 15 101 Right
     (length / 2.f), -(height / 2.f), -(width / 2.f), 1.f, 1.f, 1.f, 0.f, 0.f, // 16 101 Back
     (length / 2.f), -(height / 2.f), -(width / 2.f), 1.f, 1.f, 1.f, 0.f, 0.f, // 17 101 Bottom
    -(length / 2.f),  (height / 2.f), -(width / 2.f), 1.f, 1.f, 1.f, 0.f, 1.f, // 18 011 Left
    -(length / 2.f),  (height / 2.f), -(width / 2.f), 1.f, 1.f, 1.f, 1.f, 1.f, // 19 011 Back
    -(length / 2.f),  (height / 2.f), -(width / 2.f), 1.f, 1.f, 1.f, 0.f, 1.f, // 20 011 Top
     (length / 2.f),  (height / 2.f), -(width / 2.f), 1.f, 1.f, 1.f, 0.f, 1.f, // 21 111 Back
     (length / 2.f),  (height / 2.f), -(width / 2.f), 1.f, 1.f, 1.f, 1.f, 1.f, // 22 111 Right
     (length / 2.f),  (height / 2.f), -(width / 2.f), 1.f, 1.f, 1.f, 1.f, 1.f, // 23 111 Top
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
  5, 11, 12, // Right
  10, 7, 12, // Back
  8, 2, 12,  // Left
};

kdr::Solids::Pyramid::Pyramid(const kdr::Space::Vec3& position, const float edgeLength, const float height) : kdr::Solids::Solid(position)
{
  GLfloat pyramidVertices[] = {
    -(edgeLength / 2.f), -(height / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f,  1.f,  // 0  00 Bottom
    -(edgeLength / 2.f), -(height / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f,  0.f,  // 1  00 Front
    -(edgeLength / 2.f), -(height / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f,  0.f,  // 2  00 Left
     (edgeLength / 2.f), -(height / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f,  1.f,  // 3  10 Bottom
     (edgeLength / 2.f), -(height / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f,  0.f,  // 4  10 Front
     (edgeLength / 2.f), -(height / 2.f),  (edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f,  0.f,  // 5  10 Right
    -(edgeLength / 2.f), -(height / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f,  0.f,  // 6  01 Bottom
    -(edgeLength / 2.f), -(height / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f,  0.f,  // 7  01 Back
    -(edgeLength / 2.f), -(height / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f,  0.f,  // 8  01 Left
     (edgeLength / 2.f), -(height / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f,  0.f,  // 9  11 Bottom
     (edgeLength / 2.f), -(height / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f,  0.f,  // 10 11 Back
     (edgeLength / 2.f), -(height / 2.f), -(edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f,  0.f,  // 11 11 Right
     0.f,                 (height / 2.f),  0.f,                1.f, 1.f, 1.f, 0.5f, 0.5f, // 12    Top
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
    -(length / 2.f), 0.f,  (width / 2.f), 1.f, 1.f, 1.f, 0.f, 0.f, // 0 00
     (length / 2.f), 0.f,  (width / 2.f), 1.f, 1.f, 1.f, 1.f, 0.f, // 1 10
    -(length / 2.f), 0.f, -(width / 2.f), 1.f, 1.f, 1.f, 0.f, 1.f, // 2 01
     (length / 2.f), 0.f, -(width / 2.f), 1.f, 1.f, 1.f, 1.f, 1.f, // 3 11
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
  6, 12, 16, // Right T
  14, 8, 16, // Back  T
  10, 2, 16, // Left  T
  5, 1, 17,  // Front B
  13, 7, 17, // Right B
  9, 15, 17, // Back  B
  3, 11, 17, // Left  B
};

kdr::Solids::Octahedron::Octahedron(const kdr::Space::Vec3& position, const float edgeLength, const float height) : kdr::Solids::Solid(position)
{
  GLfloat octahedronVertices[] = {
    -(edgeLength / 2.f),  0.f,             (edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f,  0.f, // 0  00 Front T
    -(edgeLength / 2.f),  0.f,             (edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f,  0.f, // 1  00 Front B
    -(edgeLength / 2.f),  0.f,             (edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f,  0.f, // 2  00 Left  T
    -(edgeLength / 2.f),  0.f,             (edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f,  0.f, // 3  00 Left  B
     (edgeLength / 2.f),  0.f,             (edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f,  0.f, // 4  10 Front T
     (edgeLength / 2.f),  0.f,             (edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f,  0.f, // 5  10 Front B
     (edgeLength / 2.f),  0.f,             (edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f,  0.f, // 6  10 Right T
     (edgeLength / 2.f),  0.f,             (edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f,  0.f, // 7  10 Right B
    -(edgeLength / 2.f),  0.f,            -(edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f,  0.f, // 8  01 Back  T
    -(edgeLength / 2.f),  0.f,            -(edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f,  0.f, // 9  01 Back  B
    -(edgeLength / 2.f),  0.f,            -(edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f,  0.f, // 10 01 Left  T
    -(edgeLength / 2.f),  0.f,            -(edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f,  0.f, // 11 01 Left  B
     (edgeLength / 2.f),  0.f,            -(edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f,  0.f, // 12 11 Right T
     (edgeLength / 2.f),  0.f,            -(edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f,  0.f, // 13 11 Right B
     (edgeLength / 2.f),  0.f,            -(edgeLength / 2.f), 1.f, 1.f, 1.f, 0.f,  0.f, // 14 11 Back  T
     (edgeLength / 2.f),  0.f,            -(edgeLength / 2.f), 1.f, 1.f, 1.f, 1.f,  0.f, // 15 11 Back  B
     0.f,                 (height / 2.f),  0.f,                1.f, 1.f, 1.f, 0.5f, 1.f, // 16 Top
     0.f,                -(height / 2.f),  0.f,                1.f, 1.f, 1.f, 0.5f, 1.f, // 17 Top
  };
  this->initializeMembers(octahedronVertices, sizeof(octahedronVertices), octahedronIndices, sizeof(octahedronIndices));
}

void kdr::Solids::Octahedron::render()
{
  this->VAO->Bind();
  glDrawElements(GL_TRIANGLES, sizeof(octahedronIndices) / sizeof(GLuint), GL_UNSIGNED_INT, NULL);
  this->VAO->Unbind();
}
