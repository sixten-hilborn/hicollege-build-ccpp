#include <Arduino.h>

// Pin 13 has an LED connected on most Arduino boards.
constexpr int led = 13;

extern "C" {
#include <libmorse.h>

    void wait() {
        delay(200);
    }

    void on() {
        digitalWrite(led, HIGH);
    }

    void off() {
        digitalWrite(led, LOW);
    }
}


void setup() {
    pinMode(led, OUTPUT);
}

void loop() {
    char str[] = "hiq";
    morse_str(str);
    delay(1500);
}
