#include "Kedarium/Camera.hpp"

void kdr::Camera::updateKeys(GLFWwindow* window, const float deltaTime)
{
  if (kdr::Keys::isPressed(window, kdr::Key::W))
  {
    this->position += this->front * this->speed * deltaTime;
  }
  if (kdr::Keys::isPressed(window, kdr::Key::S))
  {
    this->position -= this->front * this->speed * deltaTime;
  }
  if (kdr::Keys::isPressed(window, kdr::Key::A))
  {
    this->position -= kdr::Space::cross(this->front, this->up) * this->speed * deltaTime;
  }
  if (kdr::Keys::isPressed(window, kdr::Key::D))
  {
    this->position += kdr::Space::cross(this->front, this->up) * this->speed * deltaTime;
  }

  if (kdr::Keys::isPressed(window, kdr::Key::Spacebar))
  {
    this->position += this->up * this->speed * deltaTime;
  }
  if (kdr::Keys::isPressed(window, kdr::Key::LeftShift))
  {
    this->position -= this->up * this->speed * deltaTime;
  }
}

void kdr::Camera::updateMouse(GLFWwindow* window)
{
  int windowWidth;
  int windowHeight;
  glfwGetFramebufferSize(window, &windowWidth, &windowHeight);

  double mouseX;
  double mouseY;
  glfwGetCursorPos(window, &mouseX, &mouseY);

  const float deltaX = (mouseX - (float)windowWidth / 2.f) * this->sensitivity;
  const float deltaY = (mouseY - (float)windowHeight / 2.f) * this->sensitivity;

  this->yaw += deltaX;
  this->pitch -= deltaY;

  if (this->pitch > 89.0f) this->pitch = 89.0f;
  if (this->pitch < -89.0f) this->pitch = -89.0f;
  this->yaw = std::remainderf(this->yaw, 360.f);

  glfwSetCursorPos(window, (double)windowWidth / 2.f, (double)windowHeight / 2.f);
}

void kdr::Camera::updateMatrix()
{
  kdr::Space::Mat4 view {1.f};
  kdr::Space::Mat4 proj {1.f};
  kdr::Space::Vec3 tempFront {0.f};

  tempFront.x = cos(kdr::Space::radians(this->yaw)) * cos(kdr::Space::radians(this->pitch));
  tempFront.y = sin(kdr::Space::radians(this->pitch));
  tempFront.z = sin(kdr::Space::radians(this->yaw)) * cos(kdr::Space::radians(this->pitch));

  this->front = kdr::Space::normalize(tempFront);

  view = kdr::Space::lookAt(
    this->position,
    this->position + this->front,
    this->up
  );
  proj = kdr::Space::perspective(
    this->fov,
    this->aspect,
    this->zNear,
    this->zFar
  );

  this->matrix = proj * view;
}

void kdr::Camera::applyMatrix(GLuint shaderID)
{
  GLuint matrixLoc = glGetUniformLocation(shaderID, "cameraMatrix");
  glUniformMatrix4fv(matrixLoc, 1, GL_FALSE, kdr::Space::valuePointer(this->matrix));
}
