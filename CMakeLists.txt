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
set(GLAD_HEADERS include/glad/glad.h include/KHR/khrplatform.h include/glad/glad.c)

# Add headers for stb_image, for reading texture information
set(STB_IMAGE_HEADERS include/stb_image/stb_image.h include/stb_image/stb_image.cpp)

# Headers used by the project itself
set(VOXELPROJECT_HEADERS src/Shader.hpp src/main.cpp)

add_executable(VoxelProject
        ${GLAD_HEADERS}
        ${STB_IMAGE_HEADERS}
        ${VOXELPROJECT_HEADERS})

# Set include directory
target_include_directories(VoxelProject PRIVATE include)

# Link my project against GLFW
target_link_libraries(VoxelProject glfw)

# Command to copy shader files to build directory
add_custom_command(TARGET VoxelProject POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/src/shaders/ $<TARGET_FILE_DIR:VoxelProject>/shaders
        DEPENDS ${CMAKE_SOURCE_DIR}}/src/shaders/*)


