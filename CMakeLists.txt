cmake_minimum_required(VERSION 3.21)
project(VoxelProject    VERSION 1.0
                        DESCRIPTION "Minecraft?")

set(CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# Don't create documentation or tests for GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

# Add GLFW to source tree
add_subdirectory(include/glfw)

# Add header files for GLAD
set(GLAD_HEADERS include/glad/glad.h include/KHR/khrplatform.h)

add_executable(VoxelProject
        ${GLAD_HEADERS}
        include/glad/glad.c
        src/main.cpp)

# Set include directory
target_include_directories(VoxelProject PRIVATE include)

# Link my project against GLFW
target_link_libraries(VoxelProject glfw)

