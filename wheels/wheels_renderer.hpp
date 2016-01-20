#ifndef WHEELS_WHEELS_RENDERER_HPP_
#define WHEELS_WHEELS_RENDERER_HPP_

#include "wheels/renderer.hpp"

namespace wheels {

class WheelsRenderer : public Renderer {
public:
  WheelsRenderer() = default;

  virtual ~WheelsRenderer() = default;

  virtual void Change(int width, int height) override {
    glViewport(0, 0, width, height);
  }

  virtual void Create() override {
    glClearColor(0., 0., 0., 0.);
  }

  virtual void Render() override {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  }
};

}  // namespace wheels

#endif  // WHEELS_WHEELS_RENDERER_HPP_
