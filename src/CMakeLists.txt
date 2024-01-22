# Library
add_library(
  Kedarium
  Core.cpp
  File.cpp
  Image.cpp
  Space.cpp
  Graphics.cpp
  Window.cpp
  Camera.cpp
  Solids.cpp
)

# Include Directory
target_include_directories(Kedarium PUBLIC ${CMAKE_SOURCE_DIR}/include)
