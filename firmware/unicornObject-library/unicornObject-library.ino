/* unicornObject Library Example

    Imogen Wren
    30/04/2023

    unicornObject is an attempt to further abstract and simplify lighting shows using the FastLED library

    The Targest is a basic API that can be accessed to trigger a range of different animation types


*/

/*
// FastLED definitions MUST come before #include "unicornObject.h"
#define LED_PIN 5
#define NUM_LEDS 12

#define LED_TYPE WS2811
#define COLOR_ORDER GRB

#define UPDATES_PER_SECOND 30
#define HUE_STEPS 1  // Number of steps to advance through palette between each for loop. Origionally 3

#define ANIMATION_BLEND_SPEED 128
#define NORMAL_BLEND_SPEED 2
*/

#include "unicornObject.h"




//#define START_PALETTE RainbowColors_p  // Sterile while palette to start with

using namespace pridePalettes;

#define START_PALETTE pridePalettes::lesbian
#define SECOND_PALETTE pridePalettes::lesbian


#include <autoDelay.h>

autoDelay paletteDelay;      // delay for swapping palettes
autoDelay speedChangeDelay;  // delay for changing framerate and animation speed
autoDelay globalStepsDelay;  // delay for changing number of global steps

unicornObject unicorn;


#define BRIGHTNESS 140

#define HUE_INIT 0
#define SAT_INIT 255
#define VAL_INIT BRIGHTNESS


CRGBPalette16 prideArray[11] = {
  pridePalettes::pride,
  pridePalettes::lesbian,
  pridePalettes::gay,
  pridePalettes::bisexual,
  pridePalettes::enby,
  pridePalettes::trans,
  pridePalettes::ace,
  pridePalettes::aero,
  pridePalettes::inter,
  pridePalettes::demi,
  pridePalettes::queer
};


char prideNames[][11] = {
  "pride",
  "lesbian",
  "gay",
  "bisexual",
  "enby",
  "trans",
  "ace",
  "aero",
  "inter",
  "demi",
  "queer"
};

void setup() {
  Serial.begin(115200);
  unicorn.begin();
  unicorn.currentPalette = START_PALETTE;
  unicorn.nextPalette = SECOND_PALETTE;
  unicorn.setBrightness(BRIGHTNESS);
  unicorn.introAnimation(BRIGHTNESS);
}

#define CHANGE_PALETTE_S 40
#define CHANGE_STEPS random(5, 20)  // this should be random for best effect
int8_t change_steps_delay = 20;


int8_t lastSteps = 1;  // if the last step was 3 or -3 make it reset to 1

void loop() {
  //unicorn.paintRGB(250, 250, 250);   //// Solid Color Wash



  // if (paletteDelay.secondsDelay(CHANGE_PALETTE_S)) {            // After set time, save next palette into currentPalette ! I dont think this is neededm nBlend means that currentPalette already had all of the colours from the last nextPalette
  //   unicorn.currentPalette = unicorn.nextPalette;               // Then fill nextPalette with a predefined palette, or a random palette
  //   unicorn.nextPalette = unicorn.makeRandomSaturatedPallet();  // Make this a function instead of updating a variable
  /// Serial.println("Making New Random Palette");
  // }

  // steps_delay controlls the speed of the animations. They are controlled to not go too fast, or at least if they go fast to turn back to slow quickly
  if (globalStepsDelay.secondsDelay(change_steps_delay)) {
    int8_t newStepVal = random(-4, 4);
    change_steps_delay = random(5, 30);
    if (lastSteps > 1 || lastSteps < -1) {  // force it into slower animations more frequently // this is junk but written quickly
      newStepVal = 1;
    }
    if (newStepVal > 2 || newStepVal < -2) {
      change_steps_delay = random(1, 4);
    }
    if (newStepVal == 0) {
      change_steps_delay = random(1, 2);
    }
    Serial.print("  New seconds delay: ");
    Serial.print(change_steps_delay);
    Serial.print("  newGlobalStepVal : ");
    Serial.print(newStepVal);
    //unicorn.setGlobalSteps(newStepVal);

    //LocalStep controlls the percentage of the entire palette we see at one time. if there are 256 positions, and 12 LEDs, then by selecting values close to +-20-22 then we will see all the colours at the same time. 
    // Smaller numbers will show a smaller proportion of the colours, and larger numbers will give a "patchwork" look as further away indexes will be between close by indexes.
    int8_t newLocalStep = random(-22, 22);
    Serial.print("  newLocalStep: ");
    Serial.println(newLocalStep);
    unicorn.setLocalSteps(newLocalStep);
    lastSteps = newStepVal;
  }

  if (paletteDelay.secondsDelay(CHANGE_PALETTE_S)) {
    Serial.print("Changing Palette to: ");
    Serial.println();
    uint8_t palettePicker = random(0, 13);
    if (palettePicker == 13 || palettePicker == 11) {
      Serial.println("Random Saturated Palette");
      unicorn.setNextPalette(unicorn.makeRandomSaturatedPallet());
    } else if (palettePicker == 12) {
      Serial.println("Random Pastel Palette");
      unicorn.setNextPalette(unicorn.makeRandomPastelPallet());
    } else {
      Serial.print("Pride Palette: ");
      Serial.print(palettePicker);
      unicorn.setNextPalette(prideArray[palettePicker]);
      Serial.print(" ");
      Serial.println(prideNames[palettePicker]);
    }
  }


// NEXT FUNCTION CHANGE BLEND SPEED


  unicorn.update();
}
