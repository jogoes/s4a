class Light {
  int m_pin;
  public:
    Light(int pin) : m_pin(pin) {
      pinMode(pin, OUTPUT);      
    }
    void on() {
      digitalWrite(m_pin, HIGH);
    }
    void off() {
      digitalWrite(m_pin, LOW);
    }
};


