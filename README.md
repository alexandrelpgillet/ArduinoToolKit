# ArduinoToolKit

Firmware para um robô de inspeção que utiliza comunicação RS485 entre dois Arduinos — um **Arduino Nano** (transmissor) e um **Arduino UNO** (receptor) — integrando sensores de distância, inclinação, bússola e encoder rotativo.

## Visão Geral

O projeto é composto por dois módulos que se comunicam via barramento RS485:

| Módulo | Placa | Papel | Descrição |
|---|---|---|---|
| `ArduinoNano_RS485_WIT901` | Arduino Nano | Transmissor | Lê os sensores (SharpIR e WIT901) e transmite os dados via RS485 |
| `ArduinoUNO_RS485_WIT901` | Arduino UNO | Receptor | Recebe os dados dos sensores via RS485, lê o encoder e controla o robô por comandos serial |

## Sensores e Periféricos

- **WIT901 (JY901)** — Sensor IMU (acelerômetro, giroscópio e magnetômetro) conectado via I²C. Fornece ângulo de inclinação (roll/pitch/yaw) e direção da bússola.
- **Sharp IR** — Sensor infravermelho de distância (10–80 cm), conectado a uma entrada analógica.
- **Encoder E30A** — Encoder rotativo incremental para medição de posição/deslocamento do robô.

## Comunicação RS485

A comunicação entre os dois Arduinos utiliza o protocolo RS485 via `SoftwareSerial`, com as seguintes características:

- Comunicação a 2 fios, baud rate de 9600 bps
- Alcance de até 1.200 m
- Protocolo baseado em pacotes delimitados por caracteres:
  - `a...z` → Sensor SharpIR (distância)
  - `b...z` → Ângulo de inclinação (angleX)
  - `c...z` → Bússola (yaw)
  - `d...z` → Direção da bússola (texto)

## Controle do Robô

O módulo receptor aceita comandos via porta serial para controlar o robô:

| Comando (ASCII) | Ação |
|---|---|
| `1` (49) | Avançar |
| `2` (50) | Parar |
| `3` (51) | Recuar |
| `4` (52) | Zerar encoder |
| `5` (53) | Cabeça para cima |
| `6` (54) | Cabeça para baixo |
| `7` (55) | Cabeça para esquerda |
| `8` (56) | Cabeça para direita |
| `9` (57) | Cabeça parar |

## Pinagem

### Arduino Nano (Transmissor)

| Pino | Função |
|---|---|
| A0 | Sensor Sharp IR |
| A1 | RS485 RX (RO) |
| A2 | RS485 TX (DI) |
| A3 | RS485 Enable (TX/RX) |
| A4 (SDA) | WIT901 I²C |
| A5 (SCL) | WIT901 I²C |

### Arduino UNO (Receptor)

| Pino | Função |
|---|---|
| 2 | Encoder canal A |
| 3 | Encoder canal B |
| 4–7 | Controle da cabeça do robô |
| 8 | Motor avançar |
| 9 | Motor recuar |
| A2 | RS485 TX (DI) |
| A3 | RS485 Enable (TX/RX) |
| A4 | RS485 RX (RO) |

## Estrutura do Repositório

```
ArduinoNano_RS485_WIT901/
├── ArduinoNano_RS485_WIT901.ino   # Sketch principal (transmissor)
└── Libraries/
    ├── config.h                   # Configurações e pinagem
    ├── RS485_Transmissor.h        # Comunicação RS485 (envio)
    ├── SensorSharpIR.h            # Leitura do sensor Sharp IR
    ├── SensorWT901_JY901_IIC.h    # Leitura do WIT901 via I²C
    ├── SensorWT901_JY901Serial.h  # Leitura do WIT901 via Serial
    ├── SharpIR.h / SharpIR.cpp    # Biblioteca do sensor Sharp IR
    └── JY901.h / JY901.cpp        # Biblioteca do sensor JY901

ArduinoUNO_RS485_WIT901/
├── ArduinoUNO_RS485_WIT901.ino    # Sketch principal (receptor)
└── Libraries/
    ├── config.h                   # Configurações e pinagem
    ├── RS485_receptor.h           # Comunicação RS485 (recepção)
    ├── encoder_e30A.h             # Leitura do encoder rotativo
    └── serialCallback.h           # Controle do robô via serial
```

## Como Usar

1. Abra o sketch correspondente na **Arduino IDE**:
   - `ArduinoNano_RS485_WIT901/ArduinoNano_RS485_WIT901.ino` para o transmissor
   - `ArduinoUNO_RS485_WIT901/ArduinoUNO_RS485_WIT901.ino` para o receptor
2. Instale as bibliotecas necessárias (incluídas na pasta `Libraries/` de cada módulo, também disponíveis como `Libraries.zip`).
3. Selecione a placa correta (Arduino Nano ou Arduino UNO) e faça o upload.
4. Conecte os módulos RS485 entre os dois Arduinos conforme a pinagem descrita acima.
5. Abra o Monitor Serial (9600 baud) para visualizar os dados dos sensores ou enviar comandos de controle.

## Licença

Este projeto está licenciado sob a [MIT License](LICENSE).
