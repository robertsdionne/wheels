#ifndef WHEELS_JOYSTICK_HPP_
#define WHEELS_JOYSTICK_HPP_

#include <map>
#include <string>

namespace wheels {

using std::map;
using std::string;

#define BUILD_MAP_ENTRY(value) {value, #value}

class Joystick {
public:
  Joystick() = default;

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

  virtual float GetAxis(Axis axis) = 0;

  virtual float GetAxisVelocity(Axis axis) = 0;

  virtual bool GetButton(Button button) = 0;

  virtual int GetButtonVelocity(Button button) = 0;
};

}  // namespace wheels

#endif  // WHEELS_JOYSTICK_HPP_
