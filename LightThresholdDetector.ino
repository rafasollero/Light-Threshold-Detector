
#include <Servo.h>
#define PIN_LED 13
#define PIN_SENSOR A0

void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_SENSOR, INPUT);
  Serial.begin(9600);
  Serial.println("Sistema Iniciado...");
}

void loop() {
  int lectura = analogRead(PIN_SENSOR);
  if (lectura > 500) {
    digitalWrite(PIN_LED, HIGH);
    Serial.println("Activado");
  } else {
    digitalWrite(PIN_LED, LOW);
  }
  delay(100);
}
// Simple threshold monitoring system for Arduino. 
//Reads an analog sensor (A0) and activates an LED (PIN 13) if the reading 
//exceeds the value of 500. It reports the activation status via the Serial 
//port. Ideal for basic light, movement, or proximity detection.


