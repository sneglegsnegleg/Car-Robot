const int A_1B = 5;
const int A_1A = 6;
const int B_1B = 9;
const int B_1A = 10;

const int lineTrackM = 2;
const int lineTrackL = 12;
const int lineTrackR = 11;

bool firstRun = false;

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

void loop() {
  //if(firstRun) {
  int speed = 150;
int lineColorL = digitalRead(lineTrackL);
int lineColorR = digitalRead(lineTrackR);

  int lineColor = digitalRead(lineTrackM); // 0:white  1:black
  Serial.println(lineColor); //print on the serial monitor
  if (lineColor) {
    while (lineColor) {
    moveForward(speed);
    lineColor = digitalRead(lineTrackM); // 0:white  1:black
  Serial.println(lineColor); //print on the serial monitor
    }
  } else {
    bool directionLeft = checkLeft(lineColorL, speed);
    bool directionRight = checkRight(lineColorR, speed);
    if (directionLeft) {
      moveLeft(speed);
    } else if (directionRight) {
      moveRight(speed);
    }
  }
  //firstRun = false;
  //}
}
void moveForward(int speed) {
  analogWrite(A_1B, 0);
  analogWrite(A_1A, speed);
  analogWrite(B_1B, speed);
  analogWrite(B_1A, 0);
}


void moveLeft(int speed) {
  analogWrite(A_1B, 0);
  analogWrite(A_1A, speed);
  analogWrite(B_1B, 0);
  analogWrite(B_1A, 0);
}

void moveRight(int speed) {
  analogWrite(A_1B, 0);
  analogWrite(A_1A, 0);
  analogWrite(B_1B, speed);
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