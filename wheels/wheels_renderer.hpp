#ifndef WHEELS_WHEELS_RENDERER_HPP_
#define WHEELS_WHEELS_RENDERER_HPP_

#include <GLFW/glfw3.h>
#include <vector>

#include "wheels/buffers.hpp"
#include "wheels/joystick.hpp"
#include "wheels/renderer.hpp"
#include "wheels/shaders.hpp"

namespace wheels {

using std::vector;

class WheelsRenderer : public Renderer {
public:
  WheelsRenderer(Joystick &joystick): joystick(joystick) {}

  virtual ~WheelsRenderer() = default;

  virtual void Change(int width, int height) override {
    glViewport(0, 0, width, height);
  }

  virtual void Create() override {
    glClearColor(0., 0., 0., 0.);

    program = LinkProgram(
        CompileShader(GL_VERTEX_SHADER, "wheels/vertex_shader.glsl"),
        CompileShader(GL_FRAGMENT_SHADER, "wheels/fragment_shader.glsl"));

    translate_location = glGetUniformLocation(program, "translate");

    buffer = MakeArrayBuffer<float>(GL_STATIC_DRAW, {
      -1., -1., -1.,
      1., -1., -1.,
      -1., 1., -1.,
      1., 1., -1.,
    });

    vertex_array = MakeVertexArray(buffer);
  }

  virtual void Render() override {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram(program);
    glUniform3f(translate_location, x, y, z);
    glBindVertexArray(vertex_array);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    glDisableVertexAttribArray(0);

    x -= joystick.GetAxis(Joystick::Axis::kLeftX);
    y += joystick.GetAxis(Joystick::Axis::kLeftY);
    z -= joystick.GetAxis(Joystick::Axis::kRightY);
  }

private:
  Joystick &joystick;
  GLuint buffer, program, vertex_array, translate_location;
  float x, y, z;
};

}  // namespace wheels

#endif  // WHEELS_WHEELS_RENDERER_HPP_
