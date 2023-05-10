



#include "colorPalettes.h"
using namespace colorPalettes;




DEFINE_GRADIENT_PALETTE( colorPalettes::tropicalPalette ) {
  0,      255,  230,  0,    // at index 0, yellow(0,0,0) //
  50,     255,  200,  0,    // at index 0, orange(0,0,0) //
  100,      0,  255, 255,    // at index 192, teal(255,0,0) //
  200,      0,  255, 100, // at index 255, blue(255,255,255) //
  255,    255,  190,  0    // at index 0, yellow(0,0,0) //       // last entry must be for index 255
};


DEFINE_GRADIENT_PALETTE( colorPalettes::raggaPalette ) {
  0,      255,  255,  0,    // at index 0, yellow(0,0,0) //
  100,     100,  255,  0,    // at index 0, greenyellow(0,0,0) //
  150,      0,  255, 0,    // at index 192, green(255,0,0) //
  200,     255,  0, 0, // at index 255, red(255,255,255) //
  255,    255,  255,  0    // at index 0, yellow(0,0,0) //       // last entry must be for index 255
};


DEFINE_GRADIENT_PALETTE( colorPalettes::transPalette ) {
  0,      50,  230,  255,    // at index 0, Blue(0,0,0) //
  50,     255,  50,  50,    // at index 0, Pink(0,0,0) //
  125,      255,  255, 255,    // at index 192, White(255,0,0) //
  200,     255,  50, 50, // at index 255, Pink(255,255,255) //
  255,    50,  190,  255   // at index 0, Blue(0,0,0) //       // last entry must be for index 255
};



DEFINE_GRADIENT_PALETTE( colorPalettes::biPalette ) {
  0,        0,  255,  255,    // at index 0, teal(0,0,0) //
  50,       0,  0,    255,    // at index 0, blue(0,0,0) //
  190,    255,  0,    255, // at index 255, purple(255,255,255) //
  255,    255,  0,    100   // at index 0, deep purple(0,0,0) //       // last entry must be for index 255
};


DEFINE_GRADIENT_PALETTE( colorPalettes::orange_white ) {
  0,        255,  200,  0,    // at index 0, orange(0,0,0) //
  50,       255,  40, 0,    // at index 0, orange(0,0,0) //
  235,     255,  100,  0,    // at index 0, orange(0,0,0) //
  245,    255,  255,    255, // at index 255, white(255,255,255) //
  255,    255,  50,    0   // at index 0, orange(0,0,0) //       // last entry must be for index 255
};

DEFINE_GRADIENT_PALETTE( colorPalettes::blue_white ) {
  0,        0,  0, 255,    // at index 0, orange(0,0,0) //
  50,       0,  255, 255,    // at index 0, orange(0,0,0) //
  100,        0,  0, 255,
  120,      255,  255, 255,
  140,        0,  255, 255,
  235,     0,  255,  255,    // at index 0, orange(0,0,0) //
  245,    255,  255,    255, // at index 255, white(255,255,255) //
  255,    0,  40,   255   // at index 0, orange(0,0,0) //       // last entry must be for index 255
};

DEFINE_GRADIENT_PALETTE( colorPalettes::green_white ) {
  0,        0,  255, 0,    // at index 0, orange(0,0,0) //
  50,       100,  255, 0,    // at index 0, orange(0,0,0) //
  235,     0,  255,  0,    // at index 0, orange(0,0,0) //
  245,    255,  255,    255, // at index 255, white(255,255,255) //
  255,    120,  255,   0   // at index 0, orange(0,0,0) //       // last entry must be for index 255
};


DEFINE_GRADIENT_PALETTE( colorPalettes::hotpink_blue ) {
  0,        0,  100, 255,    // at index 0, orange(0,0,0) //
  50,       0,  255, 255,    // at index 0, orange(0,0,0) //
  60,        255, 0, 150,
  100,       255, 0, 150,
  150,         0, 0, 255,
  170,       0,  255,  255,    // at index 0, orange(0,0,0) //
  222,       255,  0,  150, // at index 255, white(255,255,255) //
  255,    120,  0,   255   // at index 0, orange(0,0,0) //       // last entry must be for index 255
};



DEFINE_GRADIENT_PALETTE( colorPalettes::white_light ) {
  0,        100, 100, 100,    // at index 0, orange(0,0,0) //
  50,       40,  40, 40,    // at index 0, orange(0,0,0) //
  100,       0,  0, 0,    // at index 0, orange(0,0,0) //
  120,       255,  255, 255,    // at index 0, orange(0,0,0) //
  140,       5,  5, 5,    // at index 0, orange(0,0,0) //
  150,     150,  150,  150,    // at index 0, orange(0,0,0) //
  170,    255,  255,  255, // at index 255, white(255,255,255) //
  190,    10,  10,  10, // at index 255, white(255,255,255) //
  255,    255,  255,  255   // at index 0, orange(0,0,0) //       // last entry must be for index 255
};



DEFINE_GRADIENT_PALETTE( colorPalettes::angry_red ) {
  0,        255, 0, 0,    // at index 0, orange(0,0,0) //
  50,       255,  100, 0,    // at index 0, orange(0,0,0) //
  110,       255,  0, 0,    // at index 0, orange(0,0,0) //
  120,       255,  100, 10,    // at index 0, orange(0,0,0) //
  130,       255,  0, 5,    // at index 0, orange(0,0,0) //
  150,     255,  100,  20,    // at index 0, orange(0,0,0) //
  170,    255,  0,  40, // at index 255, white(255,255,255) //
  190,    255,  0,  1, // at index 255, white(255,255,255) //
  255,    255,  50, 0   // at index 0, orange(0,0,0) //       // last entry must be for index 255
};
