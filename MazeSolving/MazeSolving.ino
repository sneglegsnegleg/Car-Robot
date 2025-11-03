const int A_1B = 5;
const int A_1A = 6;
const int B_1B = 9;
const int B_1A = 10;

const int lineTrackM = 2;
const int lineTrackL = A0;
const int lineTrackR = A1;

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
int last = 0;

void loop() {
  int speed = 150;
int L  = analogRead(A0);
int R = analogRead(A1);

  int M = digitalRead(lineTrackM); // 0:white  1:black
  Serial.println(L); //print on the serial monitor
  //Serial.println(lineColorR); //print on the serial monitor
  Serial.println(R); //print on the serial monitor
delay(0);
  if ( M== 1 && R < 500 && R < 500) { //only middle sensor reads black
   moveForward(speed);
  } 
 else if (R > 500 && L < 500 && M == 0) { //only Right sensor reads black
     moveRight(speed, speed);
     last = 1;
  } else if (L > 500 && R < 500 && M == 0) { //only Left sensor reads black
     moveLeft(speed, speed);
     last = 0;
  }
 else
  if (M == 1 && R > 500 && L < 500) { //right and middle sensor read black
    moveRight(speed, 0);
    last = 1;
  } else if (M == 1 && R < 500 && L > 500) { //left and middle sensor read black
    moveLeft(speed, 0);
    last = 0;
  } else if (M == 1 && R > 500 && L > 500) { //all read black
   moveForward(speed);
   }else {
    if (last) {
    while (!M && R < 500 && L < 500) {
        moveRight(speed, speed);
        M = digitalRead(lineTrackM);
         L  = analogRead(A0);
       R = analogRead(A1);
    }
    } else {
      while (!M && R < 500 && L < 500) {
        moveLeft(speed, speed);
        M = digitalRead(lineTrackM);
         L  = analogRead(A0);
       R = analogRead(A1);
    }
    }
  }

}
void stop(int speed) {
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
    lineColorL = analogRead(lineTrackL); // 0:white  1:black
  Serial.println("Left Sensor: ");
  Serial.println(lineColorL);
  if (lineColorL < 500) {
    return false;
  } else {
  return true;
}
}
bool checkRight(int lineColorR, int speed) {
  // moveRight(speed); removed cuz Right sensor is checking
  lineColorR = analogRead(lineTrackR); // 0:white  1:black
  Serial.println(lineColorR);
  if (lineColorR < 500) {
    return false;
  }else {
  return true;
}
}