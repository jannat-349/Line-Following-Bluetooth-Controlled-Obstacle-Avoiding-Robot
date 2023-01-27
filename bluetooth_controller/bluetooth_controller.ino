int l1 = 5;
int l2 = 6;
int r1 = 7;
int r2 = 8;
int data;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0) {
    data = Serial.read();

    if(data == 'F') {
      digitalWrite(l1, HIGH);
      digitalWrite(l2, LOW);
      digitalWrite(r1, LOW);
      digitalWrite(r2, HIGH);
      
    }
    else if(data == 'B') {
      digitalWrite(l1, LOW);
      digitalWrite(l2, HIGH);
      digitalWrite(r1, HIGH);
      digitalWrite(r2, LOW);
      
    }
    else if(data == 'L') {
      digitalWrite(l1, LOW);
      digitalWrite(l2, LOW);
      digitalWrite(r1, LOW);
      digitalWrite(r2, HIGH);
      
    }
    else if(data == 'R') {
      digitalWrite(l1, HIGH);
      digitalWrite(l2, LOW);
      digitalWrite(r1, LOW);
      digitalWrite(r2, LOW);
      
    }
    else if(data == 'S') {
      digitalWrite(l1, LOW);
      digitalWrite(r1, LOW);
      digitalWrite(l2, LOW);
      digitalWrite(r2, LOW);
      
    }
  }

}
