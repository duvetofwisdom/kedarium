#ifndef KDR_IMAGE_HPP
#define KDR_IMAGE_HPP

#include <GL/glew.h>

#include <stdio.h>
#include <cstring>
#include <png.h>
#include <iostream>
#include <string>

namespace kdr
{
  /**
   * @namespace Image
   * @brief Contains functions for working with images, such as loading from PNG files.
   */
  namespace Image
  {
    /**
     * @brief Loads image data from a PNG file.
     *
     * This function reads the specified PNG file and allocates memory for the image data.
     *
     * @param path The path to the PNG file.
     * @param data A pointer to the image data buffer.
     * @param imgWidth Reference to store the width of the loaded image.
     * @param imgHeight Reference to store the height of the loaded image.
     * @param hasAlpha Reference to store whether the loaded image has an alpha channel.
     * @return True if the image is successfully loaded, false otherwise.
     */
    bool loadFromPng(const std::string& path, GLubyte** data, int& imgWidth, int& imgHeight, bool& hasAlpha);
  }
}

#endif // KDR_IMAGE_HPP
