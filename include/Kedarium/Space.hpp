#ifndef KDR_SPACE_HPP
#define KDR_SPACE_HPP

#include <cmath>

namespace kdr
{
  /**
   * @namespace Space
   * @brief Contains classes and structures related to 3D space.
   */
  namespace Space
  {
    /**
     * @brief The mathematical constant representing the ratio of a circle's circumference to its diameter.
     */
    inline const float PI = 3.141593f;

    /**
     * @brief Converts degrees to radians.
     *
     * This function converts an angle from degrees to radians using the formula: radians = degrees * (PI / 180).
     *
     * @param degrees The angle in degrees to be converted.
     * @return The angle in radians.
     */
    inline float radians(const float degrees)
    { return degrees * kdr::Space::PI / 180.f; }

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

    /**
     * @class Mat4
     * @brief Represents a 4x4 matrix of floating-point numbers.
     *
     * The Mat4 class provides a basic 4x4 matrix with elements stored in a 2D array.
     */
    class Mat4
    {
      public:
        /**
         * @brief Default constructor for Mat4.
         *
         * Initializes all elements of the matrix to 0.
         */
        Mat4()
        {
          for (int y = 0; y < 4; y++)
          {
            for (int x = 0; x < 4; x++)
            {
              elements[y][x] = 0.f;
            }
          }
        }
        /**
         * @brief Constructs a 4x4 matrix with diagonal elements set to a specified value.
         *
         * This constructor initializes a 4x4 matrix with diagonal elements set to the specified value,
         * and the off-diagonal elements set to 0.
         *
         * @param diagonalValue The value to set on the diagonal elements.
         */
        Mat4(const float diagonalValue)
        {
          for (int y = 0; y < 4; y++)
          {
            for (int x = 0; x < 4; x++)
            {
              elements[y][x] = x == y ? diagonalValue : 0.f;
            }
          }
        }

        /**
         * @brief Overloaded operator to access the elements of the matrix.
         *
         * Provides access to the elements of the matrix using the subscript operator.
         *
         * @param index The row index.
         * @return A pointer to the array representing the specified row of the matrix.
         */
        float* operator[](int index)
        { return this->elements[index]; }
        /**
         * @brief Overloaded operator to access the elements of the matrix (const version).
         *
         * Provides const access to the elements of the matrix using the subscript operator.
         *
         * @param index The row index.
         * @return A const pointer to the array representing the specified row of the matrix.
         */
        const float* operator[](int index) const
        { return this->elements[index]; }

        /**
         * @brief Multiplies this matrix by another matrix.
         *
         * This function performs matrix multiplication between this matrix and the provided matrix.
         *
         * @param mat The matrix to multiply with.
         * @return The result of the matrix multiplication.
         */
        Mat4 operator*(const kdr::Space::Mat4& mat) const
        {
          Mat4 result;
          for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
              for (int k = 0; k < 4; k++) {
                result[i][j] += mat[i][k] * elements[k][j];
              }
            }
          }
          return result;
        }

      private:
        float elements[4][4];
    };

    /**
     * @brief Gets a pointer to the first element of a 4x4 matrix.
     *
     * This function returns a pointer to the first element of the specified 4x4 matrix.
     * It can be useful when passing the matrix to OpenGL functions that expect a pointer
     * to a contiguous block of memory representing a matrix.
     *
     * @param mat The 4x4 matrix.
     * @return A const pointer to the first element of the matrix.
     */
    inline const float* valuePointer(const kdr::Space::Mat4& mat)
    { return &mat[0][0]; }

    /**
     * @brief Creates a translation matrix based on an existing matrix and a translation vector.
     *
     * This function generates a translation matrix by adding the specified translation vector to the
     * translation components of the given matrix.
     *
     * @param mat The original matrix to be translated.
     * @param vec The translation vector representing the translation in x, y, and z directions.
     * @return The resulting matrix after translation.
     */
    kdr::Space::Mat4 translate(const kdr::Space::Mat4& mat, const kdr::Space::Vec3& vec);
    /**
     * @brief Creates a perspective projection matrix.
     *
     * This function generates a perspective projection matrix based on the specified parameters.
     *
     * @param fov The field of view angle in degrees.
     * @param aspect The aspect ratio of the viewport (width / height).
     * @param zNear The distance to the near clipping plane.
     * @param zFar The distance to the far clipping plane.
     * @return The perspective projection matrix.
     */
    kdr::Space::Mat4 perspective(const float fov, const float aspect, const float zNear, const float zFar);
  }
}

#endif // KDR_SPACE_HPP
