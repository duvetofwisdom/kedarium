#ifndef KDR_SPACE_HPP
#define KDR_SPACE_HPP

namespace kdr
{
  /**
   * @namespace Space
   * @brief Contains classes and structures related to 3D space.
   */
  namespace Space
  {
    /**
     * @class Vec3
     * @brief Represents a 3D vector in space with x, y, and z components.
     *
     * The Vec3 class is used to represent a point or direction in 3D space
     * with float precision for the x, y, and z components.
     */
    class Vec3
    {
      public:
        /**
         * @brief Constructs a Vec3 with specified x, y, and z components.
         *
         * @param x The x component of the vector.
         * @param y The y component of the vector.
         * @param z The z component of the vector.
         */
        Vec3(const float x, const float y, const float z)
        : x(x), y(y), z(z)
        {}
        /**
         * @brief Constructs a Vec3 with all components set to the given scalar value.
         *
         * @param scalar The scalar value to set for all components (x, y, z).
         */
        Vec3(const float scalar)
        : x(scalar), y(scalar), z(scalar)
        {}

        float x;
        float y;
        float z;

        /**
         * @brief Overloaded addition operator for adding two Vec3 vectors.
         *
         * @param vec The Vec3 vector to be added.
         * @return The result of the addition operation.
         */
        Vec3 operator+(const kdr::Space::Vec3& vec) const
        {
          return kdr::Space::Vec3(
            this->x + vec.x,
            this->y + vec.y,
            this->z + vec.z
          );
        }

        /**
         * @brief Overloaded subtraction operator for subtracting two Vec3 vectors.
         *
         * @param vec The Vec3 vector to be subtracted.
         * @return The result of the subtraction operation.
         */
        Vec3 operator-(const kdr::Space::Vec3& vec) const
        {
          return kdr::Space::Vec3(
            this->x - vec.x,
            this->y - vec.y,
            this->z - vec.z
          );
        }

        /**
         * @brief Overloaded multiplication operator for multiplying the vector by a scalar.
         *
         * @tparam T The type of the scalar.
         * @param scalar The scalar value.
         * @return The result of the multiplication operation.
         */
        template <typename T>
        Vec3 operator*(const T scalar)
        {
          return kdr::Space::Vec3(
            static_cast<float>(this->x * scalar),
            static_cast<float>(this->y * scalar),
            static_cast<float>(this->z * scalar)
          );
        }

        /**
         * @brief Friend function for overloaded multiplication operator with scalar on the left-hand side.
         *
         * @tparam T The type of the scalar.
         * @param scalar The scalar value.
         * @param vec The Vec3 vector.
         * @return The result of the multiplication operation.
         */
        template <typename T>
        friend Vec3 operator*(const T scalar, const Vec3& vec)
        {
          return Vec3(
            static_cast<float>(vec.x * scalar),
            static_cast<float>(vec.y * scalar),
            static_cast<float>(vec.z * scalar)
          );
        }
    };
  }
}

#endif // KDR_SPACE_HPP
