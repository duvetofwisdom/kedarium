#ifndef KDR_CORE_HPP
#define KDR_CORE_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <unordered_map>
#include <string>

#include "Graphics.hpp"

namespace kdr
{
  /**
   * @namespace Core
   * @brief Contains core functionalities and utility classes for the engine.
   */
  namespace Core
  {
    /**
     * @brief Prints basic information about the engine.
     *
     * This function prints the name, version, author, and license of the engine.
     */
    void printEngineInfo();
    /**
     * @brief Prints version information about OpenGL, GLEW, and GLFW.
     *
     * This function prints the version information of OpenGL, GLEW, and GLFW.
     */
    void printVersionInfo();

    /**
     * A generic manager class for storing and retrieving items by key.
     *
     * @tparam T The type of items stored in the manager.
     */
    template <class T>
    class Manager
    {
      public:
        /**
         * Constructs a Manager object.
         */
        Manager()
        {}
        /**
         * @brief Destructor for the Manager class.
         *
         * Deletes all items stored in the manager and clears the internal storage.
         * This ensures proper cleanup of resources.
         */
        ~Manager() {
          for (auto& pair : items) {
            delete pair.second;
          }
          items.clear();
        }

        /**
         * Gets the value associated with the given key.
         *
         * @param key The key used to retrieve the item.
         * @return The item associated with the key, or null if not found.
         */
        T* get(const std::string& key)
        {
          auto it = items.find(key);
          return it != items.end() ? it->second : NULL;
        }

        /**
         * Adds an item to the manager with the specified key.
         *
         * @param key The key to associate with the item.
         * @param value The item to be added.
         */
        void add(const std::string& key, T* value)
        { items[key] = value; }

      private:
        std::unordered_map<std::string, T*> items;
    };

    /**
     * @brief Loads a texture from the specified PNG file.
     *
     * This function creates a new Texture object by loading an image from the
     * specified PNG file and returns a pointer to the created texture.
     *
     * @param pngName The name of the PNG file (excluding the extension).
     * @return A pointer to the loaded texture.
     */
    inline kdr::Graphics::Texture* loadTexture(const std::string& pngName)
    {
      kdr::Graphics::Texture* texture = new kdr::Graphics::Texture {
        "resources/Textures/" + pngName + ".png",
        GL_TEXTURE_2D,
        GL_TEXTURE0,
        GL_UNSIGNED_BYTE
      };
      return texture;
    }
  }
}

#endif // KDR_CORE_HPP
