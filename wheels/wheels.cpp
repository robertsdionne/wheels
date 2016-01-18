#include <iostream>

#include "libraries/glfw/include/GLFW/glfw3.h"
#include "libraries/glm/glm/glm.hpp"
#include "libraries/glm/glm/gtx/io.hpp"

int main(int argument_count, char *arguments[]) {
  if (!glfwInit()) {
    return -1;
  }
  glm::vec3 v;

  std::cout << v << std::endl;

  return 0;
}
