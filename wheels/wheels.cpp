#include <iostream>

#include "libraries/glfw/include/GLFW/glfw3.h"

int main(int argument_count, char *arguments[]) {
  if (!glfwInit()) {
    return -1;
  }
  return 0;
}
