#ifndef KDR_DEBUG_HPP
#define KDR_DEBUG_HPP

#include <iostream>

#include "Space.hpp"

namespace kdr
{
  /**
   * @namespace Debug
   * @brief Contains functions for debugging and printing information.
   */
  namespace Debug
  {
    /**
     * @brief Prints the components of a 3D vector.
     *
     * This function prints the components of a 3D vector to the standard output.
     *
     * @param vec The 3D vector to be printed.
     */
    void printVector(const kdr::Space::Vec3& vec)
    {
      std::cout << "Vector: " << vec.x << ", " << vec.y << ", " << vec.z << '\n';
    }

    void printMatrix(const kdr::Space::Mat4& mat)
    {
      std::cout << "Matrix:\n";
      for (int y = 0; y < 4; y++)
      {
        for (int x = 0; x < 4; x++)
        {
          std::cout << mat[y][x] << " ";
        }
        std::cout << '\n';
      }
    }
  }
}

#endif // KDR_DEBUG_HPP
