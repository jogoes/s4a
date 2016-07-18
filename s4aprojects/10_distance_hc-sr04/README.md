## Measuring distances with S4A and Arduino
This project demonstrates the usage of the HC-SR04 ultrasonic distance sensor with S4A and Arduino.

**Important note:** This project requires a custom firmware as found in here to be uploaded to the Arduino. 
This firmware is based on the standard S4A firmware and extends it by triggering the HC-SR04 sensor and returning
the measured distances back to S4A in the Analog3 value.
