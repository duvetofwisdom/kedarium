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
    LeftShift = GLFW_KEY_LEFT_SHIFT,
    Spacebar = GLFW_KEY_SPACE,
    A = GLFW_KEY_A,
    B = GLFW_KEY_B,
    C = GLFW_KEY_C,
    D = GLFW_KEY_D,
    E = GLFW_KEY_E,
    F = GLFW_KEY_F,
    G = GLFW_KEY_G,
    H = GLFW_KEY_H,
    I = GLFW_KEY_I,
    J = GLFW_KEY_J,
    K = GLFW_KEY_K,
    L = GLFW_KEY_L,
    M = GLFW_KEY_M,
    N = GLFW_KEY_N,
    O = GLFW_KEY_O,
    P = GLFW_KEY_P,
    Q = GLFW_KEY_Q,
    R = GLFW_KEY_R,
    S = GLFW_KEY_S,
    T = GLFW_KEY_T,
    U = GLFW_KEY_U,
    V = GLFW_KEY_V,
    W = GLFW_KEY_W,
    X = GLFW_KEY_X,
    Y = GLFW_KEY_Y,
    Z = GLFW_KEY_Z,
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
    inline bool isPressed(GLFWwindow* window, const kdr::Key& key)
    { return glfwGetKey(window, key) == GLFW_PRESS; }
  }
}

#endif // KDR_KEYS_HPP
