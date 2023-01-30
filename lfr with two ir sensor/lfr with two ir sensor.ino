/*------ Arduino Line Follower Code----- */

/*-------defining Inputs------*/

#define LS A1  // left sensor

#define RS A0  // right sensor


/*-------defining Outputs------*/

#define LM1 5  // left motor
#define LM2 6  // left motor
#define RM1 8  // right motor
#define RM2 7  // right motor

#define ENB 10
#define ENA 9

void setup() {
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);

  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}
void Move_Forward() {
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
}
void Turn_Right() {
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
}
void Turn_Left() {
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);
}
void Stop() {
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);
}
void setSpeed(int speed) {

  analogWrite(ENA, speed);
  analogWrite(ENB, speed+10);
}
void loop() {
  setSpeed(90);
  if (!digitalRead(LS) && !digitalRead(RS))  // Move Forward
  {
    Move_Forward();
  }

  else if ((digitalRead(LS)) && !(digitalRead(RS)))  // Turn right
  {
    Turn_Right();
    setSpeed(100);
  }

  else if (!(digitalRead(LS)) && (digitalRead(RS)))  // turn left
  {
    Turn_Left();
    setSpeed(100);
  }

  else if (digitalRead(LS) && digitalRead(RS))  // stop
  {
    Stop();
  }
}