#include "esphome/components/ceiling_fan_rf/select/ceiling_fan_rf_select.h"
#include "esphome/core/log.h"

namespace esphome {
namespace ceiling_fan_rf {

static const char *const TAG = "ceiling_fan_rf.select";

void CeilingFanRfSelect::control(const std::string &value) {
  if (value == "1 Hour") {
    this->parent_->send_button(0x1d);
  } else if (value == "2 Hours") {
    this->parent_->send_button(0x16);
  } else if (value == "4 Hours") {
    this->parent_->send_button(0x06);
  }
  this->publish_state(value);
}

void CeilingFanRfSelect::dump_config() { LOG_SELECT("", "Ceiling Fan RF Timer", this); }

}  // namespace ceiling_fan_rf
}  // namespace esphome
