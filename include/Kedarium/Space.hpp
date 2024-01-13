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
     * @class Vec2
     * @brief Represents a 2D vector in space with x and y components.
     *
     * The Vec2 class is used to represent a point or direction in 2D space
     * with float precision for the x and y components.
     */
    class Vec2
    {
      public:
        /**
         * @brief Constructs a Vec2 with specified x and y components.
         *
         * @param x The x component of the vector.
         * @param y The y component of the vector.
         */
        Vec2(const float x, const float y)
        : x(x), y(y)
        {}
        /**
         * @brief Constructs a Vec2 with all components set to the given scalar value.
         *
         * @param scalar The scalar value to set for both components (x, y).
         */
        Vec2(const float scalar)
        : x(scalar), y(scalar)
        {}

        float x;
        float y;

        /**
         * @brief Overloaded addition operator for adding two Vec2 vectors.
         *
         * @param vec The Vec2 vector to be added.
         * @return The result of the addition operation.
         */
        Vec2 operator+(const kdr::Space::Vec2& vec) const
        {
          return kdr::Space::Vec2(
            this->x + vec.x,
            this->y + vec.y
          );
        }

        /**
         * @brief Overloaded subtraction operator for subtracting two Vec2 vectors.
         *
         * @param vec The Vec2 vector to be subtracted.
         * @return The result of the subtraction operation.
         */
        Vec2 operator-(const kdr::Space::Vec2& vec) const
        {
          return kdr::Space::Vec2(
            this->x - vec.x,
            this->y - vec.y
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
        Vec2 operator*(const T scalar)
        {
          return kdr::Space::Vec2(
            static_cast<float>(this->x * scalar),
            static_cast<float>(this->y * scalar)
          );
        }

        /**
         * @brief Friend function for overloaded multiplication operator with scalar on the left-hand side.
         *
         * @tparam T The type of the scalar.
         * @param scalar The scalar value.
         * @param vec The Vec2 vector.
         * @return The result of the multiplication operation.
         */
        template <typename T>
        friend Vec2 operator*(const T scalar, const Vec2& vec)
        {
          return kdr::Space::Vec2(
            static_cast<float>(vec.x * scalar),
            static_cast<float>(vec.y * scalar)
          );
        }
    };

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
          return kdr::Space::Vec3(
            static_cast<float>(vec.x * scalar),
            static_cast<float>(vec.y * scalar),
            static_cast<float>(vec.z * scalar)
          );
        }
    };

    /**
     * @brief Calculates the dot product of two 2D vectors.
     *
     * This function calculates the dot product of two 2D vectors.
     *
     * @param vecA The first 2D vector.
     * @param vecB The second 2D vector.
     * @return The dot product of the two vectors.
     */
    inline float dot(const kdr::Space::Vec2& vecA, const kdr::Space::Vec2& vecB)
    {
      return vecA.x * vecB.x + vecA.y * vecB.y;
    }

    /**
     * @brief Calculates the dot product of two 3D vectors.
     *
     * This function calculates the dot product of two 3D vectors.
     *
     * @param vecA The first 3D vector.
     * @param vecB The second 3D vector.
     * @return The dot product of the two vectors.
     */
    inline float dot(const kdr::Space::Vec3& vecA, const kdr::Space::Vec3& vecB)
    {
      return vecA.x * vecB.x + vecA.y * vecB.y + vecA.z * vecB.z;
    }

    /**
     * @brief Calculates the cross product of two 3D vectors.
     *
     * This function calculates the cross product of two 3D vectors.
     *
     * @param vecA The first 3D vector.
     * @param vecB The second 3D vector.
     * @return The cross product of the two vectors.
     */
    inline kdr::Space::Vec3 cross(const kdr::Space::Vec3& vecA, const kdr::Space::Vec3& vecB)
    {
      return kdr::Space::Vec3(
        vecA.y * vecB.z - vecA.z * vecB.y,
        vecA.z * vecB.x - vecA.x * vecB.z,
        vecA.x * vecB.y - vecA.y * vecB.x
      );
    }
  }
}

#endif // KDR_SPACE_HPP
