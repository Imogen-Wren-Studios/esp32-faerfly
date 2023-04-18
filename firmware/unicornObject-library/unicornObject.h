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

#include "pridePalettes.h"
#include "colorPalettes.h"
#include <FastLED.h>
#include <autoDelay.h>

//#include "pridePalettes.h"
//#include "colorPalettes.h"

#define LED_PIN 5
#define NUM_LEDS 8
#define BRIGHTNESS 255
#define LED_TYPE WS2811
#define COLOR_ORDER GRB

#define UPDATES_PER_SECOND 30
#define HUE_STEPS 1  // Number of steps to advance through palette between each for loop. Origionally 3

#define ANIMATION_BLEND_SPEED 128
#define NORMAL_BLEND_SPEED 12


// I would love to try and initialise a unicorn object with the variables to create an fastLED object, however
// I cannot find a way of getting the variables needed into the right format for compile time assignment.
// Only solution is #DEFINE  in header for these variables

class unicornObject {
public:



  //Constructor

  unicornObject(){};

  autoDelay colorDelay;

  CRGBArray<NUM_LEDS> ledRing;




  // Methods

  void begin();

  void paintRGB(uint8_t red, uint8_t green, uint8_t blue);

  void paintHSV(uint8_t hue, uint8_t saturation, uint8_t value);

  void update();

  void makeRandomSaturatedPallet();

    CRGBPalette16 currentPalette;
   TBlendType currentBlending = LINEARBLEND;

   CRGBPalette16 nextPalette;

  bool ledDirection = true;


   void fillBufferPaletteColors(CRGBPalette16 newPalette);
void fillBufferSmooth(CRGBPalette16 newPalette, int16_t speed);


private:



  int hue_steps = 1;
  uint32_t hue_shift_timing = 5000;




  uint8_t currentIndex = 0;


  uint8_t updates_per_second = 30;

  int dataPin = 5;
};




#endif
