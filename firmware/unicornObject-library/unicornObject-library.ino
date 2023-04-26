



#include "unicornObject.h"


//#include "pridePalettes.h"

#define START_PALETTE RainbowColors_p  // Sterile while palette to start with
#define SECOND_PALETTE trans






unicornObject unicorn;



void setup() {
  Serial.begin(115200);

  unicorn.begin();
  unicorn.currentPalette = START_PALETTE;
  // unicorn.nextPalette = SECOND_PALETTE;
  unicorn.paintRGB(255, 255, 0);

  delay(500);
  unicorn.setBrightness(50);
}




void loop() {
  //unicorn.paintRGB(250, 250, 250);


  //unicorn.fillBufferSmooth(START_PALETTE,100);

  unicorn.fillBufferPaletteColors();


  unicorn.update();
}
