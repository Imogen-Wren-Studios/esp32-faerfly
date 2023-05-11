/* unicornObject Library Example

    Imogen Wren
    30/04/2023

    unicornObject is an attempt to further abstract and simplify lighting shows using the FastLED library

    The Targest is a basic API that can be accessed to trigger a range of different animation types

    There are 3 different factors that affect animations in this library.
    1. The currentPalette, nextPalette and blend speed
        - Affects which colour palettes are used to pick individual hues from
        - Controls how quickly colours swap between palettes
    2. The Local Steps and Global Steps variables, along with refresh speed.
        - Local Steps
          - Controlls how many individual colours from the palette of 255 we can see at any one time
        - Global Steps
          - Controls how quickly the effect moves around the whole palette spectrum
    3. the update/FillBuffer algorithms
        - affects how the palettes are applied to the LEDs


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
autoDelay speedChangeDelay;  // delay for changing framerate and animation speed  NOT USED AT THE MOMENT
autoDelay globalStepsDelay;  // delay for changing number of global steps
autoDelay effectDelay;
autoDelay directionDelay;

unicornObject unicorn;


#define BRIGHTNESS 70
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
  unicorn.setBlendSpeed(255);
  unicorn.setEffect(unicorn.spread);
  unicorn.setDirection(true);
}

#define CHANGE_PALETTE_S 40
#define CHANGE_STEPS random(5, 20)  // this should be random for best effect
int8_t change_steps_delay = 20;
int8_t effects_change_delay = 20;  // going to be set for 20 seconds
int8_t direction_change_delay = 10;

int8_t lastSteps = 1;  // if the last step was 3 or -3 make it reset to 1

void loop() {
  //unicorn.paintRGB(250, 250, 250);   //// Solid Color Wash

  // Changing the effect

  if (effectDelay.secondsDelay(effects_change_delay)) {
    Serial.print("Changing Effect to: ");
    int newEffect = random(3);
    Serial.println(newEffect);
    switch (newEffect) {
      case 0:
        unicorn.setEffect(unicorn.smooth);  // god this is clunky, can we hide the array call inside the method?
        break;
      case 1:
        unicorn.setEffect(unicorn.chase);
        break;
      case 2:
        unicorn.setEffect(unicorn.spread);
        break;
      default:
        unicorn.setEffect(unicorn.smooth);
        break;
    }
  }


  if (directionDelay.secondsDelay(direction_change_delay)) {    // This still only works on chase NOT on smooth GAAH #TODO work out how this can actually work for smooth
    Serial.print("Changing Direction: ");
    bool newDirection;
    if (unicorn.ledDirection) {
      newDirection = false;
    } else {
      newDirection = true;
    }
    Serial.println(newDirection);
    unicorn.setDirection(newDirection);
    direction_change_delay = random(23);
    Serial.print("New Direction Delay: ");
    Serial.println(direction_change_delay);
  }


  // Changing the color steps
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
    unicorn.setGlobalSteps(newStepVal);  // Why was this commented out!?! sheet

    //LocalStep controlls the percentage of the entire palette we see at one time. if there are 256 positions, and 12 LEDs, then by selecting values close to +-20-22 then we will see all the colours at the same time.
    // Smaller numbers will show a smaller proportion of the colours, and larger numbers will give a "patchwork" look as further away indexes will be between close by indexes.
    int8_t newLocalStep = random(-22, 22);
    Serial.print("  newLocalStep: ");
    Serial.println(newLocalStep);
    unicorn.setLocalSteps(newLocalStep);
    lastSteps = newStepVal;
  }



  // Changing Palettes
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
    unicorn.setLocalSteps(21);  // 21 should give entire palette   // Could also change localStep here so we get a preview of the new palette
    if (unicorn.currentEffect == unicorn.smooth) {
      unicorn.setGlobalSteps(1);  // This means both effects types should work
    } else {
      unicorn.setGlobalSteps(20);
    }

    change_steps_delay = 20;  // 4 second preview of new palette?                                        // Make blending really quick so it previews the next colours, the slow mixing of colours is kinda done for this gotta be quicker.
  }


  // Corrupt algorithm


  unicorn.update();
}
