#include <iostream>

#include "libraries/glfw/include/GLFW/glfw3.h"
#include "wheels/glfw_application.hpp"

int main(int argument_count, char *arguments[]) {
  auto application = wheels::GlfwApplication();
  return application.Run();
}
