#include <Arduino.h>
#include <Wire.h>

#define SDA_PIN 21
#define SCL_PIN 22

void setup() {
    Serial.begin(115200);

    Wire.begin(SDA_PIN, SCL_PIN);

    Serial.println("I2C Scanner");

    for (uint8_t address = 1; address < 127; address++) {
        Wire.beginTransmission(address);

        if (Wire.endTransmission() == 0) {
            Serial.print("Found: 0x");
            if (address < 16) Serial.print("0");
            Serial.println(address, HEX);
        }
    }
}

void loop() {
}