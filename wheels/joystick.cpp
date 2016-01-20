#include <map>
#include <string>

#include "wheels/joystick.hpp"

namespace wheels {

using std::map;
using std::string;

map<Joystick::Axis, string> Joystick::axis_names{
  BUILD_MAP_ENTRY(Joystick::Axis::kLeftX),
  BUILD_MAP_ENTRY(Joystick::Axis::kLeftY),
  BUILD_MAP_ENTRY(Joystick::Axis::kRightX),
  BUILD_MAP_ENTRY(Joystick::Axis::kRightY),
  BUILD_MAP_ENTRY(Joystick::Axis::kLeftTrigger),
  BUILD_MAP_ENTRY(Joystick::Axis::kRightTrigger),
};

map<Joystick::Button, string> Joystick::button_names{
  BUILD_MAP_ENTRY(Joystick::Button::kSquare),
  BUILD_MAP_ENTRY(Joystick::Button::kX),
  BUILD_MAP_ENTRY(Joystick::Button::kCircle),
  BUILD_MAP_ENTRY(Joystick::Button::kL1),
  BUILD_MAP_ENTRY(Joystick::Button::kR1),
  BUILD_MAP_ENTRY(Joystick::Button::kL2),
  BUILD_MAP_ENTRY(Joystick::Button::kR2),
  BUILD_MAP_ENTRY(Joystick::Button::kSelect),
  BUILD_MAP_ENTRY(Joystick::Button::kStart),
  BUILD_MAP_ENTRY(Joystick::Button::kL3),
  BUILD_MAP_ENTRY(Joystick::Button::kR3),
  BUILD_MAP_ENTRY(Joystick::Button::kPlayStation),
  BUILD_MAP_ENTRY(Joystick::Button::kClick),
  BUILD_MAP_ENTRY(Joystick::Button::kDpadUp),
  BUILD_MAP_ENTRY(Joystick::Button::kDpadRight),
  BUILD_MAP_ENTRY(Joystick::Button::kDpadDown),
  BUILD_MAP_ENTRY(Joystick::Button::kDpadLeft),
};

}  // namespace wheels
