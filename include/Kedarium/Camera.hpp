#ifndef KDR_CAMERA_HPP
#define KDR_CAMERA_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Keys.hpp"
#include "Space.hpp"

namespace kdr
{
  /**
   * @brief Structure to hold camera properties.
   */
  struct CameraProps
  {
    kdr::Space::Vec3 position;
    float fov;
    float aspect;
    float zNear;
    float zFar;
    float speed;

    /**
     * @brief Constructs a CameraProps object with specified parameters.
     *
     * @param position The position of the camera in 3D space.
     * @param fov The field of view of the camera in degrees.
     * @param aspect The aspect ratio of the camera (width divided by height).
     * @param zNear The distance to the near clipping plane.
     * @param zFar The distance to the far clipping plane.
     * @param speed The speed at which the camera can move.
     */
    CameraProps(const kdr::Space::Vec3& position, const float fov, const float aspect, const float zNear, const float zFar, const float speed)
    : position(position), fov(fov), aspect(aspect), zNear(zNear), zFar(zFar), speed(speed)
    {}
  };

  /**
   * @brief Represents a camera in a 3D scene.
   */
  class Camera
  {
    public:
      /**
       * @brief Constructs a camera with specified properties.
       *
       * @param cameraProps The camera properties.
       */
      Camera(const kdr::CameraProps& cameraProps)
      : position(cameraProps.position), fov(cameraProps.fov), aspect(cameraProps.aspect), zNear(cameraProps.zNear), zFar(cameraProps.zFar), speed(cameraProps.speed)
      {}
      /**
       * @brief Constructs a camera with specified parameters.
       *
       * @param position The position of the camera.
       * @param fov The field of view angle in degrees.
       * @param aspect The aspect ratio (width / height) of the camera viewport.
       * @param zNear The distance to the near clipping plane.
       * @param zFar The distance to the far clipping plane.
       * @param speed The movement speed of the camera.
       */
      Camera(const kdr::Space::Vec3& position, const float fov, const float aspect, const float zNear, const float zFar, const float speed)
      : position(position), fov(fov), aspect(aspect), zNear(zNear), zFar(zFar), speed(speed)
      {}

      /**
       * @brief Gets the field of view angle of the camera.
       *
       * @return The field of view angle in degrees.
       */
      float getFov() const
      { return this->fov; }
      /**
       * @brief Gets the aspect ratio of the camera's viewport.
       *
       * @return The aspect ratio (width / height).
       */
      float getAspect() const
      { return this->aspect; }
      /**
       * @brief Gets the distance to the near clipping plane.
       *
       * @return The distance to the near clipping plane.
       */
      float getZNear() const
      { return this->zNear; }
      /**
       * @brief Gets the distance to the far clipping plane.
       *
       * @return The distance to the far clipping plane.
       */
      float getZFar() const
      { return this->zFar; }

      /**
       * @brief Updates the keys for camera movement.
       *
       * @param window The GLFW window.
       * @param deltaTime The time elapsed since the last frame.
       */
      void updateKeys(GLFWwindow* window, const float deltaTime);
      /**
       * @brief Updates the camera matrix based on current camera properties.
       *
       * This function calculates and updates the camera matrix by combining the view and
       * projection matrices. The view matrix is created by translating it based on the camera's
       * position. The projection matrix is created using the camera's field of view (fov),
       * aspect ratio, near and far clipping planes.
       */
      void updateMatrix();
      /**
       * @brief Applies the camera matrix to a shader.
       *
       * This function sets the value of the "cameraMatrix" uniform variable in the specified shader
       * using the camera's internal camera matrix.
       *
       * @param shaderID The ID of the shader program.
       */
      void applyMatrix(GLuint shaderID);

    private:
      kdr::Space::Vec3 position {0.f};
      kdr::Space::Mat4 cameraMatrix {1.f};

      float fov;
      float aspect;
      float zNear;
      float zFar;
      float speed;
  };
}

#endif // KDR_CAMERA_HPP
