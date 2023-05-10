/* ) . . o o 0 0 0 0 . Planet Palettes  ) . . o o 0 0 0 0 .



   Take a tour through the solar system
   with this pack of planetary
   colour schemes

  Imogen Wren
  May 2023


*/

#include "planetPalettes.h"

using namespace planetPalettes;



DEFINE_GRADIENT_PALETTE( planetPalettes::helios) {
  0,        255, 255, 255,    /* at index 0, blue(0,0,0) */
  5,         255, 255, 255,     /* at index 0, blue(0,0,0) */
  10,           255, 255, 0,    /* at index 0, blue(0,0,0) */
  15,         255, 100, 0,    /* at index 0, blue(0,0,0) */
  100,         255, 255, 0,     /* at index 0, blue(0,0,0) */
  120,        255, 255, 255,      /* at index 0, green(0,0,0) */
  140,      255, 100, 100,      /* at index 0, green(0,0,0) */
  150,     255, 255, 0,     /* at index 0, blue(0,0,0) */
  200,     255, 100, 0,      /* at index 0, green(0,0,0) */
  220,      255, 255, 255,      /* at index 0, green(0,0,0) */
  235,       255, 255, 255,      /* at index 0, desertbrown(0,0,0) */
  240,      255, 255, 0,         /* at index 0, desertbrown(0,0,0) */       // last entry must be for index 255
  245,    255, 200, 0,   /* at index 255, desertbright(255,255,255) */
  255,     255, 255, 255   /* at index 0, blue(0,0,0) */       // last entry must be for index 255
};


DEFINE_GRADIENT_PALETTE( planetPalettes::mercury) {
  0,        169, 136, 25,    /* at index 0, blue(0,0,0) */
  5,        182,  155, 25,    /* at index 0, blue(0,0,0) */
  10,          239, 231, 40,  /* at index 0, blue(0,0,0) */
  15,         169, 136, 25,  /* at index 0, blue(0,0,0) */
  100,        221,  197, 35,   /* at index 0, blue(0,0,0) */
  120,       221, 200, 35,    /* at index 0, green(0,0,0) */
  140,      163, 125, 25,    /* at index 0, green(0,0,0) */
  150,    178, 135, 24,    /* at index 0, blue(0,0,0) */
  200,    105, 70, 13,    /* at index 0, green(0,0,0) */
  220,     150,  50,  0,    /* at index 0, green(0,0,0) */
  235,      139,  75, 1,    /* at index 0, desertbrown(0,0,0) */
  240,      188, 144, 10,       /* at index 0, desertbrown(0,0,0) */       // last entry must be for index 255
  245,   77, 74, 12, /* at index 255, desertbright(255,255,255) */
  255,    66, 54, 10 /* at index 0, blue(0,0,0) */       // last entry must be for index 255
};


