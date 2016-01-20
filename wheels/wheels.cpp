#include <GLFW/glfw3.h>
#include <cassert>
#include <iostream>

#include "wheels/glfw_application.hpp"

int main(int argument_count, char *arguments[]) {
  auto application = wheels::GlfwApplication();
  return application.Run();
}
