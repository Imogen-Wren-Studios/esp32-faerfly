/*
 Unicorn Object.

 A Library to handle ws2812b lighting FX using OOP

*/


#ifndef unicornObject_h
#define unicornObject_h

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <wProgram.h>
#endif

#include <FastLED.h>

#define LED_PIN 5
#define NUM_LEDS 8
#define BRIGHTNESS 255
#define LED_TYPE WS2811
#define COLOR_ORDER GRB

CRGBArray<NUM_LEDS> ledRing;

class unicornObject {
public:

  int num_leds = 12;


 // CRGBArray<NUM_LEDS> ledString;

  //Constructor

  unicornObject()
  // tell FastLED about the LED strip configuration
  {
  }





  // Methods

  void setup();

  void paintRGB(uint8_t red, uint8_t green, uint8_t blue);



private:


  int dataPin = 5;
};




#endif
