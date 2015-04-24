/*
 March 6, 2014
 Spark Fun Electronics
 Nathan Seidle
 Updates by Joel Bartlett
 
 This code is originally based Dean Reading's Library deanreading@hotmail.com
 http://arduino.cc/playground/Main/SevenSegmentLibrary
 He didn't have a license on it so I hope he doesn't mind me making it public domain: 
 This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).
 
This example gives you a real world scenario in which we take sensor data (in this case temperature and humidity
data from a SHT15) and print it to the bubble display using characters and numbers. 
 
 
 Pinout for HP Bubble Display:
 1:  Cathode 1
 2:  Anode E
 3:  Anode C
 4:  Cathode 3
 5:  Anode dp
 6:  Cathode 4
 7:  Anode G
 8:  Anode D
 9:  Anode F
 10: Cathode 2
 11: Anode B
 12: Anode A
 
 Pinout for SHT15:
 Vcc: 3.3V
 Data: A4 or SDA on newer Arduino boards
 SCK: A5 or SCK on newer Arduino boards 
 GND: GND
 
 Here is the character map found in the SevSeg.h file for reference 
 as to which characters can be displayed and which can't. 
 
 //  ABCDEFG  Segments
  0b1111110, // 0
  0b0110000, // 1
  0b1101101, // 2
  0b1111001, // 3
  0b0110011, // 4
  0b1011011, // 5
  0b1011111, // 6
  0b1110000, // 7
  0b1111111, // 8
  0b1111011, // 9
  0b1110111, // 10  "A"
  0b0011111, // 11  "B"
  0b1001110, // 12  "C"
  0b0111101, // 13  "D"
  0b1001111, // 14  "E"
  0b1000111, // 15  "F"
  0b0000000, // 16  NO DISPLAY
  0b0000000, // 17  NO DISPLAY
  0b0000000, // 18  NO DISPLAY
  0b0000000, // 19  NO DISPLAY
  0b0000000, // 20  NO DISPLAY
  0b0000000, // 21  NO DISPLAY
  0b0000000, // 22  NO DISPLAY
  0b0000000, // 23  NO DISPLAY
  0b0000000, // 24  NO DISPLAY
  0b0000000, // 25  NO DISPLAY
  0b0000000, // 26  NO DISPLAY
  0b0000000, // 27  NO DISPLAY
  0b0000000, // 28  NO DISPLAY
  0b0000000, // 29  NO DISPLAY
  0b0000000, // 30  NO DISPLAY
  0b0000000, // 31  NO DISPLAY
  0b0000000, // 32 ' '
  0b0000000, // 33 '!'  NO DISPLAY
  0b0100010, // 34 '"'
  0b0000000, // 35 '#'  NO DISPLAY
  0b0000000, // 36 '$'  NO DISPLAY
  0b0000000, // 37 '%'  NO DISPLAY
  0b0000000, // 38 '&'  NO DISPLAY
  0b0100000, // 39 '''
  0b1001110, // 40 '('
  0b1111000, // 41 ')'
  0b0000000, // 42 '*'  NO DISPLAY
  0b0000000, // 43 '+'  NO DISPLAY
  0b0000100, // 44 ','
  0b0000001, // 45 '-'
  0b0000000, // 46 '.'  NO DISPLAY
  0b0000000, // 47 '/'  NO DISPLAY
  0b1111110, // 48 '0'
  0b0110000, // 49 '1'
  0b1101101, // 50 '2'
  0b1111001, // 51 '3'
  0b0110011, // 52 '4'
  0b1011011, // 53 '5'
  0b1011111, // 54 '6'
  0b1110000, // 55 '7'
  0b1111111, // 56 '8'
  0b1111011, // 57 '9'
  0b0000000, // 58 ':'  NO DISPLAY
  0b0000000, // 59 ';'  NO DISPLAY
  0b0000000, // 60 '<'  NO DISPLAY
  0b0000000, // 61 '='  NO DISPLAY
  0b0000000, // 62 '>'  NO DISPLAY
  0b0000000, // 63 '?'  NO DISPLAY
  0b0000000, // 64 '@'  NO DISPLAY
  0b1110111, // 65 'A'
  0b0011111, // 66 'B'
  0b1001110, // 67 'C'
  0b0111101, // 68 'D'
  0b1001111, // 69 'E'
  0b1000111, // 70 'F'
  0b1011110, // 71 'G'
  0b0110111, // 72 'H'
  0b0110000, // 73 'I'
  0b0111000, // 74 'J'
  0b0000000, // 75 'K'  NO DISPLAY
  0b0001110, // 76 'L'
  0b0000000, // 77 'M'  NO DISPLAY
  0b0010101, // 78 'N'
  0b1111110, // 79 'O'
  0b1101111, // 80 'P'
  0b1110011, // 81 'Q'
  0b0000101, // 82 'R'
  0b1011011, // 83 'S'
  0b0001111, // 84 'T'
  0b0111110, // 85 'U'
  0b0000000, // 86 'V'  NO DISPLAY
  0b0000000, // 87 'W'  NO DISPLAY
  0b0000000, // 88 'X'  NO DISPLAY
  0b0111011, // 89 'Y'
  0b0000000, // 90 'Z'  NO DISPLAY
  0b1001110, // 91 '['
  0b0000000, // 92 '\'  NO DISPLAY
  0b1111000, // 93 ']'
  0b0000000, // 94 '^'  NO DISPLAY
  0b0001000, // 95 '_'
  0b0000010, // 96 '`'
  0b1110111, // 97 'a' SAME AS CAP
  0b0011111, // 98 'b' SAME AS CAP
  0b0001101, // 99 'c'
  0b0111101, // 100 'd' SAME AS CAP
  0b1101111, // 101 'e'
  0b1000111, // 102 'f' SAME AS CAP
  0b1011110, // 103 'g' SAME AS CAP
  0b0010111, // 104 'h'
  0b0010000, // 105 'i'
  0b0111000, // 106 'j' SAME AS CAP
  0b0000000, // 107 'k'  NO DISPLAY
  0b0110000, // 108 'l'
  0b0000000, // 109 'm'  NO DISPLAY
  0b0010101, // 110 'n' SAME AS CAP
  0b0011101, // 111 'o'
  0b1100111, // 112 'p' SAME AS CAP
  0b1110011, // 113 'q' SAME AS CAP
  0b0000101, // 114 'r' SAME AS CAP
  0b1011011, // 115 's' SAME AS CAP
  0b0001111, // 116 't' SAME AS CAP
  0b0011100, // 117 'u'
  0b0000000, // 118 'b'  NO DISPLAY
  0b0000000, // 119 'w'  NO DISPLAY
  0b0000000, // 120 'x'  NO DISPLAY
  0b0000000, // 121 'y'  NO DISPLAY
  0b0000000, // 122 'z'  NO DISPLAY
  0b0000000, // 123 '0b'  NO DISPLAY
  0b0000000, // 124 '|'  NO DISPLAY
  0b0000000, // 125 ','  NO DISPLAY
  0b0000000, // 126 '~'  NO DISPLAY
  0b0000000, // 127 'DEL'  NO DISPLAY
  
  SHT15 code based on the code found at Wiring.org
  http://wiring.org.co/learning/basics/humiditytemperaturesht15.html

 */


