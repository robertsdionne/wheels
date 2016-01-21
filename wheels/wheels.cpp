#include "wheels/glfw_application.hpp"
#include "wheels/glfw_joystick.hpp"
#include "wheels/wheels_renderer.hpp"

int main(int argument_count, char *arguments[]) {
  auto joystick = wheels::GlfwJoystick();
  auto renderer = wheels::WheelsRenderer(joystick);
  return wheels::GlfwApplication(argument_count, arguments, renderer, joystick).Run();
}
