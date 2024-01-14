#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aCol;

uniform mat4 cameraMatrix;

out vec3 vertCol;

void main()
{
  gl_Position = cameraMatrix * vec4(aPos, 1.f);
  vertCol = aCol;
}
