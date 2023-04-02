/*
 Unicorn Object.

 A Library to handle ws2812b lighting FX using OOP


*/



#ifndef unicornObject_h
#define unicornObject_h

#if (ARDUINO >=100)
#include <Arduino.h>
#else
#include <wProgram.h>
#endif

#include <FastLED.h>
#define LED_PIN 5
#define NUM_LEDS 8
#define BRIGHTNESS 255
#define LED_TYPE WS2811
#define COLOR_ORDER GRB
CRGBArray<NUM_LEDS> leds;
uint8_t updates_per_second = 30;



class unicornObject {

  public:

    // Constructor

  public:

    int total_leds;

    CRGBArray<TOTAL_LEDS> ledRing;

    //Constructor

    unicornObject(int number_leds, int data_pin):

      total_leds((number_digits * leds_per_segment) + extra_leds),
      ledString()
      // tell FastLED about the LED strip configuration

    {
    }



    unicornObject(int ledDataPin):
      dataPin(ledDataPin)
    {

    }

    // Methods

    void begin();

    uint8_t sampleADC();

    uint8_t deriveButton();     // Derives which button has been pushed based on analog vaule   // This replaces detectButton

    uint8_t buttonArray();

    uint8_t tinyButtonLoop();

  private:

    int dataPin = 5;
    uint8_t buttonStates[4];            // Stores the recent history of the button - Private as no need to access this outside of library (hmmmm)

};




#endif
