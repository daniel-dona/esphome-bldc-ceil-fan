#include "esphome/components/ceiling_fan_rf/button/ceiling_fan_rf_button.h"
#include "esphome/core/log.h"

namespace esphome {
namespace ceiling_fan_rf {

static const char *const TAG = "ceiling_fan_rf.button";

void CeilingFanRfButton::press_action() { this->parent_->send_button(this->button_code_); }

void CeilingFanRfButton::dump_config() {
  ESP_LOGCONFIG(TAG, "Ceiling Fan RF Button:");
  LOG_BUTTON("", "Ceiling Fan RF Button", this);
  ESP_LOGCONFIG(TAG, "  Button Code: 0x%02X", this->button_code_);
}

}  // namespace ceiling_fan_rf
}  // namespace esphome
