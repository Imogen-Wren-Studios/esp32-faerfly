/* ) . . o o 0 0 0 0 . Pride Palettes  ) . . o o 0 0 0 0 .


   Take a tour through the solar system
   with this pack of planetary
   colour schemes

*/


#ifndef pridePalettes_h
#define pridePalettes_h



DEFINE_GRADIENT_PALETTE( pride) {
  0,        255, 0, 0,    /*Red) */
  40,         255, 100, 0,     /* Orange */
  80,           255, 255, 0,    /* Yellow */
  120,         0, 255, 0,    /* Green*/
  160,        0, 255, 255,     /* teal */
  200,        0, 0, 255,      /* Blue */
  255,        255, 0, 255      /* Purple */
};


DEFINE_GRADIENT_PALETTE( lesbian) {
  0,        255, 100, 0,    /* Dark Orange*/
  32,        255,  255, 0,    /* Light Orange */
  64,          255, 255, 100,  /* Pumkin */
  98,         255, 255, 255,  /* White/Cream*/
  130,        255,  197, 255,   /* Pink */
  162,       255, 150, 255,    /*Purple/Mauve*/
  194,      255, 0, 255,    /* Red Pink */
  255,    255, 0, 100    /* Deep Pink*/
};

// Not used yet
DEFINE_GRADIENT_PALETTE( gay) {
  0,        190, 190, 120,    /* at index 0, blue(0,0,0) */
  5,        230,  200, 70,    /* at index 0, blue(0,0,0) */
  10,       230,  200, 10,    /* at index 0, blue(0,0,0) */
  15,       150,  120, 70,    /* at index 0, blue(0,0,0) */
  110,        70,  50, 30,    /* at index 0, blue(0,0,0) */
  120,       220,  190, 130,    /* at index 0, green(0,0,0) */
  140,       150,  100, 40,    /* at index 0, green(0,0,0) */
  150,     200,  190,  20,    /* at index 0, blue(0,0,0) */
  200,     250, 70,  0,    /* at index 0, green(0,0,0) */
  210,     150,  100,  0,    /* at index 0, green(0,0,0) */
  235,      140,  65, 1,    /* at index 0, desertbrown(0,0,0) */
  240,        30,  30, 0,       /* at index 0, desertbrown(0,0,0) */       // last entry must be for index 255
  245,    145,  120,    30, /* at index 255, desertbright(255,255,255) */
  255,    120,  100,   100  /* at index 0, blue(0,0,0) */       // last entry must be for index 255
};




DEFINE_GRADIENT_PALETTE( bisexual) {
  0,        255, 0, 100,    /* RedPink */
  130,        255, 0, 150,    /* RedPink */
  120,       255, 0, 255,    /* Purple*/
  140,       150, 0, 255,    /*Bluepurple */
  255,       100, 0, 255    /*Bluepurple */

};



DEFINE_GRADIENT_PALETTE(enby) {
  0,        230,  255, 0,    /* Yellow*/
  32,       255,  255, 255,    /* White*/
  64,        255,  0, 255,    /* Purple */
  98,        0,  0, 0,    /*Black */
  130,       255,  255, 255,    /* White*/
  162,       255,  0, 255,    /* Purple */
  194,     230,  255,  0,    /* Yellow */
  255,     0,  0,  0    /* Black*/
};



// Would prefer an HSV way of specifying this.
DEFINE_GRADIENT_PALETTE( trans) {
  0,        0, 40, 255,    /* Baby Blue */
  8,        200, 20, 150,   /* Baby Pink */
  10,       255,  255, 255,    /* White */
  13,       200, 20, 150,    /* Baby Pink*/
  255,      0, 40, 255     /* Baby Blue */
};




DEFINE_GRADIENT_PALETTE(ace) {   // Black, Grey, White, Purple
  0,         0,   0,    0,     // Black
  100,         20,   20,    20,     // Grey
  150,         255,   255,    255,     // White
  255,      131,   0,   255         // Purple
};



