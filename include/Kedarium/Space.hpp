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

        float x;
        float y;
        float z;
    };
  }
}

#endif // KDR_SPACE_HPP
