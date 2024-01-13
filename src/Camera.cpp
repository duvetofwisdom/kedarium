#include "Kedarium/Camera.hpp"

void kdr::Camera::updateMatrix()
{
  kdr::Space::Mat4 view {1.f};
  kdr::Space::Mat4 proj {1.f};

  view = kdr::Space::translate(
    view,
    this->position
  );
  proj = kdr::Space::perspective(
    this->fov,
    this->aspect,
    this->zNear,
    this->zFar
  );

  this->cameraMatrix = proj * view;
}

void kdr::Camera::applyMatrix(GLuint shaderID)
{
  GLuint matrixLoc = glGetUniformLocation(shaderID, "cameraMatrix");
  glUniformMatrix4fv(matrixLoc, 1, GL_FALSE, kdr::Space::valuePointer(this->cameraMatrix));
}
