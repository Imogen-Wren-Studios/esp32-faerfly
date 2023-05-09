/* ) . . o o 0 0 0 0 . Pride Palettes  ) . . o o 0 0 0 0 .


   Take a tour through the solar system
   with this pack of planetary
   colour schemes

*/
#include <FastLED.h>

//#ifndef pridePalettes_h
//#define pridePalettes_h

// pragma once is precompiler message to only include this text once, it replaces header guards in most compilers
#pragma once


namespace pridePalettes {

DECLARE_GRADIENT_PALETTE(pride);
DECLARE_GRADIENT_PALETTE(lesbian);
DECLARE_GRADIENT_PALETTE(gay);
DECLARE_GRADIENT_PALETTE(bisexual);
DECLARE_GRADIENT_PALETTE(enby);
DECLARE_GRADIENT_PALETTE(trans);
DECLARE_GRADIENT_PALETTE(ace);
DECLARE_GRADIENT_PALETTE(aero);
DECLARE_GRADIENT_PALETTE(inter);
DECLARE_GRADIENT_PALETTE(demi);
DECLARE_GRADIENT_PALETTE(queer);
DECLARE_GRADIENT_PALETTE(color_tester);
DECLARE_GRADIENT_PALETTE(black_black);


//CRGBPalette16 prideArray[11];




}  // end namespace





/*
// Function to call planet palettes



byte current_flag = 0;

CRGBPalette16 select_flag() {

  CRGBPalette16 outputPalette;


  switch (current_flag) {
    case 0:
      outputPalette = pride;
      //     Serial.println("The Sun");
      //      Serial.println("Entering Heliocentric Orbit");
      break;
    case 1:
      outputPalette = lesbian;
      //     Serial.println("Mercury");
      break;
    case 2:
      outputPalette = gay;
      //     Serial.println("Venus");
      break;
    case 3:
      outputPalette = bisexual;
      //      Serial.println("Earth");
      break;
    case 4:
      outputPalette = enby;
      //      Serial.println("The Moon");
      break;
    case 5:
      outputPalette = trans;
      //     Serial.println("Mars");
      break;
    case 6:
      outputPalette = ace;
      //      Serial.println("Jupiter");
      break;
    case 7:
      outputPalette = aero;
      //     Serial.println("Saturn");
      break;
    case 8:
      outputPalette = inter;
      //     Serial.println("Uranus");
      break;
    case 9:
      outputPalette = demi;
      //      Serial.println("Neptune");
      break;
    case 10:
      outputPalette = queer;
      //      Serial.println("Pluto");
      break;
    default:
      //     Serial.println("Random");
      for ( int i = 0; i < 16; i++) {
        outputPalette[i] = CHSV( random8(), 255, random8());
      }
      break;
  }
  //return green_white;
  current_flag++;

  if (current_flag >= 12) {
    current_flag = 0;
    // solar_system_mode = false;    // Once we have finished our flight around the solar system, return to colour palletes
    //    Serial.println("Colour Palette Mode");

  }
  return outputPalette;
}


*/





// add a macro to DEFINE_HSV_GRADIENT_PALETTE





/* Not controlable enough Shame
  CRGBPalette16 planet_jupiter() {

  CRGB cloud  = CHSV( 0, 0, 255);
  CRGB grey_cloud = CHSV( 0, 0, 110);

  CRGB golden = CHSV(33, 204, 181);
  CRGB sand = CHSV( 38, 138, 227);
  CRGB tan_suit  = CHSV( 31, 99, 70);
  CRGB gravel = CHSV( 30, 43, 70);
  CRGB mud  = CHSV( 21, 115, 110);

  CRGB dirty_orange  = CHSV( 15, 74, 110);
  CRGB reddish_dust  = CHSV( 21, 189, 181);

  CRGB red_spot = CHSV( 0, 189, 181);

  CRGBPalette16 output =  CRGBPalette16( mud,  dirty_orange,  gravel,  tan_suit,
                     cloud, sand, sand,  reddish_dust,
                     dirty_orange,  mud,  sand,  grey_cloud,
                     golden, sand, red_spot,  mud);

  return output;


  }
*/


//#endif
