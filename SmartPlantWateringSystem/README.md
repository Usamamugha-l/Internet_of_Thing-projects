# 🌱 Smart Plant Watering System (ESP8266 + Blynk)

This project is an **IoT-based Smart Plant Watering System** using an **ESP8266 (NodeMCU)**, **Soil Moisture Sensor**, **DHT11 (Temperature & Humidity Sensor)**, **Water Pump**, and **Blynk IoT App**. The system automatically waters the plant when soil moisture is low and allows **manual control** via the Blynk mobile application. It also provides **real-time temperature, humidity, soil moisture, and light control**.

---

## 📌 Features

* 🌡️ **Temperature & Humidity Monitoring** using **DHT11 sensor**.
* 🌱 **Soil Moisture Detection** (0–100%) with automatic pump activation.
* 💧 **Automatic Irrigation** when soil moisture drops below threshold.
* 📲 **Manual Pump Control** via Blynk App (override mode).
* 💡 **Light Control** via Blynk app.
* 📊 Real-time data visualization on **Blynk Dashboard**.

---

## 🛠️ Components Required

* ESP8266 NodeMCU (Wi-Fi module)
* DHT11 Temperature & Humidity Sensor
* Soil Moisture Sensor
* Water Pump (Mini DC Pump + Relay/MOSFET Driver if required)
* LED/Light (optional grow light)
* Resistors (220Ω for LEDs)
* Jumper Wires
* Breadboard

---

## ⚡ Circuit Connections

| Component         | ESP8266 Pin |
| ----------------- | ----------- |
| Soil Moisture     | A0          |
| Water Pump        | D5          |
| Light (Relay/LED) | D3          |
| DHT11 Sensor      | D4          |

⚠️ **Note:** Use a **relay module or MOSFET** to drive the water pump, as connecting it directly to NodeMCU may damage the board.

---

## 📲 Blynk Virtual Pins

| Virtual Pin | Function                     |
| ----------- | ---------------------------- |
| V0          | Soil Moisture (%)            |
| V1          | Manual Pump Control (Switch) |
| V2          | Light Control (Switch)       |
| V3          | Humidity (%)                 |
| V4          | Temperature (°C)             |

---

## 📜 Code Explanation

1. **Setup**:

   * Initializes Wi-Fi, Blynk, and DHT11 sensor.
   * Configures pump & light as outputs.
   * Sets timers for soil moisture check (1s) and DHT sensor (5s).

2. **Soil Moisture Function**:

   * Reads soil moisture value (0–100%).
   * Sends data to Blynk (V0).
   * If moisture < 30% → Pump ON, else Pump OFF.
   * Skips automation if **manual override** is active.

3. **DHT Sensor Function**:

   * Reads **temperature & humidity**.
   * Sends values to Blynk (V3, V4).

4. **Blynk Control**:

   * V1 → Manual Pump Control.
   * V2 → Light Control.

---

## 🚦 Workflow

* **Normal Mode**:

  * Soil moisture < 30% → Pump ON (water plant).
  * Soil moisture ≥ 30% → Pump OFF.
* **Manual Override** (via Blynk V1):

  * User can turn Pump ON/OFF manually.
* **Light Control** (via Blynk V2):

  * User can switch grow light ON/OFF manually.

---

## 📊 Blynk Dashboard

* 🌱 Soil Moisture (%) → Gauge/Display
* 💧 Pump Control → Switch (V1)
* 💡 Light Control → Switch (V2)
* 🌡️ Temperature (°C) → Value Display (V4)
* 💦 Humidity (%) → Value Display (V3)

---

## ▶️ How to Use

1. Open **Blynk App** and create a new project.
2. Select **ESP8266** as device.
3. Copy your **auth token** into the Arduino sketch.
4. Connect hardware as per circuit.
5. Upload the code to ESP8266.
6. Run the project and monitor/control via **Blynk App**.

---
