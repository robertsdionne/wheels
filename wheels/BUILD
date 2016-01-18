
cc_binary(
  name = 'wheels',
  srcs = [
    'wheels.cpp',
  ],
  deps = [
    '//libraries/glfw/include/GLFW',
    '//libraries/glfw/src',
  ],
  linkopts = [
    '-framework Cocoa',
    '-framework OpenGL',
  ],
)
