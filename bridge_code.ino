#include <ESP32Servo.h>


Servo servoLeft;
Servo servoRight;


const int waterSensor = 13;      
const int redLED = 19;
const int greenLED = 21;
const int buzzer = 18;
const int servoLeft = 16;
const int servoRight = 17;



void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(waterSensor, INPUT);

  servoLeft.attach(servoLeft);
  servoRight.attach(servoRight);

 
  servoLeft.write(0);     
  servoRight.write(0);     
  digitalWrite(greenLED, HIGH);
  digitalWrite(redLED, LOW);
  digitalWrite(buzzer, LOW);
}

void loop() {
  int sensorValue = analogRead(waterSensor);

  if (sensorValue ==HIGH) {
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
    digitalWrite(buzzer, HIGH);

    servoLeft.write(45);
    servoRight.write(45);

  } else {
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
    digitalWrite(buzzer, LOW);

    servoLeft.write(0);
    servoRight.write(0);
  }

delay(500);
}
