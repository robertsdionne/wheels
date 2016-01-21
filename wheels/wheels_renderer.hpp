#ifndef WHEELS_WHEELS_RENDERER_HPP_
#define WHEELS_WHEELS_RENDERER_HPP_

#include <GLFW/glfw3.h>
#include <vector>

#include "wheels/buffers.hpp"
#include "wheels/renderer.hpp"
#include "wheels/shaders.hpp"

namespace wheels {

using std::vector;

class WheelsRenderer : public Renderer {
public:
  WheelsRenderer() = default;

  virtual ~WheelsRenderer() = default;

  virtual void Change(int width, int height) override {
    glViewport(0, 0, width, height);
  }

  virtual void Create() override {
    glClearColor(0., 0., 0., 0.);

    program = LinkProgram(
        CompileShader(GL_VERTEX_SHADER, "wheels/vertex_shader.glsl"),
        CompileShader(GL_FRAGMENT_SHADER, "wheels/fragment_shader.glsl"));

    buffer = MakeArrayBuffer<float>(GL_STATIC_DRAW, {
      -1., -1., -1.,
      1., -1., -1.,
      -1., 1., -1.,
      1., 1., -1.,
    });
  }

  virtual void Render() override {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  }

private:
  GLuint buffer, program;
};

}  // namespace wheels

#endif  // WHEELS_WHEELS_RENDERER_HPP_
