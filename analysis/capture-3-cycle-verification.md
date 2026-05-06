# Capture 3: Single Button × 16 Presses (Cycle Verification)

## Overview

Button ID `0x16` (even, offset `0x1E`) pressed 16 times to verify the rolling sequence wraps after 8 steps. Only **8 unique codes** appear — the second cycle is identical to the first.

Counter was at index **3** when capture started.

## Decoded Codes

| Press | Step | 32-bit Code | Base | Rolling (`base ^ 0x1E`) | Cycle |
|---|---|---|---|---|---|
| 1 | 3 | `0xBEC5169F` | `0x81` | `0x9F` | 1 |
| 2 | 4 | `0xBEC51671` | `0x6F` | `0x71` | 1 |
| 3 | 5 | `0xBEC51653` | `0x4D` | `0x53` | 1 |
| 4 | 6 | `0xBEC51635` | `0x2B` | `0x35` | 1 |
| 5 | 7 | `0xBEC51617` | `0x09` | `0x17` | 1 |
| 6 | 0 | `0xBEC516F9` | `0xE7` | `0xF9` | 1 |
| 7 | 1 | `0xBEC516DB` | `0xC5` | `0xDB` | 1 |
| 8 | 2 | `0xBEC516BD` | `0xA3` | `0xBD` | 1 |
| 9 | 3 | `0xBEC5169F` | `0x81` | `0x9F` | 2 |
| 10 | 4 | `0xBEC51671` | `0x6F` | `0x71` | 2 |
| 11 | 5 | `0xBEC51653` | `0x4D` | `0x53` | 2 |
| 12 | 6 | `0xBEC51635` | `0x2B` | `0x35` | 2 |
| 13 | 7 | `0xBEC51617` | `0x09` | `0x17` | 2 |
| 14 | 0 | `0xBEC516F9` | `0xE7` | `0xF9` | 2 |
| 15 | 1 | `0xBEC516DB` | `0xC5` | `0xDB` | 2 |
| 16 | 2 | `0xBEC516BD` | `0xA3` | `0xBD` | 2 |

## Rolling Sequence Trace

```
Step:    3    4    5    6    7    0    1    2    |  3    4    5    6    7    0    1    2
Base:  0x81 0x6F 0x4D 0x2B 0x09 0xE7 0xC5 0xA3  | 0x81 0x6F 0x4D 0x2B 0x09 0xE7 0xC5 0xA3
XOR:   ^0x1E                                        ^0x1E
Roll:  0x9F 0x71 0x53 0x35 0x17 0xF9 0xDB 0xBD  | 0x9F 0x71 0x53 0x35 0x17 0xF9 0xDB 0xBD
                                                   ╰──── identical ────╯
```

## Raw Capture

```
codes     : {32}bec5169f
codes     : {33}9f628b4f8
codes     : {33}9f628b4f8
codes     : {33}9f628b4f8
codes     : {33}9f628b4f8
codes     : {33}9f628b4f8
codes     : {33}9f628b4f8
codes     : {32}bec51671
codes     : {33}9f628b388
codes     : {33}9f628b388
codes     : {33}9f628b388
codes     : {33}9f628b388
codes     : {33}9f628b388
codes     : {33}9f628b388
codes     : {32}bec51653
codes     : {33}9f628b298
codes     : {33}9f628b298
codes     : {33}9f628b298
codes     : {33}9f628b298
codes     : {33}9f628b298
codes     : {33}9f628b298
codes     : {32}bec51635
codes     : {33}9f628b1a8
codes     : {33}9f628b1a8
codes     : {33}9f628b1a8
codes     : {33}9f628b1a8
codes     : {33}9f628b1a8
codes     : {33}9f628b1a8
codes     : {32}bec51617
codes     : {33}9f628b0b8
codes     : {33}9f628b0b8
codes     : {33}9f628b0b8
codes     : {33}9f628b0b8
codes     : {33}9f628b0b8
codes     : {33}9f628b0b8
codes     : {32}bec516f9
codes     : {33}9f628b7c8
codes     : {33}9f628b7c8
codes     : {33}9f628b7c8
codes     : {33}9f628b7c8
codes     : {33}9f628b7c8
codes     : {33}9f628b7c8
codes     : {32}bec516db
codes     : {33}9f628b6d8
codes     : {33}9f628b6d8
codes     : {33}9f628b6d8
codes     : {33}9f628b6d8
codes     : {33}9f628b6d8
codes     : {33}9f628b6d8
codes     : {32}bec516bd
codes     : {33}9f628b5e8
codes     : {33}9f628b5e8
codes     : {33}9f628b5e8
codes     : {33}9f628b5e8
codes     : {33}9f628b5e8
codes     : {33}9f628b5e8

# Second cycle (identical):
codes     : {32}bec5169f
codes     : {33}9f628b4f8
codes     : {33}9f628b4f8
codes     : {33}9f628b4f8
codes     : {33}9f628b4f8
codes     : {33}9f628b4f8
codes     : {33}9f628b4f8
codes     : {32}bec51671
codes     : {33}9f628b388
codes     : {33}9f628b388
codes     : {33}9f628b388
codes     : {33}9f628b388
codes     : {33}9f628b388
codes     : {33}9f628b388
codes     : {32}bec51653
codes     : {33}9f628b298
codes     : {33}9f628b298
codes     : {33}9f628b298
codes     : {33}9f628b298
codes     : {33}9f628b298
codes     : {33}9f628b298
codes     : {32}bec51635
codes     : {33}9f628b1a8
codes     : {33}9f628b1a8
codes     : {33}9f628b1a8
codes     : {33}9f628b1a8
codes     : {33}9f628b1a8
codes     : {33}9f628b1a8
codes     : {32}bec51617
codes     : {33}9f628b0b8
codes     : {33}9f628b0b8
codes     : {33}9f628b0b8
codes     : {33}9f628b0b8
codes     : {33}9f628b0b8
codes     : {33}9f628b0b8
codes     : {32}bec516f9
codes     : {33}9f628b7c8
codes     : {33}9f628b7c8
codes     : {33}9f628b7c8
codes     : {33}9f628b7c8
codes     : {33}9f628b7c8
codes     : {33}9f628b7c8
codes     : {32}bec516db
codes     : {33}9f628b6d8
codes     : {33}9f628b6d8
codes     : {33}9f628b6d8
codes     : {33}9f628b6d8
codes     : {33}9f628b6d8
codes     : {33}9f628b6d8
codes     : {32}bec516bd
codes     : {33}9f628b5e8
codes     : {33}9f628b5e8
codes     : {33}9f628b5e8
codes     : {33}9f628b5e8
codes     : {33}9f628b5e8
codes     : {33}9f628b5e8
```
