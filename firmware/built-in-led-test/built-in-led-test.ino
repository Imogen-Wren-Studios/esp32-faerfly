/*----------------- ESP_fadeLED_example --  -------

  Example showing how to use ledObject and fadeLED 
  with ESP32 Microcontrollers


     Created by Wren. 05/01/2021
     Released into Public Domain.

*/


#include "ledObject.h"


//#include <autoDelay.h>                            // Not used for any LED functions ( though ledObject borrows from topology) // Only used for demo functions
// available @ https://github.com/PanGalacticTech/autoDelay_Library

//autoDelay basicDelay;                 // Set up instance of autoDelay




// LEDs attached to PWM capable pins can use fadeLED object (they can also use all the flashing functions from ledObject)

// Naming objects one by one.
/*
  fadeLED fadeLED3(3);                    // Set up instance of fade LED (1 for each fading LED - Must be passed PWM capable pin)
  fadeLED fadeLED5(5);                    // Set up instance of fade LED (1 for each fading LED - Must be passed PWM capable pin)
  fadeLED fadeLED6(6);                    // Set up instance of fade LED (1 for each fading LED - Must be passed PWM capable pin)
  fadeLED fadeLED9(9);                    // Set up instance of fade LED (1 for each fading LED - Must be passed PWM capable pin)
  fadeLED fadeLED10(10);                    // Set up instance of fade LED (1 for each fading LED - Must be passed PWM capable pin)
  fadeLED fadeLED11(11);                    // Set up instance of fade LED (1 for each fading LED - Must be passed PWM capable pin)
*/

// Or can be done all in one go.
//fadeLED fade[6] = {fadeLED(3), fadeLED(5), fadeLED(6), fadeLED(9), fadeLED(10), fadeLED(11)};  // Set up an array of fade objects. Each LED is passed a PWM capable output pin







#define PWM_PIN 23
#define LED_CH  0
#define PWM_FREQ 5000
#define PWM_RESO 8                                 // No of Bits, 8 = byte = 255 steps 


fadeLED led(PWM_PIN, LED_CH, PWM_FREQ, PWM_RESO);   // Constructor for ESP Boards Includes (PIN, CHANNEL, PWM FREQUENCY, RESOLUTION)

#define NANO_LED_PIN 11

//fadeLED led(NANO_LED_PIN);                             // Constructor for AVR (AtMega) Boards arguments(pin number)


#define INITIAL_BRIGHTNESS 50     //defines a starting brightness for fadeLED object. byte value from 0 - 255 valid

#define MIN_BRIGHT 10
#define MAX_BRIGHT 255
#define TIME_MS  400



void setup() {


  // Fading LED Examples

  led.setup(INITIAL_BRIGHTNESS);                                 // Begin fadeLED library by passing the starting brightness. (default 150 if not passed any arguments)
  // this can be done one by one

  // or we can iterate through the array if we have called the objects using an array structure:

  /*
    for (int i = 0; i < NUM_FADERS; i++) {

      fade[i].setup(INITIAL_BRIGHTNESS);
      fade[i].startFading(0, 255, random(1, 1000));                                     // Calls a fade event that continues untill stopped (min brightness, max brightness, fadetime mS); feeding random numbers for some chaos
    }

  */




  led.startFading(MIN_BRIGHT, MAX_BRIGHT, TIME_MS);     //(min brightness, max brightness, fadetimeMilliseconds)       // Timing may not be accurate at really short delay times, but function has been confirmed down to 1ms delay with slow motion video.
  // Some low value arguments may not produce visible results.

  //.startFading();   //if no arguments are passed - default values 10, 50 500

  //.fadeMoment(0, 250, ledTwo.FADE_DOWN, 4000 );    // Sets up a Single Fade moment passed arguments (defaults) (min = 0, max = 255, direction = FADE_DOWN, timeMs=1500)

  //.fadeEvent(0, 250, 4, 300 );                 // sets up repeating fade event (min, max, number of cycles, timeMs)



}









void loop() {




  

  // .stopFading();                             // any fade events must be stopped before blink events can be called.
  //  .blinkEvent(4, 200, 200);



  //  .fadeOut();                   // fade LED to black argument(fadeOut_time milliseconds);

  // fade events will take precidence over blink events


  // .turnOff();                    // turn the LED off instantly





  // performBlink() & performFades() must run through every loop for every object. Avoid using delay() functions in the rest of the code as it will interrupt the function of these libraries.
  // for delay() free code see autoDelay.h library @ https://github.com/PanGalacticTech/autoDelay_Library







  led.performFades();        // PerformFade events, also performs blink events.



}