#include "SevSeg.h"

//Create an instance of the object.
SevSeg myDisplay;

int temperatureCommand  = B00000011;  // command used to read temperature 
int humidityCommand = B00000101;  // command used to read humidity 
 
int clockPin = A5;  // pin used for clock 
int dataPin  = A4;  // pin used for data 
int ack;  // track acknowledgment for errors 
int val;  
float tempF;          
float humidity; 
float tempC;

char tempString[5];
//-------------------------------------------------------------------------------------------
void setup()
{
 int displayType = COMMON_CATHODE; //Your display is either common cathode or common anode

  //This pinout is for a bubble dispaly
       //Declare what pins are connected to the GND pins (cathodes)
       int digit1 = 8; //Pin 1
       int digit2 = 5; //Pin 10
       int digit3 = 11; //Pin 4
       int digit4 = 13; //Pin 6
       
       //Declare what pins are connected to the segments (anodes)
       int segA = 7; //Pin 12
       int segB = 6; //Pin 11
       int segC = 10; //Pin 3
       int segD = 3; //Pin 8
       int segE = 9; //Pin 2
       int segF = 4; //Pin 9
       int segG = 2; //Pin 7
       int segDP= 12; //Pin 5
   
  int numberOfDigits = 4; //Do you have a 1, 2 or 4 digit display?

  myDisplay.Begin(displayType, numberOfDigits, digit1, digit2, digit3, digit4, segA, segB, segC, segD, segE, segF, segG, segDP);
  
  myDisplay.SetBrightness(100); //Set the display to 100% brightness level
}
//-------------------------------------------------------------------------------------------
void loop()
{
  
  sht15();
  clear();
  for(int i =0;i<500;i++)
  {
      tempString[0] = 'T'; 
      tempString[1] = 'F';
   
      myDisplay.DisplayString(tempString, 0);
 
    sprintf(tempString, "%4d",  (long)tempF, DEC);
    myDisplay.DisplayString(tempString, 0);
  }
  clear();
   for(int i =0;i<500;i++)
  {
      tempString[0] = 'R'; 
      tempString[1] = 'H';
    
    myDisplay.DisplayString(tempString, 0);

    sprintf(tempString, "%4d",  (long)humidity, DEC);
    myDisplay.DisplayString(tempString, 0);
  }
}
//-------------------------------------------------------------------------------------------
void clear()
{
      //write a non-displayable character to each position to clear the display
      tempString[0] = 'm'; 
      tempString[1] = 'm';
      tempString[2] = 'm';
      tempString[3] = 'm';
   
      myDisplay.DisplayString(tempString, 0);
}
//-------------------------------------------------------------------------------------------
int sht15()
{
  // read the temperature and convert it to centigrades 
  sendCommandSHT(temperatureCommand, dataPin, clockPin); 
  waitForResultSHT(dataPin); 
  val = getData16SHT(dataPin, clockPin); 
  skipCrcSHT(dataPin, clockPin); 
  tempC = (float)val * 0.01 - 40; 
  tempF = (float)tempC * 1.8 + 32;
  
  //Serial.print("Temperature: "); 
  //Serial.print((long)tempF, DEC);
  //Serial.print("_"); 
  //Serial.print((char)176); 
  //Serial.print("F "); 
  
  // read the humidity 
  sendCommandSHT(humidityCommand, dataPin, clockPin); 
  waitForResultSHT(dataPin); 
  val = getData16SHT(dataPin, clockPin); 
  skipCrcSHT(dataPin, clockPin); 
  humidity = -4.0 + 0.0405 * val + -0.0000028 * val * val; 
  
  //Serial.print(" Relative Humidity: "); 
  //Serial.print((long)humidity, DEC); 
   //Serial.println("%");
  //delay(1000); // wait for 3 sec for next reading 
  return tempF, tempC, humidity;
}
 
 
// commands for reading/sending data to a SHTx sensor 
 
