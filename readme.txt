This library allows an Arduino to easily display numbers in decimal format on a 4 digit 7-segment display without a separate 7-segment display controller.

Original Library by Dean Reading, 2012
Improvements by Nathan Seidle, 2012

Version 2.0; Now works for any digital pin arrangement, common anode and common cathode displays.
Direct any questions or suggestions to deanreading@hotmail.com

Hardware Setup:
4 digit 7 segment displays use 12 digital pins.

There are:
4 common pins; 1 for each digit. These will be cathodes (negative pins) for common cathode displays, or anodes (positive pins) for common anode displays. These are referred to as 'digit' pins.

8 pins for the individual segments (seven segments plus the decimal point). I refer to these as 'segment' pins.

Connect the four digit pins with four limiting resistors in series to any digital or analog pins. Connect the eight segment pins to any digital or analog pins.