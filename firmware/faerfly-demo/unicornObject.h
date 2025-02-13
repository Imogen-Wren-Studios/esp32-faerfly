/*
 Unicorn Object.

 A Library to handle ws2812b lighting FX using OOP

*/


#ifndef unicornObject_h
#define unicornObject_h

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <wProgram.h>
#endif

#include <FastLED.h>
#include "pridePalettes.h"
#include "colorPalettes.h"


#include <autoDelay.h>



//#include "pridePalettes.h"
//#include "colorPalettes.h"

#define LED_PIN 5
#define NUM_LEDS 12

#define LED_TYPE WS2811
#define COLOR_ORDER GRB

#define UPDATES_PER_SECOND 30
#define HUE_STEPS 1  // Number of steps to advance through palette between each for loop. Origionally 3

#define ANIMATION_BLEND_SPEED 128
#define NORMAL_BLEND_SPEED 2


// I would love to try and initialise a unicorn object with the variables to create an fastLED object, however
// I cannot find a way of getting the variables needed into the right format for compile time assignment.
// Only solution is #DEFINE  in header for these variables

class unicornObject {
public:



  //Constructor


  autoDelay colorDelay;

  CRGBArray<NUM_LEDS> ledRing;




  unicornObject()
  // tell FastLED about the LED strip configuration
  {
  }



  // Methods

  void begin();

  void paintRGB(uint8_t red, uint8_t green, uint8_t blue);

  void paintHSV(uint8_t hue, uint8_t saturation, uint8_t value);

  void update();

  void setBrightness(uint8_t brightness =  255);

  void changeHueSteps(uint8_t newHueSteps = 1);   // No method written yet might not need it looks good as is

  CRGBPalette16 makeRandomSaturatedPallet();

  CRGBPalette16 currentPalette;
  TBlendType currentBlending = LINEARBLEND;

  CRGBPalette16 nextPalette;

  bool ledDirection = true;


  void fillBufferPaletteColors(uint8_t colorIndex);

  void fillBufferSmooth(int16_t speed);

  uint8_t currentIndex = 0;  // make this private once moved everything into class

 int hue_steps = 1; // Make this private once everything hidden in class

/*
char c_red[12] = {"red"};

  char colorNames[18][12] = { "red", "red-orange", "orange", "yellow-orange", "yellow", "lime-green", "green", "blue-green", "cyan", "sky-blue", "blue", "dark-blue", "mouve", "purple", "pink", "white" };

  enum colorEnum {
    RED,
    RED_ORANGE,
    ORANGE,
    YELLOW_ORANGE,
    YELLOW,
    LIME_GREEN,
    GREEN,
    BLUE_GREEN,
    CYAN,
    SKY_BLUE,
    BLUE,
    DARK_BLUE,
    MOUVE,
    PURPLE,
    PINK,
    WHITE
  };
 
 colorEnum colorName = RED;

void printColorName(int colorName);
*/



private:

  CRGBPalette16 paletteBuffer;  // empty pallette can be used for moving palettes around if needed (try not to use - use local variable insread)

 
  uint32_t hue_shift_timing = 5000;

  uint8_t blendSpeed = 2;

  uint8_t currentBrightness = 255;






  uint8_t updates_per_second = 30;

  int dataPin = 5;
};




#endif
