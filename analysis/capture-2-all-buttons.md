# Capture 2: All 15 Buttons × 2 Presses

## Overview

All 15 buttons pressed 2 times each in sequence. This revealed the **shared global counter** (steps advance across buttons) and the **parity-based XOR** (odd vs even button IDs use different constants).

Counter was at index **1** when capture started (arbitrary — just wherever it happened to be).

## Global Step Counter Trace

The counter increments on every press regardless of which button, confirming it's shared:

| # | Button ID | Parity | Step | Press # |
|---|---|---|---|---|
| 1 | `0x19` | odd | 1 | 1 |
| 1 | `0x19` | odd | 2 | 2 |
| 2 | `0x17` | odd | 3 | 3 |
| 2 | `0x17` | odd | 4 | 4 |
| 3 | `0x0F` | odd | 5 | 5 |
| 3 | `0x0F` | odd | 6 | 6 |
| 4 | `0x0D` | odd | 7 | 7 |
| 4 | `0x0D` | odd | 0 | 8 |
| 5 | `0x03` | odd | 1 | 9 |
| 5 | `0x03` | odd | 2 | 10 |
| 6 | `0x15` | odd | 3 | 11 |
| 6 | `0x15` | odd | 4 | 12 |
| 7 | `0x10` | even | 5 | 13 |
| 7 | `0x10` | even | 6 | 14 |
| 8 | `0x13` | odd | 7 | 15 |
| 8 | `0x13` | odd | 0 | 16 |
| 9 | `0x09` | odd | 1 | 17 |
| 9 | `0x09` | odd | 2 | 18 |
| 10 | `0x1B` | odd | 3 | 19 |
| 10 | `0x1B` | odd | 4 | 20 |
| 11 | `0x0A` | even | 5 | 21 |
| 11 | `0x0A` | even | 6 | 22 |
| 12 | `0x0E` | even | 7 | 23 |
| 12 | `0x0E` | even | 0 | 24 |
| 13 | `0x1D` | odd | 1 | 25 |
| 13 | `0x1D` | odd | 2 | 26 |
| 14 | `0x16` | even | 3 | 27 |
| 14 | `0x16` | even | 4 | 28 |
| 15 | `0x06` | even | 5 | 29 |
| 15 | `0x06` | even | 6 | 30 |

## Decoded Codes

### Odd Buttons (XOR constant = `0x19`)

| Button ID | Offset (`0x19 ^ id`) | Press | Step | 32-bit Code | Base | Rolling |
|---|---|---|---|---|---|---|
| `0x19` | `0x00` | 1 | 1 | `0xBEC519C5` | `0xC5` | `0xC5` |
| | | 2 | 2 | `0xBEC519A3` | `0xA3` | `0xA3` |
| `0x17` | `0x0E` | 1 | 3 | `0xBEC5178F` | `0x81` | `0x8F` |
| | | 2 | 4 | `0xBEC51761` | `0x6F` | `0x61` |
| `0x0F` | `0x16` | 1 | 5 | `0xBEC50F5B` | `0x4D` | `0x5B` |
| | | 2 | 6 | `0xBEC50F3D` | `0x2B` | `0x3D` |
| `0x0D` | `0x14` | 1 | 7 | `0xBEC50D1D` | `0x09` | `0x1D` |
| | | 2 | 0 | `0xBEC50DF3` | `0xE7` | `0xF3` |
| `0x03` | `0x1A` | 1 | 1 | `0xBEC503DF` | `0xC5` | `0xDF` |
| | | 2 | 2 | `0xBEC503B9` | `0xA3` | `0xB9` |
| `0x15` | `0x0C` | 1 | 3 | `0xBEC5158D` | `0x81` | `0x8D` |
| | | 2 | 4 | `0xBEC51563` | `0x6F` | `0x63` |
| `0x13` | `0x0A` | 1 | 7 | `0xBEC51303` | `0x09` | `0x03` |
| | | 2 | 0 | `0xBEC513ED` | `0xE7` | `0xED` |
| `0x09` | `0x10` | 1 | 1 | `0xBEC509D5` | `0xC5` | `0xD5` |
| | | 2 | 2 | `0xBEC509B3` | `0xA3` | `0xB3` |
| `0x1B` | `0x02` | 1 | 3 | `0xBEC51B83` | `0x81` | `0x83` |
| | | 2 | 4 | `0xBEC51B6D` | `0x6F` | `0x6D` |
| `0x1D` | `0x04` | 1 | 1 | `0xBEC51DC1` | `0xC5` | `0xC1` |
| | | 2 | 2 | `0xBEC51DA7` | `0xA3` | `0xA7` |

