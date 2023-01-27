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

void loop() {
  // put your main code here, to run repeatedly:
  // analogWrite(ena, 150);
  // analogWrite(enb, 150);
  if (Serial.available() > 0) {
    data = Serial.read();


    if (data == 'F') {
      // analogWrite(ena, 150);
      // analogWrite(enb, 150);
      digitalWrite(l1, HIGH);
      digitalWrite(l2, LOW);
      digitalWrite(r1, LOW);
      digitalWrite(r2, HIGH);

    } else if (data == 'B') {

      // analogWrite(ena, 150);
      // analogWrite(enb, 150);

      digitalWrite(l1, LOW);
      digitalWrite(l2, HIGH);
      digitalWrite(r1, HIGH);
      digitalWrite(r2, LOW);

    } else if (data == 'L') {
      // analogWrite(ena, 150);
      // analogWrite(enb, 150);

      digitalWrite(l1, LOW);
      digitalWrite(l2, LOW);
      digitalWrite(r1, LOW);
      digitalWrite(r2, HIGH);
      delay(500);
      digitalWrite(l1, HIGH);
      digitalWrite(l2, LOW);
      digitalWrite(r1, LOW);
      digitalWrite(r2, HIGH);

    } else if (data == 'R') {
      // analogWrite(ena, 150);
      // analogWrite(enb, 150);

      digitalWrite(l1, HIGH);
      digitalWrite(l2, LOW);
      digitalWrite(r1, LOW);
      digitalWrite(r2, LOW);
      delay(500);
      digitalWrite(l1, HIGH);
      digitalWrite(l2, LOW);
      digitalWrite(r1, LOW);
      digitalWrite(r2, HIGH);

    } else if (data == 'S') {

      digitalWrite(l1, LOW);
      digitalWrite(r1, LOW);
      digitalWrite(l2, LOW);
      digitalWrite(r2, LOW);
    } 
    //
    if (data == '1' || data == '2' || data == '3') {
      analogWrite(ena, 100);
      analogWrite(enb, 100);
    } else if (data == '4' || data == '5' || data == '6') {
      analogWrite(ena, 150);
      analogWrite(enb, 150);
    } else if (data == '7' || data == '8' || data == '9') {
      analogWrite(ena, 200);
      analogWrite(enb, 200);
    }
  }
}