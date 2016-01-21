#ifndef WHEELS_WHEELS_RENDERER_HPP_
#define WHEELS_WHEELS_RENDERER_HPP_

#include <GLFW/glfw3.h>
#include <vector>

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

    auto vertex_shader = CompileShader(GL_VERTEX_SHADER, "wheels/vertex_shader.glsl");
    auto fragment_shader = CompileShader(GL_FRAGMENT_SHADER, "wheels/fragment_shader.glsl");
    program = LinkProgram(vertex_shader, fragment_shader);

    auto quad = vector<float>{
      -1., -1., -1.,
      1., -1., -1.,
      -1., 1., -1.,
      1., 1., -1.,
    };
  }

  virtual void Render() override {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  }

private:
  GLuint buffer, program;
};

}  // namespace wheels

#endif  // WHEELS_WHEELS_RENDERER_HPP_
