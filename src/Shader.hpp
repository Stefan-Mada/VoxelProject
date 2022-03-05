//
// Created by Stefan on 2/21/2022.
// The class wraps shader functionality in an easy to use object
//
#ifndef VOXELPROJECT_SHADER_HPP
#define VOXELPROJECT_SHADER_HPP

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>
#include <string>

class Shader
{
public:
    // state
    unsigned int ID;
    // constructor
    Shader() { }
    // compiles the shader from given source code
    void Compile(const char *vertexSource, const char *fragmentSource, const char *geometrySource = nullptr); // note: geometry source code is optional
    // constructor that compiles
    Shader (const char* vertexPath, const char* fragmentPath, const char *geometryPath = nullptr);
    // sets the current shader as active
    Shader  &Use();
    // utility functions
    void SetFloat    (const char *name, float value, bool useShader = false);
    void SetInt      (const char *name, int value, bool useShader = false);
    void SetVector2f (const char *name, float x, float y, bool useShader = false);
    void SetVector2f (const char *name, const glm::vec2 &value, bool useShader = false);
    void SetVector3f (const char *name, float x, float y, float z, bool useShader = false);
    void SetVector3f (const char *name, const glm::vec3 &value, bool useShader = false);
    void SetVector4f (const char *name, float x, float y, float z, float w, bool useShader = false);
    void SetVector4f (const char *name, const glm::vec4 &value, bool useShader = false);
    void SetMatrix4  (const char *name, const glm::mat4 &matrix, bool useShader = false);
private:
    // checks if compilation or linking failed and if so, print the error logs
    void    checkCompileErrors(unsigned int object, std::string type);
};




#endif //VOXELPROJECT_SHADER_HPP
