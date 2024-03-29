#include "Kedarium/Core.hpp"

const std::string ENGINE_NAME    {"Kedarium"};
const std::string ENGINE_VERSION {"0.2 InDev"};
const std::string ENGINE_AUTHOR  {"duvetofwisdom"};
const std::string ENGINE_LICENSE {"GNU GLPv3"};

void kdr::Core::printEngineInfo()
{
  std::cout << ENGINE_NAME << ' ' << ENGINE_VERSION << '\n';
  std::cout << "Created by " << ENGINE_AUTHOR << '\n';
  std::cout << "Licensed under " << ENGINE_LICENSE << '\n';
}

void kdr::Core::printVersionInfo()
{
  std::cout << "OpenGL: " << glGetString(GL_VERSION) << '\n';
  std::cout << "GLEW:   " << glewGetString(GLEW_VERSION) << '\n';
  std::cout << "GLFW:   " << glfwGetVersionString() << '\n';
}
