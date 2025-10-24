const int A_1B = 5;
const int A_1A = 6;
const int B_1B = 9;
const int B_1A = 10;

const int lineTrackM = 2;
const int lineTrackL = 12;
const int lineTrackR = 11;

void setup() {
  Serial.begin(9600);

  //motor
  pinMode(A_1B, OUTPUT);
  pinMode(A_1A, OUTPUT);
  pinMode(B_1B, OUTPUT);
  pinMode(B_1A, OUTPUT);
  //line track
  pinMode(lineTrackM, INPUT);
  pinMode(lineTrackL, INPUT);
  pinMode(lineTrackR, INPUT);
}
int d = 0;

void loop() {
  int speed = 150;
int lineColorL = analogRead(A1);
int lineColorR = analogRead(A0);

  int lineColorM = digitalRead(lineTrackM); // 0:white  1:black
  Serial.println(lineColorM); //print on the serial monitor
  if (lineColorM) {
    moveForward(speed);
  } else if (lineColorR) {
     moveRight(speed, speed);
  } else if (lineColorL) {
     moveLeft(speed, speed);
  } else if (lineColorM && lineColorR && lineColorL){
    moveForward(speed);
  } else if (lineColorM && lineColorR && !lineColorL) {
    moveLeft(speed, 0);
  } else if (lineColorM && !lineColorR && lineColorL) {
    moveRight(speed, 0);
  } else {
    moveBackward(speed); 
  }
}
void stop() {
  analogWrite(A_1B, 0);
  analogWrite(A_1A, 0);
  analogWrite(B_1B, 0);
  analogWrite(B_1A, 0);
}
void moveForward(int speed) {
  analogWrite(A_1B, 0);
  analogWrite(A_1A, speed);
  analogWrite(B_1B, speed);
  analogWrite(B_1A, 0);
}
void moveBackward(int speed) {
  analogWrite(A_1B, speed);
  analogWrite(A_1A, 0);
  analogWrite(B_1B, 0);
  analogWrite(B_1A, speed);
}


void moveLeft(int speed1, int speed2) {
  analogWrite(A_1B, 0);
  analogWrite(A_1A, speed1);
  analogWrite(B_1B, 0);
  analogWrite(B_1A, speed2);
}

void moveRight(int speed1, int speed2) {
  analogWrite(A_1B, speed2);
  analogWrite(A_1A, 0);
  analogWrite(B_1B, speed1);
  analogWrite(B_1A, 0);
}
bool checkLeft(int lineColorL, int speed) {
  //moveLeft(speed); removed cuz Left sensor is checking
    lineColorL = digitalRead(lineTrackL); // 0:white  1:black
  Serial.println(lineColorL);
  if (lineColorL = 1) {
    return true;
  }
  return false;
}

bool checkRight(int lineColorR, int speed) {
  // moveRight(speed); removed cuz Right sensor is checking
  lineColorR = digitalRead(lineTrackR); // 0:white  1:black
  Serial.println(lineColorR);
  if (lineColorR = 1) {
    return true;
  }
  return false;
}