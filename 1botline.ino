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
int lastTurn = 1;

void loop() {

  int speed = 200;

  int lineColor = digitalRead(lineTrack); // 0:white  1:black
  Serial.println(lineColor); //print on the serial monitor
  if(lineColor) {
    moveForward(speed);
    delay(50);
  } else {
    int amount = 5;
    while (!lineColor) {
      checkLeft(speed, amount);
      stop();
      delay(75);
      checkRight(speed, amount);
      stop();
      delay(75);
      lineColor = digitalRead(lineTrack); // 0:white  1:black
  Serial.println(lineColor); //print on the serial monitor
      amount += 5;
    }
  }
  
}
void moveLeft(int speed) {
  analogWrite(A_1B, 0);
  analogWrite(A_1A, speed);
  analogWrite(B_1B, 0);
  analogWrite(B_1A, speed);
}

void moveRight(int speed) {
  analogWrite(A_1B, speed);
  analogWrite(A_1A, 0);
  analogWrite(B_1B, speed);
  analogWrite(B_1A, 0);
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
void checkLeft(int speed, int amount) {
  for (int i = 0; i < amount; i++) {
    moveLeft(speed);
    delay(25);
    int lineColor = digitalRead(lineTrack); // 0:white  1:black
    Serial.println(lineColor); //print on the serial monitor
    if (lineColor) {
      return;
    }
  }
}
void checkRight(int speed, int amount) {
  for (int i = 0; i < amount * 2; i++) {
    moveRight(speed);
    delay(25);
    int lineColor = digitalRead(lineTrack); // 0:white  1:black
    Serial.println(lineColor); //print on the serial monitor

    if (lineColor) {
      return;
    }
  }
}