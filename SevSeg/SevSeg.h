//Written by Dean Reading, 2012.  deanreading@hotmail.com
//See .cpp file for info

#ifndef SevSeg_h
#define SevSeg_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif


class SevSeg {

public:
  SevSeg();

  //Public Functions
  void PrintOutput();
  void NewNum(int number_in, byte DecPlace_in); 
  void Begin(boolean mode_in, byte C1, byte C2, byte C3, byte C4, byte UC1, byte UC2, byte UC3, byte UC4, byte UC5, byte UC6, byte UC7, byte UC8);

  //Public Variables


private:
  //Private Functions
  void CreateArray();
  void FindNums();

  //Private Variables
  boolean mode, DigitOn, DigitOff, SegOn, SegOff;
  byte DigitPins[4];
  byte SegmentPins[8];
  boolean lights[4][8];
  byte nums[4];
  int number;
  byte DecPlace;
  boolean negative;

};

#endif

