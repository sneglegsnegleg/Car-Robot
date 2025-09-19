const int A_1B = 5;
const int A_1A = 6;
const int B_1B = 9;
const int B_1A = 10;

const int lineTrack = 2;
bool firstRun = false;

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
  //if(firstRun) {
  int speed = 150;

  int lineColor = digitalRead(lineTrack); // 0:white  1:black
  Serial.println(lineColor); //print on the serial monitor
  if (lineColor) {
    while (lineColor) {
    moveForward(speed);
    lineColor = digitalRead(lineTrack); // 0:white  1:black
  Serial.println(lineColor); //print on the serial monitor
    }
  } else {
    bool directionLeft = checkLeft(lineColor, speed);
    bool directionRight = checkRight(lineColor, speed);
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
bool checkLeft(int lineColor, int speed) {
  moveLeft(speed);
  if (lineColor = 1) {
    return true;
  }
  return false;
}

bool checkRight(int lineColor, int speed) {
  moveRight(speed);
  if (lineColor = 1) {
    return true;
  }
  return false;
}