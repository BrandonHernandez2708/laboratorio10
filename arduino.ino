#include <Servo.h>

Servo myServo;
int servoPin = 9;

void setup() {
  myServo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char direccion = Serial.read();
    int angulo = Serial.parseInt();
    
    if (direccion == 'd') {
      rotateServo(angulo, 'd');
    } else if (direccion == 'i') {
      rotateServo(angulo, 'i');
    }
  }
}

void rotateServo(int angulo, char direccion) {
  int currentMicroseconds = myServo.readMicroseconds();
  int targetMicroseconds = map(angulo, 0, 180, 1000, 2000);
  
  if (direccion == 'r') {
    while (currentMicroseconds < targetMicroseconds) {
      currentMicroseconds += 1;
      if (currentMicroseconds > targetMicroseconds) currentMicroseconds = targetMicroseconds;
      myServo.writeMicroseconds(currentMicroseconds);
      delay(15);
    }
  } else if (direccion == 'l') {
    while (currentMicroseconds > targetMicroseconds) {
      currentMicroseconds -= 1;
      if (currentMicroseconds < targetMicroseconds) currentMicroseconds = targetMicroseconds;
      myServo.writeMicroseconds(currentMicroseconds);
      delay(15);
    }
  }
  
  myServo.writeMicroseconds(targetMicroseconds);
}
