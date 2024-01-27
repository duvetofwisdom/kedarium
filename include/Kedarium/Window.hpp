#ifndef KDR_WINDOW_HPP
#define KDR_WINDOW_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

#include "Color.hpp"
#include "Graphics.hpp"
#include "Solids.hpp"
#include "Camera.hpp"

namespace kdr
{
  /**
   * @struct WindowProps
   * @brief Holds properties for window creation.
   *
   * This struct encapsulates properties such as width, height, and title
   * to be used when creating a window.
   */
  struct WindowProps
  {
    unsigned int width;
    unsigned int height;
    std::string title;

    /**
     * @brief Constructs a WindowProps object with specified width, height, and title.
     *
     * @param width  The width of the window.
     * @param height The height of the window.
     * @param title  The title of the window.
     */
    WindowProps(const unsigned int width, const unsigned int height, const std::string& title)
    : width(width), height(height), title(title)
    {}
  };

  /**
   * @class Window
   * @brief Represents an abstract window with OpenGL rendering capabilities.
   *
   * The Window class provides an abstraction for creating and managing
   * an OpenGL window. It supports basic window creation, initialization,
   * and a loop for updating and rendering.
   */
  class Window
  {
    public:
      /**
       * @brief Constructs a Window object with specified properties.
       *
       * This constructor initializes the window with the provided properties.
       *
       * @param windowProps Properties for window creation.
       */
      Window(const WindowProps& windowProps)
      : width(windowProps.width), height(windowProps.height), title(windowProps.title)
      { this->_initialize(); }
      /**
       * @brief Constructs a Window object with specified width and height.
       *
       * This constructor initializes the window with the specified width and height.
       *
       * @param width  The width of the window.
       * @param height The height of the window.
       */
      Window(const unsigned int width, const unsigned int height)
      : width(width), height(height)
      { this->_initialize(); }
      /**
       * @brief Constructs a Window object with specified width, height, and title.
       *
       * This constructor initializes the window with the specified width, height, and title.
       *
       * @param width  The width of the window.
       * @param height The height of the window.
       * @param title  The title of the window.
       */
      Window(const unsigned int width, const unsigned int height, const std::string& title)
      : width(width), height(height), title(title)
      { this->_initialize(); }
      /**
       * @brief Destroys the Window object.
       */
      virtual ~Window();

      /**
       * @brief Initializes the window.
       *
       * Derived classes must implement this function to perform additional initialization.
       */
      virtual void initialize() = 0;
      /**
       * @brief Enters the window's main loop for updating and rendering.
       */
      void loop();
      /**
       * @brief Closes the window, triggering a request to close the application.
       */
      void close()
      { glfwSetWindowShouldClose(this->glfwWindow, GLFW_TRUE); }

      /**
       * @brief Gets the GLFW window associated with this object.
       *
       * This function returns the pointer to the GLFW window associated with this object.
       *
       * @return A pointer to the GLFW window.
       */
      GLFWwindow* getGlfwWindow() const
      { return this->glfwWindow; }
      /**
       * @brief Checks if the window is maximized.
       *
       * @return True if the window is maximized, false otherwise.
       */
      bool getIsMaximized() const
      { return this->isMaximized; }
      /**
       * @brief Gets the current time in seconds.
       *
       * This function returns the current time in seconds using GLFW's glfwGetTime function.
       *
       * @return The current time in seconds.
       */
      float getCurrentTime() const
      { return (float)glfwGetTime(); }
      /**
       * @brief Gets the time elapsed since the last frame.
       *
       * This function returns the time elapsed since the last frame, providing the delta time.
       *
       * @return The time elapsed since the last frame.
       */
      float getDeltaTime() const
      { return this->deltaTime; }
      /**
       * @brief Gets the camera bound to this window.
       *
       * This function returns a pointer to the camera that is currently bound to this window.
       *
       * @return A pointer to the bound camera, or nullptr if no camera is bound.
       */
      kdr::Camera* getBoundCamera() const
      { return this->boundCamera; }

      /**
       * @brief Sets the clear color for rendering.
       *
       * This function sets the clear color for rendering and updates the OpenGL clear color.
       *
       * @param clearColor The RGBA color to set as the clear color.
       */
      void setClearColor(const kdr::Color::RGBA& clearColor)
      {
        this->clearColor = clearColor;
        glClearColor(
          clearColor.red,
          clearColor.green,
          clearColor.blue,
          clearColor.alpha
        );
      }
      /**
       * @brief Sets the camera to be bound to the camera controller.
       *
       * This function sets the specified camera as the one bound to the camera controller.
       * It allows the camera controller to interact with and control the specified camera.
       *
       * @param camera A pointer to the camera to be bound. Pass a null pointer to unbind any existing camera.
       */
      void setBoundCamera(kdr::Camera* camera)
      { this->boundCamera = camera; }

