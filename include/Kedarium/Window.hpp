#ifndef KDR_WINDOW_HPP
#define KDR_WINDOW_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

#include "Color.hpp"

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

    private:
      unsigned int width {800};
      unsigned int height {600};
      std::string title {"GLFW"};

      GLFWwindow* glfwWindow;
      kdr::Color::RGBA clearColor {kdr::Color::Black};

      bool isMouseLocked {false};

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
