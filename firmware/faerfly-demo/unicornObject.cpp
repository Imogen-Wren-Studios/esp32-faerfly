
//#include <FastLED.h>
#include "unicornObject.h"




void unicornObject::begin() {
  // Serial.println("Gathering Spectrum...");
  delay(1000);  // power-up safety delay


  // ledRing = new CRGB[num_leds];

  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(ledRing, NUM_LEDS).setCorrection(TypicalLEDStrip);

  //FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(ledRing, NUM_LEDS).setCorrection(TypicalLEDStrip);
  // Serial.println("...Processing Light Threads...");
  FastLED.setBrightness(currentBrightness);
  randomSeed(analogRead(0));  // psudo random number generator for randomness & chaos
  ledRing(0, NUM_LEDS - 1) = CHSV(255, 255, 0);
  // Serial.println("               Weaving Colours...  \n     ...Selecting Pigments\n");
  //  Serial.println("Chroma Paintbrush Initialised:  Luminescence Matrix Applied.\n Starting Visual Light Imbument\n ");
  FastLED.show();
 // delay(500);
}



void unicornObject::paintRGB(uint8_t red, uint8_t green, uint8_t blue) {
  ledRing(0, NUM_LEDS - 1) = CRGB(red, green, blue);
}

void unicornObject::paintHSV(uint8_t hue, uint8_t saturation, uint8_t value) {
  ledRing(0, NUM_LEDS - 1) = CHSV(hue, saturation, value);
}



// Update the output with any changes to the buffer
void unicornObject::update() {
  // n blend towards pallet
  nblendPaletteTowardPalette(currentPalette, nextPalette, blendSpeed);  // This updates currentPalette with colours from nextPalette so it acts on the currentPalette variable
  FastLED.show();   // show is called by delay
  FastLED.delay(1000 / updates_per_second);  // This isnt doing its job here Why are animations running so fast?? is it because of faster processor on ESP?
}


// This function returns palette with totally random saturated colors.
CRGBPalette16 unicornObject::makeRandomSaturatedPallet() {
    CRGBPalette16 newPalette;
  for (int i = 0; i < 16; i++) {
    newPalette[i] = CHSV(random8(), 255, 255);
  }
  return newPalette;
}


void unicornObject::fillBufferPaletteColors(uint8_t colorIndex) {
  for (int i = 0; i < NUM_LEDS; i++) {
    ledRing[i] = ColorFromPalette(currentPalette, colorIndex, currentBrightness, currentBlending);
    if (ledDirection) {
      colorIndex += 1;  //Motion Speed currentIndex is the COLOUR index, not the LED array Index
    } else {
      colorIndex += 1;  // Tried -= but made more jumps not good.
    }
  }
}


// This is wrong but shouldnt be broken just not worthwhile
void unicornObject::fillBufferSmooth(int16_t speed) {

  if (colorDelay.millisDelay(speed)) {
    unicornObject::fillBufferPaletteColors(currentIndex);   // this is now likely wrong but compiles. does this function even needed if fill buffer is fixed? we can name nicer later
  }
}

void unicornObject::setBrightness(uint8_t brightness) {
  currentBrightness = brightness;
  FastLED.setBrightness(brightness);
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
