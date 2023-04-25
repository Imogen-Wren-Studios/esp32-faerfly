# ledObject *(V2.0.0)*
#### Built and maintained by [Imogen Wren](mailto:pangalactictech@gmail.com "Email me!") on behalf of [Pan Galactic Tech](https://PanGalacticTech.com)

## Features
* Object Orientated library for controling single LEDs.
* Seperate class defintions for "blink" (digital) and "fade" (PWM) LED outputs.
* Set up LED blink & fade behaviour without dealing with any delay() functions and the problems this causes.
* fadeLED inherets all functions from ledObject (blink) LEDs.
* Call blink or fade events which count down a specific number of ledEvents before ending.
* Set up blinks and fades that continue until stop method is called.
* Functions work with both AVR (ATmega) / Arduino Boards & ESP32/8266 Espressif Microcontrollers.
* Call as many constructors as needed, each one controls a single LED, but many can be stacked and accessed as object arrays.

___________________________________________________________________________________________________________

## Getting Started
### Deployment
1. Clone or Download library folder into Arduino IDE libraries folder.
2. Extract files from zipped folder if required.
3. Open Arduino IDE and select from example programs.

### Dependencies
No dependency for library function, however examples have the following dependencies:
* autoDelay_library available from [here](https://github.com/PanGalacticTech/autoDelay_Library) - written by PanGalacticTech
___________________________________________________________________________________________________________

## Use:

### Precompiler Requirements:

`#include <ledObject.h>   // Libary include N.B.This includes both ledObject & fadeLED classes ` <br> <br>


#### <u>AVR</u>
Define the LED pin and the initial state.

`#define LED_PIN 9                         // Define LED pin. If undefined - defaults to pin 13.` <br>
`#define INITIAL_STATE 1                  // Defines if LED pin starts with initial state ON or OFF - defaults to OFF` <br> <br>

#### <u>ESP32 / espressif</u>
For ESP32 & espressif boards, additional variables are required for setup.

`#define PWM_PIN 2                       // PWM drive capable pin`   <br>
`#define LED_CH  0                        // PWM Channel (ESP32 up to 16 channels total)`  <br>
`#define PWM_FREQ 5000                    // PWM Frequency (Hz)`    <br>
`#define PWM_RESO 8                       // PWM Resolution (bits)`   <br> <br>

___________________________________________________________________________________________________________

### Object Constructors

#### <u>AVR</u>
Declaring a blink LED object:

`ledObject led(LED_PIN) `<br> <br>

Declaring a fade LED object:

`fadeLED led(LED_PIN);      		// Note: LED_PIN must be PWM capable pin`<br> <br>

#### <u>ESP32 / espressif</u>
Declaring a fade LED object:

`fadeLED led(PWM_PIN, LED_CH, PWM_FREQ, PWM_RESO);      // ESP32 Requires 4 arguments for constructor`<br> <br>

<br>

___________________________________________________________________________________________________________

### Setup Functions:
Setup function for Blink LEDs pass the initial state as an argument. Defaults to off.

`led.begin(INITIAL_STATE);`<br> <br>

Setup function for Fade LEDs pass the initial brightness as an argument. Default is 150

`led.begin(INITIAL_BRIGHTNESS);`<br> <br>

<br>

___________________________________________________________________________________________________________

### Loop Functions:

Call performBlink() or PerformFade(); on LED objects to set the output pins.
This method should be called in main loop for each ledObject or fadeLED object. 

For blink objects <br>
`led.performBlink();`<br> <br>

For fade objects <br>
`led.performFade();`<br> <br>

Note: performBlink(); and performFade(); are both valid for fadeLED objects, performFade will also
carry out any Blink events triggered. Fading events take priority over Blink events if they are called together.

performFade(); is not valid for ledObjects. 

<br>


___________________________________________________________________________________________________________

### Starting & Stopping Events:
#### Starting Events

Blink & Fade events must be triggered to be performed.

Start a Blink event that continues indefinatly:

`led.startBlink(onDuration, offDuration);`<br> <br>

Call a Blink event that repeats a number of times:

`led.blinkEvent(numberofBlinks, onDuration, offDuration );`<br> <br>


Start a Fade event that continues indefinatly:

`led.startFading(minBrightness, maxBrightness , timeMs);  // timeMs is time for complete fade (Up & Down)`<br> <br>

Call a Fade event that repeats a number of times:

`led.fadeEvent(minimum , maximum, repeats, timeMs = 500);`<br> <br>

<br>
_____

#### Stopping Events

To stop a blink event call:

`led.stopBlink();`<br> <br>

To stop a fade event call:

`led.stopFading();`<br> <br>


___________________________________________________________________________________________________________

### Advanced Uses:
See [star_trek_flash_board](https://github.com/PanGalacticTech/ledObject_library/blob/master/star_trek_flash_board/star_trek_flash_board.ino) to see these techniques in action.

Set up arrays of ledObject and fadeLED constructors to iterate through large numbers of outputs easily. 

`ledObject flash[6] = {ledObject(2), ledObject(4), ledObject(7), ledObject(8), ledObject(12), ledObject(13)};`  <br> 
`                                      // Set up an array of ledObjects, each ledObject is passed an output pin`<br>

`fadeLED fade[6] = {fadeLED(3), fadeLED(5), fadeLED(6), fadeLED(9), fadeLED(10), fadeLED(11)};`<br>
`                                      // Set up an array of fadeLEDs. Each LED is passed a PWM capable output pin`<br> <br>

Iterate through object array using a for loop for setup functions.

`for (int i = 0; i < NUM_FLASHERS; i++) {`<br>
`    flash[i].begin(INITIAL_STATE);`<br>
` }`<br> <br>

Iterate through object array using a for loop to start or change flashing/fading behaviour.

`for (int i = 0; i < NUM_FADERS; i++) {`<br>
`    fade[i].startFading(0, 255, random(1, 1000));                    // feed new random numbers into the fade objects`<br>
`  }`<br> <br>

Iterate through object array with perform function (Must be called in every loop).

`for (int i = 0; i < NUM_FADERS; i++) {`<br>
`   fade[i].performFades();        // PerformFade events, also performs blink events.`<br>
` }` <br> <br>




<br>
<br>

___________________________________________________________________________________________________________
___________________________________________________________________________________________________________

### Limitations:



<br>

### Known Issues V2.0.0
  - Please report any bugs or issues found.
  - 
### Known Issues V1.0.0
  - Please report any bugs or issues found.

<br>

### Features to be Added 

<br>
<br>

## About
### Built With
* [Arduino IDE](https://www.arduino.cc/) - Default IDE


### Author
#### Imogen Wren
* [LinkedIn](https://www.linkedin.com/in/declan-heard-91103b58/)
* Email: [Personal](mailto:Imogen.Wren91@gmail.com "Imogen.Wren91@gmail.com") | [Company](mailto:PanGalacticTech@gmail.com "PanGalacticTech@gmail.com")
* [Github Profile](https://github.com/PanGalacticTech)
