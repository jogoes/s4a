# Scratch for Arduino (S4A) and Arduino
A collection of projects for combining S4A and Arduino. All projects are provided with schematics.

Before using the projects make sure you upload the S4A firmware onto the Arduino. The firmware can be downloaded from 
http://s4a.cat/.

Some of the projects require a
customized firmware because with the standard S4A firmware it's not possible (or at least difficult) to get appropriate
sensor values. For instance, for the HC-SR04 distance sensor it's required to trigger the sensor in order to get the 
travel time of the signal. The custom firmware makes this easy by periodically triggering the signal and returning the 
measured distance in centimeters in one of the Analog values in S4A.


