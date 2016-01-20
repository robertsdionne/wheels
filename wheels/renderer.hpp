#ifndef WHEELS_RENDERER_HPP_
#define WHEELS_RENDERER_HPP_

namespace wheels {

class Renderer {
public:
  Renderer() = default;

  virtual ~Renderer() = default;

  virtual void Change(int width, int height) = 0;

  virtual void Create() = 0;

  virtual void Render() = 0;
};

}  // namespace wheels

#endif  // WHEELS_RENDERER_HPP_
