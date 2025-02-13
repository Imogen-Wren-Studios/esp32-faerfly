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


// Moved to .ino page. these MUST go before include for unicornObject library
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

  void introAnimation(uint8_t initBrightness = 255);

  void paintRGB(uint8_t red, uint8_t green, uint8_t blue);

  void paintHSV(uint8_t hue, uint8_t saturation, uint8_t value);

  void show();  // Show the contents of the buffer

  void update();  // Do all nessisary updates for palettes (later this should be changed to updatePalettes or some method should work out what state we are in)

  void setBrightness(uint8_t brightness = 255);

  void setGlobalSteps(int8_t newGlobalSteps = 1);  // sets how far the global index steps through each loop (typical is 1)

  void setLocalSteps(int8_t newLocalSteps = 1);  /// does not (Have) to be positive number

  void setBlendSpeed(uint8_t newBlendSpeed = 2);  // Sets how many colours are blended from newPalette into currentPallette each time (16 max or 255 max?)

  // This is stupid there is a better way of doing this. This complicates things does not make it easier
  enum effect {
    smooth,
    chase,
    spread,
    drop
  };

  // int effectArray[3] = {smooth, chase, spread};

  void setEffect(effect newEffect = smooth);

  void setDirection(bool newDirection = true);

  //  void addCorruption(uint8_t width, CHSV(0,0,255));   // No Idea if this will work

  void setNextPalette(CRGBPalette16 newPalette);

  void setFrameRate(uint16_t frameRate = 30);  // 30 default value

  CRGBPalette16 makeRandomSaturatedPallet();

  CRGBPalette16 makeRandomPastelPallet();

  CRGBPalette16 currentPalette;
  TBlendType currentBlending = LINEARBLEND;

  CRGBPalette16 nextPalette;








  void printNameHSV(uint8_t hue, uint8_t saturation, uint8_t value);

  // uint8_t currentIndex = 0;  // make this private once moved everything into class // Being replaced entirely with globalIndex

  uint8_t globalIndex = 0;  // variable to track the global starting point for new hue update

  // int hue_steps = 1;  // Make this private once everything hidden in class


  char red_s[16] = "red";
  char red_o_s[16] = "red-orange";
  char orange_s[16] = "orange";
  char yellow_o_s[16] = "yellow-orange";
  char yellow_s[16] = "yellow";
  char lime_s[16] = "lime-green";
  char green_s[16] = "green";
  char blue_g_s[16] = "blue-green";
  char cyan_s[16] = "cyan";
  char sky_s[16] = "sky-blue";
  char blue_s[16] = "blue";
  char darkblue_s[16] = "dark-blue";
  char mouve_s[16] = "mouve";
  char purple_s[16] = "purple";
  char pink_s[16] = "pink";
  char hotpink_s[16] = "hot-pink";
  char redpink_s[16] = "red-pink";

  char *colorNames[17] = {
    red_s,
    red_o_s,
    orange_s,
    yellow_o_s,
    yellow_s,
    lime_s,
    green_s,
    blue_g_s,
    cyan_s,
    sky_s,
    blue_s,
    darkblue_s,
    mouve_s,
    purple_s,
    pink_s,
    hotpink_s,
    redpink_s
  };

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
    HOT_PINK,
    RED_PINK
  };

  colorEnum colorName = RED;

  void printColorName(colorEnum index);

  void printColorName(int colorName);



  effect currentEffect = smooth;


  // These should be made private when possible (public for testing)

  bool ledDirection = true;

  int16_t animateCycle = 0;  // Tracks the cycle of the animation cycle will always be less than NUM_LEDS
private:

  // Used for different effects lighting
  void fillBufferSmooth();
  void fillBufferChase();
  void fillBufferSpread();
  void fillBufferDrops();

  CRGBPalette16 paletteBuffer;  // empty pallette can be used for moving palettes around if needed (try not to use - use local variable insread)

int16_t loopIndex(int16_t ledIndex);  // Used to check if ledIndex is out of bounds and loop back around to the start or end

  uint32_t hue_shift_timing = 5000;

  uint8_t blendSpeed = 2;

  uint8_t currentBrightness = 255;

  int16_t g_ledIndex = 0;  // used in chase effect to track the current LED

  // Track location of drops starting LED

  int16_t animateLed = 0;





  int8_t g_step = 1;  // global step variable modifyer (advance this much through palette array every loop though ALL LEDs)
  int8_t l_step = 1;  // local step variable modifyer (advance this much through palette array for each LED in string);


  uint8_t updates_per_second = 30;
  int dataPin = 5;
};




#endif
