class DistanceControl {
  private:
    int m_triggerPin;
    int m_echoPin;
    
  public:
    DistanceControl(int triggerPin, int echoPin) : m_triggerPin(triggerPin), m_echoPin(echoPin) {
      pinMode(m_triggerPin, OUTPUT);
      pinMode(m_echoPin, INPUT);
    }

    long getDistance() {
      digitalWrite(m_triggerPin, LOW);
      delayMicroseconds(2);
      digitalWrite(m_triggerPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(m_echoPin, LOW);

      long durationMicroseconds = pulseIn(m_echoPin, HIGH);
      // speed of sound is 340 m/s which is 29 microseconds/cm
      // the signal travels twice the distance therefore return half of this distance
      return durationMicroseconds / 29 / 2;
    }
};

