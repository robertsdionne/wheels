#version 410

uniform vec3 translate;

in vec3 unnormalized_ray;

out vec4 color;

float DistanceFrom(vec3 position);
vec4 VectorToColor(vec3 vector);

const float kPi = 3.14159265358979323846264338327950288;
const float kEpsilon = 1e-3;
const vec3 kLightDirection = normalize(vec3(1., 1., 1.));

void main() {
  vec3 ray = normalize(unnormalized_ray);
  vec3 position = vec3(0.);

  lowp float hit = 0.;
  for (int i = 0; i < 128; ++i) {
    float distance = DistanceFrom(position);
    hit = float(distance < kEpsilon);
    position += distance * ray * (1. - hit);
  }

  vec3 dx = vec3(kEpsilon, 0., 0.);
  vec3 dy = vec3(0., kEpsilon, 0.);
  vec3 dz = vec3(0., 0., kEpsilon);

  vec3 normal = normalize(vec3(
      DistanceFrom(position + dx) - DistanceFrom(position - dx),
      DistanceFrom(position + dy) - DistanceFrom(position - dy),
      DistanceFrom(position + dz) - DistanceFrom(position - dz)));

  float intensity = clamp(dot(normal, kLightDirection), 0., 1.);

  vec4 ray_color = VectorToColor(ray);
  vec4 normal_color = VectorToColor(normal);

  color = mix(ray_color, vec4(intensity * normal_color.xyz, 1.), hit);
}

float DistanceFrom(vec3 position) {
  vec3 q = position + translate + vec3(0., 0., 10.);
  return length(q) - 1.;
}

vec4 VectorToColor(vec3 vector) {
  return vec4((normalize(vector) + vec3(1.)) / 2., 1.);
}
