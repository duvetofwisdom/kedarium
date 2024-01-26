#include "Kedarium/Space.hpp"

kdr::Space::Mat4 kdr::Space::translate(const kdr::Space::Mat4& mat, const kdr::Space::Vec3& vec)
{
  kdr::Space::Mat4 result {mat};
  result[3][0] += vec.x;
  result[3][1] += vec.y;
  result[3][2] += vec.z;  
  return result;
}

kdr::Space::Mat4 kdr::Space::rotate(const kdr::Space::Mat4& mat, const kdr::Space::Vec3& vec, const float angle)
{
  kdr::Space::Vec3 normalizedVec = kdr::Space::normalize(vec);
  kdr::Space::Mat4 viewMat {mat};

  const float cosTheta = std::cos(kdr::Space::radians(angle));
  const float sinTheta = std::sin(kdr::Space::radians(angle));
  const float oneMinusCosTheta = 1 - cosTheta;

  viewMat[0][0] = cosTheta + normalizedVec.x * normalizedVec.x * oneMinusCosTheta;
  viewMat[0][1] = normalizedVec.x * normalizedVec.y * oneMinusCosTheta - normalizedVec.z * sinTheta;
  viewMat[0][2] = normalizedVec.x * normalizedVec.z * oneMinusCosTheta + normalizedVec.y * sinTheta;
  viewMat[1][0] = normalizedVec.y * normalizedVec.x * oneMinusCosTheta + normalizedVec.z * sinTheta;
  viewMat[1][1] = cosTheta + normalizedVec.y * normalizedVec.y * oneMinusCosTheta;
  viewMat[1][2] = normalizedVec.y * normalizedVec.z * oneMinusCosTheta - normalizedVec.x * sinTheta;
  viewMat[2][0] = normalizedVec.z * normalizedVec.x * oneMinusCosTheta - normalizedVec.y * sinTheta;
  viewMat[2][1] = normalizedVec.z * normalizedVec.y * oneMinusCosTheta + normalizedVec.x * sinTheta;
  viewMat[2][2] = cosTheta + normalizedVec.z * normalizedVec.z * oneMinusCosTheta;

  return viewMat * mat;
}

kdr::Space::Mat4 kdr::Space::perspective(const float fov, const float aspect, const float zNear, const float zFar)
{
  kdr::Space::Mat4 result;
  const float halfTanFOV = tanf(kdr::Space::radians(fov)) / 2.f;

  result[0][0] = 1.f / (halfTanFOV * aspect);
  result[1][1] = 1.f / halfTanFOV;
  result[2][2] = (zFar + zNear) / (zNear - zFar);
  result[2][3] = -1.f;
  result[3][2] = -(2.f * zFar * zNear) / (zFar - zNear);

  return result;
}

kdr::Space::Mat4 kdr::Space::lookAt(const kdr::Space::Vec3& eye, const kdr::Space::Vec3& target, const kdr::Space::Vec3& up)
{
  kdr::Space::Vec3 front = kdr::Space::normalize(eye - target);
  kdr::Space::Vec3 right = kdr::Space::normalize(kdr::Space::cross(up, front));
  kdr::Space::Vec3 newUp = kdr::Space::cross(front, right);
  kdr::Space::Mat4 result;

  result[0][0] = right.x;
  result[1][0] = right.y;
  result[2][0] = right.z;
  result[0][1] = newUp.x;
  result[1][1] = newUp.y;
  result[2][1] = newUp.z;
  result[0][2] = front.x;
  result[1][2] = front.y;
  result[2][2] = front.z;
  result[3][0] = -kdr::Space::dot(right, eye);
  result[3][1] = -kdr::Space::dot(newUp, eye);
  result[3][2] = -kdr::Space::dot(front, eye);
  result[3][3] = 1.f;

  return result;
}
