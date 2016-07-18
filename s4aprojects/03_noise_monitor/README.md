# Noise monitor traffic lights for S4A and Arduino
This project utilizes a MAX 9814 amplifier (e.g. https://learn.adafruit.com/adafruit-agc-electret-microphone-amplifier-max9814/overview) 
to return the sound level to S4A. 

**Important Note**: this project requires the custom firmware as found here to be uploaded to the Arduino. The firmware 
returns the current sound level in the Analog5 value in S4A.
