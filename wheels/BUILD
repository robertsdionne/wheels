
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
  ],
)

cc_binary(
  name = 'wheels',
  srcs = [
    'wheels.cpp',
  ],
  deps = [
    ':glfw_application',
    '//libraries/glfw',
    '//libraries/glm',
  ],
  linkopts = [
    '-framework Cocoa',
    '-framework OpenGL',
  ],
)
