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
}

void goForward() {
  digitalWrite(l1, HIGH);
  digitalWrite(l2, LOW);
  digitalWrite(r1, LOW);
  digitalWrite(r2, HIGH);
}

int convertSpeedFromPotentiometer(int analogSpeed) {
  int speed;
  speed = int(0.249 * analogSpeed);
  return speed;
}

void setSpeed(int speed) {

  analogWrite(ena, speed);
  analogWrite(enb, speed);
}
void loop() {

  goForward();
  int sensorValue = analogRead(A0);
  int speed = convertSpeedFromPotentiometer(sensorValue);
  setSpeed(speed);
}
