cmake_minimum_required(VERSION 3.21)
project(Sparky)

set(CMAKE_CXX_STANDARD 23)

include_directories(${PROJECT_SOURCE_DIR}/Dependencies/GLFW/include)

include_directories(${PROJECT_SOURCE_DIR}/Dependencies/GLEW/include)

link_directories(${PROJECT_SOURCE_DIR}/Dependencies/GLFW/lib-universal)

link_directories(${PROJECT_SOURCE_DIR}/Dependencies/GLEW/lib)

add_executable(Sparky Sparky-core/main.cpp Sparky-core/src/graphics/window.cpp Sparky-core/src/graphics/window.h)

target_link_libraries(Sparky glfw3)

target_link_libraries(Sparky glew)

target_link_libraries(Sparky "-framework OpenGL")
target_link_libraries(Sparky "-framework Cocoa")
target_link_libraries(Sparky "-framework IOKit")
target_link_libraries(Sparky "-framework CoreVideo")

