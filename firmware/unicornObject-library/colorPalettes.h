/*       Color Palettes
       Multi Colour and Mood Palettes




*/




#include <FastLED.h>


// pragma once is precompiler message to only include this text once, it replaces header guards in most compilers
#pragma once


namespace colorPalettes {
DECLARE_GRADIENT_PALETTE( tropicalPalette );
DECLARE_GRADIENT_PALETTE( raggaPalette );
DECLARE_GRADIENT_PALETTE( transPalette );
DECLARE_GRADIENT_PALETTE( biPalette );
DECLARE_GRADIENT_PALETTE( orange_white );
DECLARE_GRADIENT_PALETTE( blue_white );
DECLARE_GRADIENT_PALETTE( green_white );
DECLARE_GRADIENT_PALETTE( hotpink_blue );
DECLARE_GRADIENT_PALETTE( white_light );
DECLARE_GRADIENT_PALETTE( angry_red );
}  // end namespace





/*
// This function fills the palette with totally random colors.
CRGBPalette16 returnRandomPalette() {
  CRGBPalette16  randomPalette;
  for ( int i = 0; i < 16; i++) {
    randomPalette[i] = CHSV( random8(), 255, 255);
  }
  return randomPalette;
}


#define NUM_FX 17
// Function to call palettes above

CRGBPalette16 select_palette(byte number) {

  CRGBPalette16 outputPalette;


  switch (number) {
    case 0:
      outputPalette = tropicalPalette;
      //    Serial.println("Tropical");
      break;
    case 1:
      outputPalette = raggaPalette;
      //    Serial.println("Ragga");
      break;
    case 2:
      outputPalette = transPalette;
      //     Serial.println("Trans");
      break;
    case 3:
      outputPalette = biPalette;
      //    Serial.println("Bi");
      break;
    case 4:
      outputPalette = ace;
      //     Serial.println("Orange/White");
      break;
    case 5:
      outputPalette = blue_white;
      //     Serial.println("blue_white");
      break;
    case 6:
      outputPalette = bisexual;
      //      Serial.println("Green/White");
      break;
    case 7:
      outputPalette = lesbian;
      //      Serial.println("Planet Earth");
      break;
    case 8:
      outputPalette = RainbowColors_p;
      //      Serial.println("Rainbow Colours");
      break;
    case 9:
      outputPalette = RainbowStripeColors_p;
      //      Serial.println("Rainbow Stripe Colours");
      break;
    case 10:
      outputPalette = returnRandomPalette();
      //     Serial.println("Cloud Colours");
      break;
    case 11:
      outputPalette = PartyColors_p;
      //      Serial.println("Party Colours");
      break;
    case 12:
      outputPalette = enby;
      //     Serial.println("Lava Colours");
      break;
    case 13:
      outputPalette = trans;
      //     Serial.println("Ocean Colours");
      break;
    case 14:
      outputPalette = returnRandomPalette();
      //     Serial.println("Forest Colours");
      break;
    case 15:
      outputPalette = returnRandomPalette();
      //      Serial.println("Heat Map Colours");
      break;
    case 16:
      outputPalette = hotpink_blue;
      //      Serial.println("Hotpink Blue");
      break;
    default:
      //     Serial.println("Random");
      for ( int i = 0; i < 16; i++) {
        outputPalette[i] = CHSV( random8(), 255, random8());
      }
      break;
  }
  //return green_white;
  return outputPalette;
}
//

*/

