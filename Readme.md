# 🌊 IoT River Cleaner & Water Hyacinth Collector Boat 🚤

An eco-friendly, IoT-enabled mobile robotic boat designed to collect floating garbage, plastic waste, and water hyacinth (*Jalkumbhi*) from rivers, lakes, and ponds. Controlled remotely using NodeMCU (ESP8266) via the Blynk IoT Cloud platform.

---

## ✨ Key Features

- **Wireless IoT Navigation:** Remote direction control (Forward, Backward, Left, Right) over Wi-Fi using Blynk IoT app.
- **Automated Conveyor Mechanism:** Onboard motor-driven conveyor belt system to scoop up floating trash and water hyacinth into an integrated collection bin.
- **Dual Motor Driver Setup:** Utilizes two L293N motor drivers—one dedicated to differential boat propulsion and the second dedicated to conveyor operation.
- **Eco-Friendly Solution:** Designed for water body rejuvenation and environmental cleanliness.

---

## 🛠️ Hardware Stack

| Component | Quantity | Description |
| :--- | :--- | :--- |
| **NodeMCU (ESP8266)** | 1 | Microcontroller with built-in Wi-Fi |
| **L293N Motor Driver Shield** | 2 | Driver #1 for propulsion, Driver #2 for conveyor belt |
| **DC Geared Motors** | 2 | High-torque propulsion motors |
| **Conveyor Motor** | 1 | Motor driving the waste collection mechanism |
| **Waterproof Hull / Chassis** | 1 | Lightweight floating boat base |
| **Rechargeable Battery** | 1 | Power source for ESP8266 and motors |

---

## 🔌 Circuit Wiring & Pin Mapping

### 1. Boat Movement (L293N Driver #1)
| Motor Driver Pin | ESP8266 NodeMCU Pin | Function |
| :--- | :--- | :--- |
| **ENA** | `D0` | Left Motor Speed Enable |
| **IN1** | `D1` | Left Motor Direction 1 |
| **IN2** | `D2` | Left Motor Direction 2 |
| **ENB** | `D5` | Right Motor Speed Enable |
| **IN3** | `D3` | Right Motor Direction 1 |
| **IN4** | `D4` | Right Motor Direction 2 |

### 2. Conveyor Belt Mechanism (L293N Driver #2)
| Motor Driver Pin | ESP8266 NodeMCU Pin | Function |
| :--- | :--- | :--- |
| **C_ENA** | `D6` | Conveyor Motor Enable |
| **C_IN1** | `D7` | Conveyor Direction 1 |
| **C_IN2** | `D8` | Conveyor Direction 2 |

---

## 📱 Blynk Dashboard Configuration

Configure the Blynk 2.0 Mobile Dashboard with the following virtual pin widgets:

| Button Name | Virtual Pin | Mode | Action |
| :--- | :--- | :--- | :--- |
| **FORWARD** | `V0` | Push Button (0/1) | Moves boat forward |
| **BACKWARD** | `V1` | Push Button (0/1) | Moves boat backward |
| **LEFT** | `V2` | Push Button (0/1) | Turns boat left |
| **RIGHT** | `V3` | Push Button (0/1) | Turns boat right |
| **CONVEYOR** | `V4` | Switch Button (0/1) | Toggles Waste Conveyor ON/OFF |

---

## 🚀 Getting Started

1. **Install Prerequisites:**
   - Install **Arduino IDE**.
   - Add ESP8266 board support via Board Manager (`http://arduino.esp8266.com/stable/package_esp8266com_index.json`).
   - Install `Blynk` and `ESP8266WiFi` libraries.

2. **Upload Firmware:**
   - Clone this repository:
     ```bash
     git clone [https://github.com/YOUR_USERNAME/River-Cleaner-Boat.git](https://github.com/YOUR_USERNAME/River-Cleaner-Boat.git)
     ```
   - Open `river_cleaner_boat.ino` in Arduino IDE.
   - Update your Wi-Fi credentials (`ssid`, `pass`) and Blynk Auth Token (`BLYNK_AUTH_TOKEN`).
   - Select Board: `NodeMCU 1.0 (ESP-12E Module)`.
   - Compile and Upload!

---

## 🤝 Project Lead & Acknowledgments
- **Shivshankar Kumar**
- **Institution:** Government Engineering College, Sheohar
