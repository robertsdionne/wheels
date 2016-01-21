#ifndef WHEELS_SHADERS_HPP_
#define WHEELS_SHADERS_HPP_

#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

#include "wheels/file.hpp"

namespace wheels {

using std::cerr;
using std::endl;
using std::string;

static constexpr size_t kInfoLogSize = 4096;

GLuint CompileShader(GLenum shader_type, const string &shader_source_filename) {
  auto shader_source = ReadFile(shader_source_filename).c_str();
  auto shader = glCreateShader(shader_type);
  glShaderSource(shader, 1, &shader_source, nullptr);
  glCompileShader(shader);
  GLint shader_compile_status = GL_FALSE;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &shader_compile_status);
  if (!shader_compile_status) {
    GLchar info_log[kInfoLogSize];
    glGetShaderInfoLog(shader, kInfoLogSize, nullptr, info_log);
    cerr << info_log << endl;
  }
  assert(GL_TRUE == shader_compile_status);
  return shader;
}

GLuint LinkProgram(GLuint vertex_shader, GLuint fragment_shader) {
  auto program = glCreateProgram();
  glAttachShader(program, vertex_shader);
  glAttachShader(program, fragment_shader);
  glLinkProgram(program);
  GLint program_link_status = GL_FALSE;
  glGetProgramiv(program, GL_LINK_STATUS, &program_link_status);
  if (!program_link_status) {
    GLchar info_log[kInfoLogSize];
    glGetProgramInfoLog(program, kInfoLogSize, nullptr, info_log);
    cerr << info_log << endl;
  }
  glDetachShader(program, vertex_shader);
  glDeleteShader(vertex_shader);
  glDetachShader(program, fragment_shader);
  glDeleteShader(fragment_shader);
  assert(GL_TRUE == program_link_status);
  return program;
}

}  // namespace shaders

#endif  // WHEELS_SHADERS_HPP_
