*[Leia em Português](README.md)*

# ArduinoToolKit

Firmware for an inspection robot that uses RS485 communication between two Arduinos — an **Arduino Nano** (transmitter) and an **Arduino UNO** (receiver) — integrating distance, tilt, compass, and rotary encoder sensors.

## Overview

The project consists of two modules that communicate via an RS485 bus:

| Module | Board | Role | Description |
|---|---|---|---|
| `ArduinoNano_RS485_WIT901` | Arduino Nano | Transmitter | Reads sensors (SharpIR and WIT901) and transmits data via RS485 |
| `ArduinoUNO_RS485_WIT901` | Arduino UNO | Receiver | Receives sensor data via RS485, reads the encoder, and controls the robot via serial commands |

## Sensors and Peripherals

- **WIT901 (JY901)** — IMU sensor (accelerometer, gyroscope, and magnetometer) connected via I²C. Provides tilt angle (roll/pitch/yaw) and compass heading.
- **Sharp IR** — Infrared distance sensor (10–80 cm), connected to an analog input.
- **Encoder E30A** — Incremental rotary encoder for measuring robot position/displacement.

## RS485 Communication

Communication between the two Arduinos uses the RS485 protocol via `SoftwareSerial`, with the following characteristics:

- 2-wire communication, 9600 bps baud rate
- Range up to 1,200 m
- Packet-based protocol delimited by characters:
  - `a...z` → SharpIR sensor (distance)
  - `b...z` → Tilt angle (angleX)
  - `c...z` → Compass (yaw)
  - `d...z` → Compass direction (text)

## Robot Control

The receiver module accepts commands via the serial port to control the robot:

| Command (ASCII) | Action |
|---|---|
| `1` (49) | Move forward |
| `2` (50) | Stop |
| `3` (51) | Move backward |
| `4` (52) | Reset encoder |
| `5` (53) | Head up |
| `6` (54) | Head down |
| `7` (55) | Head left |
| `8` (56) | Head right |
| `9` (57) | Head stop |

## Pin Mapping

### Arduino Nano (Transmitter)

| Pin | Function |
|---|---|
| A0 | Sharp IR sensor |
| A1 | RS485 RX (RO) |
| A2 | RS485 TX (DI) |
| A3 | RS485 Enable (TX/RX) |
| A4 (SDA) | WIT901 I²C |
| A5 (SCL) | WIT901 I²C |

### Arduino UNO (Receiver)

| Pin | Function |
|---|---|
| 2 | Encoder channel A |
| 3 | Encoder channel B |
| 4–7 | Robot head control |
| 8 | Motor forward |
| 9 | Motor backward |
| A2 | RS485 TX (DI) |
| A3 | RS485 Enable (TX/RX) |
| A4 | RS485 RX (RO) |

## Repository Structure

```
ArduinoNano_RS485_WIT901/
├── ArduinoNano_RS485_WIT901.ino   # Main sketch (transmitter)
└── Libraries/
    ├── config.h                   # Settings and pin mapping
    ├── RS485_Transmissor.h        # RS485 communication (send)
    ├── SensorSharpIR.h            # Sharp IR sensor reading
    ├── SensorWT901_JY901_IIC.h    # WIT901 reading via I²C
    ├── SensorWT901_JY901Serial.h  # WIT901 reading via Serial
    ├── SharpIR.h / SharpIR.cpp    # Sharp IR sensor library
    └── JY901.h / JY901.cpp        # JY901 sensor library

ArduinoUNO_RS485_WIT901/
├── ArduinoUNO_RS485_WIT901.ino    # Main sketch (receiver)
└── Libraries/
    ├── config.h                   # Settings and pin mapping
    ├── RS485_receptor.h           # RS485 communication (receive)
    ├── encoder_e30A.h             # Rotary encoder reading
    └── serialCallback.h           # Robot control via serial
```

## How to Use

1. Open the corresponding sketch in the **Arduino IDE**:
   - `ArduinoNano_RS485_WIT901/ArduinoNano_RS485_WIT901.ino` for the transmitter
   - `ArduinoUNO_RS485_WIT901/ArduinoUNO_RS485_WIT901.ino` for the receiver
2. Install the required libraries (included in each module's `Libraries/` folder, also available as `Libraries.zip`).
3. Select the correct board (Arduino Nano or Arduino UNO) and upload the sketch.
4. Connect the RS485 modules between the two Arduinos according to the pin mapping described above.
5. Open the Serial Monitor (9600 baud) to view sensor data or send control commands.

## License

This project is licensed under the [MIT License](LICENSE).
