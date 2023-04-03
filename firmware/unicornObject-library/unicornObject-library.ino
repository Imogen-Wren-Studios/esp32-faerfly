
#include <autoDelay.h>



#include "unicornObject.h"
unicornObject unicorn;
//#include "pridePalettes.h"



#define UPDATES_PER_SECOND 30
#define HUE_STEPS 5  // Number of steps to advance through palette between each for loop. Origionally 3




#define START_PALETTE RainbowColors_p  // Sterile while palette to start with
#define SECOND_PALETTE trans





void setup() {
  Serial.begin(115200);
  unicorn.setup();
  unicorn.currentPalette = START_PALETTE;
  unicorn.nextPalette = SECOND_PALETTE;
  unicorn.paintRGB(0, 255, 0);
  delay(500);
}

void loop() {
  //unicorn.paintRGB(250, 250, 250);
//  nblendPaletteTowardPalette(currentPalette, nextPalette, ANIMATION_BLEND_SPEED);  

 // unicorn.fillBufferPaletteColors(START_PALETTE);

  unicorn.update();
}
