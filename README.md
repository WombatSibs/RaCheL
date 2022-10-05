# RaCheL
RAspberry pi CHEss cLock

This project provides the necessary software and hardware-wiring-schematics for running a (hopefully) functional chess clock on a Raspberry Pi.


The hardware wiring consists of a resistor (we used 12k ohm, reasonable deviation should be fine), a switch and some wires.
Connect the resistor via a wire to a 3.3V pin.
On the other side of the resistor, connect another wire, which 'splits' up into two wires.
Connect one end to a GPIO pin (by default, pin 13 (GPIO 2 according to the wiringPi library) is expected).
Attach the switch to the other wire and connect the other side of the switch to one of the 'ground' pins.
In the end, the result should look something like this:

3.3V----   <br>
       |   <br>
       R   <br>
       |   <br>
GP02---|   <br>
       |   <br>
       S   <br>
       |   <br>
GRND----   <br>

where R is a resistor, S a switch and 3.3, G02 and GND the pins.
We used pins 1 (3.3V), 13 (GPIO) and 39 (ground).
The pin for detecting the input can be changed, but this also requires a change in the code.
In particular, the value 2 in pinMode(2, INPUT) in main.cpp and digitalRead(2) in clock.cpp needs to be changed to whatever pin you choose.
Make sure to use the values from the wiringPi library, which you can get by calling 'gpio readall' in the terminal/console.
For checking if the switch works, 'gpio read 2' (with 2 being the number of the pin) can be called in the terminal.
