#ifndef WHEELS_GLFW_JOYSTICK_HPP_
#define WHEELS_GLFW_JOYSTICK_HPP_

#include <GLFW/glfw3.h>
#include <cassert>
#include <chrono>
#include <glm/glm.hpp>
#include <map>
#include <string>

#include "wheels/joystick.hpp"

namespace wheels {

using std::map;
using std::string;

class GlfwJoystick : public Joystick {
public:
  GlfwJoystick(int joystick_id=GLFW_JOYSTICK_1): joystick_id(joystick_id) {}

  virtual ~GlfwJoystick() = default;

  static constexpr float kDeadZone = 0.1;

  virtual float GetAxis(Axis axis) override {
    return glm::abs(axes[axis]) > kDeadZone ? axes[axis] : 0.;
  }

  virtual float GetAxisVelocity(Axis axis) override {
    return (axes[axis] - previous_axes[axis]) * dt;
  }

  virtual bool GetButton(Button button) override {
    return buttons[button];
  }

  virtual int GetButtonVelocity(Button button) override {
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

#endif  // WHEELS_GLFW_JOYSTICK_HPP_
