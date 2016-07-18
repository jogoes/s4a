## A robot with S4A and Arduino
This project contains the schematics and code for a simple robot. The robot is based on two DC motors
and a HC-SR04 distance sensor used to avoid crashing into obstacles. 

You can find Arduino code which is used control the robot and giving it a very limited level of intelligence... 
Basically, all the code does is detecting whether there is an obstacle within close in front. If this is the case 
the robot is moving backwards, turning and moving forward again.

An S4A project is provided that can be used to control the robot using the arrow keys. Since S4A always requires 
being connected to the Arduino, the use of this is limited unless you find a way to handle the cables somehow.

For this reason schematics are provided showing how to connect an XBee device to the robot allowing  
wirelessly controlling the robot. 
Unfortunately, the XBee devices requires a bit of setup in order for them to work together. Some information on how to 
do this can be found here: https://learn.sparkfun.com/tutorials/exploring-xbees-and-xctu

More information can also be found in this book: http://shop.oreilly.com/product/9780596807740.do




