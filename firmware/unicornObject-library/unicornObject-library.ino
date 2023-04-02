#include <FastLED.h>
#include <autoDelay.h>









#include "unicornObject.h"
unicornObject unicorn;

CRGBPalette16 currentPalette;
TBlendType currentBlending;


CRGBPalette16 nextPalette;
//TBlendType    currentBlending;


#include "pridePalettes.h"
#include "colorPalettes.h"


#define UPDATES_PER_SECOND 30
#define HUE_STEPS 5  // Number of steps to advance through palette between each for loop. Origionally 3






uint8_t updates_per_second = 30;



uint8_t startIndex = 0;


int16_t index_addr = 1;


bool ledDirection = true;  // Sets the LEDs to update in a positive direction if true, or reverse direction if false

int hue_steps = 3;
uint32_t hue_shift_timing = 5000;

#define START_PALETTE RainbowColors_p  // Sterile while palette to start with
#define SECOND_PALETTE transPalette

#define ANIMATION_BLEND_SPEED 128
#define NORMAL_BLEND_SPEED 12

// Utilities

void FillLEDsFromPaletteColors(uint8_t colorIndex) {

  for (int i = 0; i < NUM_LEDS; i++) {
    ledRing[i] = ColorFromPalette(currentPalette, colorIndex, BRIGHTNESS, currentBlending);

    if (ledDirection) {
      colorIndex += hue_steps;
    } else {
      colorIndex += hue_steps;  // Tried -= but made more jumps not good.
    }
  }
}


// Fills led buffer from palette
void apply_palette() {

  if (ledDirection) {
    startIndex = startIndex + 1; /* motion speed */  //startIndex is the COLOUR index, not the LED array Index
  } else {
    startIndex = startIndex - 1; /* motion speed */  //startIndex is the COLOUR index, not the LED array Index
  }

  // This function currently ignores colour direction updates?!

  FillLEDsFromPaletteColors(startIndex);  // Current Best Method Imogen 23/10/2021

  //  fillLEDS_smoothly(startIndex);     // Smoother way of doing it, hopefully. Also simpler
}








void setup() {
  Serial.begin(115200);
//  unicorn.setup();
  currentPalette = START_PALETTE;
  nextPalette = SECOND_PALETTE;
  ///unicorn.Begin();
}

void loop() {
  // unicorn.paintRGB(250,250,250);
  nblendPaletteTowardPalette(currentPalette, nextPalette, ANIMATION_BLEND_SPEED);
  apply_palette();  //applies palette to LED buffer
  FastLED.show();
  FastLED.delay(1000 / updates_per_second);
}
