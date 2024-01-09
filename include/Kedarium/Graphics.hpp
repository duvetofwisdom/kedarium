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

    /**
     * @class VBO
     * @brief Represents a Vertex Buffer Object (VBO) for storing vertex data in OpenGL.
     *
     * The VBO class encapsulates the functionality for creating, managing, and using
     * OpenGL Vertex Buffer Objects (VBOs) to store vertex data for rendering.
     */
    class VBO
    {
      public:
        /**
         * @brief Constructs a VBO object and initializes it with vertex data.
         *
         * This constructor creates a VBO and initializes it with the specified vertex data.
         * The size parameter indicates the size (in bytes) of the vertex data.
         *
         * @param vertices An array of GLfloat representing the vertex data.
         * @param size     The size (in bytes) of the vertex data.
         */
        VBO(GLfloat vertices[], GLsizeiptr size);
        /**
         * @brief Destroys the VBO object, releasing associated OpenGL resources.
         *
         * The destructor cleans up the OpenGL resources associated with the VBO.
         */
        ~VBO();

        /**
         * @brief Binds the VBO to the OpenGL context.
         *
         * This function binds the VBO to the OpenGL context, making it the current
         * GL_ARRAY_BUFFER. Subsequent OpenGL operations will affect this VBO.
         */
        void Bind()
        { glBindBuffer(GL_ARRAY_BUFFER, this->ID); }
        /**
         * @brief Unbinds the VBO from the OpenGL context.
         *
         * This function unbinds the VBO from the OpenGL context, making it no longer
         * the current GL_ARRAY_BUFFER. Subsequent OpenGL operations will not affect this VBO.
         */
        void Unbind()
        { glBindBuffer(GL_ARRAY_BUFFER, 0); }
        /**
         * @brief Deletes the VBO, releasing associated OpenGL resources.
         *
         * This function deletes the VBO, releasing the OpenGL buffer object.
         */
        void Delete()
        { glDeleteBuffers(1, &this->ID); }

      private:
        GLuint ID;
    };
  }
}

#endif // KDR_GRAPHICS_HPP
