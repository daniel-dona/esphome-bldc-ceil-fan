#include "esphome/components/ceiling_fan_rf/ceiling_fan_rf.h"
#include "esphome/core/log.h"

namespace esphome {
namespace ceiling_fan_rf {

static const char *const TAG = "ceiling_fan_rf";

void CeilingFanRf::send_button(uint8_t btn_id) {
  static const uint8_t BASE_SEQ[] = {0xe7, 0xc5, 0xa3, 0x81, 0x6f, 0x4d, 0x2b, 0x09};
  static const uint8_t XOR_CONST[] = {0x08, 0x19};
  static const int PULSE_HIGH = 250;
  static const int PULSE_LOW = 750;
  static const int GAP_HIGH = 0;
  static const int GAP_LOW = 8000;
  static const int REPEAT_COUNT = 6;

  uint8_t step = this->step_ & 0x07;
  uint8_t base = BASE_SEQ[step];
  uint8_t offset = XOR_CONST[btn_id & 1] ^ btn_id;
  uint8_t roll = base ^ offset;

  uint32_t first_packet = ((uint32_t) this->fan_id_ << 16) | ((uint32_t) btn_id << 8) | roll;
  uint64_t repeat_packet = ((uint64_t) first_packet & 0x7FFFFFFF) | 0x100000000;

  ESP_LOGD(TAG, "btn=0x%02X step=%d base=0x%02X roll=0x%02X", btn_id, step, base, roll);
  ESP_LOGD(TAG, "32-bit packet: 0x%08X", first_packet);
  ESP_LOGD(TAG, "33-bit repeat_packet: 0x%08X%08X", (uint32_t)(repeat_packet >> 32),
           (uint32_t)(repeat_packet & 0xFFFFFFFF));

  this->step_ = (this->step_ + 1) & 0x07;

  auto call = this->transmitter_->transmit();
  auto *d = call.get_data();

  for (int i = 31; i >= 0; i--) {
    if (first_packet & (1U << i))
      d->item(PULSE_HIGH, PULSE_LOW);
    else
      d->item(PULSE_LOW, PULSE_HIGH);
  }

  d->item(GAP_HIGH, GAP_LOW);

  for (int repeat = 0; repeat < REPEAT_COUNT; repeat++) {
    for (int i = 32; i >= 0; i--) {
      if (repeat_packet & (1ULL << i))
        d->item(PULSE_HIGH, PULSE_LOW);
      else
        d->item(PULSE_LOW, PULSE_HIGH);
    }
    if (repeat < REPEAT_COUNT - 1)
      d->item(GAP_HIGH, GAP_LOW);
  }

  call.perform();
}

void CeilingFanRf::dump_config() {
  ESP_LOGCONFIG(TAG, "CeilingFanRf:");
  ESP_LOGCONFIG(TAG, "  Fan ID: 0x%04X", this->fan_id_);
}

}  // namespace ceiling_fan_rf
}  // namespace esphome
