#define L1 5     //Left Motor MB2
#define L2 6     //Left Motor MB1
#define R1 7     //Right Motor MA1
#define R2 8     //Right Motor MA2
#define enaL 9   //Left Motor Enable Pin EB
#define enaR 10  //Right Motor Enable Pin EA

//**********5 Channel IR Sensor Connection**********//
#define ir1 A0
#define ir2 A1
#define ir3 A2
#define ir4 A3
#define ir5 A4
//*************************************************//

void setup() {
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L1, OUTPUT);
  pinMode(enaR, OUTPUT);
  pinMode(enaL, OUTPUT);
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);
}
int s1, s2, s3, s4, s5;
void sensorRead() {
  s1 = digitalRead(ir1);  //Left Most Sensor
  s2 = digitalRead(ir2);  //Left Sensor
  s3 = digitalRead(ir3);  //Middle Sensor
  s4 = digitalRead(ir4);  //Right Sensor
  s5 = digitalRead(ir5);  //Right Most Sensor
}

void setSpeed(int speed) {
  analogWrite(enaR, speed);
  analogWrite(enaL, speed);
}

void goForward() {
  digitalWrite(R1, HIGH);
  digitalWrite(R2, LOW);
  digitalWrite(L1, LOW);
  digitalWrite(L2, HIGH);
}
void goLeft() {
  if (s2 == 0) {
    digitalWrite(R1, HIGH);
    digitalWrite(R2, LOW);
    digitalWrite(L1, LOW);
    digitalWrite(L2, LOW);
  }
  if (s1 == 0) {
    digitalWrite(R1, HIGH);
    digitalWrite(R2, LOW);
    digitalWrite(L1, HIGH);
    digitalWrite(L2, LOW);
  }
}
void goRight() {
  if (s4 == 0) {
    digitalWrite(R1, LOW);
    digitalWrite(R2, LOW);
    digitalWrite(L1, LOW);
    digitalWrite(L2, HIGH);
  } else if (s5 == 0) {
    digitalWrite(R1, LOW);
    digitalWrite(R2, HIGH);
    digitalWrite(L1, LOW);
    digitalWrite(L2, HIGH);
  }
}
void goStop() {
  digitalWrite(R1, LOW);
  digitalWrite(R2, LOW);
  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
}

void loop() {
  sensorRead();
  setSpeed(80);
  //if only middle sensor detects black line
  if ((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 1) && (s5 == 1)) {
    goForward();
  }

  //if only left sensor detects black line
  if ((s1 == 1) && (s2 == 0) && (s3 == 1) && (s4 == 1) && (s5 == 1)) {
    goLeft();
  }

  //if only left most sensor detects black line
  if ((s1 == 0) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 1)) {
    goLeft();
  }

  //if only right sensor detects black line
  if ((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 0) && (s5 == 1)) {
    goRight();
  }

  //if only right most sensor detects black line
  if ((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 0)) {
    goRight();
  }

  //if middle and right sensor detects black line
  if ((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 1)) {
    goRight();
  }

  //if middle and left sensor detects black line
  if ((s1 == 1) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 1)) {
    goLeft();
  }

  //if middle, left and left most sensor detects black line
  if ((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 1)) {
    goLeft();
  }

  //if middle, right and right most sensor detects black line
  if ((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 0)) {
    goRight();
  }

  //if all sensors are on a black line
  if ((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 0)) {
    //stop
    goStop();
  }
}