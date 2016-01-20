#ifndef WHEELS_JOYSTICK_HPP_
#define WHEELS_JOYSTICK_HPP_

#include <GLFW/glfw3.h>
#include <cassert>
#include <chrono>
#include <glm/glm.hpp>
#include <map>
#include <string>

namespace wheels {

using std::map;
using std::string;

#define BUILD_MAP_ENTRY(value) {value, #value}

class Joystick {
public:
  Joystick(int joystick_id): joystick_id(joystick_id) {}

  virtual ~Joystick() = default;

  enum class Axis {
    kLeftX = 0,
    kLeftY = 1,
    kRightX = 2,
    kRightY = 3,
    kLeftTrigger = 4,
    kRightTrigger = 5,
  };
  static map<Axis, string> axis_names;

  enum class Button {
    kSquare = 0,
    kX = 1,
    kCircle = 2,
    kTriangle = 3,
    kL1 = 4,
    kR1 = 5,
    kL2 = 6,
    kR2 = 7,
    kSelect = 8,
    kStart = 9,
    kL3 = 10,
    kR3 = 11,
    kPlayStation = 12,
    kClick = 13,
    kDpadUp = 14,
    kDpadRight = 15,
    kDpadDown = 16,
    kDpadLeft = 17,
    kEnd,
    kBegin = kSquare,
  };
  static map<Button, string> button_names;

  static constexpr float kDeadZone = 0.1;

  float GetAxis(Axis axis) {
    return glm::abs(axes[axis]) > kDeadZone ? axes[axis] : 0.;
  }

  float GetAxisVelocity(Axis axis) {
    return (axes[axis] - previous_axes[axis]) * dt;
  }

  bool GetButton(Button button) {
    return buttons[button];
  }

  int GetButtonVelocity(Button button) {
    return buttons[button] - previous_buttons[button];
  }

  void Update() {
    previous_axes = axes;
    previous_buttons = buttons;
    if (glfwJoystickPresent(joystick_id)) {
      int axis_count = 0;
      const float *axis_data = glfwGetJoystickAxes(joystick_id, &axis_count);
      assert(axis_count && axis_data);
      for (auto i = 0; i < axis_count; ++i) {
        axes[static_cast<Axis>(i)] = axis_data[i];
      }
      int button_count = 0;
      const unsigned char *button_data = glfwGetJoystickButtons(joystick_id, &button_count);
      assert(button_count && button_data);
      for (auto i = static_cast<int>(Button::kBegin); i < static_cast<int>(Button::kEnd); ++i) {
        buttons[static_cast<Button>(i)] = button_data[i];
      }
      auto now = std::chrono::high_resolution_clock::now();
      dt = std::chrono::duration_cast<std::chrono::duration<float>>(now - last_update_time).count();
      last_update_time = now;
    }
  }

private:
  int joystick_id;
  map<Axis, float> axes, previous_axes;
  map<Button, bool> buttons, previous_buttons;
  std::chrono::high_resolution_clock::time_point last_update_time;
  float dt;
};

}  // namespace wheels

#endif  // WHEELS_JOYSTICK_HPP_
