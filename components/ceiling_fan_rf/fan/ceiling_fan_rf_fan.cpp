#include "esphome/components/ceiling_fan_rf/fan/ceiling_fan_rf_fan.h"
#include "esphome/core/log.h"

namespace esphome {
namespace ceiling_fan_rf {

static const char *const TAG = "ceiling_fan_rf.fan";

uint8_t CeilingFanRfFan::speed_to_btn(int speed) {
  switch (speed) {
    case 1: return 0x0f;
    case 2: return 0x0d;
    case 3: return 0x03;
    case 4: return 0x15;
    case 5: return 0x10;
    case 6: return 0x13;
    default: return 0x0f;
  }
}

fan::FanTraits CeilingFanRfFan::get_traits() { return fan::FanTraits(true, true, true, 6); }

void CeilingFanRfFan::control(const fan::FanCall &call) {
  if (call.get_state().has_value())
    this->state = *call.get_state();
  if (call.get_speed().has_value())
    this->speed = *call.get_speed();
  if (call.get_direction().has_value())
    this->direction = *call.get_direction();
  if (call.get_oscillating().has_value())
    this->oscillating = *call.get_oscillating();

  if (call.get_speed().has_value() && this->state) {
    this->parent_->send_button(speed_to_btn(this->speed));
  } else if (call.get_state().has_value()) {
    if (this->state) {
      if (this->speed == 0)
        this->speed = 1;
      this->parent_->send_button(speed_to_btn(this->speed));
    } else {
      this->parent_->send_button(0x09);
    }
  }

  if (call.get_direction().has_value()) {
    this->parent_->send_button(this->direction == fan::FanDirection::FORWARD ? 0x1b : 0x0e);
  }

  if (call.get_oscillating().has_value()) {
    this->parent_->send_button(0x0a);
  }

  this->publish_state();
}

void CeilingFanRfFan::dump_config() { LOG_FAN("", "Ceiling Fan RF Fan", this); }

}  // namespace ceiling_fan_rf
}  // namespace esphome
