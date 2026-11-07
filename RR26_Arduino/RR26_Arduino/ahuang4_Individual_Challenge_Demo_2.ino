const int LEFT_MOTORS_SP = 5;
const int RIGHT_MOTORS_SP = 6;
const int LEFT_MOTOR_DIR = 8;
const int RIGHT_MOTOR_DIR = 7;
const int MOTOR_OUTPUT = 3;

int starterSpeed = 50;

const int IR_RIGHT = A0;
const int IR_MIDDLE = A1;
const int IR_LEFT = A2;

const int BLACK = 90;
const int THRESHOLD_ABOVE_IS_NOISE = 1000;

void off ()
{
  digitalWrite(MOTOR_OUTPUT, LOW); 
}

void forward (int forwardSpeed) 
{
  digitalWrite(MOTOR_OUTPUT, HIGH);
  digitalWrite(LEFT_MOTOR_DIR, HIGH); 
  digitalWrite(RIGHT_MOTOR_DIR, HIGH);
  analogWrite(LEFT_MOTORS_SP, forwardSpeed);
  analogWrite(RIGHT_MOTORS_SP, forwardSpeed);
}
void moveright (int leftSpeed, int rightSpeed) {  // front of mobot turns right and back turns left
      digitalWrite(MOTOR_OUTPUT, HIGH); //HIGH turns on output to motors
      digitalWrite(LEFT_MOTOR_DIR, HIGH); //HIGH sets direction to forward (LOW sets direction to reverse)
      digitalWrite(RIGHT_MOTOR_DIR, LOW);
      analogWrite(LEFT_MOTORS_SP, leftSpeed);  //speed should be more than zero (range is 0-255)
      analogWrite(RIGHT_MOTORS_SP, rightSpeed);
    }

void moveleft (int leftSpeed, int rightSpeed) { //front of mobot turns left and back turns right
      digitalWrite(MOTOR_OUTPUT, HIGH); // HIGH turns on output to motors
      digitalWrite(LEFT_MOTOR_DIR, LOW); // HIGH sets direction to forward (LOW sets direction to reverse)
      digitalWrite(RIGHT_MOTOR_DIR, HIGH);
      analogWrite(LEFT_MOTORS_SP, leftSpeed);  // speed should be more than zero (range is 0-255)
      analogWrite(RIGHT_MOTORS_SP, rightSpeed);
    }

void back (int backSpeed) 
{
  digitalWrite(MOTOR_OUTPUT, HIGH);
  digitalWrite(LEFT_MOTOR_DIR, LOW); 
  digitalWrite(RIGHT_MOTOR_DIR, LOW);
  analogWrite(LEFT_MOTORS_SP, backSpeed);
  analogWrite(RIGHT_MOTORS_SP, backSpeed);
}

void setup() 
{
  pinMode(IR_LEFT, INPUT);
  pinMode(IR_MIDDLE, INPUT);
  pinMode(IR_RIGHT, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  int leftReadIR = analogRead(IR_LEFT);
  int middleReadIR = analogRead(IR_MIDDLE);
  int rightReadIR = analogRead(IR_RIGHT);

  back(starterSpeed);
  delay(5000);

  while(middleReadIR < BLACK)
  {
    back(starterSpeed);
    delay(500);
    leftReadIR = analogRead(IR_LEFT);
    middleReadIR = analogRead(IR_MIDDLE);
    rightReadIR = analogRead(IR_RIGHT);
  }

  back(starterSpeed);
  delay(200);

  off();
  delay(100);

  while (true)
  {
    while(middleReadIR > BLACK)
    {
      forward(starterSpeed);
      delay(100);
      middleReadIR = analogRead(IR_MIDDLE);
    }
    //off();
    //delay(100);
    while(leftReadIR > BLACK && middleReadIR < BLACK)
    {
      moveleft(starterSpeed, starterSpeed);
      delay(100);
      middleReadIR = analogRead(IR_MIDDLE);
      leftReadIR = analogRead(IR_LEFT);
    }
    //off();
    //delay(100);
    while(rightReadIR > BLACK && middleReadIR < BLACK)
    {
      moveright(starterSpeed, starterSpeed);
      delay(100);
      middleReadIR = analogRead(IR_MIDDLE);
      rightReadIR = analogRead(IR_RIGHT);
    }
    leftReadIR = analogRead(IR_LEFT);
    middleReadIR = analogRead(IR_MIDDLE);
    rightReadIR = analogRead(IR_RIGHT);
    off();
    /*while(leftReadIR < BLACK && middleReadIR < BLACK && rightReadIR < BLACK)
    {
      forward(starterSpeed);
      delay(1000);
      moveright(starterSpeed, starterSpeed);
      delay(1500);
      forward(starterSpeed);
      delay(500);
      off();
      while(true){}
    }*/

  }
}

