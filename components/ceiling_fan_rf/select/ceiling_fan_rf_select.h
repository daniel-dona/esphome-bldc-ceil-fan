#pragma once

#include "esphome/core/component.h"
#include "esphome/components/select/select.h"
#include "esphome/components/ceiling_fan_rf/ceiling_fan_rf.h"

namespace esphome {
namespace ceiling_fan_rf {

class CeilingFanRfSelect : public select::Select, public Component {
 public:
  void set_parent(CeilingFanRf *parent) { parent_ = parent; }
  void control(const std::string &value) override;
  void dump_config() override;

 protected:
  CeilingFanRf *parent_;
};

}  // namespace ceiling_fan_rf
}  // namespace esphome
