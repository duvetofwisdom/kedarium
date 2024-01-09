#ifndef KDR_GRAPHICS_HPP
#define KDR_GRAPHICS_HPP

#include <GL/glew.h>
#include <string>

#include "File.hpp"

namespace kdr
{
  /**
   * @namespace Graphics
   * @brief Contains classes and functions related to graphics and rendering.
   *
   * This namespace provides functionality for graphics and rendering, including classes
   * for managing shaders and other graphics-related operations.
   */
  namespace Graphics
  {
    /**
     * @class Shader
     * @brief Represents a shader program for use in graphics rendering.
     *
     * The Shader class encapsulates the functionality for creating, managing, and using
     * shader programs in OpenGL graphics rendering.
     */
    class Shader
    {
      public: 
        /**
         * @brief Constructs a Shader object by loading and compiling shader source code.
         *
         * This constructor loads and compiles the vertex and fragment shaders specified
         * by the provided file paths. It links the shaders into a program, and the program ID
         * can be retrieved using the getID() method.
         *
         * @param vertexPath   The file path to the vertex shader source code.
         * @param fragmentPath The file path to the fragment shader source code.
         */
        Shader(const std::string& vertexPath, const std::string& fragmentPath);
        /**
         * @brief Destroys the Shader object.
         *
         * The destructor cleans up the OpenGL resources associated with the shader program.
         */
        ~Shader();

        /**
         * @brief Gets the OpenGL ID of the shader program.
         *
         * @return The OpenGL ID of the shader program.
         */
        GLuint getID() const
        { return this->ID; }

        /**
         * @brief Sets this shader as the currently active shader in the OpenGL context.
         */
        void Use()
        { glUseProgram(this->ID); }
        /**
         * @brief Deletes the shader program, releasing associated OpenGL resources.
         */
        void Delete()
        { glDeleteProgram(this->ID); }

      private:
        GLuint ID;
    };
  }
}

#endif // KDR_GRAPHICS_HPP
