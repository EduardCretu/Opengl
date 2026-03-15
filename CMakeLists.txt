cmake_minimum_required(VERSION 3.10)

project(MyGLFWProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(OpenGL REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW REQUIRED glfw3)

# Include GLFW headers
include_directories(${GLFW_INCLUDE_DIRS})

# Add the executable
add_executable(main main.cpp)

# Link libraries
target_link_libraries(main ${GLFW_LIBRARIES} ${OPENGL_LIBRARIES})
