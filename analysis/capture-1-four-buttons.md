# Capture 1: Four Buttons × 16 Presses each
## Overview

Four buttons were captured, each pressed 16 times consecutively to verify there were only 8 steps/states.

## Raw rtl_433 Output Format

Each button press appears as 7 lines in the rtl_433 output:
```
codes     : {32}bec5194d        ← primary code (unique per press)
codes     : {33}9f628ca68       ← repeat #1
codes     : {33}9f628ca68       ← repeat #2
codes     : {33}9f628ca68       ← repeat #3
codes     : {33}9f628ca68       ← repeat #4
codes     : {33}9f628ca68       ← repeat #5
codes     : {33}9f628ca68       ← repeat #6
```

The 6 `{33}` repeats are always identical — they carry the same payload but always setting the bit 33 to 1 and the bit 32 to 0. Only the `{32}` code changes between presses.

## Decoded Codes

### Button 1 — ID `0x19` (odd)

All 4 buttons in this capture are odd. Button `0x19` has offset `0x00` (since `0x19 ^ 0x19 = 0x00`), meaning the rolling byte equals the base value directly.

| Press | Step | 32-bit Code | Base | Offset | Rolling (`base ^ offset`) | Binary (lower 16 bits) | Cycle |
|---|---|---|---|---|---|---|---|
| 1 | 5 | `0xBEC5194D` | `0x4D` | `0x00` | `0x4D` | `0001 1001 0100 1101` | 1 |
| 2 | 6 | `0xBEC5192B` | `0x2B` | `0x00` | `0x2B` | `0001 1001 0010 1011` | 1 |
| 3 | 7 | `0xBEC51909` | `0x09` | `0x00` | `0x09` | `0001 1001 0000 1001` | 1 |
| 4 | 0 | `0xBEC519E7` | `0xE7` | `0x00` | `0xE7` | `0001 1001 1110 0111` | 1 |
| 5 | 1 | `0xBEC519C5` | `0xC5` | `0x00` | `0xC5` | `0001 1001 1100 0101` | 1 |
| 6 | 2 | `0xBEC519A3` | `0xA3` | `0x00` | `0xA3` | `0001 1001 1010 0011` | 1 |
| 7 | 3 | `0xBEC51981` | `0x81` | `0x00` | `0x81` | `0001 1001 1000 0001` | 1 |
| 8 | 4 | `0xBEC5196F` | `0x6F` | `0x00` | `0x6F` | `0001 1001 0110 1111` | 1 |
| 9 | 5 | `0xBEC5194D` | `0x4D` | `0x00` | `0x4D` | `0001 1001 0100 1101` | 2 |
| 10 | 6 | `0xBEC5192B` | `0x2B` | `0x00` | `0x2B` | `0001 1001 0010 1011` | 2 |
| 11 | 7 | `0xBEC51909` | `0x09` | `0x00` | `0x09` | `0001 1001 0000 1001` | 2 |
| 12 | 0 | `0xBEC519E7` | `0xE7` | `0x00` | `0xE7` | `0001 1001 1110 0111` | 2 |
| 13 | 1 | `0xBEC519C5` | `0xC5` | `0x00` | `0xC5` | `0001 1001 1100 0101` | 2 |
| 14 | 2 | `0xBEC519A3` | `0xA3` | `0x00` | `0xA3` | `0001 1001 1010 0011` | 2 |
| 15 | 3 | `0xBEC51981` | `0x81` | `0x00` | `0x81` | `0001 1001 1000 0001` | 2 |
| 16 | 4 | `0xBEC5196F` | `0x6F` | `0x00` | `0x6F` | `0001 1001 0110 1111` | 2 |

> Counter was at index **5** when this capture started. Each button's 16 presses consume exactly 2 full cycles.

### Button 2 — ID `0x17` (odd)

Offset: `0x17 ^ 0x19 = 0x0E`

| Press | Step | 32-bit Code | Base | Offset | Rolling |
|---|---|---|---|---|---|
| 1 | 5 | `0xBEC51743` | `0x4D` | `0x0E` | `0x43` |
| 2 | 6 | `0xBEC51725` | `0x2B` | `0x0E` | `0x25` |
| 3 | 7 | `0xBEC51707` | `0x09` | `0x0E` | `0x07` |
| 4 | 0 | `0xBEC517E9` | `0xE7` | `0x0E` | `0xE9` |
| 5 | 1 | `0xBEC517CB` | `0xC5` | `0x0E` | `0xCB` |
| 6 | 2 | `0xBEC517AD` | `0xA3` | `0x0E` | `0xAD` |
| 7 | 3 | `0xBEC5178F` | `0x81` | `0x0E` | `0x8F` |
| 8 | 4 | `0xBEC51761` | `0x6F` | `0x0E` | `0x61` |
| 9–16 | 5→4 | *(identical to presses 1–8)* | | | |

### Button 3 — ID `0x0F` (odd)

Offset: `0x0F ^ 0x19 = 0x16`

| Press | Step | 32-bit Code | Base | Offset | Rolling |
|---|---|---|---|---|---|
| 1 | 5 | `0xBEC50F5B` | `0x4D` | `0x16` | `0x5B` |
| 2 | 6 | `0xBEC50F3D` | `0x2B` | `0x16` | `0x3D` |
| 3 | 7 | `0xBEC50F1F` | `0x09` | `0x16` | `0x1F` |
| 4 | 0 | `0xBEC50FF1` | `0xE7` | `0x16` | `0xF1` |
| 5 | 1 | `0xBEC50FD3` | `0xC5` | `0x16` | `0xD3` |
| 6 | 2 | `0xBEC50FB5` | `0xA3` | `0x16` | `0xB5` |
| 7 | 3 | `0xBEC50F97` | `0x81` | `0x16` | `0x97` |
| 8 | 4 | `0xBEC50F79` | `0x6F` | `0x16` | `0x79` |
| 9–16 | 5→4 | *(identical to presses 1–8)* | | | |

### Button 4 — ID `0x0D` (odd)

Offset: `0x0D ^ 0x19 = 0x14`

| Press | Step | 32-bit Code | Base | Offset | Rolling |
|---|---|---|---|---|---|
| 1 | 5 | `0xBEC50D59` | `0x4D` | `0x14` | `0x59` |
| 2 | 6 | `0xBEC50D3F` | `0x2B` | `0x14` | `0x3F` |
| 3 | 7 | `0xBEC50D1D` | `0x09` | `0x14` | `0x1D` |
| 4 | 0 | `0xBEC50DF3` | `0xE7` | `0x14` | `0xF3` |
| 5 | 1 | `0xBEC50DD1` | `0xC5` | `0x14` | `0xD1` |
| 6 | 2 | `0xBEC50DB7` | `0xA3` | `0x14` | `0xB7` |
| 7 | 3 | `0xBEC50D95` | `0x81` | `0x14` | `0x95` |
| 8 | 4 | `0xBEC50D7B` | `0x6F` | `0x14` | `0x7B` |
| 9–16 | 5→4 | *(identical to presses 1–8)* | | | |
