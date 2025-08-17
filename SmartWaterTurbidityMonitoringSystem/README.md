# 💧 Smart Water Turbidity Monitoring System (Arduino + LCD)

This project is a **Smart Water Turbidity Monitoring System** using an **Arduino**, **Turbidity Sensor**, and an **I2C LCD Display**. The system continuously measures the **turbidity level of water** and displays the results on an LCD while also controlling indicator LEDs to represent water quality (**Clear, Cloudy, Dirty**).

---

## 📌 Features

* 📊 **Real-time Turbidity Monitoring** using a turbidity sensor.
* 🖥️ **LCD Display Output** showing turbidity level and status.
* 🔴🟡🟢 **LED Indicators** for water quality levels:

  * ✅ Clear (Green + Red ON)
  * ⚠️ Cloudy (Green + Yellow ON)
  * ❌ Dirty (Red + Yellow ON)
* 🔄 **Serial Monitor Output** for debugging and live monitoring.

---

## 🛠️ Components Required

* Arduino Uno (or compatible board)
* Turbidity Sensor Module
* I2C LCD Display (16x2)
* LEDs (Green, Yellow, Red)
* Resistors (220Ω for LEDs)
* Jumper Wires
* Breadboard

---

## ⚡ Circuit Connections

| Component        | Arduino Pin        |
| ---------------- | ------------------ |
| Turbidity Sensor | A0                 |
| Green LED        | D7                 |
| Yellow LED       | D8                 |
| Red LED          | D9                 |
| LCD (I2C)        | SDA → A4, SCL → A5 |

---

## 📜 Code Explanation

1. **Setup**:

   * Initializes LCD, LEDs, and serial communication.
   * LCD backlight enabled.

2. **Loop**:

   * Reads turbidity value from sensor (`0–750`).
   * Maps it into a **percentage scale (0–100%)**.
   * Displays **turbidity value & status** on LCD.
   * Controls LEDs based on water condition:

     * **Clear (<20%)** → Green + Red ON.
     * **Cloudy (20–50%)** → Green + Yellow ON.
     * **Dirty (≥50%)** → Red + Yellow ON.

---

## 🚦 Water Quality Levels

* ✅ **Clear Water**: Turbidity < 20% → Safe for use.
* ⚠️ **Cloudy Water**: 20% ≤ Turbidity < 50% → Needs attention.
* ❌ **Dirty Water**: Turbidity ≥ 50% → Unsafe, should be filtered.

---

## 📊 Serial Monitor Output

* Prints **raw turbidity sensor values**.
* Prints **status message** (`CLEAR`, `CLOUDY`, `DIRTY`).

---

## ▶️ How to Use

1. Connect components as per circuit.
2. Upload the Arduino sketch.
3. Open **Serial Monitor** at 9600 baud.
4. Observe turbidity levels on **LCD** and **LED indicators**.
5. Test by using clean, cloudy, and dirty water samples.

---
