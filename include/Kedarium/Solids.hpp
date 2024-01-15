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
        {
          this->translate(position);
        }
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
         * @brief Translates the solid object by the specified 3D vector.
         *
         * This function updates the model matrix of the solid object by applying a translation
         * based on the provided 3D vector.
         *
         * @param vec The translation vector specifying the amount to move along each axis.
         */
        void translate(const kdr::Space::Vec3& vec)
        {
          this->model = kdr::Space::translate(this->model, vec);
        }
        /**
         * @brief Translates the solid object along the X-axis by the specified amount.
         *
         * This function updates the model matrix of the solid object by applying a translation
         * along the X-axis based on the provided amount.
         *
         * @param amount The amount to move along the X-axis.
         */
        void translateX(const float amount)
        {
          this->model = kdr::Space::translate(this->model, {amount, 0.f, 0.f});
        }
        /**
         * @brief Translates the solid object along the Y-axis by the specified amount.
         *
         * This function updates the model matrix of the solid object by applying a translation
         * along the Y-axis based on the provided amount.
         *
         * @param amount The amount to move along the Y-axis.
         */
        void translateY(const float amount)
        {
          this->model = kdr::Space::translate(this->model, {0.f, amount, 0.f});
        }
        /**
         * @brief Translates the solid object along the Z-axis by the specified amount.
         *
         * This function updates the model matrix of the solid object by applying a translation
         * along the Z-axis based on the provided amount.
         *
         * @param amount The amount to move along the Z-axis.
         */
        void translateZ(const float amount)
        {
          this->model = kdr::Space::translate(this->model, {0.f, 0.f, amount});
        }

        /**
         * @brief Pure virtual function to render the solid object.
         *
         * Derived classes must implement this function to handle rendering of the solid object.
         */
        virtual void render() = 0;

      protected:
        kdr::Graphics::VAO* VAO {NULL};
        kdr::Graphics::VBO* VBO {NULL};
        kdr::Graphics::EBO* EBO {NULL};

      private:
        kdr::Space::Vec3 position {0.f};
        kdr::Space::Mat4 model {1.f};
    };

    /**
     * @brief Represents a cube in 3D space, derived from the Solid class.
     */
    class Cube : public kdr::Solids::Solid
    {
      public:
        /**
         * @brief Constructs a cube with specified position and edge length.
         *
         * @param position The position of the cube in 3D space.
         * @param edgeLength The length of each edge of the cube.
         */
        Cube(const kdr::Space::Vec3& position, const float edgeLength);

        /**
         * @brief Renders the cube.
         *
         * This function is responsible for rendering the cube, applying its model matrix
         * and any additional rendering logic.
         */
        void render();
    };
  }
}

#endif // KDR_SOLIDS_HPP
