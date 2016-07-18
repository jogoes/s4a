#include <IRremote.h> 
int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

int lastButtonCode = 0;

long getButtonCode() {
  long result = 0;
  if (irrecv.decode(&results)) {
    result = results.value;
    if(result != 0xffffffff) {
      lastButtonCode = result;
    } else {
      result = lastButtonCode;
    }
    irrecv.resume();
  } else {
    result = 0;
  }
  return result & 0xff;
}

void loop()
{
  int button = getButtonCode();
  if(button) {
    Serial.println(button, HEX);
  }
}