### Even Buttons (XOR constant = `0x08`)

| Button ID | Offset (`0x08 ^ id`) | Press | Step | 32-bit Code | Base | Rolling |
|---|---|---|---|---|---|---|
| `0x10` | `0x18` | 1 | 5 | `0xBEC51055` | `0x4D` | `0x55` |
| | | 2 | 6 | `0xBEC51033` | `0x2B` | `0x33` |
| `0x0A` | `0x02` | 1 | 5 | `0xBEC50A4F` | `0x4D` | `0x4F` |
| | | 2 | 6 | `0xBEC50A29` | `0x2B` | `0x29` |
| `0x0E` | `0x06` | 1 | 7 | `0xBEC50E0F` | `0x09` | `0x0F` |
| | | 2 | 0 | `0xBEC50EE1` | `0xE7` | `0xE1` |
| `0x16` | `0x1E` | 1 | 3 | `0xBEC5169F` | `0x81` | `0x9F` |
| | | 2 | 4 | `0xBEC51671` | `0x6F` | `0x71` |
| `0x06` | `0x0E` | 1 | 5 | `0xBEC50643` | `0x4D` | `0x43` |
| | | 2 | 6 | `0xBEC50625` | `0x2B` | `0x25` |

## Raw Capture

```
# Button 1 (ID=0x19, odd)
codes     : {32}bec519c5
codes     : {33}9f628ce28
codes     : {33}9f628ce28
codes     : {33}9f628ce28
codes     : {33}9f628ce28
codes     : {33}9f628ce28
codes     : {33}9f628ce28
codes     : {32}bec519a3
codes     : {33}9f628cd18
codes     : {33}9f628cd18
codes     : {33}9f628cd18
codes     : {33}9f628cd18
codes     : {33}9f628cd18
codes     : {33}9f628cd18

# Button 2 (ID=0x17, odd)
codes     : {32}bec5178f
codes     : {33}9f628bc78
codes     : {33}9f628bc78
codes     : {33}9f628bc78
codes     : {33}9f628bc78
codes     : {33}9f628bc78
codes     : {33}9f628bc78
codes     : {32}bec51761
codes     : {33}9f628bb08
codes     : {33}9f628bb08
codes     : {33}9f628bb08
codes     : {33}9f628bb08
codes     : {33}9f628bb08
codes     : {33}9f628bb08

# Button 3 (ID=0x0f, odd)
codes     : {32}bec50f5b
codes     : {33}9f6287ad8
codes     : {33}9f6287ad8
codes     : {33}9f6287ad8
codes     : {33}9f6287ad8
codes     : {33}9f6287ad8
codes     : {33}9f6287ad8
codes     : {32}bec50f3d
codes     : {33}9f62879e8
codes     : {33}9f62879e8
codes     : {33}9f62879e8
codes     : {33}9f62879e8
codes     : {33}9f62879e8
codes     : {33}9f62879e8

# Button 4 (ID=0x0d, odd)
codes     : {32}bec50d1d
codes     : {33}9f62868e8
codes     : {33}9f62868e8
codes     : {33}9f62868e8
codes     : {33}9f62868e8
codes     : {33}9f62868e8
codes     : {33}9f62868e8
codes     : {32}bec50df3
codes     : {33}9f6286f98
codes     : {33}9f6286f98
codes     : {33}9f6286f98
codes     : {33}9f6286f98
codes     : {33}9f6286f98
codes     : {33}9f6286f98

# Button 5 (ID=0x03, odd)
codes     : {32}bec503df
codes     : {33}9f6281ef8
codes     : {33}9f6281ef8
codes     : {33}9f6281ef8
codes     : {33}9f6281ef8
codes     : {33}9f6281ef8
codes     : {33}9f6281ef8
codes     : {32}bec503b9
codes     : {33}9f6281dc8
codes     : {33}9f6281dc8
codes     : {33}9f6281dc8
codes     : {33}9f6281dc8
codes     : {33}9f6281dc8
codes     : {33}9f6281dc8

# Button 6 (ID=0x15, odd)
codes     : {32}bec5158d
codes     : {33}9f628ac68
codes     : {33}9f628ac68
codes     : {33}9f628ac68
codes     : {33}9f628ac68
codes     : {33}9f628ac68
codes     : {33}9f628ac68
codes     : {32}bec51563
codes     : {33}9f628ab18
codes     : {33}9f628ab18
codes     : {33}9f628ab18
codes     : {33}9f628ab18
codes     : {33}9f628ab18
codes     : {33}9f628ab18

# Button 7 (ID=0x10, even)
codes     : {32}bec51055
codes     : {33}9f62882a8
codes     : {33}9f62882a8
codes     : {33}9f62882a8
codes     : {33}9f62882a8
codes     : {33}9f62882a8
codes     : {33}9f62882a8
codes     : {32}bec51033
codes     : {33}9f6288198
codes     : {33}9f6288198
codes     : {33}9f6288198
codes     : {33}9f6288198
codes     : {33}9f6288198
codes     : {33}9f6288198

# Button 8 (ID=0x13, odd)
codes     : {32}bec51303
codes     : {33}9f6289818
codes     : {33}9f6289818
codes     : {33}9f6289818
codes     : {33}9f6289818
codes     : {33}9f6289818
codes     : {33}9f6289818
codes     : {32}bec513ed
codes     : {33}9f6289f68
codes     : {33}9f6289f68
codes     : {33}9f6289f68
codes     : {33}9f6289f68
codes     : {33}9f6289f68
codes     : {33}9f6289f68

# Button 9 (ID=0x09, odd)
codes     : {32}bec509d5
codes     : {33}9f6284ea8
codes     : {33}9f6284ea8
codes     : {33}9f6284ea8
codes     : {33}9f6284ea8
codes     : {33}9f6284ea8
codes     : {33}9f6284ea8
codes     : {32}bec509b3
codes     : {33}9f6284d98
codes     : {33}9f6284d98
codes     : {33}9f6284d98
codes     : {33}9f6284d98
codes     : {33}9f6284d98
codes     : {33}9f6284d98

# Button 10 (ID=0x1b, odd)
codes     : {32}bec51b83
codes     : {33}9f628dc18
codes     : {33}9f628dc18
codes     : {33}9f628dc18
codes     : {33}9f628dc18
codes     : {33}9f628dc18
codes     : {33}9f628dc18
codes     : {32}bec51b6d
codes     : {33}9f628db68
codes     : {33}9f628db68
codes     : {33}9f628db68
codes     : {33}9f628db68
codes     : {33}9f628db68
codes     : {33}9f628db68

# Button 11 (ID=0x0a, even)
codes     : {32}bec50a4f
codes     : {33}9f6285278
codes     : {33}9f6285278
codes     : {33}9f6285278
codes     : {33}9f6285278
codes     : {33}9f6285278
codes     : {33}9f6285278
codes     : {32}bec50a29
codes     : {33}9f6285148
codes     : {33}9f6285148
codes     : {33}9f6285148
codes     : {33}9f6285148
codes     : {33}9f6285148
codes     : {33}9f6285148

# Button 12 (ID=0x0e, even)
codes     : {32}bec50e0f
codes     : {33}9f6287078
codes     : {33}9f6287078
codes     : {33}9f6287078
codes     : {33}9f6287078
codes     : {33}9f6287078
codes     : {33}9f6287078
codes     : {32}bec50ee1
codes     : {33}9f6287708
codes     : {33}9f6287708
codes     : {33}9f6287708
codes     : {33}9f6287708
codes     : {33}9f6287708
codes     : {33}9f6287708

# Button 13 (ID=0x1d, odd)
codes     : {32}bec51dc1
codes     : {33}9f628ee08
codes     : {33}9f628ee08
codes     : {33}9f628ee08
codes     : {33}9f628ee08
codes     : {33}9f628ee08
codes     : {33}9f628ee08
codes     : {32}bec51da7
codes     : {33}9f628ed38
codes     : {33}9f628ed38
codes     : {33}9f628ed38
codes     : {33}9f628ed38
codes     : {33}9f628ed38
codes     : {33}9f628ed38

# Button 14 (ID=0x16, even)
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

# Button 15 (ID=0x06, even)
codes     : {32}bec50643
codes     : {33}9f6283218
codes     : {33}9f6283218
codes     : {33}9f6283218
codes     : {33}9f6283218
codes     : {33}9f6283218
codes     : {33}9f6283218
codes     : {32}bec50625
codes     : {33}9f6283128
codes     : {33}9f6283128
codes     : {33}9f6283128
codes     : {33}9f6283128
codes     : {33}9f6283128
codes     : {33}9f6283128
```
