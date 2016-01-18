#ifndef WHEELS_APPLICATION_HPP_
#define WHEELS_APPLICATION_HPP_

namespace wheels {

class Application {
public:
  Application() = default;

  virtual ~Application() = default;

  virtual int Run() = 0;
};

}  // namespace wheels

#endif  // WHEELS_APPLICATION_HPP_
