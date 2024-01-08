#ifndef KDR_COLOR_HPP
#define KDR_COLOR_HPP

#include <stdint.h>

namespace kdr
{
  /**
   * @namespace Color
   * @brief Namespace containing structures and functions related to color manipulation.
   *
   * This namespace provides structures for representing colors in different color spaces.
   * It also includes functions for color operations and manipulations.
   */
  namespace Color
  {
    /**
     * @struct RGB
     * @brief Represents a color in the RGB color space.
     *
     * This structure defines a color using the red, green, and blue components.
     */
    struct RGB
    {
      float red;
      float green;
      float blue;

      /**
       * @brief Constructor for RGB color using uint8_t values.
       *
       * Converts uint8_t values to floats by dividing them by 255.0.
       *
       * @param red   Red component of the color (0-255).
       * @param green Green component of the color (0-255).
       * @param blue  Blue component of the color (0-255).
       */
      RGB(const uint8_t red, const uint8_t green, const uint8_t blue)
      : red(red / 255.f), green(green / 255.f), blue(blue / 255.f)
      {}
    };

    /**
     * @struct RGBA
     * @brief Represents a color in the RGBA color space.
     *
     * This structure defines a color using the red, green, blue, and alpha components.
     */
    struct RGBA
    {
      float red;
      float green;
      float blue;
      float alpha;

      /**
       * @brief Constructor for RGBA color using uint8_t values.
       *
       * Converts uint8_t values to floats by dividing them by 255.0.
       *
       * @param red   Red component of the color (0-255).
       * @param green Green component of the color (0-255).
       * @param blue  Blue component of the color (0-255).
       * @param alpha Alpha component of the color (0.0-1.0).
       */
      RGBA(const uint8_t red, const uint8_t green, const uint8_t blue, const float alpha)
      : red(red / 255.f), green(green / 255.f), blue(blue / 255.f), alpha(alpha)
      {}
    };
  }
}

#endif // KDR_COLOR_HPP
