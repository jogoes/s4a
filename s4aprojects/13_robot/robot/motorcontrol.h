// Class used to abstract a DC motor connected on two pins via a motor driver like the L293D.
class Motor {
  private:
  int m_pin1;
  int m_pin2;
  
  public:
    Motor(int pin1, int pin2) {
      m_pin1 = pin1;
      m_pin2 = pin2;

      pinMode(m_pin1,OUTPUT); 
      pinMode(m_pin2,OUTPUT); 
  }

  void setPins(int state1, int state2) {
    digitalWrite(m_pin1, state1);
    digitalWrite(m_pin2, state2);
  }

  void backward() {
    setPins(HIGH, LOW);
  }
  
  void forward() {
    setPins(LOW, HIGH);
  }

  void stop() {
    setPins(LOW, LOW);
  }
};

class MotorControl {
  private:
    Motor& m_motorLeft;
    Motor& m_motorRight;
    volatile int* m_pCurrentDistance;

  public:
    MotorControl(Motor& motorLeft, Motor& motorRight, volatile int* pCurrentDistance) : 
          m_motorLeft(motorLeft), 
          m_motorRight(motorRight),
          m_pCurrentDistance(pCurrentDistance) {
    }

    void stop() {
      m_motorLeft.stop();
      m_motorRight.stop();
    }

    void stopAfterOrOnObstacle(int ms) {
      unsigned long startMillis = millis();
      while(millis() - startMillis < ms && *m_pCurrentDistance > 5) {
        delay(10);
      }
      m_motorLeft.stop();
      m_motorRight.stop();
    }
    
    void stopAfter(int ms) {
      delay(ms);
      m_motorLeft.stop();
      m_motorRight.stop();
    }
    
    void backward(int ms) {
      m_motorLeft.backward();
      m_motorRight.backward();
      stopAfter(ms);
    }
  
    void forward(int ms) {
      m_motorLeft.forward();
      m_motorRight.forward();
      stopAfterOrOnObstacle(ms);
    }

    void turnLeft(int ms) {
      m_motorLeft.backward();
      m_motorRight.forward();
      stopAfterOrOnObstacle(ms);
    }
    
    void turnRight(int ms) {
      m_motorLeft.forward();
      m_motorRight.backward();
      stopAfterOrOnObstacle(ms);
    }
};

