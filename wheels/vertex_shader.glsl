#version 410

in vec4 position;

out vec3 unnormalized_ray;

void main() {
  unnormalized_ray = position.xyz;
  gl_Position = position;
}
