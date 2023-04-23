



#include "unicornObject.h"
<<<<<<< HEAD
=======
unicornObject unicorn;
//#include "pridePalettes.h"



#define UPDATES_PER_SECOND 30
#define HUE_STEPS 5  // Number of steps to advance through palette between each for loop. Origionally 3


>>>>>>> aed9e8b1bd6262c663b5d1dece955dd8eafa3b6f

#include "pridePalettes.h"

#define START_PALETTE RainbowColors_p  // Sterile while palette to start with
#define SECOND_PALETTE trans






unicornObject unicorn;



void setup() {
  Serial.begin(115200);
<<<<<<< HEAD
  unicorn.begin();
  unicorn.currentPalette = START_PALETTE;
 // unicorn.nextPalette = SECOND_PALETTE;
  unicorn.paintRGB(255, 255, 0);
  
=======
  unicorn.setup();
  unicorn.currentPalette = START_PALETTE;
  unicorn.nextPalette = SECOND_PALETTE;
  unicorn.paintRGB(0, 255, 0);
>>>>>>> aed9e8b1bd6262c663b5d1dece955dd8eafa3b6f
  delay(500);
}

void loop() {
  //unicorn.paintRGB(250, 250, 250);
  //  nblendPaletteTowardPalette(currentPalette, nextPalette, ANIMATION_BLEND_SPEED);

<<<<<<< HEAD
  unicorn.fillBufferSmooth(START_PALETTE, 1000);
=======
 // unicorn.fillBufferPaletteColors(START_PALETTE);
>>>>>>> aed9e8b1bd6262c663b5d1dece955dd8eafa3b6f

  unicorn.update();
}
