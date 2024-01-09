#ifndef KDR_FILE_HPP
#define KDR_FILE_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

namespace kdr
{
  /**
   * @namespace File
   * @brief Contains functions for file-related operations.
   *
   * This namespace provides functions for performing operations related to files,
   * such as reading file contents.
   */
  namespace File
  {
    /**
     * @brief Reads the contents of a file and returns them as a string.
     *
     * This function opens the specified file, reads its contents, and returns them as a string.
     * If the file cannot be opened or read, an error message is printed to the standard error stream,
     * and an empty string is returned.
     *
     * @param path The path to the file.
     * @return The contents of the file as a string. An empty string if the file cannot be opened or read.
     */
    std::string getContents(const std::string& path);
  };
}

#endif // KDR_FILE_HPP