DEFINE_GRADIENT_PALETTE( planetPalettes::venus) {
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




DEFINE_GRADIENT_PALETTE( planetPalettes::earth) {
  0,        19, 21, 255,    /* at index 0, blue(0,0,0) */
  7,       20, 100, 255,    /* at index 0, blue(0,0,0) */
  10,       255,  255, 255,    /* at index 0, cloud(0,0,0) */
  13,        2, 150, 255,   /* at index 0, blue(0,0,0) */
  60,       130, 255, 0,    /* at index 0, landgreen(0,0,0) */
  100,       20, 255, 2,    /* at index 0, green(0,0,0) */
  120,       10, 100, 255,    /* at index 0, blue(0,0,0) */
  135,       70, 255, 5,    /* at index 0, landgreen(0,0,0) */
  145,       230, 235, 20,    /* at index 0, desert(0,0,0) */
  170,     235, 158, 5,    /* at index 0, orangedesert(0,0,0) */
  190,       70, 255, 5,    /* at index 0, landgreen(0,0,0) */
  213,    24, 30, 234,    /* at index 0, dark sea(0,0,0) */
  224,     0, 0, 0,    /* at index 0, Night(0,0,0) */
  233,     50, 50, 0,       /* at index 0, Lights @ Night(0,0,0) */      // last entry must be for index 255
  240,    0, 0, 20, /* at index 255, ight(255,255,255) */
  255,   0, 21, 40,   /* at index 0, sunrise(0,0,0) */       // last entry must be for index 255
};



DEFINE_GRADIENT_PALETTE( planetPalettes::luna) {
  0,        0,  0, 0,    /* at index 0, blue(0,0,0) */
  5,        100,  100, 100,    /* at index 0, blue(0,0,0) */
  10,       20,  20, 20,    /* at index 0, blue(0,0,0) */
  15,        255,  255, 255,    /* at index 0, blue(0,0,0) */
  100,        50,  50, 50,    /* at index 0, blue(0,0,0) */
  120,       200,  200, 200,    /* at index 0, green(0,0,0) */
  140,       0,  0, 0,    /* at index 0, green(0,0,0) */
  150,     20,  20,  20,    /* at index 0, blue(0,0,0) */
  200,     200,  200,  200,    /* at index 0, green(0,0,0) */
  220,     150,  150,  150,    /* at index 0, green(0,0,0) */
  235,        10,  10, 10,    /* at index 0, desertbrown(0,0,0) */
  240,    255,  255, 255,       /* at index 0, desertbrown(0,0,0) */       // last entry must be for index 255
  245,    200,  200,    200, /* at index 255, desertbright(255,255,255) */
  255,    1,  1,   1   /* at index 0, blue(0,0,0) */       // last entry must be for index 255
};



// Would prefer an HSV way of specifying this.
DEFINE_GRADIENT_PALETTE( planetPalettes::mars) {
  0,        255, 140, 0,    /* at index 0, blue(0,0,0) */
  8,        240,  20, 0,    /* at index 0, blue(0,0,0) */
  10,       200,  170, 100,    /* at index 0, blue(0,0,0) */
  13,       200,  100, 0,    /* at index 0, blue(0,0,0) */
  100,        190,  50, 0,    /* at index 0, blue(0,0,0) */
  120,       240,  50, 0,    /* at index 0, green(0,0,0) */
  140,      190,  64, 0,    /* at index 0, green(0,0,0) */
  150,     230,  30,  0,    /* at index 0, blue(0,0,0) */
  200,     255, 23,  0,    /* at index 0, green(0,0,0) */
  210,     100,  50,  0,    /* at index 0, green(0,0,0) */
  235,      200,  40, 1,    /* at index 0, desertbrown(0,0,0) */
  240,        0,  0, 0,       /* at index 0, desertbrown(0,0,0) */       // last entry must be for index 255
  245,    145,  40,    0, /* at index 255, desertbright(255,255,255) */
  255,    130,  50,   0   /* at index 0, blue(0,0,0) */       // last entry must be for index 255
};




DEFINE_GRADIENT_PALETTE( planetPalettes::jupiter) {
  0,         140,   87,    20,     // mud   0
  40,        180,    134,    20 ,    //gravel 1
  42,         220,    140,   20 ,      // dirty orange (very thin) 2
  45,        224,   194,   20,    //tan_suit 3
  70,        205,   191,    40,      //sand 4
  73,       130,    127,     125,     // clouds or grey_clouds (very thin) 5
  78,       255,    106,     2,      // reddish_dust (medium thin) 6
  90,       250,    160,     13,    // dirty_orange (thicc) 7
  140,       228,   181,    20,     //sand (thin) 8
  160,       200,   87,     20,       //mud (thin) 9
  180,      223,   140,   20,      // tan_suit (mid thin) 10
  190,       255,   10,     0,      // red_dot (thin) 11
  194,      150,    100,   2,       // gravel  (thick) 13
  197,      137,    135,     120,     // clouds (thin) 12
  202,        202,  140,   20,        // tan suit 14
  255,      131,   87,    20         // mud (thin) 15

};



DEFINE_GRADIENT_PALETTE(planetPalettes::saturn) {
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


DEFINE_GRADIENT_PALETTE(planetPalettes::uranus) {
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



DEFINE_GRADIENT_PALETTE(planetPalettes::neptune) {
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




DEFINE_GRADIENT_PALETTE(planetPalettes::pluto) {
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

DEFINE_GRADIENT_PALETTE( planetPalettes::space) {
  0,        0,  0, 0,    /* at index 0, blue(0,0,0) */

  255,    0,  0, 0      /* at index 0, blue(0,0,0) */       // last entry must be for index 255
};

DEFINE_GRADIENT_PALETTE( colour_tester) {
  0,        139,  75, 1,    /* at index 0, blue(0,0,0) */

  255,    139,  75, 15       /* at index 0, blue(0,0,0) */       // last entry must be for index 255
};




