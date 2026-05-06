# RF Protocol Specification

## Physical Layer

| Parameter | Value |
|---|---|
| Frequency | 433.92 MHz |
| Modulation | OOK (On-Off Keying) |
| Encoding | PWM |
| Bit 1 | 250 µs high / 750 µs low |
| Bit 0 | 750 µs high / 250 µs low |
| Inter-message gap | 8000 µs |

## Transmission Format

Each button press sends **1 header + 6 repeats**:

```
[32-bit header] gap [33-bit repeat] gap ... [33-bit repeat]  (6× repeats)
```

## 32-bit Code Structure

```
 31       16 15      8 7        0
┌──────────┬──────────┬──────────┐
│ Constant │ Button ID│ Rolling  │
│  0xBEC5  │  8 bits  │  8 bits  │
└──────────┴──────────┴──────────┘
```

## 33-bit Repeat Code

Bit 32 = 1 (sync), bit 31 = 0, bits 30–0 = lower 31 bits of the 32-bit code.

rtl_433 appends 3 padding bits, so `{33}` output = `(payload << 3) | 0x800000000`.

## Rolling Code Algorithm

```python
BASE_SEQ = [0xE7, 0xC5, 0xA3, 0x81, 0x6F, 0x4D, 0x2B, 0x09]
XOR_CONST = [0x08, 0x19]  # [even, odd]

global_step = 0  # shared across ALL buttons

def make_code(btn_id):
    base = BASE_SEQ[global_step % 8]
    offset = XOR_CONST[btn_id & 1] ^ btn_id
    rolling = base ^ offset
    global_step = (global_step + 1) % 8
    return 0xBEC50000 | (btn_id << 8) | rolling
```

### Reverse: extract step from a captured code

```python
def extract_step(code_32):
    btn_id = (code_32 >> 8) & 0xFF
    rolling = code_32 & 0xFF
    offset = XOR_CONST[btn_id & 1] ^ btn_id
    base = rolling ^ offset
    return BASE_SEQ.index(base)
```

## Button Map

| Button ID | Parity | Offset | Function |
|---|---|---|---|
| `0x19` | odd | `0x00` | All Off |
| `0x0F` | odd | `0x16` | Fan Speed 1 / Fan On |
| `0x0D` | odd | `0x14` | Fan Speed 2 |
| `0x03` | odd | `0x1A` | Fan Speed 3 |
| `0x15` | odd | `0x0C` | Fan Speed 4 |
| `0x10` | even | `0x18` | Fan Speed 5 |
| `0x13` | odd | `0x0A` | Fan Speed 6 |
| `0x09` | odd | `0x10` | Fan Off |
| `0x1B` | odd | `0x02` | Direction (Forward) |
| `0x0E` | even | `0x06` | Direction (Reverse) |
| `0x0A` | even | `0x02` | Breeze / Wind Mode |
| `0x17` | odd | `0x0E` | Light Cycle |
| `0x1D` | odd | `0x04` | Timer 1 Hour |
| `0x16` | even | `0x1E` | Timer 2 Hours |
| `0x06` | even | `0x0E` | Timer 4 Hours |

## Base Sequence

The byte is two independent nibble counters, each stepping by −2 (mod 16) with no cross-nibble carry:

```
Index  Base   High nibble   Low nibble
  0    0xE7   E → C         7 → 5
  1    0xC5   C → A         5 → 3
  2    0xA3   A → 8         3 → 1
  3    0x81   8 → 6         1 → F  (wraps: 1−2 = −1 → 15)
  4    0x6F   6 → 4         F → D
  5    0x4D   4 → 2         D → B
  6    0x2B   2 → 0         B → 9
  7    0x09   0 → E  (wraps) 9 → 7  (wraps)
```

Equivalently, the whole byte decreases by `0x22` each step — but the low nibble wraps at 0 without borrowing from the high nibble. Compare:

```
Normal 8-bit: 0x81 − 0x22 = 0x5F  (borrow propagates across nibble boundary)
Observed:     0x81 − 0x22 = 0x6F  (no borrow; each nibble wraps independently)
```

| Index | Base | Binary |
|---|---|---|
| 0 | `0xE7` | `1110 0111` |
| 1 | `0xC5` | `1100 0101` |
| 2 | `0xA3` | `1010 0011` |
| 3 | `0x81` | `1000 0001` |
| 4 | `0x6F` | `0110 1111` |
| 5 | `0x4D` | `0100 1101` |
| 6 | `0x2B` | `0010 1011` |
| 7 | `0x09` | `0000 1001` |

## Security

No cryptographic security — only 8 rolling states (3 bits of entropy), fully deterministic and predictable from a single observed code.
