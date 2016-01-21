#ifndef WHEELS_BUFFERS_HPP_
#define WHEELS_BUFFERS_HPP_

#include <GLFW/glfw3.h>
#include <vector>

namespace wheels {

using std::vector;

template <typename F>
GLuint MakeArrayBuffer(GLenum usage, const vector<F> &data) {
  GLuint buffer;
  glGenBuffers(1, &buffer);
  glBindBuffer(GL_ARRAY_BUFFER, buffer);
  glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(F), data.data(), usage);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  return buffer;
}

GLuint MakeVertexArray(GLuint buffer) {
  GLuint vertex_array;
  glGenVertexArrays(1, &vertex_array);
  return vertex_array;
}

}  // namespace wheels

#endif  // WHEELS_BUFFERS_HPP_
