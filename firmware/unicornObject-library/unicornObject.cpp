
//#include <FastLED.h>
#include "unicornObject.h"




void unicornObject::setup() {
  // Serial.println("Gathering Spectrum...");
  delay(1000);  // power-up safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(ledRing, NUM_LEDS).setCorrection(TypicalLEDStrip);
  // Serial.println("...Processing Light Threads...");
  FastLED.setBrightness(BRIGHTNESS);
  randomSeed(analogRead(0));  // psudo random number generator for randomness & chaos
  ledRing(0, NUM_LEDS - 1) = CHSV(255, 255, 0);
  // Serial.println("               Weaving Colours...  \n     ...Selecting Pigments\n");
  //  Serial.println("Chroma Paintbrush Initialised:  Luminescence Matrix Applied.\n Starting Visual Light Imbument\n ");
  FastLED.show();
  delay(500);
}



void unicornObject::paintRGB(uint8_t red, uint8_t green, uint8_t blue) {
  ledRing(0, NUM_LEDS - 1) = CRGB(red, green, blue);
}

void unicornObject::paintHSV(uint8_t hue, uint8_t saturation, uint8_t value) {
  ledRing(0, NUM_LEDS - 1) = CHSV(hue, saturation, value);
}

// Update the output with any changes to the buffer
void unicornObject::update() {
  FastLED.show();
  FastLED.delay(1000 / updates_per_second);
}


// This function fills the palette with totally random colors.
void unicornObject::makeRandomSaturatedPallet() {
  for (int i = 0; i < 16; i++) {
    currentPalette[i] = CHSV(random8(), 255, 255);
  }
}


void unicornObject::fillBufferPaletteColors(CRGBPalette16 newPalette) {  // Colour index is passed as the starting point for the blending effect
  for (int i = 0; i < NUM_LEDS; i++) {
    ledRing[i] = ColorFromPalette(newPalette, currentIndex, BRIGHTNESS, currentBlending);
    if (ledDirection) {
      currentIndex += hue_steps;  //Motion Speed currentIndex is the COLOUR index, not the LED array Index
    } else {
      currentIndex += hue_steps;  // Tried -= but made more jumps not good.
    }
  }
}

/*
// Fills led buffer from palette
void unicornObject::apply_palette() {
  if (ledDirection) {
    startIndex = startIndex + 1; 
  } else {
    startIndex = startIndex - 1; /  //startIndex is the COLOUR index, not the LED array Index
  }
  // This function currently ignores colour direction updates?!
  FillLEDsFromPaletteColors(startIndex);  // Current Best Method Imogen 23/10/2021
  //  fillLEDS_smoothly(startIndex);     // Smoother way of doing it, hopefully. Also simpler
}

*/