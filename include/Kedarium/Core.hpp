#ifndef KDR_CORE_HPP
#define KDR_CORE_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

namespace kdr
{
  /**
   * @namespace Core
   * @brief Contains core functionality for the Kedarium engine.
   *
   * This namespace includes functions related to engine information and version details.
   */
  namespace Core
  {
    /**
     * @brief Prints basic information about the engine.
     *
     * This function prints the name, version, author, and license of the engine.
     */
    void printEngineInfo();

    /**
     * @brief Prints version information about OpenGL, GLEW, and GLFW.
     *
     * This function prints the version information of OpenGL, GLEW, and GLFW.
     */
    void printVersionInfo();
  }
}

#endif // KDR_CORE_HPP
