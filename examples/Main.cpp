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
    void initialize()
    {
      kdr::Graphics::setPointSize(5.f);
      kdr::Graphics::setLineWidth(2.f);

      kdr::Graphics::Texture* sandTexture = kdr::Core::loadTexture("sand");
      kdr::Graphics::Texture* grassTexture = kdr::Core::loadTexture("grass");
      kdr::Graphics::Texture* stoneTexture = kdr::Core::loadTexture("stone");
      kdr::Graphics::Texture* snowTexture = kdr::Core::loadTexture("snow");

      this->textureManager.add("sand", sandTexture);
      this->textureManager.add("grass", grassTexture);
      this->textureManager.add("stone", stoneTexture);
      this->textureManager.add("snow", snowTexture);

      kdr::Solids::Plane* sandPlane = new kdr::Solids::Plane(
        {-4.f, 0.f, -4.f},
        8.f,
        8.f
      );
      sandPlane->setTexture("sand");
      kdr::Solids::Plane* grassPlane = new kdr::Solids::Plane(
        {4.f, 0.f, -4.f},
        8.f,
        8.f
      );
      grassPlane->setTexture("grass");
      kdr::Solids::Plane* stonePlane = new kdr::Solids::Plane(
        {-4.f, 0.f, 4.f},
        8.f,
        8.f
      );
      stonePlane->setTexture("stone");
      kdr::Solids::Plane* snowPlane = new kdr::Solids::Plane(
        {4.f, 0.f, 4.f},
        8.f,
        8.f
      );
      snowPlane->setTexture("snow");

      this->planes.push_back(sandPlane);
      this->planes.push_back(grassPlane);
      this->planes.push_back(stonePlane);
      this->planes.push_back(snowPlane);
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
      this->defaultShader.SetVector3("lightPos", {0.f, 10.f, 0.f});
      this->defaultShader.SetVector4("lightColor", {1.f, 1.f, 1.f, 1.f});

      for (kdr::Solids::Plane* plane : this->planes)
      {
        this->renderSolid(*plane);
      }
    }

  private:
    kdr::Core::Manager<kdr::Graphics::Texture> textureManager;
    kdr::Graphics::Shader defaultShader { 
      "resources/Shaders/default.vert",
      "resources/Shaders/default.frag"
    };
    std::vector<kdr::Solids::Plane*> planes;
    bool canMaximize {true};
};

int main()
{
  // Clear Color
  kdr::Color::RGBA clearColor {0, 0, 0, 1.f};

  // Camera
  kdr::Camera mainCamera {
    {0.f, 2.f, 0.f},
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
