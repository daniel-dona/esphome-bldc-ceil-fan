#pragma once

#include "esphome/core/component.h"
#include "esphome/components/fan/fan.h"
#include "esphome/components/ceiling_fan_rf/ceiling_fan_rf.h"

namespace esphome {
namespace ceiling_fan_rf {

class CeilingFanRfFan : public fan::Fan, public Component {
 public:
  void set_parent(CeilingFanRf *parent) { parent_ = parent; }
  fan::FanTraits get_traits() override;
  void control(const fan::FanCall &call) override;
  void dump_config() override;

 protected:
  static uint8_t speed_to_btn(int speed);
  CeilingFanRf *parent_;
};

}  // namespace ceiling_fan_rf
}  // namespace esphome
