#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

#include "Kedarium/Core.hpp"
#include "Kedarium/File.hpp"
#include "Kedarium/Color.hpp"
#include "Kedarium/Keys.hpp"
#include "Kedarium/Space.hpp"
#include "Kedarium/Graphics.hpp"
#include "Kedarium/Window.hpp"
#include "Kedarium/Debug.hpp"

// Constants
const unsigned int WINDOW_WIDTH  {800};
const unsigned int WINDOW_HEIGHT {600};
const std::string  WINDOW_TITLE  {"GLFW"};

// Vertices and Indices
GLfloat vertices[] = {
  -0.5f,  -0.5f, -2.f, 1.f, 1.f, 1.f,
   0.0f,  -0.5f, -2.f, 1.f, 1.f, 1.f,
   0.5f,  -0.5f, -2.f, 1.f, 1.f, 1.f,
  -0.25f,  0.0f, -2.f, 1.f, 1.f, 1.f,
   0.25f,  0.0f, -2.f, 1.f, 1.f, 1.f,
   0.0f,   0.5f, -2.f, 1.f, 1.f, 1.f,
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
    }

  protected:
    void update()
    {
      if (kdr::Keys::isPressed(this->getGlfwWindow(), kdr::Key::E))
      {
        this->setIsMouseLocked(true);
      }
      else if (kdr::Keys::isPressed(this->getGlfwWindow(), kdr::Key::Escape))
      {
        this->setIsMouseLocked(false);
      }
    }
    
    void render()
    {
      defaultShader.Use();
      VAO1.Bind();

      kdr::Space::Mat4 model {1.f};
      kdr::Space::Mat4 view {1.f};
      kdr::Space::Mat4 proj {1.f};

      proj = kdr::Space::perspective(
        60.f,
        WINDOW_WIDTH / WINDOW_HEIGHT,
        0.1f,
        100.f
      );
      
      GLuint modelLoc = glGetUniformLocation(defaultShader.getID(), "model");
      GLuint viewLoc = glGetUniformLocation(defaultShader.getID(), "view");
      GLuint projLoc = glGetUniformLocation(defaultShader.getID(), "proj");

      glUniformMatrix4fv(modelLoc, 1, GL_FALSE, kdr::Space::valuePointer(model));
      glUniformMatrix4fv(viewLoc, 1, GL_FALSE, kdr::Space::valuePointer(view));
      glUniformMatrix4fv(projLoc, 1, GL_FALSE, kdr::Space::valuePointer(proj));

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
