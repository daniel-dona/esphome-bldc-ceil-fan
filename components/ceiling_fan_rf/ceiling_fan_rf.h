#pragma once

#include "esphome/core/component.h"
#include "esphome/components/remote_base/remote_base.h"

namespace esphome {
namespace ceiling_fan_rf {

class CeilingFanRf : public Component {
 public:
  void set_transmitter(remote_base::RemoteTransmitterBase *transmitter) { transmitter_ = transmitter; }
  void send_button(uint8_t btn_id);
  void dump_config() override;

 protected:
  remote_base::RemoteTransmitterBase *transmitter_{nullptr};
  uint8_t step_{0};
};

}  // namespace ceiling_fan_rf
}  // namespace esphome
