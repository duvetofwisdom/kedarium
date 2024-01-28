#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <iostream>
#include <string>

#include "Kedarium/Core.hpp"
#include "Kedarium/Color.hpp"
#include "Kedarium/Keys.hpp"
#include "Kedarium/Space.hpp"
#include "Kedarium/Graphics.hpp"
#include "Kedarium/Window.hpp"
#include "Kedarium/Camera.hpp"
#include "Kedarium/Solids.hpp"
#include "Kedarium/Debug.hpp"

// Constants
constexpr unsigned int WINDOW_WIDTH  {800};
constexpr unsigned int WINDOW_HEIGHT {600};
const     std::string  WINDOW_TITLE  {"GLFW"};

// Camera Settings
constexpr float CAMERA_FOV         {60.f};
constexpr float CAMERA_ASPECT      {WINDOW_WIDTH / (float)WINDOW_HEIGHT};
constexpr float CAMERA_NEAR        {0.1f};
constexpr float CAMERA_FAR         {100.f};
constexpr float CAMERA_SPEED       {3.f};
constexpr float CAMERA_SENSITIVITY {0.1f};

// Vertices and Indices
GLfloat vertices[] = {
  -0.5f,  -0.5f,  0.5f,  1.f, 0.f, 1.f,
   0.0f,  -0.5f,  0.5f,  0.f, 1.f, 0.f,
   0.5f,  -0.5f,  0.5f,  0.f, 0.f, 1.f,
  -0.5f,  -0.5f,  0.0f,  1.f, 1.f, 0.f,
   0.0f,  -0.5f,  0.0f,  0.f, 1.f, 1.f,
   0.5f,  -0.5f,  0.0f,  1.f, 0.f, 1.f,
  -0.5f,  -0.5f, -0.5f,  1.f, 0.f, 0.f,
   0.0f,  -0.5f, -0.5f,  0.f, 1.f, 0.f,
   0.5f,  -0.5f, -0.5f,  0.f, 0.f, 1.f,
  -0.25f,  0.0f,  0.25f, 1.f, 1.f, 0.f,
   0.25f,  0.0f,  0.25f, 0.f, 1.f, 1.f,
  -0.25f,  0.0f, -0.25f, 1.f, 0.f, 1.f,
   0.25f,  0.0f, -0.25f, 1.f, 0.f, 0.f,
   0.f,    0.5f,  0.f,   0.f, 1.f, 0.f,
};
GLuint indices[] = {
  0, 1, 4,
  0, 4, 3,
  1, 2, 5,
  1, 5, 4,
  3, 4, 7,
  3, 7, 6,
  4, 5, 8,
  4, 8, 7,
  0, 1, 9,
  1, 4, 9,
  4, 3, 9,
  3, 0, 9,
  1, 2, 10,
  2, 5, 10,
  5, 4, 10,
  4, 1, 10,
  3, 4, 11,
  4, 7, 11,
  7, 6, 11,
  6, 3, 11,
  4, 5, 12,
  5, 8, 12,
  8, 7, 12,
  7, 4, 12,
  9, 10, 12,
  9, 12, 11,
  9, 10, 13,
  10, 12, 13,
  12, 11, 13,
  11, 9, 13,
};

class MainWindow : public kdr::Window::Window
{
  using kdr::Window::Window;

  public:
    ~MainWindow()
    {
      defaultShader.Delete();
      emeraldTexture.Delete();
    }

    void initialize()
    {
      kdr::Graphics::setPointSize(5.f);
      kdr::Graphics::setLineWidth(2.f);

      kdr::Solids::Octahedron* octahedron;
      for (int z = 0; z < 10; z++)
      {
        for (int x = 0; x < 10; x++)
        {
          octahedron = new kdr::Solids::Octahedron({
            {(x - 5) * 2.f, 0.f, (z - 5) * 2.f},
            1.f,
            3.f
          });
          this->octahedrons.push_back(octahedron);
        }
      }
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

      if (kdr::Keys::isPressed(this->getGlfwWindow(), kdr::Key::C))
      {
        kdr::Graphics::usePointMode();
      }
      else if (kdr::Keys::isPressed(this->getGlfwWindow(), kdr::Key::V))
      {
        kdr::Graphics::useLineMode();
      }
      else if (kdr::Keys::isPressed(this->getGlfwWindow(), kdr::Key::B))
      {
        kdr::Graphics::useFillMode();
      }

      if (kdr::Keys::isPressed(this->getGlfwWindow(), kdr::Key::F))
      {
        if (this->canMaximize)
        {
          this->getIsMaximized() ? this->unmaximize() : this->maximize();
          this->canMaximize = false;
        }
      }
      else
      {
        this->canMaximize = true;
      }
    }
    
    void render()
    {
      this->bindShader(this->defaultShader);
      this->defaultShader.SetVector3("lightPos", {0.f, 0.f, 10.f});
      this->defaultShader.SetVector4("lightColor", {1.f, 1.f, 1.f, 1.f});
      this->bindTexture(this->emeraldTexture);

      for (kdr::Solids::Octahedron* octahedron : this->octahedrons)
      {
        this->renderSolid(*octahedron);
      }
    }

  private:
    kdr::Graphics::Shader defaultShader { 
      "resources/Shaders/default.vert",
      "resources/Shaders/default.frag"
    };
    kdr::Graphics::Texture emeraldTexture {
      "resources/Textures/emerald.png",
      GL_TEXTURE_2D,
      GL_TEXTURE0,
      GL_UNSIGNED_BYTE
    };
    std::vector<kdr::Solids::Octahedron*> octahedrons;
    bool canMaximize {true};
};

int main()
{
  // Clear Color
  kdr::Color::RGBA clearColor {0, 0, 0, 1.f};

  // Camera
  kdr::Camera mainCamera {
    {0.f, 0.f, 5.f},
    CAMERA_FOV,
    CAMERA_ASPECT,
    CAMERA_NEAR,
    CAMERA_FAR,
    CAMERA_SPEED,
    CAMERA_SENSITIVITY
  };

  // Main Window
  MainWindow mainWindow {
    WINDOW_WIDTH,
    WINDOW_HEIGHT,
    WINDOW_TITLE
  };
  mainWindow.initialize();
  mainWindow.setClearColor(clearColor);
  mainWindow.setBoundCamera(&mainCamera);

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
