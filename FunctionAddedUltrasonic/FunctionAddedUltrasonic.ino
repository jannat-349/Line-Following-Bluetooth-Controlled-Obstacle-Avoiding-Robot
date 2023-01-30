#define trigPin 4
#define echoPin 3
#include <stdlib.h>
int l1 = 5;
int l2 = 6;
int r1 = 7;
int r2 = 8;
int ena = 9;
int enb = 10;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ena, OUTPUT);
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(enb, OUTPUT);
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void goForward() {

  digitalWrite(l1, HIGH);
  digitalWrite(l2, LOW);
  digitalWrite(r1, LOW);
  digitalWrite(r2, HIGH);
}
void goStop() {
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(r1, LOW);
  digitalWrite(r2, LOW);
}
void turnLeft() {
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(r1, HIGH);
  digitalWrite(r2, LOW);
  delay(100);
  }
void turnRight() {
  digitalWrite(l1, HIGH);
  digitalWrite(l2, LOW);
  digitalWrite(r1, LOW);
  digitalWrite(r2, LOW);
  delay(100);
}


long calculateTriggerDistance() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(100);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  return distance;
}
void setSpeed(int speed) {
  analogWrite(ena, speed);
  analogWrite(enb, speed);
}
int generateSide() {
  
  long randomSide = random(100) % 2;
  return randomSide;
}
void loop() {
  long distance = calculateTriggerDistance();

  if (distance > 300) {
    setSpeed(180);
    goForward();
  } else if (distance > 120) {
    setSpeed(100);
    goForward();
  } else if (distance > 50) {
    setSpeed(70);
    goForward();
  } else {
    goStop();
    if (generateSide() == 1) {
      turnLeft();
    } else {
      turnRight();
    }  
  }
}