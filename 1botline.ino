const int A_1B = 5;
const int A_1A = 6;
const int B_1B = 9;
const int B_1A = 10;

const int lineTrack = 2;

void setup() {
  Serial.begin(9600);

  //motor
  pinMode(A_1B, OUTPUT);
  pinMode(A_1A, OUTPUT);
  pinMode(B_1B, OUTPUT);
  pinMode(B_1A, OUTPUT);
  //line track
  pinMode(lineTrack, INPUT);
}


void loop() {

  int speed = 150;

  int lineColor = digitalRead(lineTrack); // 0:white  1:black
  Serial.println(lineColor); //print on the serial monitor
  if (lineColor) {
    moveForward(150);
  } else {
    checkLeft(speed);
    checkRight(speed);
  }
}
void moveLeft(int speed) {
  analogWrite(A_1B, speed);
  analogWrite(A_1A, 0);
  analogWrite(B_1B, speed);
  analogWrite(B_1A, 0);
}

void moveRight(int speed) {
  analogWrite(A_1B, 0);
  analogWrite(A_1A, speed);
  analogWrite(B_1B, 0);
  analogWrite(B_1A, speed);
}

void moveForward(int speed) {
  digitalWrite(A_1B, 0);
    digitalWrite(A_1A, speed);
    digitalWrite(B_1B, speed);
    digitalWrite(B_1A, 0);
}

void moveBackward(int speed) {
    digitalWrite(A_1B, speed);
    digitalWrite(A_1A, 0);
    digitalWrite(B_1B, 0);
    digitalWrite(B_1A, speed);
}

void stop() {
    digitalWrite(A_1B, 0);
    digitalWrite(A_1A, 0);
    digitalWrite(B_1B, 0);
    digitalWrite(B_1A, 0);
}
void checkLeft(int speed) {
  for (int i = 0; i < 180; i++) {
    moveLeft(speed);
    int lineColor = digitalRead(lineTrack); // 0:white  1:black
    Serial.println(lineColor); //print on the serial monitor
    if (lineColor) {
      moveForward(speed);
      return;
    }
  }
}
void checkRight(int speed) {
  for (int i = 0; i < 360; i++) {
    moveRight(speed);
    int lineColor = digitalRead(lineTrack); // 0:white  1:black
    Serial.println(lineColor); //print on the serial monitor

    if (lineColor) {
      moveForward(speed);
      return;
    }
  }
}