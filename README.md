# arduino-basics
This package contains a collection of stand-alone Arduino sketches to try out some basic functionality.
## How to use
The code in this package was tested with an Arduino 101.  Your mileage may vary with other boards.

To run the sketches, you will want to have the Arduino IDE installed on your computer.  You can get it here: [Arduino IDE](https://www.arduino.cc/en/Main/Software)

In most cases, the pins used in the project will be defined at the top of the sketch like this:
```
const int TRIGGER = A0;
const int ECHO = A1;
```
If you plan on using different pins, just change the value in the variable assignment.
