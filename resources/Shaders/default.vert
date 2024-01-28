#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aCol;
layout (location = 2) in vec2 aTex;
layout (location = 3) in vec3 aNorm;

uniform mat4 cameraMatrix;
uniform mat4 model;

out vec3 vertPos;
out vec3 vertCol;
out vec2 vertTex;
out vec3 vertNorm;

void main()
{
  gl_Position = cameraMatrix * model * vec4(aPos, 1.f);
  vertPos = aPos;
  vertCol = aCol;
  vertTex = aTex;
  vertNorm = aNorm;
}
