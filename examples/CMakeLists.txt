# Executable
add_executable(
  example
  Main.cpp
)

# Include Directory
target_include_directories(Kedarium PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Libraries
target_link_libraries(example PRIVATE Kedarium GLEW glfw png)
if (APPLE)
  target_link_libraries(example PRIVATE "-framework OpenGL")
else()
  target_link_libraries(example PRIVATE GL)
endif()
