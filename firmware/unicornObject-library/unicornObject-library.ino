



#include "unicornObject.h"


//#include "pridePalettes.h"

#define START_PALETTE RainbowColors_p  // Sterile while palette to start with
#define SECOND_PALETTE trans


#include <autoDelay.h>

autoDelay paletteDelay;
unicornObject unicorn;


#define BRIGHTNESS 150

#define HUE_INIT 0
#define SAT_INIT 255
#define VAL_INIT 255

void setup() {
  Serial.begin(115200);
  unicorn.begin();
  unicorn.currentPalette = START_PALETTE;
  unicorn.nextPalette = SECOND_PALETTE;
  unicorn.setBrightness(BRIGHTNESS);
  /*
  for (int i = 0; i < 25; i++) {
  unicorn.paintHSV(HUE_INIT + 10*i, SAT_INIT, VAL_INIT);
  unicorn.printNameHSV(HUE_INI + 10*i, SAT_INIT, VAL_INIT);
  unicorn.update();
  delay(10000);
} */
  int i = 0;
  while (i < 440) {
    unicorn.paintHSV(i, SAT_INIT, VAL_INIT);
    //   unicorn.printNameHSV(i, SAT_INIT, VAL_INIT);
    unicorn.show();
    delay(4);
    i = i + 1;
  }
  unicorn.paintHSV(0, 0, VAL_INIT);
  unicorn.show();
  delay(15);
  i = 255;
  while (i > 0) {
    unicorn.paintHSV(0, 0, i);
    unicorn.show();
    i = i - 1;
    delay(4);
  }
  delay(15);
}

#define CHANGE_PALETTE_S 60


void loop() {
  //unicorn.paintRGB(250, 250, 250);



  if (paletteDelay.secondsDelay(CHANGE_PALETTE_S)) {            // After set time, save next palette into currentPalette ! I dont think this is neededm nBlend means that currentPalette already had all of the colours from the last nextPalette
    unicorn.currentPalette = unicorn.nextPalette;               // Then fill nextPalette with a predefined palette, or a random palette
    unicorn.nextPalette = unicorn.makeRandomSaturatedPallet();  // Make this a function instead of updating a variable
                                                                /// Serial.println("Making New Random Palette");
  }



  unicorn.fillBufferPaletteColors();
  // unicorn.fillBufferSmooth(30);   // attempt to slow down animations but I do not think it is correct

  unicorn.update();
}
