#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

#include "Kedarium/Core.hpp"
#include "Kedarium/File.hpp"
#include "Kedarium/Color.hpp"
#include "Kedarium/Graphics.hpp"
#include "Kedarium/Window.hpp"
#include "Kedarium/Space.hpp"
#include "Kedarium/Debug.hpp"

// Constants
const unsigned int WINDOW_WIDTH  {800};
const unsigned int WINDOW_HEIGHT {600};
const std::string  WINDOW_TITLE  {"GLFW"};

// Vertices and Indices
GLfloat vertices[] = {
  -0.5f,  -0.5f, 0.f, 1.f, 1.f, 1.f,
   0.0f,  -0.5f, 0.f, 1.f, 1.f, 1.f,
   0.5f,  -0.5f, 0.f, 1.f, 1.f, 1.f,
  -0.25f,  0.0f, 0.f, 1.f, 1.f, 1.f,
   0.25f,  0.0f, 0.f, 1.f, 1.f, 1.f,
   0.0f,   0.5f, 0.f, 1.f, 1.f, 1.f,
};
GLuint indices[] = {
  0, 1, 3,
  1, 2, 4,
  3, 4, 5,
};

class MainWindow : public kdr::Window::Window
{
  using kdr::Window::Window;

  public:
    ~MainWindow()
    {
      this->VAO1.Delete();
      this->VBO1.Delete();
      this->EBO1.Delete();
      defaultShader.Delete();
    }

    void initialize()
    {
      this->VAO1.Bind();
      this->VBO1.Bind();
      this->EBO1.Bind();

      this->VAO1.LinkAttrib(this->VBO1, 0, 3, GL_FLOAT, 6 * sizeof(GLfloat), (void*)0);
      this->VAO1.LinkAttrib(this->VBO1, 1, 3, GL_FLOAT, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));

      this->VAO1.Unbind();
      this->VBO1.Unbind();
      this->EBO1.Unbind();

      kdr::Space::Vec3 vecA {1.f, 3.f, 1.f};
      kdr::Space::Vec3 vecB {3.f, 1.f, 2.f};
      kdr::Space::Vec3 vecC {2.f, 2.f, 3.f};
    }

  protected:
    void update()
    {}
    
    void render()
    {
      defaultShader.Use();
      VAO1.Bind();
      glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(GLuint), GL_UNSIGNED_INT, NULL);
    }

  private:
    kdr::Graphics::Shader defaultShader {
      "resources/Shaders/default.vert",
      "resources/Shaders/default.frag"
    };
    kdr::Graphics::VAO VAO1;
    kdr::Graphics::VBO VBO1 {vertices, sizeof(vertices)};
    kdr::Graphics::EBO EBO1 {indices, sizeof(indices)};
};

int main()
{
  // Clear Color
  kdr::Color::RGBA clearColor {0, 0, 0, 1.f};

  // Main Window
  MainWindow mainWindow {
    WINDOW_WIDTH,
    WINDOW_HEIGHT,
    WINDOW_TITLE
  };
  mainWindow.initialize();
  mainWindow.setClearColor(clearColor);

  // Version Info
  kdr::Core::printEngineInfo();
  std::cout << '\n';
  kdr::Core::printVersionInfo();

  // Main Loop
  mainWindow.loop();
  mainWindow.close();

  glfwTerminate();
  return 0;
}
