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

#define BLANK 20 //Special case to display time without leading zeros
#define DASH 21 //Special character to display negative number and Not a Number (NaN)
#define DP 22 //Special case to turn on the decimal point segment


class SevSeg {

public:
  SevSeg();

  //Public Functions
  void DisplayNumber(int, byte);
  void NewNumber(int number_in, byte DecPlace_in); 
  void Begin(boolean mode_in, byte numOfDigits, byte digit1, byte digit2, byte digit3, byte digit4, byte segment1, byte segment2, byte segment3, byte segment4, byte segment5, byte segment6, byte segment7, byte segmentDP);

  //Public Variables


private:
  //Private Functions
  void lightNumber(byte numberToDisplay); //Illuminates the correct segments
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

