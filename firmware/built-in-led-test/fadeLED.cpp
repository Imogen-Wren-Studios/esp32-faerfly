/* ----------fadeLED---------------------------

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


#include "ledObject.h"


//Methods



void fadeLED::setup(byte startBrightness) {

  ledObject::ledPin = pwmPin;                                // required to interface with ledObject library.
#ifdef __AVR__
  pinMode(pwmPin, OUTPUT);                          // Set PWM pin to output
#elif defined(ESP8266) || defined(ESP32)
  ledcSetup(ledCH, frequency, resolution); ledcAttachPin(pwmPin, ledCH);
#endif

  fadeLED::updatePWM(startBrightness);                       // update output with current brightness

}




// Method to write ledBrightness to PWM pin


void fadeLED::updatePWM(byte brightness) {

#ifdef __AVR__
  analogWrite(pwmPin, brightness);
#elif defined(ESP8266) || defined(ESP32)
  ledcWrite(ledCH, brightness);
#endif

  //Serial.println(brightness);
}


// Method to write ledBrightness to PWM pin by specifying a value to add or subtract from the current brightness

void fadeLED::modifyPWM(int16_t amount) {

  ledBrightness = ledBrightness + amount;

  ledBrightness = constrain(ledBrightness, 0 , 255);

  fadeLED::updatePWM(ledBrightness);


}


// Function to get around using ledON and ledOFF on ESP32 when using a pin previously used for PWM outputs for digital on and off

void fadeLED::hardON(){	

	ledBrightness = 255;
	fadeLED::updatePWM(ledBrightness);
	ledState = HIGH;
	
}


void fadeLED::hardOFF(){	

	ledBrightness = 0;
	fadeLED::updatePWM(ledBrightness);
	ledState = LOW;
	
}


void fadeLED::hardToggle(){	

	if (fadeState == FADE_UP or fadeState == FADE_DOWN){
		fadeState = OFF;
	}

	if (ledState == HIGH){
	fadeLED::hardOFF();		
	} else {
	fadeLED::hardON();		
	}
}



// Void fade moment and fade event should be able to stop startFading without explicilty calling stopFading

// Fades led in or out once by jumping to a start value then fading from there
void fadeLED::fadeMoment(byte minimum, byte maximum, int fadeDirection, uint32_t timeMs) {

  if (fadeDirection == FADE_UP || fadeDirection == OFF) {                // makes sure that fadeState has a direction to move
    fadeState = FADE_UP;
    ledBrightness = minimum;
  } else if (fadeDirection == FADE_DOWN) {
    fadeState = FADE_DOWN;
    ledBrightness = maximum;
  }

  interval = fadeLED::calculateFade(minimum, maximum, timeMs);


  pulsesRemaining = 1;

}





// Fades led in and out a defined number of times
void fadeLED::fadeEvent(byte minimum, byte maximum, int repeats, uint32_t timeMs) {

  interval = fadeLED::calculateFade(minimum, maximum, timeMs);

  pulsesRemaining = repeats * 2;  // Double the number of pulses as the algorithm subtracks 2 for every phase.

  if (fadeState == OFF) {             // starts fading if fading is turned off.
    fadeState = FADE_UP;
  }

} // Can be used to fade





// Starts Fade event that continues untill it is stopped
void fadeLED::startFading(byte minimum, byte maximum, uint32_t timeMs) {


  interval = fadeLED::calculateFade(minimum, maximum, timeMs);

  if (fadeState == OFF) {
    fadeState = FADE_UP;
  }


  /*
    Serial.print("timeMicros: ");
    Serial.println(timeMicros);
    Serial.print("Range: ");
    Serial.println(range);
    Serial.print("fadeState: ");
    Serial.println(fadeState);
    Serial.println(interval);
    uint32_t intervalMillis = interval/1000;
    Serial.print("interval Millis: ");
    Serial.println(intervalMillis);
  */
}




void fadeLED::stopFading() {

  fadeState = OFF;
  pulsesRemaining = 0;

}  // Instantly stops fading



void fadeLED::fadeOut(byte endBrightness, uint32_t timeMs) {

  interval = fadeLED::calculateFade(ledBrightness, endBrightness, timeMs);



  if (ledBrightness > endBrightness) {
    fadeState = FADE_DOWN;
    minBrightness = endBrightness;
  } else if (ledBrightness < endBrightness) {
    fadeState = FADE_UP;
    maxBrightness = endBrightness;
  } else if (ledBrightness == endBrightness) {
    fadeState = OFF;
  }

  pulsesRemaining = 1;


} // fades in or out using the current brightness as a starting positon








// Final loop for performing all fadeLED events and moments
void fadeLED::performFades() {


  if (pulsesRemaining > 0 || fadeState != OFF) {

    currentInterval = micros();

    if (currentInterval - lastInterval >= interval) {
      switch (fadeState) {
        case OFF:
          // Do nothing
          break;

        case FADE_UP:
          ledBrightness++;
          if (ledBrightness >= maxBrightness) {
            fadeState = FADE_DOWN;
            pulsesRemaining = fadeLED::updatePulses(pulsesRemaining);
          }
          break;

        case FADE_DOWN:
          ledBrightness--;
          if (ledBrightness <= minBrightness) {
            fadeState = FADE_UP;
            pulsesRemaining = fadeLED::updatePulses(pulsesRemaining);
          }
          break;

        default:
          // Also Do Nothing
          break;
      }
      lastInterval = currentInterval;

      fadeLED::updatePWM(ledBrightness);

    }

  } else {

    ledObject::performBlink();
  }
}


void fadeLED::advancedFade(byte startBrightness, byte endBrightness, uint32_t timeOne, uint32_t timeTwo, int repeats) {};   // Future implementation will cover this method




uint32_t fadeLED::calculateFade(byte minimum, byte maximum, uint32_t timeMs) {


  int range = maximum - minimum;

  if (range < 0) {
    range = range * (-1);
  }

  minBrightness = minimum;

  maxBrightness = maximum;

  uint32_t timeMicros = timeMs * 1000;



  timeMicros = (timeMicros / range);

  return timeMicros;


}

int fadeLED::updatePulses(int pulseNumber) {
  if (pulseNumber > 0) {
    pulseNumber--;
    if (pulseNumber == 0) {
      fadeState = OFF;
    }
  }
  return pulseNumber;
}
