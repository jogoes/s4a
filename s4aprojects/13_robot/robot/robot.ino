// (JGoebel)
// Simple sketch to cntrol a robot equipped with a HC-SR04 distance sensor and two DC motors wired to a L293D motor driver.

#include <avr/io.h>
#include <avr/interrupt.h>

#include "light.h"
#include "motorcontrol.h"
#include "distancecontrol.h"

// current distance to obstacle is updated via interrupt
volatile int currentDistance = 0;

// initialize motors
const int PIN_MOTOR1_1 = 10;                  
const int PIN_MOTOR1_2 = 11;

const int PIN_MOTOR2_1 = 12;
const int PIN_MOTOR2_2 = 13;

Motor motor1(PIN_MOTOR1_1, PIN_MOTOR1_2);
Motor motor2(PIN_MOTOR2_1, PIN_MOTOR2_2);

MotorControl motorControl(motor1, motor2, &currentDistance);

// initialize distance control sensor
const int PIN_TRIGGER = 3;
const int PIN_ECHO = 4;

DistanceControl distanceControl(PIN_TRIGGER, PIN_ECHO);

// initialize LEDs
const int PIN_RED_LED = 7;
const int PIN_GREEN_LED = 8;

Light redLED(PIN_RED_LED);
Light greenLED(PIN_GREEN_LED);

void setup() {
  Serial.begin(9600);

  // initialize random number generator
  randomSeed(analogRead(0));
  
  // setup timer
  OCR0A = 0xAF;
  TIMSK0 |= _BV(OCIE0A);  
}

unsigned long lastMillis = 0;

SIGNAL(TIMER0_COMPA_vect) {
  unsigned long currentMillis = millis();
  unsigned long elapsedMillis = currentMillis - lastMillis;
  // measure the distance only every 500ms
  if(elapsedMillis < 500) {
    return;
  }

  lastMillis = currentMillis;
  currentDistance = distanceControl.getDistance();
  Serial.println(currentDistance);
}

void robotAvoidObstacle() {
    redLED.on();
    motorControl.backward(1000);
    delay(500);
    redLED.off();
    // turn left or right based on random value
    int rnd = random(2);
    if(rnd == 0) {
      motorControl.turnLeft(500);    
    } else {
      motorControl.turnRight(500);    
    }
    delay(500);
    greenLED.on();
    motorControl.forward(1000);
    greenLED.off();
    delay(200);
}

void loop() {  
  if(currentDistance < 20) {
    robotAvoidObstacle();
  }
}
