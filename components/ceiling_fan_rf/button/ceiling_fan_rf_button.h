#pragma once

#include "esphome/core/component.h"
#include "esphome/components/button/button.h"
#include "esphome/components/ceiling_fan_rf/ceiling_fan_rf.h"

namespace esphome {
namespace ceiling_fan_rf {

class CeilingFanRfButton : public button::Button, public Component {
 public:
  void set_parent(CeilingFanRf *parent) { parent_ = parent; }
  void set_button_code(uint8_t code) { button_code_ = code; }
  void dump_config() override;

 protected:
  void press_action() override;
  CeilingFanRf *parent_;
  uint8_t button_code_{0};
};

}  // namespace ceiling_fan_rf
}  // namespace esphome
