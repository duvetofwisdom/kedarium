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

void kdr::Window::maximize()
{
  GLFWmonitor* monitor = glfwGetPrimaryMonitor();
  const GLFWvidmode* mode = glfwGetVideoMode(monitor);
  glfwSetWindowMonitor(
    this->glfwWindow,
    monitor,
    0,
    0,
    mode->width,
    mode->height,
    mode->refreshRate
  );
  this->isMaximized = true;
}

void kdr::Window::unmaximize()
{
  GLFWmonitor* monitor = glfwGetPrimaryMonitor();
  const GLFWvidmode* mode = glfwGetVideoMode(monitor); 
  glfwSetWindowMonitor(
    this->glfwWindow,
    NULL,
    mode->width / 2 - 400,
    mode->height / 2 - 300,
    800,
    600,
    GLFW_DONT_CARE
  );
  this->isMaximized = false;
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
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);
  return true;
}

void kdr::Window::_initialize()
{
  if (!this->_initializeGlfw()) return;
  if (!this->_initializeGlfwWindow()) return;
  if (!this->_initializeGlew()) return;
  if (!this->_initializeOpenGLSettings()) return;
}

void kdr::Window::_updateDeltaTime()
{
  const float currentTime = (float)glfwGetTime();
  this->deltaTime = currentTime - lastTime;
  lastTime = currentTime;
}

void kdr::Window::_updateCamera()
{
  if (
    this->boundCamera == NULL ||
    this->boundShader == 0
  ) return;
  if (this->isMouseLocked)
  {
    this->boundCamera->updateKeys(this->glfwWindow, this->deltaTime);
    this->boundCamera->updateMouse(this->glfwWindow);
  }
  this->boundCamera->updateMatrix();
  this->boundCamera->applyMatrix(this->boundShader);
}

void kdr::Window::_update()
{
  glfwPollEvents();
  this->_updateDeltaTime();
  this->_updateCamera();
  this->update();

  if (!this->isMouseLocked) {
    glfwSetInputMode(this->glfwWindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    return;
  }

  glfwSetInputMode(this->glfwWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void kdr::Window::_render()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  this->render();
  glfwSwapBuffers(this->glfwWindow);
}
