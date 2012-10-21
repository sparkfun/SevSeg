This library allows an Arduino to easily display numbers and characters on a 4 digit 7-segment display without a separate 7-segment display controller.

If you have feature suggestions or need support please use the github support page: https://github.com/sparkfun/SevSeg

Original Library by Dean Reading (deanreading@hotmail.com: http://arduino.cc/playground/Main/SevenSegmentLibrary), 2012

Improvements by Nathan Seidle, 2012

Now works for any digital pin arrangement, common anode and common cathode displays. 
Added character support including letters A-F and many symbols.

Hardware Setup: 4 digit 7 segment displays use 12 digital pins. You may need more pins if your display has colons or apostrophes.

There are 4 digit pins and 8 segment pins. Digit pins are connected to the cathodes for common cathode displays, or anodes for common anode displays. 8 pins control the individual segments (seven segments plus the decimal point). 

Connect the four digit pins with four limiting resistors in series to any digital or analog pins. Connect the eight segment pins to any digital or analog pins (no limiting resistors needed). See the SevSeg example for more connection information.
