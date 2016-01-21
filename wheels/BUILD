
cc_library(
  name = 'application',
  srcs = [
    'application.hpp',
  ],
)

cc_library(
  name = 'buffers',
  srcs = [
    'buffers.hpp',
  ],
  deps = [
    '//libraries/glfw',
  ],
)

cc_library(
  name = 'files',
  srcs = [
    'files.hpp',
  ],
)

cc_library(
  name = 'glfw_application',
  srcs = [
    'glfw_application.hpp',
  ],
  deps = [
    ':application',
    ':glfw_joystick',
    '//libraries/glfw',
  ],
)

cc_library(
  name = 'glfw_joystick',
  srcs = [
    'glfw_joystick.hpp',
  ],
  deps = [
    ':joystick',
    '//libraries/glfw',
    '//libraries/glm',
  ],
)

cc_library(
  name = 'joystick',
  srcs = [
    'joystick.cpp',
    'joystick.hpp',
  ],
)

cc_library(
  name = 'renderer',
  srcs = [
    'renderer.hpp',
  ],
)

cc_library(
  name = 'shaders',
  srcs = [
    'shaders.hpp',
  ],
  deps = [
    ':files',
    '//libraries/glfw',
  ],
)

cc_binary(
  name = 'wheels',
  srcs = [
    'wheels.cpp',
  ],
  deps = [
    ':glfw_application',
    ':glfw_joystick',
    ':wheels_renderer',
  ],
  defines = [
    'GLFW_INCLUDE_GLCOREARB=1',
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
    ':buffers',
    ':joystick',
    ':renderer',
    ':shaders',
    '//libraries/glfw',
  ],
  data = [
    'fragment_shader.glsl',
    'vertex_shader.glsl',
  ],
)
