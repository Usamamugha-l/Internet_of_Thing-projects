# 🔥 Fire Alarm System with Automatic Water Pump (Arduino-Based)

This project is an **Arduino-based Fire Alarm & Extinguishing System** that not only detects fire but also **activates a water pump** to extinguish it. It uses a fire sensor for detection, a buzzer for sound alerts, LEDs for status indication, and a water pump for fire control.

---

## 📌 Features

* **Fire Detection** using a digital fire sensor.
* **Visual Alerts**:

  * 🔴 Red LED (Safe Condition)
  * 🟢 Green LED (Fire Detected)
* **Sound Alert**: Buzzer alarm when fire is detected.
* **Automatic Fire Extinguishing**: Activates a water pump when fire is detected.
* **Serial Monitor Output**: Displays fire sensor readings for debugging.

---

## 🛠️ Components Required

* Arduino Uno (or compatible board)
* Fire Sensor (Digital Output)
* Buzzer
* Red LED
* Green LED
* Water Pump (Mini DC Pump + Relay/MOSFET Driver if required)
* Resistors (220Ω for LEDs)
* Jumper Wires
* Breadboard

---

## ⚡ Circuit Connections

| Component   | Arduino Pin           |
| ----------- | --------------------- |
| Buzzer      | D3                    |
| Fire Sensor | D4 (Digital)          |
| Green LED   | D5                    |
| Red LED     | D2                    |
| Water Pump  | D6 (via relay/MOSFET) |

---

## 📜 Code Explanation

1. **Setup Phase**:

   * Initializes I/O pins for buzzer, LEDs, fire sensor, and water pump.
   * Default: Red LED ON (Safe), Green LED OFF, Buzzer OFF, Pump OFF.

2. **Loop Phase**:

   * Reads **fireValue** from fire sensor.
   * If fire detected (`fireValue == 0`):

     * Buzzer sounds.
     * Green LED ON, Red LED OFF.
     * Pump remains OFF (alert stage).
   * If no fire detected:

     * Buzzer OFF.
     * Red LED ON, Green LED OFF.
     * Pump ON (active extinguishing mode).

---

## 🚦 Workflow

* **Safe Condition**:

  * 🔴 Red LED ON
  * 🟢 Green LED OFF
  * 🔕 Buzzer OFF
  * 💧 Pump OFF

* **Fire Detected**:

  * 🔴 Red LED OFF
  * 🟢 Green LED ON
  * 🔔 Buzzer ON
  * 💧 Pump ON

---

## 📊 Serial Monitor Output

* Prints the **digital fire sensor value (0/1)** every second.

---

## ▶️ How to Use

1. Connect all components as per circuit diagram.
2. Upload the Arduino sketch to your board.
3. Open the **Serial Monitor** at 9600 baud.
4. Test the system by bringing a flame near the fire sensor.
5. Pump activates automatically when fire is detected.

---

