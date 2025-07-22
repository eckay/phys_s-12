#include <ESP32Servo.h>

int servoPin_x = 25;
int servoPin_y = 26;
int servoPin_z = 27;

const int veloPin = 34;
int veloVal;

class AxisServo {
  Servo servo;
  unsigned long prev_ms = 0;
  unsigned long current_ms;
  unsigned long prev_backtrack_ms = 0;
  int backtrack_interval = 1000;
  int timingInterval;
  int startPos;
  int endPos;
  int pos;
  bool direction = 1; // 1 is forward

  public:
  AxisServo(int interval_ms, int start_us, int end_us){
    timingInterval = interval_ms;
    startPos = start_us;
    endPos = end_us;
  }

  void Sweep() {
    current_ms = millis();

    if (current_ms - prev_ms > timingInterval) {
      if (direction) {
        pos += 1;
        servo.writeMicroseconds(pos);
        if (pos == endPos) {
          direction = 0;
        }
      }
      else {
        pos -= 1;
        servo.writeMicroseconds(pos);
        if (pos == startPos) {
          direction = 1;
        }
      }
      prev_ms = current_ms;
    }
  }

  void Backtrack() {
    if (millis() - prev_backtrack_ms > backtrack_interval) {
      pos = 520;
      servo.writeMicroseconds(pos);
      prev_ms = millis() + 100;
      prev_backtrack_ms = millis();
    }
  }

  void WriteMicros(int us) {
    servo.writeMicroseconds(us);
  }

  void Attach(int pin){
    servo.attach(pin);
    servo.writeMicroseconds(startPos);
    pos = startPos;
  }

  void Detach(){
    servo.detach();
  }

  void Write(int Pos) {
    servo.writeMicroseconds(Pos);
    pos = Pos;
  }

  int getPos() {
    return pos;
  }
};

AxisServo servoX(4, 900, 2000);
AxisServo servoY(4, 1200, 1800);
AxisServo servoZ(4, 500, 1250);

void setup() {
  servoX.Attach(servoPin_x);
  servoY.Attach(servoPin_y);
  servoZ.Attach(servoPin_z);
  servoZ.Write(1200);
  //pinMode(veloPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  //veloVal = analogRead(veloPin);
  
  servoZ.Sweep();
  servoY.Sweep();
  servoX.Sweep();
  /*if (veloVal > 0){
    servoZ.Backtrack();
  }*/
  //Serial.println(servoZ.getPos());
}
