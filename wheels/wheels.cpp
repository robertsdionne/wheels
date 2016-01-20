#include "wheels/glfw_application.hpp"

int main(int argument_count, char *arguments[]) {
  return wheels::GlfwApplication(argument_count, arguments).Run();
}
