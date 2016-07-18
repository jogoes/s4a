/* YourDuino Electronic Brick Test: 
 Light Sensor Analog + Digital AB-890202
 terry@yourduino.com */

/*-----( Declare Constants )-----*/
#define ANALOG_SENSOR_PIN  A0 
#define DIGITAL_SENSOR_PIN 3
#define LEDPIN    13  // The onboard LED

/*-----( Declare Variables )-----*/
int  switch_state;  /* Holds the last digital value */
int  LightAnalogValue; /* Holds the last analog value */

void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  pinMode(LEDPIN, OUTPUT);
  Serial.begin(9600);          // Enable the Serial data output
  Serial.println("YourDuino Light Sensor Test 1.10 ");  

}/*--(end setup )---*/


void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/

// This module is ACTIVE LOW when a reflection is seen
{

  switch_state = digitalRead(DIGITAL_SENSOR_PIN);  
  if (switch_state == LOW)
  {
    digitalWrite(LEDPIN, HIGH);
    Serial.println("Digital Signal ON ");
  }  
  else
  {
    digitalWrite(LEDPIN, LOW);
  }

  LightAnalogValue = analogRead(ANALOG_SENSOR_PIN);  //Read the voltage from sensor
  Serial.print("Analog Value (0 to 1023)"); 
  Serial.println(LightAnalogValue,DEC);      // Send result to Serial Monitor

  Serial.println(analogRead(A1));
  
  delay(500);

}