int shiftIn(int dataPin, int clockPin, int numBits) { 
  int ret = 0; 
 
  for (int i=0; i<numBits; ++i) { 
    digitalWrite(clockPin, HIGH); 
    //delay(10); not needed :) 
    ret = ret*2 + digitalRead(dataPin); 
    digitalWrite(clockPin, LOW); 
  } 
  return(ret); 
} 
 
// send a command to the SHTx sensor 
void sendCommandSHT(int command, int dataPin, int clockPin) { 
  int ack; 
 
  // transmission start 
  pinMode(dataPin, OUTPUT); 
  pinMode(clockPin, OUTPUT); 
  digitalWrite(dataPin, HIGH); 
  digitalWrite(clockPin, HIGH); 
  digitalWrite(dataPin, LOW); 
  digitalWrite(clockPin, LOW); 
  digitalWrite(clockPin, HIGH); 
  digitalWrite(dataPin, HIGH); 
  digitalWrite(clockPin, LOW); 
  
  // shift out the command (the 3 MSB are address and must be 000, the last 5 bits are the command) 
  shiftOut(dataPin, clockPin, MSBFIRST, command); 
  
  // verify we get the right ACK 
  digitalWrite(clockPin, HIGH); 
  pinMode(dataPin, INPUT); 
  ack = digitalRead(dataPin); 
  if (ack != LOW) 
    Serial.println("ACK error 0"); 
  digitalWrite(clockPin, LOW); 
  ack = digitalRead(dataPin); 
  if (ack != HIGH) 
    Serial.println("ACK error 1"); 
} 
 
// wait for the SHTx answer 
void waitForResultSHT(int dataPin) { 
  int ack; 
 
  pinMode(dataPin, INPUT); 
  for(int i=0; i<100; ++i) { 
    delay(10); 
    ack = digitalRead(dataPin); 
    if (ack == LOW) 
      break; 
  } 
  if (ack == HIGH) 
    Serial.println("ACK error 2"); 
} 
 
// get data from the SHTx sensor 
int getData16SHT(int dataPin, int clockPin) { 
  int val; 
 
  // get the MSB (most significant bits) 
  pinMode(dataPin, INPUT); 
  pinMode(clockPin, OUTPUT); 
  val = shiftIn(dataPin, clockPin, 8); 
  val *= 256; // this is equivalent to val << 8; 
  
  // send the required ACK 
  pinMode(dataPin, OUTPUT); 
  digitalWrite(dataPin, HIGH); 
  digitalWrite(dataPin, LOW); 
  digitalWrite(clockPin, HIGH); 
  digitalWrite(clockPin, LOW); 
  
  // get the LSB (less significant bits) 
  pinMode(dataPin, INPUT); 
  val |= shiftIn(dataPin, clockPin, 8); 
  return val; 
} 
 
// skip CRC data from the SHTx sensor 
void skipCrcSHT(int dataPin, int clockPin) { 
  pinMode(dataPin, OUTPUT); 
  pinMode(clockPin, OUTPUT); 
  digitalWrite(dataPin, HIGH); 
  digitalWrite(clockPin, HIGH); 
  digitalWrite(clockPin, LOW); 
} 
//-------------------------------------------------------------------------------------------
