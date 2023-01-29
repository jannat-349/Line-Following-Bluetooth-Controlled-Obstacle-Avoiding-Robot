int l1 = 5;
int l2 = 6;
int r1 = 7;
int r2 = 8;
int ena = 9;
int enb = 10;

int data;

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
void goBackward() {
digitalWrite(l1, LOW);
      digitalWrite(l2, HIGH);
      digitalWrite(r1, HIGH);
      digitalWrite(r2, LOW);
}
void goLeft() {
  digitalWrite(l1, LOW);
      digitalWrite(l2, LOW);
      digitalWrite(r1, LOW);
      digitalWrite(r2, HIGH);
      delay(500);
      digitalWrite(l1, HIGH);
      digitalWrite(l2, LOW);
      digitalWrite(r1, LOW);
      digitalWrite(r2, HIGH);
}
void goRight() {
  digitalWrite(l1, HIGH);
      digitalWrite(l2, LOW);
      digitalWrite(r1, LOW);
      digitalWrite(r2, LOW);
      delay(500);
      digitalWrite(l1, HIGH);
      digitalWrite(l2, LOW);
      digitalWrite(r1, LOW);
      digitalWrite(r2, HIGH);
}
void goStop() {
   digitalWrite(l1, LOW);
      digitalWrite(r1, LOW);
      digitalWrite(l2, LOW);
      digitalWrite(r2, LOW);
}
void setSpeed(int speed) {
  analogWrite(ena, speed);
      analogWrite(enb, speed);
}
void loop() {
  // put your main code here, to run repeatedly:
  // analogWrite(ena, 150);
  // analogWrite(enb, 150);
  if (Serial.available() > 0) {
    data = Serial.read();


    if (data == 'F') {
      goForward();
      
    } else if (data == 'B') {
      goBackward();

    } else if (data == 'L') {
      goLeft();

      

    } else if (data == 'R') {
      goRight();

      

    } else if (data == 'S') {

     goStop();
    } 
    //
    if (data == '1' || data == '2' || data == '3') {
      setSpeed(100);
    } else if (data == '4' || data == '5' || data == '6') {
      setSpeed(150);
    } else if (data == '7' || data == '8' || data == '9') {
      setSpeed(200);
    }
  }
}