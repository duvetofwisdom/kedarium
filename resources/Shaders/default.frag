#version 330 core

in vec3 vertCol;
in vec2 vertTex;

uniform sampler2D tex0;

out vec4 FragColor;

void main()
{
  float ambientFactor = 0.1f;
  float lightFactor = ambientFactor;

  FragColor = texture(tex0, vertTex) * lightFactor;
}
