/*

     Library to control a single LED

     Can be used to make simple animations for basic UIs
     Using single LEDs

     Created by Declan Heard. 01/08/2020
     Released into Public Domain.

*/






#ifndef ledObject_h
#define ledObject_h

#if (ARDUINO >=100)
#include <Arduino.h>
#else
#include <wProgram.h>
#endif



#define blinkEvent callBlink     // Set up Synonyms for common functions



class ledObject
{
  public:

    // constructor
    ledObject(int led_pin);


    //Basic Methods

    //    void begin(int ledPin = 13, int initialState = 0);

    void begin(int initialState = 0);

    void turnOn();

    void turnOff();

    void toggleLED();

    void startBlink(long onDuration = 40, long offDuration = 130);                                 // default values allow startBlink() with no arguments. // performBlink must be called in main loop to actuate

    void stopBlink();                                                                                   // Stops any blink events dead.


    // Blink Event Methods
    // Blink events contain a call to set up and performBlink in main loop to carry out the action.
    void callBlink(int numberofBlinks = 2, long onDuration = 40, long offDuration = 130 );    // Default values allow simple callBlink() with no arguments to default to these settings. callBlink(5); single argument only sets number of blinks.

    void performBlink();                                                                      // Must be Called in the main loop if using blink functions. performs the actions of callBlink and StartBlink

    // variables
    bool ledState = LOW;      // stores the state of the LED


    bool blinkActive;     // remains true while blink Event functions are active (and need to be repeated)

    int ledPin;


  private:



    unsigned long currentAction = 0;    // Global variables to hold the time of the current, and the previous timed actions
    unsigned long lastAction = 0;

    int blinkQuantity;              // Global Variables used for blink events
    long blinkOnDuration;
    long blinkOffDuration;





};


/* fadeLED

    Derived class from ledObject

    This class can be used to control
    fading effects using
    an LED attached to PWM pins.

    on arduino uno:
    3~
    5~
    6~
    9~
    10~
    11~



*/


#define updateLED updatePWM          // Set up Synonyms for common functions
#define updateOutput updatePWM

// Precompiler define functions for ESP & AtMega implementations






class fadeLED: public ledObject {

  public:

    //Constructor


#ifdef __AVR__
    fadeLED(int pwm_Pin): ledObject(pwm_Pin),    // Not 100% sure this is correct syntax, we will see
      pwmPin(pwm_Pin)                         // Passed pwm_Pin during constructor now.
    {
    }

#elif defined(ESP8266) || defined(ESP32)
    fadeLED(int pwm_Pin = 2, int led_ch = 0, int freq = 5000, int reso = 8): // Constructor defined by precompiler macro depending on microcontroller environment selected
      ledObject(pwm_Pin),
      pwmPin(pwm_Pin),
      ledCH(led_ch),
      frequency(freq),
      resolution(reso)
    {
    }
#else

#error “Unsupported board selected!”
#endif





    //Methods
    // No begin method as it already exists in ledObject, and the new function
    // doesnt change anything. not true: this does need a begin I think:

    //   void setup(int ledPin = 9, byte startBrightness = 150);    // Set up called once during setup

    void setup(byte startBrightness = 150);     // New setup


    // Methods to control LEDs direction. i.e. without using loop functions

    void updatePWM(byte brightness);                // simple method to update the PWM output directly from a byte input. Can be called without using perform function


    void modifyPWM(int16_t amount = 1);                   // Simple method to add or remove a value from the current LED brightnes. can be called without using perform function

    void hardON();

    void hardOFF();

    void hardToggle();


    // Methods to control LEDS using loop functions

    // Void fade moment and fade event should be able to stop startFading without explicilty calling stopFading


    // Fades led in or out once
    void fadeMoment(byte minimum = 0, byte maximum = 255, int fadeDirection = 2, uint32_t timeMs = 1500);   // Sets up a single fade event

    // Fades
    void fadeEvent(byte minimum = 10 , byte maximum = 200,  int repeats = 4, uint32_t timeMs = 500); // Can be used to fade

    void startFading(byte minBrightness = 10, byte maxBrightness = 150, uint32_t timeMs = 750);

    void stopFading();  // Instantly stops fading

    void fadeOut(byte endBrightness = 0 , uint32_t timeMs = 1000); // fades in or out using the current brightness as a starting positon





    void performFades();            // Method called once per loop to perform any fading actions or events called



    void advancedFade(byte startBrightness, byte endBrightness, uint32_t timeOne, uint32_t timeTwo, int repeats);



    byte ledBrightness;    // global variable to hold the current LED brightness

    byte minBrightness;    // global variables that are updated by event calls

    byte maxBrightness;


    int pulsesRemaining;   // global variable to hold the number of pulses left in a fadeEvent

    uint32_t fadeTimeMs;        // fade time for events to happen over



    enum fadeDirection
    {
      OFF = 0,
      FADE_UP = 1,
      FADE_DOWN = 2
    };

    int fadeState = OFF; // Variable to hold current fadeState from fadeDirection

  private:

    // Methods:

    uint32_t  calculateFade(byte minimum, byte maximum, uint32_t timeMs);     // Method to turn the time passed for a complete Fade in microseconds, and return the interval between
    // "ticks" increasing or decreasing PWM output


    uint32_t interval;   // variable to hold the interval between "ticks" up and down while fading.

    int updatePulses(int pulseNumber);    // method to track the number of fade pulses left.


    bool fadingActive;


    // Constructor Variables
    int pwmPin;
    int ledCH;
    int frequency;
    int resolution;

    uint32_t currentInterval = 0;
    uint32_t lastInterval = 0;   // This needs to be defined before it is used



};









#endif
