#include "Kedarium/Window.hpp"

void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
  (void)window;
  glViewport(0, 0, width, height);
}

kdr::Window::~Window()
{
  glfwDestroyWindow(this->glfwWindow);
}

void kdr::Window::loop()
{
  while (!glfwWindowShouldClose(this->glfwWindow))
  {
    this->_update();
    this->_render();
  }
}

bool kdr::Window::_initializeGlfw()
{
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  return true;
}

bool kdr::Window::_initializeGlfwWindow()
{
  this->glfwWindow = glfwCreateWindow(
    this->width,
    this->height,
    this->title.c_str(),
    NULL,
    NULL
  );
  if (this->glfwWindow == NULL)
  {
    std::cerr << "Failed to create a GLFW window!\n";
    glfwTerminate();
    return false;
  }
  glfwMakeContextCurrent(this->glfwWindow);
  glfwSetFramebufferSizeCallback(this->glfwWindow, framebufferSizeCallback);
  return true;
}

bool kdr::Window::_initializeGlew()
{
  GLenum err = glewInit();
  if (err != GLEW_OK)
  {
    std::cerr << "Failed to initialize GLEW!\n";
    std::cerr << "Error: " << glewGetErrorString(err) << '\n';
    glfwTerminate();
    return false;
  }
  return true;
}

bool kdr::Window::_initializeOpenGLSettings()
{
  return true;
}

void kdr::Window::_initialize()
{
  if (!this->_initializeGlfw()) return;
  if (!this->_initializeGlfwWindow()) return;
  if (!this->_initializeGlew()) return;
  if (!this->_initializeOpenGLSettings()) return;
}

void kdr::Window::_update()
{
  glfwPollEvents();
  this->update();

  if (!this->isMouseLocked) {
    glfwSetInputMode(this->glfwWindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    return;
  }

  glfwSetInputMode(this->glfwWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void kdr::Window::_render()
{
  glClear(GL_COLOR_BUFFER_BIT);
  this->render();
  glfwSwapBuffers(this->glfwWindow);
}
