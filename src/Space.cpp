#include "Kedarium/Space.hpp"

kdr::Space::Mat4 kdr::Space::translate(const kdr::Space::Mat4& mat, const kdr::Space::Vec3& vec)
{
  kdr::Space::Mat4 result {mat};
  result[3][0] += vec.x;
  result[3][1] += vec.y;
  result[3][2] += vec.z;  
  return result;
}

kdr::Space::Mat4 kdr::Space::perspective(const float fov, const float aspect, const float zNear, const float zFar)
{
  kdr::Space::Mat4 result;
  const float halfTanFOV = tanf(kdr::Space::radians(fov));

  result[0][0] = 1.f / (halfTanFOV * aspect);
  result[1][1] = 1.f / halfTanFOV;
  result[2][2] = (zFar + zNear) / (zNear - zFar);
  result[2][3] = -1.f;
  result[3][2] = -(2.f * zFar * zNear) / (zFar - zNear);

  return result;
}
