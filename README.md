This library allows an Arduino to easily display numbers and characters on a 4 digit 7-segment display without a separate 7-segment display controller.
It works for any digital pin arrangement, common anode and common cathode displays. It also has character support including letters A-F and many symbols. 

Hardware Setup
--------------
4 digit 7 segment displays use 12 digital pins. You may need more pins if your display has colons or apostrophes.

There are 4 digit pins and 8 segment pins. Digit pins are connected to the cathodes for common cathode displays, or anodes for common anode displays. 8 pins control the individual segments (seven segments plus the decimal point). 

Connect the four digit pins with four limiting resistors in series to any digital or analog pins. Connect the eight segment pins to any digital or analog pins (no limiting resistors needed). See the SevSeg example for more connection information.

Repository Contents
-------------------

* **/examples** - Arduino example sketches
* **/src** - Source files for Arduino library

Documentation
--------------
* **[Hookup Guide](https://learn.sparkfun.com/tutorials/using-the-serial-7-segment-display)** - Basic hookup guide for the Serial Segment Displays.
* **[Compatible Displays](https://www.sparkfun.com/wish_lists/120699)** - Products that work with this code. 

License Information
-------------------
Original Library by Dean Reading (deanreading@hotmail.com: http://arduino.cc/playground/Main/SevenSegmentLibrary), 2012

Improvements by Nathan Seidle, 2012

All code is open source so please feel free to do anything you want with it; you buy me a beer if you use this and we meet someday ([Beerware license](http://en.wikipedia.org/wiki/Beerware)).
