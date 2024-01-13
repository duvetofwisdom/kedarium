#ifndef KDR_KEYS_HPP
#define KDR_KEYS_HPP

#include <GLFW/glfw3.h>

namespace kdr
{
  /**
   * @brief Enumeration of commonly used keyboard keys.
   */
  enum Key
  {
    Escape = GLFW_KEY_ESCAPE,
    E = GLFW_KEY_E,
  };

  /**
   * @namespace Keys
   * @brief Provides utilities for working with keyboard keys.
   */
  namespace Keys
  {
    /**
     * @brief Checks if a specific key is currently pressed.
     *
     * This function checks whether the specified key is currently pressed.
     *
     * @param window The GLFW window.
     * @param key The key to check.
     * @return True if the key is pressed, false otherwise.
     */
    bool isPressed(GLFWwindow* window, const kdr::Key& key)
    { return glfwGetKey(window, key) == GLFW_PRESS; }
  }
}

#endif // KDR_KEYS_HPP
