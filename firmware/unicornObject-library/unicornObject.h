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
#include "pridePalettes.h"
#include "colorPalettes.h"

//#include "pridePalettes.h"
//#include "colorPalettes.h"



class unicornObject {
public:


#define LED_PIN 5
#define NUM_LEDS 8
#define BRIGHTNESS 255
#define LED_TYPE WS2811
#define COLOR_ORDER GRB

#define ANIMATION_BLEND_SPEED 128
#define NORMAL_BLEND_SPEED 12

  int num_leds = 12;

  CRGBArray<NUM_LEDS> ledRing;

  // CRGBArray<NUM_LEDS> ledString;

  //Constructor

  unicornObject()
  // tell FastLED about the LED strip configuration
  {
  }
  

  // Methods

  void setup();

  void paintRGB(uint8_t red, uint8_t green, uint8_t blue);

  void paintHSV(uint8_t hue, uint8_t saturation, uint8_t value);

  void update();

  void makeRandomSaturatedPallet();

  CRGBPalette16 currentPalette;
  TBlendType currentBlending;

  CRGBPalette16 nextPalette;

  bool ledDirection = true;

  void fillBufferPaletteColors(CRGBPalette16 newPalette);



private:

  int hue_steps = 3;
  uint32_t hue_shift_timing = 5000;




  uint8_t currentIndex = 0;


  uint8_t updates_per_second = 30;

  int dataPin = 5;
};




#endif
