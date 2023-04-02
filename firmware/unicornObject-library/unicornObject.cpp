

#include "unicornObject.h"




void unicornObject::setup() {

  //Serial.begin(115200);

  // Serial.println("Gathering Spectrum...");
  delay(1000);  // power-up safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(ledRing, NUM_LEDS).setCorrection(TypicalLEDStrip);
  // Serial.println("...Processing Light Threads...");
  FastLED.setBrightness(BRIGHTNESS);

  randomSeed(analogRead(0));  // psudo random number generator for randomness & chaos

  ledRing(0, 9) = CHSV(255, 255, 0);

  // Serial.println("               Weaving Colours...  \n     ...Selecting Pigments\n");
  delay(500);
  //  Serial.println("Chroma Paintbrush Initialised:  Luminescence Matrix Applied.\n Starting Visual Light Imbument\n ");


  FastLED.show();
}