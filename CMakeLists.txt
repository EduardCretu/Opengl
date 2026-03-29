cmake_minimum_required(VERSION 3.10)

project(MyGLFWProject)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find packages
find_package(OpenGL REQUIRED)
find_package(PkgConfig REQUIRED)
find_package(GLUT REQUIRED)

pkg_check_modules(GLFW REQUIRED glfw3)

# Include dirs
include_directories(
    ${GLFW_INCLUDE_DIRS}
    ${GLUT_INCLUDE_DIRS}
)

# Executable
add_executable(main main.cpp)

# Link libraries
target_link_libraries(main
    ${GLFW_LIBRARIES}
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARIES}
)
