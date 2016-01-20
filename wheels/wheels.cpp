#include "wheels/glfw_application.hpp"
#include "wheels/wheels_renderer.hpp"

int main(int argument_count, char *arguments[]) {
  return wheels::GlfwApplication(argument_count, arguments, wheels::WheelsRenderer()).Run();
}
