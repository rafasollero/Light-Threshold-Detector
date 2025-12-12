Simple Threshold Monitoring System (Arduino LDR)

This is a basic Arduino project designed to demonstrate threshold monitoring using an Analog Sensor (specifically, a Light Dependent Resistor or LDR). When the ambient light intensity (read by the LDR) exceeds a predefined threshold, an LED is activated.

It's a perfect starting point for beginners or as the core logic for automated light switches, motion detectors, or basic intrusion alarms.

 Components Required

| Component | Quantity | Notes |
| :--- | :--- | :--- |
| **Arduino Uno** (or compatible board) | 1 | |
| **Light Dependent Resistor (LDR)** | 1 | Used as the analog sensor. |
| **LED** | 1 | Standard indicator LED. |
| **Resistor 10kΩ** | 1 | Used for the LDR's voltage divider circuit. |
| **Resistor 220Ω** | 1 | Current limiting resistor for the LED. |
| Jumper Wires | - | For connections. |
| Breadboard | 1 | Highly recommended for assembly. |

 Wiring Diagram

The circuit uses a simple voltage divider setup for the LDR to read analog light levels.

| Component Pin | Connection to Arduino | Purpose |
| :--- | :--- | :--- |
| **LED** (Anode/Long Leg) | Digital Pin **13** | Output indicator. |
| **LED** (Cathode/Short Leg) | **GND** via 220Ω resistor | Complete the LED circuit. |
| **LDR** (Leg 1) | **5V** | Part of the voltage divider. |
| **LDR** (Leg 2) | **Analog Pin A0** | Read point of the voltage. |
| **10kΩ Resistor** (Leg 1) | **Analog Pin A0** | Other part of the voltage divider. |
| **10kΩ Resistor** (Leg 2) | **GND** | Complete the voltage divider to ground. |



 Arduino Code (Sketch)

The following code reads the analog value from the sensor and checks if it is above the threshold value of `500`.

```cpp
#include <Servo.h> // NOTE: This library is included in the original code but is unused.
#define PIN_LED 13
#define PIN_SENSOR A0

void setup() {
    // Set up the pins
    pinMode(PIN_LED, OUTPUT);
    pinMode(PIN_SENSOR, INPUT);
    
    // Initialize serial communication for debugging
    Serial.begin(9600);
    Serial.println("System Initialized...");
}

void loop() {
    // Read the analog sensor value (0-1023)
    int lectura = analogRead(PIN_SENSOR);
    
    // Check if the reading exceeds the threshold (500)
    if (lectura > 500) {
        // If threshold is exceeded, turn the LED ON and report status
        digitalWrite(PIN_LED, HIGH);
        Serial.println("Activated");
    } else {
        // Otherwise, turn the LED OFF
        digitalWrite(PIN_LED, LOW);
    }
    
    // Short delay to prevent excessive reading rate
    delay(100);
}
// Simple threshold monitoring system for Arduino.
// Reads an analog sensor (A0) and activates an LED (PIN 13) if the reading
// exceeds the value of 500. It reports the activation status via the Serial
// port. Ideal for basic light, movement, or proximity detection.
