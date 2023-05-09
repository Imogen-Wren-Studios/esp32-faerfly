
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
void unicornObject::show() {
  FastLED.show();  // show is called by delay
}

// Update the output with any changes to the buffer
void unicornObject::update() {
  unicornObject::fillBufferPaletteColors();
  // n blend towards pallet
  nblendPaletteTowardPalette(currentPalette, nextPalette, blendSpeed);  // This updates currentPalette with colours from nextPalette so it acts on the currentPalette variable
  FastLED.show();                                                       // show is called by delay
  FastLED.delay(1000 / updates_per_second);                             // This isnt doing its job here Why are animations running so fast?? is it because of faster processor on ESP?
}


// This function returns palette with totally random saturated colors.
CRGBPalette16 unicornObject::makeRandomSaturatedPallet() {
  CRGBPalette16 newPalette;
  for (int i = 0; i < 16; i++) {
    uint8_t newHueIndex = random8();
    Serial.print("New HSV Colour: ");
    unicornObject::printNameHSV(newHueIndex, 255, 255);
    newPalette[i] = CHSV(newHueIndex, 255, 255);
  }
  return newPalette;
}

// This function returns palette with totally random unsaturated colors.
CRGBPalette16 unicornObject::makeRandomPastelPallet() {
  CRGBPalette16 newPalette;
  for (int i = 0; i < 16; i++) {
    uint8_t newHueIndex = random8();
    uint8_t newSatVal = random8();
    Serial.print("New HSV Colour: ");
    unicornObject::printNameHSV(newHueIndex, newSatVal, 255);
    newPalette[i] = CHSV(newHueIndex, newSatVal, 255);
  }
  return newPalette;
}


/*

To make this pattern work correctly the following numbers need to be passed somehow.

globalIndex = n
localIndex = n + (iterate over each LED to a max value of n + NUM_LEDS)

over the next run through value passed are

globalIndex = n + 1



*/
void unicornObject::fillBufferPaletteColors() {
  uint8_t localIndex = globalIndex;
  globalIndex += g_step;  // this value could be changed programatically later
  for (int i = 0; i < NUM_LEDS; i++) {
    ledRing[i] = ColorFromPalette(currentPalette, localIndex, currentBrightness, currentBlending);
    if (ledDirection) {
      localIndex += l_step;  //Motion Speed currentIndex is the COLOUR index, not the LED array Index
    } else {
      localIndex += l_step;  // Tried -= but made more jumps not good.
    }
  }
}


// This is wrong but shouldnt be broken just not worthwhile
void unicornObject::fillBufferSmooth(int16_t speed) {

  if (colorDelay.millisDelay(speed)) {
    unicornObject::fillBufferPaletteColors();  // this is now likely wrong but compiles. does this function even needed if fill buffer is fixed? we can name nicer later
  }
}


// Public Methods


void unicornObject::setBrightness(uint8_t brightness) {
  currentBrightness = brightness;
  FastLED.setBrightness(brightness);
}

// Pass low values for best effect
void unicornObject::setGlobalSteps(int8_t newGlobalSteps) {
  // This should probably limit inputs at the very least
  g_step = newGlobalSteps;
}

void unicornObject::setLocalSteps(int8_t newLocalSteps) {
  // This should probably limit inputs at the very least
  l_step = newLocalSteps;
}


void unicornObject::setNextPalette(CRGBPalette16 newPalette) {
  nextPalette = newPalette;
}



void unicornObject::printNameHSV(uint8_t hue, uint8_t saturation, uint8_t value) {  // This is not that accurate could be dialed in slighty
  uint8_t index = map(hue, 0, 255, 0, 16);                                          //#TODO This was 16
  char buffer[128];
  char colorMod[12] = { " " };
  if (saturation < 150) {
    sprintf(colorMod, "%s", "Pastel");
  }
  sprintf(buffer, "Hue Index: %3i, Sat: %3i Name Index: %3i, Colour Name: %s %s", hue, saturation, index, colorMod, colorNames[index]);  //colorMod,
  Serial.println(buffer);
}

void unicornObject::printColorName(colorEnum index) {
  Serial.print("Colour Name: ");
  Serial.println(colorNames[index]);
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


void unicornObject::introAnimation(uint8_t initBrightness) {
  /*
  for (int i = 0; i < 25; i++) {
  unicorn.paintHSV(HUE_INIT + 10*i, SAT_INIT, VAL_INIT);
  unicorn.printNameHSV(HUE_INI + 10*i, SAT_INIT, VAL_INIT);
  unicorn.update();
  delay(10000);
} */
  int i = 0;
  while (i < 440) {
    unicornObject::paintHSV(i, 255, initBrightness);
    //   unicorn.printNameHSV(i, SAT_INIT, VAL_INIT);
    unicornObject::show();
    delay(4);
    i = i + 1;
  }
  unicornObject::paintHSV(0, 0, initBrightness);
  unicornObject::show();
  delay(15);
  i = 255;
  while (i > 0) {
    unicornObject::paintHSV(0, 0, i);
    unicornObject::show();
    i = i - 1;
    delay(4);
  }
  delay(15);
}