      /**
       * @brief Maximizes the window.
       */
      void maximize();
      /**
       * @brief Unmaximizes the window.
       */
      void unmaximize();

    protected:
      /**
       * @brief Updates the window.
       *
       * This function is called during each iteration of the main loop to update the window.
       * Derived classes must implement this function to handle update logic.
       */
      virtual void update() = 0;
      /**
       * @brief Renders the window.
       *
       * This function is called during each iteration of the main loop to render the window.
       * Derived classes must implement this function to handle rendering.
       */
      virtual void render() = 0;

      /**
       * @brief Sets the flag indicating whether the mouse is locked.
       *
       * This function sets the flag indicating whether the mouse is locked within the window.
       *
       * @param isMouseLocked True if the mouse should be locked, false otherwise.
       */
      void setIsMouseLocked(const bool isMouseLocked)
      { this->isMouseLocked = isMouseLocked; }

      /**
       * @brief Binds the specified shader for rendering.
       *
       * This function sets the specified shader as the currently active shader program for rendering.
       * It also updates the internal state to keep track of the currently bound shader.
       *
       * @param shader The shader to be bound for rendering.
       */
      void bindShader(const kdr::Graphics::Shader& shader)
      {
        glUseProgram(shader.getID());
        this->boundShader = shader.getID();
      }
      /**
       * @brief Binds the specified texture for rendering.
       *
       * This function sets the specified texture unit in the bound shader and binds the texture.
       * It is used to prepare a texture for rendering.
       *
       * @param texture The texture to be bound for rendering.
       */
      void bindTexture(const kdr::Graphics::Texture& texture)
      {
        texture.TextureUnit(this->boundShader, "tex0", 0);
        texture.Bind();
      }
      /**
       * @brief Renders the specified solid object.
       *
       * This function applies the model matrix of the provided solid to the bound shader
       * and renders the solid object.
       *
       * @param solid The solid object to be rendered.
       */
      void renderSolid(kdr::Solids::Solid& solid)
      {
        solid.applyModelMatrix(this->boundShader);
        solid.render();
      }

    private:
      unsigned int width {800};
      unsigned int height {600};
      std::string title {"GLFW"};

      GLFWwindow* glfwWindow {NULL};
      kdr::Color::RGBA clearColor {kdr::Color::Black};

      GLuint boundShader {0};
      kdr::Camera* boundCamera {NULL};

      bool isMaximized {false};
      bool isMouseLocked {false};

      float deltaTime {0.f};
      float lastTime {(float)glfwGetTime()};

      /**
       * @brief Initializes GLFW.
       *
       * This function initializes the GLFW library and sets up error callback.
       *
       * @return True if GLFW initialization is successful; false otherwise.
       */
      bool _initializeGlfw();
      /**
       * @brief Initializes GLFW window creation settings.
       *
       * This function configures GLFW settings for window creation, such as
       * window hints, context version, and profile.
       *
       * @return True if GLFW window initialization is successful; false otherwise.
       */
      bool _initializeGlfwWindow();
      /**
       * @brief Initializes GLEW.
       *
       * This function initializes the GLEW library to manage OpenGL extensions.
       *
       * @return True if GLEW initialization is successful; false otherwise.
       */
      bool _initializeGlew();
      /**
        * @brief Initializes OpenGL settings.
        *
        * This function configures various OpenGL settings, such as enabling depth testing,
        * setting the clear color, and configuring the viewport.
        *
        * @return True if OpenGL settings initialization is successful; false otherwise.
        */
      bool _initializeOpenGLSettings();
      /**
       * @brief Initializes the window.
       */
      void _initialize();
      /**
       * @brief Updates the time elapsed since the last frame.
       *
       * This function updates the delta time, representing the time elapsed since the last frame.
       * It is called during each iteration of the main loop.
       */
      void _updateDeltaTime();
      /**
       * @brief Updates the camera.
       *
       * This function updates the camera's internal state, such as its position and orientation.
       * It is called during each iteration of the main loop.
       */
      void _updateCamera();
      /**
       * @brief Updates the window.
       */
      void _update();
      /**
       * @brief Renders the window.
       */
      void _render();
  };
}

#endif // KDR_WINDOW_HPP
