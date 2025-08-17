# 🔥 Fire Alarm System (Arduino-Based)

This project is a **Fire Alarm System** built using an Arduino, a fire sensor, a buzzer, and indicator LEDs. The system detects fire/smoke and activates a buzzer alarm while changing LED states to alert users.

---

## 📌 Features

* **Real-time Fire Detection** using a digital fire sensor.
* **Smoke/Flame Intensity Detection** using an analog input (A0).
* **Visual Alert**:

  * Green LED (Normal Condition)
  * Red LED (Fire Detected)
* **Audio Alert**: Buzzer activates when fire/smoke is detected.
* **Serial Monitor Output** for debugging and monitoring sensor values.

---

## 🛠️ Components Required

* Arduino Uno (or compatible board)
* Fire Sensor (Digital + Analog Output)
* Buzzer
* Red LED
* Green LED
* Resistors (220Ω recommended for LEDs)
* Jumper Wires
* Breadboard

---

## ⚡ Circuit Connections

| Component   | Arduino Pin  |
| ----------- | ------------ |
| Buzzer      | D3           |
| Fire Sensor | D4 (Digital) |
| Fire Sensor | A0 (Analog)  |
| Green LED   | D5           |
| Red LED     | D2           |

---

## 📜 Code Explanation

1. **Initialization**:

   * Sets buzzer, LEDs as OUTPUT and fire sensor as INPUT.
   * Default: Green LED ON, Red LED OFF, Buzzer OFF.

2. **Loop**:

   * Reads **fireValue** (digital) and **sensorValue** (analog).
   * If fire detected (`fireValue == 0` OR `sensorValue > 500`):

     * Buzzer sounds.
     * Red LED ON, Green LED OFF.
   * Otherwise:

     * System stays in safe state (Buzzer OFF, Green LED ON).

---

## 🚦 Workflow

* **Normal Condition**: Green LED ON, Red LED OFF, Buzzer Silent.
* **Fire/Smoke Detected**: Green LED OFF, Red LED ON, Buzzer Alarm.

---

## 📊 Serial Monitor Output

* Prints **digital sensor value (0/1)**.
* Prints **analog sensor reading (0–1023)** for smoke/fire intensity.

---

## ▶️ How to Use

1. Connect the components as per circuit diagram.
2. Upload the Arduino sketch to your board.
3. Open the **Serial Monitor** (9600 baud).
4. Test the system by exposing the fire sensor to flame/smoke.

---
