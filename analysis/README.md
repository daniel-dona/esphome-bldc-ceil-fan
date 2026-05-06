# RF Signal Captures

Signal captures from `rtl_433` used to reverse-engineer the ceiling fan's 433 MHz RF remote protocol.

## Capture Setup

```bash
rtl_433 -f 433.92M -s 1024k \
  -X "n=mydevice,m=OOK_PWM,s=250,l=750,r=1500,g=1000,t=500" \
  -M time:usec -M bits | grep codes
```

| Parameter | Value |
|---|---|
| Frequency | 433.92 MHz |
| Modulation | OOK_PWM |
| Short / Long pulse | 250 µs / 750 µs |
| Gap / Reset | 1000 µs / 1500 µs |

## Captures

| # | File | Buttons | Presses | Unique codes | What it proved |
|---|---|---|---|---|---|
| 1 | [capture-1-four-buttons.md](capture-1-four-buttons.md) | 4 | 16 each (64 total) | 32 | Base sequence, XOR offset formula |
| 2 | [capture-2-all-buttons.md](capture-2-all-buttons.md) | 15 | 2 each (30 total) | 30 | Shared global counter, parity-based XOR, all button IDs |
| 3 | [capture-3-cycle-verification.md](capture-3-cycle-verification.md) | 1 | 16 (2 cycles) | 8 | Rolling sequence wraps cleanly after 8 steps |

**Total: 78 codes, 70 unique**

## Protocol Reference

See [protocol.md](protocol.md) for the complete specification.
