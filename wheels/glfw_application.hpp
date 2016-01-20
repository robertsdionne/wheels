#ifndef WHEELS_GLFW_APPLICATION_HPP_
#define WHEELS_GLFW_APPLICATION_HPP_

#include <cassert>
#include <iostream>

#include "libraries/glfw/include/GLFW/glfw3.h"
#include "wheels/application.hpp"

namespace wheels {

class GlfwApplication : public Application {
public:
  GlfwApplication() = default;

  virtual ~GlfwApplication() = default;

  static constexpr int kWidth = 1024, kHeight = 768;

  static constexpr const char *kTitle = u8"wheels";

  virtual int Run() override {
    assert(glfwInit());
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(kWidth, kHeight, kTitle, nullptr, nullptr);
    assert(window);

    glfwMakeContextCurrent(window);

    std::cout << glGetString(GL_VERSION) << std::endl;

    glClearColor(0., 0., 0., 0.);

    while (!glfwWindowShouldClose(window)) {
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

      glfwSwapBuffers(window);
      glfwPollEvents();
    }

    glfwTerminate();
    return 0;
  }

  GLFWwindow *window;
};

}  // namespace wheels

#endif  // WHEELS_GLFW_APPLICATION_HPP_
