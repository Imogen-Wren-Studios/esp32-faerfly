



#include "unicornObject.h"


//#include "pridePalettes.h"

#define START_PALETTE RainbowColors_p  // Sterile while palette to start with
#define SECOND_PALETTE trans


#include <autoDelay.h>

autoDelay paletteDelay;




unicornObject unicorn;



void setup() {
  Serial.begin(115200);
  unicorn.begin();
  unicorn.currentPalette = START_PALETTE;
  unicorn.nextPalette = SECOND_PALETTE;
  unicorn.setBrightness(50);
  unicorn.paintRGB(255, 255, 0);
  // delay(500);
  
}

#define CHANGE_PALETTE_S 30


void loop() {
  //unicorn.paintRGB(250, 250, 250);



  if (paletteDelay.secondsDelay(CHANGE_PALETTE_S)) {            // After set time, save next palette into currentPalette
    unicorn.currentPalette = unicorn.nextPalette;               // Then fill nextPalette with a predefined palette, or a random palette
    unicorn.nextPalette = unicorn.makeRandomSaturatedPallet();  // Make this a function instead of updating a variable
  }

  unicorn.currentIndex = unicorn.currentIndex + unicorn.hue_steps;   // this should all be hidden inside class

  unicorn.fillBufferPaletteColors(unicorn.currentIndex);
  // unicorn.fillBufferSmooth(30);   // attempt to slow down animations but I do not think it is correct

  unicorn.update();
}
