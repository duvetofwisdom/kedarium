#ifndef KDR_SOLIDS_HPP
#define KDR_SOLIDS_HPP

#include "Space.hpp"
#include "Graphics.hpp"

namespace kdr
{
  /**
   * @namespace Solids
   * @brief Contains classes and functions related to solid objects in a 3D space.
   *
   * This namespace provides a base class for solid objects and related functionalities.
   */
  namespace Solids
  {
    /**
     * @brief Base class for solid objects in a 3D space.
     */
    class Solid
    {
      public:
        /**
         * @brief Constructs a Solid object at the specified position.
         *
         * @param position The position of the solid object in 3D space.
         */
        Solid(const kdr::Space::Vec3& position)
        : position(position)
        {}
        /**
         * @brief Destructor for the Solid class.
         *
         * Deletes associated OpenGL resources (VAO, VBO, EBO).
         */
        virtual ~Solid()
        {
          this->VAO->Delete();
          this->VBO->Delete();
          this->EBO->Delete();
        }

        /**
         * @brief Applies the model matrix to the specified shader.
         *
         * This function sets the value of the "model" uniform variable in the specified shader
         * using the solid object's internal model matrix.
         *
         * @param shaderID The ID of the shader program.
         */
        void applyModelMatrix(const GLuint shaderID)
        {
          GLuint location = glGetUniformLocation(shaderID, "model");
          glUniformMatrix4fv(location, 1, GL_FALSE, kdr::Space::valuePointer(this->model));
        }

        /**
         * @brief Pure virtual function to render the solid object.
         *
         * Derived classes must implement this function to handle rendering of the solid object.
         */
        virtual void render() = 0;

      private:
        kdr::Space::Vec3 position {0.f};
        kdr::Space::Mat4 model {1.f};

        kdr::Graphics::VAO* VAO {NULL};
        kdr::Graphics::VBO* VBO {NULL};
        kdr::Graphics::EBO* EBO {NULL};
    };
  }
}

#endif // KDR_SOLIDS_HPP
