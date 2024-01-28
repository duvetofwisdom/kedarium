#version 330 core

in vec3 vertPos;
in vec3 vertCol;
in vec2 vertTex;
in vec3 vertNorm;

uniform vec3 lightPos;
uniform vec4 lightColor;
uniform sampler2D tex0;

out vec4 FragColor;

void main()
{
  vec3 normal = normalize(vertNorm);
  vec3 lightDir = normalize(lightPos - vertPos);

  float ambientFactor = 0.1f;
  float diffuseFactor = max(dot(normal, lightDir), 0.f);
  float lightFactor = (ambientFactor + diffuseFactor);

  FragColor = texture(tex0, vertTex) * lightColor * lightFactor;
}
