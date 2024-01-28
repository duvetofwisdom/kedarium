#include "Kedarium/Graphics.hpp"

kdr::Graphics::Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath)
{
   // Shader Sources
  const std::string vertexShaderSource = kdr::File::getContents(vertexPath);
  const std::string fragmentShaderSource = kdr::File::getContents(fragmentPath);

  // Shader Sources (C)
  const char* vertexShaderSourceC = vertexShaderSource.c_str();
  const char* fragmentShaderSourceC = fragmentShaderSource.c_str();

  // Shaders
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

  glShaderSource(vertexShader, 1, &vertexShaderSourceC, NULL);
  glShaderSource(fragmentShader, 1, &fragmentShaderSourceC, NULL);

  glCompileShader(vertexShader);
  glCompileShader(fragmentShader);

  // Info Log
  int success {0};
  char infoLog[512];

  // Validating the Vertex Shader
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    std::cerr << "Failed to compile the vertex shader!\n";
    std::cerr << "Error: " << infoLog << '\n';
  }

  // Validating the Fragment Shader
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    std::cerr << "Failed to compile the fragment shader!\n";
    std::cerr << "Error: " << infoLog << '\n';
  }

  // Shader Program
  this->ID = glCreateProgram();
  glAttachShader(this->ID, vertexShader);
  glAttachShader(this->ID, fragmentShader);
  glLinkProgram(this->ID);

  // Validating the Shader Program
  glGetProgramiv(this->ID, GL_LINK_STATUS, &success);
  if (!success)
  {
    glGetProgramInfoLog(this->ID, 512, NULL, infoLog);
    std::cerr << "Failed to link the shader program!\n";
    std::cerr << "Error: " << infoLog << '\n';
  }

  // Deleting the Shaders
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
}

kdr::Graphics::VBO::VBO(GLfloat vertices[], GLsizeiptr size)
{
  glGenBuffers(1, &this->ID);
  glBindBuffer(GL_ARRAY_BUFFER, this->ID);
  glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

kdr::Graphics::EBO::EBO(GLuint indices[], GLsizeiptr size)
{
  glGenBuffers(1, &this->ID);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ID);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void kdr::Graphics::VAO::LinkAttrib(const kdr::Graphics::VBO& VBO, GLuint layout, GLuint size, GLenum type, GLsizeiptr stride, const void* offset) const
{
  VBO.Bind();
  glVertexAttribPointer(layout, size, type, GL_FALSE, stride, offset);
  glEnableVertexAttribArray(layout);
  VBO.Unbind();
}

kdr::Graphics::Texture::Texture(const std::string& pngPath, GLenum type, GLenum slot, GLenum pixelType) : type(type)
{
  int imgWidth {0};
  int imgHeight {0};
  bool hasAlpha {false};
  GLubyte* imageData {NULL};
  kdr::Image::loadFromPng(pngPath, &imageData, imgWidth, imgHeight, hasAlpha);

  if (!imageData)
  {
    return;
  }

  glGenTextures(1, &this->ID);
  glActiveTexture(slot);
  glBindTexture(this->type, this->ID);

  glTexParameteri(this->type, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(this->type, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  glTexImage2D(
    this->type,
    0,
    GL_RGBA,
    imgWidth,
    imgHeight,
    0,
    hasAlpha ? GL_RGBA : GL_RGB,
    pixelType,
    imageData
  );
  glGenerateMipmap(this->type);

  glBindTexture(this->type, 0); 
  delete imageData;
}
