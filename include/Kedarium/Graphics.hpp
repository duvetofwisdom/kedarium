#ifndef KDR_GRAPHICS_HPP
#define KDR_GRAPHICS_HPP

#include <GL/glew.h>
#include <string>

#include "File.hpp"
#include "Image.hpp"

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
     * @brief Sets the OpenGL polygon mode to point mode.
     */
    inline void usePointMode()
    { glPolygonMode(GL_FRONT_AND_BACK, GL_POINT); }
    /**
     * @brief Sets the OpenGL polygon mode to line mode.
     */
    inline void useLineMode()
    { glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); }
    /**
     * @brief Sets the OpenGL polygon mode to fill mode.
     */
    inline void useFillMode()
    { glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); }

    /**
     * @brief Sets the size of points when rendering in point mode.
     *
     * @param size The size of points.
     */
    inline void setPointSize(const float size)
    { glPointSize(size); }
    /**
     * @brief Sets the width of lines when rendering in line mode.
     *
     * @param width The width of lines.
     */
    inline void setLineWidth(const float width)
    { glLineWidth(width); }

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
        ~VBO()
        { glDeleteBuffers(1, &this->ID); }

        /**
         * @brief Binds the VBO to the OpenGL context.
         *
         * This function binds the VBO to the OpenGL context, making it the current
         * GL_ARRAY_BUFFER. Subsequent OpenGL operations will affect this VBO.
         */
        void Bind() const
        { glBindBuffer(GL_ARRAY_BUFFER, this->ID); }
        /**
         * @brief Unbinds the VBO from the OpenGL context.
         *
         * This function unbinds the VBO from the OpenGL context, making it no longer
         * the current GL_ARRAY_BUFFER. Subsequent OpenGL operations will not affect this VBO.
         */
        void Unbind() const
        { glBindBuffer(GL_ARRAY_BUFFER, 0); }
        /**
         * @brief Deletes the VBO, releasing associated OpenGL resources.
         *
         * This function deletes the VBO, releasing the OpenGL buffer object.
         */
        void Delete() const
        { glDeleteBuffers(1, &this->ID); }

      private:
        GLuint ID;
    };

    /**
     * @class EBO
     * @brief Represents an Element Buffer Object (EBO) for storing element (index) data in OpenGL.
     *
     * The EBO class encapsulates the functionality for creating, managing, and using
     * OpenGL Element Buffer Objects (EBOs) to store element (index) data for rendering.
     */
    class EBO
    {
      public:
        /**
         * @brief Constructs an EBO object and initializes it with element data.
         *
         * This constructor creates an EBO and initializes it with the specified element data.
         * The size parameter indicates the size (in bytes) of the element data.
         *
         * @param indices An array of GLuint representing the element (index) data.
         * @param size    The size (in bytes) of the element data.
         */
        EBO(GLuint indices[], GLsizeiptr size);
        /**
         * @brief Destroys the EBO object, releasing associated OpenGL resources.
         *
         * The destructor cleans up the OpenGL resources associated with the EBO.
         */
        ~EBO()
        { glDeleteBuffers(1, &this->ID); }

        /**
         * @brief Binds the EBO to the OpenGL context.
         *
         * This function binds the EBO to the OpenGL context, making it the current
         * GL_ELEMENT_ARRAY_BUFFER. Subsequent OpenGL operations will affect this EBO.
         */
        void Bind() const
        { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ID); }
        /**
         * @brief Unbinds the EBO from the OpenGL context.
         *
         * This function unbinds the EBO from the OpenGL context, making it no longer
         * the current GL_ELEMENT_ARRAY_BUFFER. Subsequent OpenGL operations will not affect this EBO.
         */
        void Unbind() const
        { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }
        /**
         * @brief Deletes the EBO, releasing associated OpenGL resources.
         *
         * This function deletes the EBO, releasing the OpenGL buffer object.
         */
        void Delete() const
        { glDeleteBuffers(1, &this->ID); }

      private:
        GLuint ID;
    };

    /**
     * @class VAO
     * @brief Represents a Vertex Array Object (VAO) for encapsulating vertex attribute configuration in OpenGL.
     *
     * The VAO class encapsulates the functionality for creating, managing, and using
     * OpenGL Vertex Array Objects (VAOs) to define the configuration of vertex attributes
     * for rendering with Vertex Buffer Objects (VBOs).
     */
    class VAO
    {
      public:
        /**
         * @brief Constructs a VAO and generates its OpenGL ID.
         *
         * This constructor generates an OpenGL Vertex Array Object (VAO) ID.
         */
        VAO()
        { glGenVertexArrays(1, &this->ID); }
        /**
         * @brief Destroys the VAO object, releasing associated OpenGL resources.
         *
         * The destructor cleans up the OpenGL resources associated with the VAO.
         */
        ~VAO()
        { glDeleteVertexArrays(1, &this->ID); }

        /**
         * @brief Binds the VAO to the OpenGL context.
         *
         * This function binds the VAO to the OpenGL context, making it the current
         * Vertex Array Object. Subsequent OpenGL operations will affect this VAO.
         */
        void Bind() const
        { glBindVertexArray(this->ID); }
        /**
         * @brief Unbinds the VAO from the OpenGL context.
         *
         * This function unbinds the VAO from the OpenGL context, making it no longer
         * the current Vertex Array Object. Subsequent OpenGL operations will not affect this VAO.
         */
        void Unbind() const
        { glBindVertexArray(0); }
        /**
         * @brief Deletes the VAO, releasing associated OpenGL resources.
         *
         * This function deletes the VAO, releasing the OpenGL buffer object.
         */
        void Delete() const
        { glDeleteVertexArrays(1, &this->ID); }
        /**
         * @brief Links a VBO's attribute to the VAO's layout configuration.
         *
         * This function associates a VBO's attribute with the layout configuration of the VAO.
         *
         * @param VBO     The VBO containing the attribute data.
         * @param layout  The layout index for the attribute.
         * @param size    The number of components per attribute (e.g., 3 for a vec3).
         * @param type    The data type of the attribute.
         * @param stride  The stride between consecutive attributes in the VBO.
         * @param offset  The offset of the attribute in the VBO.
         */
        void LinkAttrib(const kdr::Graphics::VBO& VBO, GLuint layout, GLuint size, GLenum type, GLsizeiptr stride, const void* offset) const;

      private:
        GLuint ID;
    };

    /**
     * @brief Represents a texture in a graphics application.
     *
     * This class provides functionality to load and manage textures in OpenGL.
     */
    class Texture
    {
      public:
        /**
         * @brief Constructs a Texture object from a PNG file.
         *
         * @param pngPath The path to the PNG file.
         * @param type The target of the texture (e.g., GL_TEXTURE_2D).
         * @param pixelFormat The pixel format of the texture.
         * @param pixelType The data type of the texture.
         */
        Texture(const std::string& pngPath, GLenum type, GLenum slot, GLenum pixelType);
        /**
         * @brief Destructor for the Texture class.
         *
         * Releases OpenGL resources associated with the texture.
         */
        ~Texture()
        { glDeleteTextures(1, &this->ID); }

        /**
         * @brief Sets the texture unit for a shader uniform.
         *
         * @param shaderID The ID of the shader program.
         * @param uniform The name of the uniform variable in the shader.
         * @param unit The texture unit to set.
         */
        void TextureUnit(const GLuint shaderID, const std::string& uniform, GLuint unit)
        {
          GLuint texUnitLoc = glGetUniformLocation(shaderID, uniform.c_str());
          glUniform1i(texUnitLoc, unit);
        }
        /**
         * @brief Binds the texture to its designated texture target.
         */
        void Bind()
        { glBindTexture(this->type, this->ID); };
        /**
         * @brief Unbinds the texture.
         */
        void Unbind()
        { glBindTexture(this->type, 0); };
        /**
         * @brief Deletes the texture, releasing associated OpenGL resources.
         */
        void Delete()
        { glDeleteTextures(1, &this->ID); }

      private:
        GLuint ID;
        GLenum type;
    };
  }
}

#endif // KDR_GRAPHICS_HPP
