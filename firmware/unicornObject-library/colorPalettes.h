/*
       Multi Colour and Mood Palettes



*/


//#include "globals.h"
#include "pridePalettes.h"


DEFINE_GRADIENT_PALETTE( tropicalPalette ) {
  0,      255,  230,  0,    /* at index 0, yellow(0,0,0) */
  50,     255,  200,  0,    /* at index 0, orange(0,0,0) */
  100,      0,  255, 255,    /* at index 192, teal(255,0,0) */
  200,      0,  255, 100, /* at index 255, blue(255,255,255) */
  255,    255,  190,  0    /* at index 0, yellow(0,0,0) */       // last entry must be for index 255
};


DEFINE_GRADIENT_PALETTE( raggaPalette ) {
  0,      255,  255,  0,    /* at index 0, yellow(0,0,0) */
  100,     100,  255,  0,    /* at index 0, greenyellow(0,0,0) */
  150,      0,  255, 0,    /* at index 192, green(255,0,0) */
  200,     255,  0, 0, /* at index 255, red(255,255,255) */
  255,    255,  255,  0    /* at index 0, yellow(0,0,0) */       // last entry must be for index 255
};


DEFINE_GRADIENT_PALETTE( transPalette ) {
  0,      50,  230,  255,    /* at index 0, Blue(0,0,0) */
  50,     255,  50,  50,    /* at index 0, Pink(0,0,0) */
  125,      255,  255, 255,    /* at index 192, White(255,0,0) */
  200,     255,  50, 50, /* at index 255, Pink(255,255,255) */
  255,    50,  190,  255   /* at index 0, Blue(0,0,0) */       // last entry must be for index 255
};



DEFINE_GRADIENT_PALETTE( biPalette ) {
  0,        0,  255,  255,    /* at index 0, teal(0,0,0) */
  50,       0,  0,    255,    /* at index 0, blue(0,0,0) */
  190,    255,  0,    255, /* at index 255, purple(255,255,255) */
  255,    255,  0,    100   /* at index 0, deep purple(0,0,0) */       // last entry must be for index 255
};


DEFINE_GRADIENT_PALETTE( orange_white ) {
  0,        255,  200,  0,    /* at index 0, orange(0,0,0) */
  50,       255,  40, 0,    /* at index 0, orange(0,0,0) */
  235,     255,  100,  0,    /* at index 0, orange(0,0,0) */
  245,    255,  255,    255, /* at index 255, white(255,255,255) */
  255,    255,  50,    0   /* at index 0, orange(0,0,0) */       // last entry must be for index 255
};

DEFINE_GRADIENT_PALETTE( blue_white ) {
  0,        0,  0, 255,    /* at index 0, orange(0,0,0) */
  50,       0,  255, 255,    /* at index 0, orange(0,0,0) */
  100,        0,  0, 255,
  120,      255,  255, 255,
  140,        0,  255, 255,
  235,     0,  255,  255,    /* at index 0, orange(0,0,0) */
  245,    255,  255,    255, /* at index 255, white(255,255,255) */
  255,    0,  40,   255   /* at index 0, orange(0,0,0) */       // last entry must be for index 255
};

DEFINE_GRADIENT_PALETTE( green_white ) {
  0,        0,  255, 0,    /* at index 0, orange(0,0,0) */
  50,       100,  255, 0,    /* at index 0, orange(0,0,0) */
  235,     0,  255,  0,    /* at index 0, orange(0,0,0) */
  245,    255,  255,    255, /* at index 255, white(255,255,255) */
  255,    120,  255,   0   /* at index 0, orange(0,0,0) */       // last entry must be for index 255
};


DEFINE_GRADIENT_PALETTE( hotpink_blue ) {
  0,        0,  100, 255,    /* at index 0, orange(0,0,0) */
  50,       0,  255, 255,    /* at index 0, orange(0,0,0) */
  60,        255, 0, 150,
  100,       255, 0, 150,
  150,         0, 0, 255,
  170,       0,  255,  255,    /* at index 0, orange(0,0,0) */
  222,       255,  0,  150, /* at index 255, white(255,255,255) */
  255,    120,  0,   255   /* at index 0, orange(0,0,0) */       // last entry must be for index 255
};



DEFINE_GRADIENT_PALETTE( white_light ) {
  0,        100, 100, 100,    /* at index 0, orange(0,0,0) */
  50,       40,  40, 40,    /* at index 0, orange(0,0,0) */
  100,       0,  0, 0,    /* at index 0, orange(0,0,0) */
  120,       255,  255, 255,    /* at index 0, orange(0,0,0) */
  140,       5,  5, 5,    /* at index 0, orange(0,0,0) */
  150,     150,  150,  150,    /* at index 0, orange(0,0,0) */
  170,    255,  255,  255, /* at index 255, white(255,255,255) */
  190,    10,  10,  10, /* at index 255, white(255,255,255) */
  255,    255,  255,  255   /* at index 0, orange(0,0,0) */       // last entry must be for index 255
};



DEFINE_GRADIENT_PALETTE( angry_red ) {
  0,        255, 0, 0,    /* at index 0, orange(0,0,0) */
  50,       255,  100, 0,    /* at index 0, orange(0,0,0) */
  110,       255,  0, 0,    /* at index 0, orange(0,0,0) */
  120,       255,  100, 10,    /* at index 0, orange(0,0,0) */
  130,       255,  0, 5,    /* at index 0, orange(0,0,0) */
  150,     255,  100,  20,    /* at index 0, orange(0,0,0) */
  170,    255,  0,  40, /* at index 255, white(255,255,255) */
  190,    255,  0,  1, /* at index 255, white(255,255,255) */
  255,    255,  50, 0   /* at index 0, orange(0,0,0) */       // last entry must be for index 255
};



// This function fills the palette with totally random colors.
void SetupTotallyRandomPalette() {
  for ( int i = 0; i < 16; i++) {
    currentPalette[i] = CHSV( random8(), 255, 255);
  }
}


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
