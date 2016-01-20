
cc_library(
  name = 'application',
  srcs = [
    'application.hpp',
  ],
)

cc_library(
  name = 'glfw_application',
  srcs = [
    'glfw_application.hpp',
  ],
  deps = [
    ':application',
    ':joystick',
    '//libraries/glfw',
  ],
)

cc_library(
  name = 'joystick',
  srcs = [
    'joystick.cpp',
    'joystick.hpp',
  ],
  deps = [
    '//libraries/glfw',
    '//libraries/glm',
  ],
)

cc_library(
  name = 'renderer',
  srcs = [
    'renderer.hpp',
  ],
)

cc_binary(
  name = 'wheels',
  srcs = [
    'wheels.cpp',
  ],
  deps = [
    ':glfw_application',
    ':wheels_renderer',
  ],
  linkopts = [
    '-framework Cocoa',
    '-framework OpenGL',
  ],
)

cc_library(
  name = 'wheels_renderer',
  srcs = [
    'wheels_renderer.hpp',
  ],
  deps = [
    ':renderer',
    '//libraries/glfw',
  ],
)
