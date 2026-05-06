#pragma once

#include "esphome/core/component.h"
#include "esphome/components/remote_base/remote_base.h"

namespace esphome {
namespace ceiling_fan_rf {

class CeilingFanRf : public Component {
 public:
  void set_transmitter(remote_base::RemoteTransmitterBase *transmitter) { transmitter_ = transmitter; }
  void set_fan_id(uint16_t fan_id) { fan_id_ = fan_id; }
  void send_button(uint8_t btn_id);
  void dump_config() override;

 protected:
  remote_base::RemoteTransmitterBase *transmitter_{nullptr};
  uint16_t fan_id_{0xBEC5};
  uint8_t step_{0};
};

}  // namespace ceiling_fan_rf
}  // namespace esphome
