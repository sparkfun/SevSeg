/*
 7-23-2012
 Spark Fun Electronics
 Nathan Seidle
 
 This code is originally based Dean Reading's Library deanreading@hotmail.com
 http://arduino.cc/playground/Main/SevenSegmentLibrary
 He didn't have a license on it so I hope he doesn't mind me making it public domain:
 
 This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).
 
 This example is a centi-second counter to demonstrate the use of the SevSeg library.

 I have a cheap one from China, and the pins of the display are in the following order:
 Top Row
 1,a,f,2,3,b
 Bottom Row
 e,d,dp,c,g,4
 Where the digit pins are 1-4 and the segment pins are a-g + dp
 
 ToDo:
 Allow for user selectable digits
 Pass in a brightness value
 Picture of setup with pin 1 indicator
 Possibly allow user to specify leading zeros or no
 
 2264 bytes
 2134 bytes with new BigTime functions
 2214 if full DP support

 < is usually faster than <= (only one check instead of two)
 
 */

#include "SevSeg.h"

//Create an instance of the object.
SevSeg sevseg;

//Create global variables
unsigned long timer;
int CentSec = 0;

void setup() {

  int displayType = COMMON_CATHODE;
  
  //Declare what pins are connected to the digits
  int digit1 = 2; //Pin 12 on 4 digit display
  int digit2 = 3; //Pin 9 on 4 digit display
  int digit3 = 4; //Pin 8 on 4 digit display
  int digit4 = 5; //Pin 6 on 4 digit display
  
  //Declare what pins are connected to the segments
  int segA = 6; //Pin 11 on 4 digit display
  int segB = 7; //Pin 7 on 4 digit display
  int segC = 8; //Pin 4 on 4 digit display
  int segD = 9; //Pin 2 on 4 digit display
  int segE = 10; //Pin 1 on 4 digit display
  int segF = 11; //Pin 10 on 4 digit display
  int segG = 12; //Pin 5 on 4 digit display
  int segDP= 13; //Pin 3 on 4 digit display
  
  int numberOfDigits = 4;

  sevseg.Begin(displayType, numberOfDigits, digit1, digit2, digit3, digit4, segA, segB, segC, segD, segE, segF, segG, segDP);

  timer = millis();
}

void loop() {
  //Produce an output on the display
  sevseg.DisplayNumber(CentSec, 2);

  //Check if 10ms has elapsed
  unsigned long mils = millis();
  
  if (mils - timer >= 10) {
    timer = mils;
    CentSec++;

    //Update the number to be displayed, with a decimal
    //place in the correct position.
    //sevseg.NewNumber(CentSec, (byte)2);
  }
}




