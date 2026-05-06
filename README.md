# esphome-bldc-ceil-fan

ESPHome external component for controlling BLDC ceiling fans via 433 MHz RF. Reverse-engineered from a generic 15-button ceiling fan remote.

## Install

Add to your ESPHome YAML:

```yaml
external_components:
  - source:
      type: git
      url: https://github.com/daniel-dona/esphome-bldc-ceil-fan
      ref: main
    components: [ceiling_fan_rf]
```

## Wiring

| ESP32 Pin | RF Transmitter |
|---|---|
| GPIO32 (or any GPIO) | DATA |
| 3.3V | VCC |
| GND | GND |

## Configuration

```yaml
remote_transmitter:
  - id: my_tx
    pin: GPIO32
    carrier_duty_percent: 100%

# Core component — holds the transmitter and rolling code state
ceiling_fan_rf:
  transmitter_id: my_tx
  fan_id: 0xBEC5  # 2-byte ID unique to your fan/receiver (first 2 bytes of RF packet)
```

### Fan Platform

Exposes the fan as a Home Assistant fan entity with 6 speeds, oscillation (breeze mode), and direction control.

```yaml
fan:
  - platform: ceiling_fan_rf
    name: "Ceiling Fan"
```

| Action | RF Button |
|---|---|
| Turn on (speed 1–6) | `0x0F`–`0x13` |
| Turn off | `0x09` |
| Direction forward | `0x1B` |
| Direction reverse | `0x0E` |
| Oscillation toggle (breeze) | `0x0A` |

### Select Platform

Timer select with 4 options.

```yaml
select:
  - platform: ceiling_fan_rf
    name: "Fan Timer"
```

| Option | RF Button |
|---|---|
| Off | *(no signal)* |
| 1 Hour | `0x1D` |
| 2 Hours | `0x16` |
| 4 Hours | `0x06` |

### Button Platform

Generic button — sends any RF button code. Use `button_code` to specify which.

```yaml
button:
  - platform: ceiling_fan_rf
    name: "Light Cycle"
    button_code: 0x17
  - platform: ceiling_fan_rf
    name: "All Off"
    button_code: 0x19
```

## Full Example

See [`esp_fan_example.yaml`](esp_fan_example.yaml).

## Protocol Details

See [`analysis/`](analysis/) for the complete RF protocol reverse-engineering documentation.