DEFINE_GRADIENT_PALETTE(aero) {
  0,         131,   87,    20,     // mud   0
  40,        166,    134,    20 ,    //gravel 1
  50,         207,    140,   20 ,      // dirty orange (very thin) 2
  60,        202,   194,   20,    //tan_suit 3
  70,        228,   214,    20,      //sand 4
  80,       233,    233,     221,     // clouds or grey_clouds (very thin) 5
  90,       245,    106,     2,      // reddish_dust (medium thin) 6
  100,       220,    160,     13,    // dirty_orange (thicc) 7
  150,       228,   214,    20,     //sand (thin) 8
  160,       131,   87,     20,       //mud (thin) 9
  170,      202,   194,   20,      // tan_suit (mid thin) 10
  180,       255,   50,     20,      // red_dot (thin) 11
  190,      233,    233,     221,     // clouds (thin) 12
  200,      166,    134,   2,       // gravel  (thick) 13
  235,        202,   194,   20,        // tan suit 14
  255,      131,   87,    20         // mud (thin) 15

};


DEFINE_GRADIENT_PALETTE(inter) {
  0,         0,   200,    255,     // Blue  0
  40,        0,    0,    255 ,    //gravel 1
  42,         0,    0,   255 ,      // dirty orange (very thin) 2
  45,        202,   255,   255,    //tan_suit 3
  60,        0,   214,    255,      //sand 4
  73,       0,    0,     255,     // clouds or grey_clouds (very thin) 5
  75,       0,    0,    255,      // reddish_dust (medium thin) 6
  80,       0,    255,     255,    // dirty_orange (thicc) 7
  120,       0,   255,    255,     //sand (thin) 8
  180,       0,   0,     255,       //mud (thin) 9
  190,      0,   194,   255,      // tan_suit (mid thin) 10
  192,       0,   0,     255,      // red_dot (thin) 11
  195,      233,    233,     255,     // clouds (thin) 12
  200,      0,    134,   255,       // gravel  (thick) 13
  235,        0,   194,   255,        // tan suit 14
  255,      0,   0,    255         // mud (thin) 15

};



DEFINE_GRADIENT_PALETTE(demi) {
  0,         0,   0,    255,     // Blue  0
  40,        0,    0,    255 ,    //gravel 1
  42,         0,    0,   255 ,      // dirty orange (very thin) 2
  45,        202,   255,   255,    //tan_suit 3
  60,        0,   0,    255,      //sand 4
  73,       0,    0,     255,     // clouds or grey_clouds (very thin) 5
  75,       0,    0,    255,      // reddish_dust (medium thin) 6
  80,       0,    255,     255,    // dirty_orange (thicc) 7
  120,       0,   255,    255,     //sand (thin) 8
  180,       0,   0,     255,       //mud (thin) 9
  190,      0,   0,   255,      // tan_suit (mid thin) 10
  192,       0,   0,     255,      // red_dot (thin) 11
  195,      233,    233,     255,     // clouds (thin) 12
  200,      0,    0,   255,       // gravel  (thick) 13
  235,        0,   255,   255,        // tan suit 14
  255,      0,   0,    255         // mud (thin) 15

};




DEFINE_GRADIENT_PALETTE(queer) {
  0,         255,  255,    255,     // Blue  0
  30,        220, 43, 22,    //gravel 1
  45,         65, 34, 29,       // dirty orange (very thin) 2
  50,         255,  255,    255,   //tan_suit 3
  60,          58, 110, 230,      //sand 4
  70,          70, 140, 210,      // clouds or grey_clouds (very thin) 5
  80,       140, 127, 121,      // reddish_dust (medium thin) 6
  100,         255,  255,    255,     // dirty_orange (thicc) 7
  110,          255,  255,    255,      //sand (thin) 8
  150,         222, 10, 5,      //mud (thin) 9
  170,       73, 88, 92,   // tan_suit (mid thin) 10
  176,        255,  255,    255,       // red_dot (thin) 11
  200,        10, 13, 242,      // clouds (thin) 12
  220,       122, 104, 111 ,    // gravel  (thick) 13
  230,        60, 60, 57,        // tan suit 14
  255,      0,   0,    0        // mud (thin) 15

};



DEFINE_GRADIENT_PALETTE( colour_tester) {
  0,        139,  75, 1,    /* at index 0, blue(0,0,0) */

  255,    139,  75, 15       /* at index 0, blue(0,0,0) */       // last entry must be for index 255
};


DEFINE_GRADIENT_PALETTE( black_black) {
  0,        0,  0, 0,    /* at index 0, blue(0,0,0) */

  255,    0,  0, 0      /* at index 0, blue(0,0,0) */       // last entry must be for index 255
};



// Function to call planet palettes

/*

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


#endif
