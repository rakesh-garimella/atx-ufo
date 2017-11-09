//#include <Adafruit_ESP8266.h>

//        demo project for the Radioshack LED Tricolor Light Strip
//        a project for Arduino
//             by AUDREY LOVE
//
//
//
//        with great support from the FastLED.io Library
//            download it here: https://github.com/FastLED
//
//
//
#define FASTLED_ESP8266_D1_PIN_ORDER

#include "FastLED.h"

#define NUM_LEDS 60 //this defines the number of LED Segments in the Strip

#define DATA_PIN 4 //plug the green wire of the TM1803 Radioshack Strip into Pin 7

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  //  pinMode(0, OUTPUT);


  Serial.begin(115200);      // initialize serial communication at 9600 bits per second:
}

void loop() {
  for (int dot = 0 , dot1 = 31; dot < 30 , dot1 < 60; dot++ , dot1++) {
    leds[dot] = CRGB::Blue;
    leds[dot1] = CRGB::Red;

    FastLED.show();
    // clear this led for the next time around the loop
    leds[dot] = CRGB::Black;
    leds[dot1] = CRGB::Black;

    delay(20);
  }
  //  for (int dot = 23; dot <= 30; dot++) {
  //    leds[dot] = CRGB::Red;
  //    FastLED.show();
  //    // clear this led for the next time around the loop
  //    leds[dot] = CRGB::Black;
  //    delay(20);
  //  }
  //  for (int dot = 1; dot < 7; dot++) {
  //    leds[dot] = CRGB::Yellow;
  //    FastLED.show();
  //    // clear this led for the next time around the loop
  //    leds[dot] = CRGB::Black;
  //    delay(20);
  //  }
  //  for (int dot = 15; dot <= 22; dot++) {
  //    leds[dot] = CRGB::Green;
  //    FastLED.show();
  //    // clear this led for the next time around the loop
  //    leds[dot] = CRGB::Black;
  //    delay(20);
  //  }
}
