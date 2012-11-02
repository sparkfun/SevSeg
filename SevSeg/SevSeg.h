//Written by Dean Reading, 2012.  deanreading@hotmail.com
//See .cpp file for info

#ifndef SevSeg_h
#define SevSeg_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define COMMON_CATHODE 0
#define COMMON_ANODE 1

#define BLANK 16 //Special character that turns off all segments (we chose 16 as it is the first spot that has this)

// framePeriod controls the length of time between display refreshes
// It's also closely linked to the brightness setting
#define FRAMEPERIOD 3000 
//Total amount of time (in microseconds) for the display frame. 1,000us is roughly 1000Hz update rate
//A framePeriod of:
//5000 is flickery
//3000 has good low brightness vs full brightness
//2000 works well
//500 seems like the low brightness is pretty bright, not great


//This is the combined array that contains all the segment configurations for many different characters and symbols
const unsigned char characterArray[128][7] = {
// A  B  C  D  E  F  G  Segments
  {1, 1, 1, 1, 1, 1, 0},  // 0
  {0, 1, 1, 0, 0, 0, 0},  // 1
  {1, 1, 0, 1, 1, 0, 1},  // 2
  {1, 1, 1, 1, 0, 0, 1},  // 3
  {0, 1, 1, 0, 0, 1, 1},  // 4
  {1, 0, 1, 1, 0, 1, 1},  // 5
  {1, 0, 1, 1, 1, 1, 1},  // 6
  {1, 1, 1, 0, 0, 0, 0},  // 7
  {1, 1, 1, 1, 1, 1, 1},  // 8
  {1, 1, 1, 1, 0, 1, 1},  // 9
  {1, 1, 1, 0, 1, 1, 1},  // 10  "A"
  {0, 0, 1, 1, 1, 1, 1},  // 11  "B"
  {1, 0, 0, 1, 1, 1, 0},  // 12  "C"
  {0, 1, 1, 1, 1, 0, 1},  // 13  "D"
  {1, 0, 0, 1, 1, 1, 1},  // 14  "E"
  {1, 0, 0, 0, 1, 1, 1},  // 15  "F"
  {0, 0, 0, 0, 0, 0, 0},  // 16  NO DISPLAY
  {0, 0, 0, 0, 0, 0, 0},  // 17  NO DISPLAY
  {0, 0, 0, 0, 0, 0, 0},  // 18  NO DISPLAY
  {0, 0, 0, 0, 0, 0, 0},  // 19  NO DISPLAY
  {0, 0, 0, 0, 0, 0, 0},  // 20  NO DISPLAY
  {0, 0, 0, 0, 0, 0, 0},  // 21  NO DISPLAY
  {0, 0, 0, 0, 0, 0, 0},  // 22  NO DISPLAY
  {0, 0, 0, 0, 0, 0, 0},  // 23  NO DISPLAY
  {0, 0, 0, 0, 0, 0, 0},  // 24  NO DISPLAY
  {0, 0, 0, 0, 0, 0, 0},  // 25  NO DISPLAY
  {0, 0, 0, 0, 0, 0, 0},  // 26  NO DISPLAY
  {0, 0, 0, 0, 0, 0, 0},  // 27  NO DISPLAY
  {0, 0, 0, 0, 0, 0, 0},  // 28  NO DISPLAY
  {0, 0, 0, 0, 0, 0, 0},  // 29  NO DISPLAY
  {0, 0, 0, 0, 0, 0, 0},  // 30  NO DISPLAY
  {0, 0, 0, 0, 0, 0, 0},  // 31  NO DISPLAY
  {0, 0, 0, 0, 0, 0, 0},  // 32 ' '
  {0, 0, 0, 0, 0, 0, 0},  // 33 '!'  NO DISPLAY
  {0, 1, 0, 0, 0, 1, 0},  // 34 '"'
  {0, 0, 0, 0, 0, 0, 0},  // 35 '#'  NO DISPLAY
  {0, 0, 0, 0, 0, 0, 0},  // 36 '$'  NO DISPLAY
  {0, 0, 0, 0, 0, 0, 0},  // 37 '%'  NO DISPLAY
  {0, 0, 0, 0, 0, 0, 0},  // 38 '&'  NO DISPLAY
  {0, 1, 0, 0, 0, 0, 0},  // 39 '''
  {1, 0, 0, 1, 1, 1, 0},  // 40 '('
  {1, 1, 1, 1, 0, 0, 0},  // 41 ')'
  {0, 0, 0, 0, 0, 0, 0},  // 42 '*'  NO DISPLAY
  {0, 0, 0, 0, 0, 0, 0},  // 43 '+'  NO DISPLAY
  {0, 0, 0, 0, 1, 0, 0},  // 44 ','
  {0, 0, 0, 0, 0, 0, 1},  // 45 '-'
  {0, 0, 0, 0, 0, 0, 0},  // 46 '.'  NO DISPLAY
  {0, 0, 0, 0, 0, 0, 0},  // 47 '/'  NO DISPLAY
  {1, 1, 1, 1, 1, 1, 0},  // 48 '0'
  {0, 1, 1, 0, 0, 0, 0},  // 49 '1'
  {1, 1, 0, 1, 1, 0, 1},  // 50 '2'
  {1, 1, 1, 1, 0, 0, 1},  // 51 '3'
  {0, 1, 1, 0, 0, 1, 1},  // 52 '4'
  {1, 0, 1, 1, 0, 1, 1},  // 53 '5'
  {1, 0, 1, 1, 1, 1, 1},  // 54 '6'
  {1, 1, 1, 0, 0, 0, 0},  // 55 '7'
  {1, 1, 1, 1, 1, 1, 1},  // 56 '8'
  {1, 1, 1, 1, 0, 1, 1},  // 57 '9'
  {0, 0, 0, 0, 0, 0, 0},  // 58 ':'  NO DISPLAY
  {0, 0, 0, 0, 0, 0, 0},  // 59 ';'  NO DISPLAY
  {0, 0, 0, 0, 0, 0, 0},  // 60 '<'  NO DISPLAY
  {0, 0, 0, 0, 0, 0, 0},  // 61 '='  NO DISPLAY
  {0, 0, 0, 0, 0, 0, 0},  // 62 '>'  NO DISPLAY
  {0, 0, 0, 0, 0, 0, 0},  // 63 '?'  NO DISPLAY
  {0, 0, 0, 0, 0, 0, 0},  // 64 '@'  NO DISPLAY
  {1, 1, 1, 0, 1, 1, 1},  // 65 'A'
  {0, 0, 1, 1, 1, 1, 1},  // 66 'B'
  {1, 0, 0, 1, 1, 1, 0},  // 67 'C'
  {0, 1, 1, 1, 1, 0, 1},  // 68 'D'
  {1, 0, 0, 1, 1, 1, 1},  // 69 'E'
  {1, 0, 0, 0, 1, 1, 1},  // 70 'F'
  {1, 0, 1, 1, 1, 1, 0},  // 71 'G'
  {0, 1, 1, 0, 1, 1, 1},  // 72 'H'
  {0, 1, 1, 0, 0, 0, 0},  // 73 'I'
  {0, 1, 1, 1, 0, 0, 0},  // 74 'J'
  {0, 0, 0, 0, 0, 0, 0},  // 75 'K'  NO DISPLAY
  {0, 0, 0, 1, 1, 1, 0},  // 76 'L'
  {0, 0, 0, 0, 0, 0, 0},  // 77 'M'  NO DISPLAY
  {0, 0, 1, 0, 1, 0, 1},  // 78 'N'
  {1, 1, 1, 1, 1, 1, 0},  // 79 'O'
  {1, 1, 0, 1, 1, 1, 1},  // 80 'P'
  {1, 1, 1, 0, 0, 1, 1},  // 81 'Q'
  {0, 0, 0, 0, 1, 0, 1},  // 82 'R'
  {1, 0, 1, 1, 0, 1, 1},  // 83 'S'
  {0, 0, 0, 1, 1, 1, 1},  // 84 'T'
  {0, 1, 1, 1, 1, 1, 0},  // 85 'U'
  {0, 0, 0, 0, 0, 0, 0},  // 86 'V'  NO DISPLAY
  {0, 0, 0, 0, 0, 0, 0},  // 87 'W'  NO DISPLAY
  {0, 0, 0, 0, 0, 0, 0},  // 88 'X'  NO DISPLAY
  {0, 1, 1, 1, 0, 1, 1},  // 89 'Y'
  {0, 0, 0, 0, 0, 0, 0},  // 90 'Z'  NO DISPLAY
  {1, 0, 0, 1, 1, 1, 0},  // 91 '['
  {0, 0, 0, 0, 0, 0, 0},  // 92 '\'  NO DISPLAY
  {1, 1, 1, 1, 0, 0, 0},  // 93 ']'
  {0, 0, 0, 0, 0, 0, 0},  // 94 '^'  NO DISPLAY
  {0, 0, 0, 1, 0, 0, 0},  // 95 '_'
  {0, 0, 0, 0, 0, 1, 0},  // 96 '`'
  {1, 1, 1, 0, 1, 1, 1},  // 97 'a' SAME AS CAP
  {0, 0, 1, 1, 1, 1, 1},  // 98 'b' SAME AS CAP
  {0, 0, 0, 1, 1, 0, 1},  // 99 'c'
  {0, 1, 1, 1, 1, 0, 1},  // 100 'd' SAME AS CAP
  {1, 1, 0, 1, 1, 1, 1},  // 101 'e'
  {1, 0, 0, 0, 1, 1, 1},  // 102 'f' SAME AS CAP
  {1, 0, 1, 1, 1, 1, 0},  // 103 'g' SAME AS CAP
  {0, 0, 1, 0, 1, 1, 1},  // 104 'h'
  {0, 0, 1, 0, 0, 0, 0},  // 105 'i'
  {0, 1, 1, 1, 0, 0, 0},  // 106 'j' SAME AS CAP
  {0, 0, 0, 0, 0, 0, 0},  // 107 'k'  NO DISPLAY
  {0, 1, 1, 0, 0, 0, 0},  // 108 'l'
  {0, 0, 0, 0, 0, 0, 0},  // 109 'm'  NO DISPLAY
  {0, 0, 1, 0, 1, 0, 1},  // 110 'n' SAME AS CAP
  {0, 0, 1, 1, 1, 0, 1},  // 111 'o'
  {1, 1, 0, 0, 1, 1, 1},  // 112 'p' SAME AS CAP
  {1, 1, 1, 0, 0, 1, 1},  // 113 'q' SAME AS CAP
  {0, 0, 0, 0, 1, 0, 1},  // 114 'r' SAME AS CAP
  {1, 0, 1, 1, 0, 1, 1},  // 115 's' SAME AS CAP
  {0, 0, 0, 1, 1, 1, 1},  // 116 't' SAME AS CAP
  {0, 0, 1, 1, 1, 0, 0},  // 117 'u'
  {0, 0, 0, 0, 0, 0, 0},  // 118 'b'  NO DISPLAY
  {0, 0, 0, 0, 0, 0, 0},  // 119 'w'  NO DISPLAY
  {0, 0, 0, 0, 0, 0, 0},  // 120 'x'  NO DISPLAY
  {0, 0, 0, 0, 0, 0, 0},  // 121 'y'  NO DISPLAY
  {0, 0, 0, 0, 0, 0, 0},  // 122 'z'  NO DISPLAY
  {0, 0, 0, 0, 0, 0, 0},  // 123 '{'  NO DISPLAY
  {0, 0, 0, 0, 0, 0, 0},  // 124 '|'  NO DISPLAY
  {0, 0, 0, 0, 0, 0, 0},  // 125 '}'  NO DISPLAY
  {0, 0, 0, 0, 0, 0, 0},  // 126 '~'  NO DISPLAY
  {0, 0, 0, 0, 0, 0, 0},  // 127 'DEL'  NO DISPLAY
};


class SevSeg {

public:
  SevSeg();

  //Public Functions
  void DisplayString(char*, byte, unsigned int);
//  void NewNumber(int number_in, byte DecPlace_in); 
  void Begin(boolean mode_in, byte numOfDigits, byte digit1, byte digit2, byte digit3, byte digit4, byte segment1, byte segment2, byte segment3, byte segment4, byte segment5, byte segment6, byte segment7, byte segmentDP);

  //Public Variables

private:
  //Private Functions
  void displayCharacter(byte characterToDisplay); //Illuminates the correct segments
  void SplitNumber(int);

  //Private Variables
  boolean mode, DigitOn, DigitOff, SegOn, SegOff;

  byte digit1, digit2, digit3, digit4;
  byte segmentA, segmentB, segmentC, segmentD, segmentE, segmentF, segmentG, segmentDP;
  
  byte numberOfDigits;

  byte DigitPins[4];
  byte SegmentPins[8];
  boolean lights[4][8];
  byte nums[4];

  byte DecPlace;
};

#endif

