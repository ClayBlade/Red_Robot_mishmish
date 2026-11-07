/**
 * @brief Red Robot 2026 main code!
 * 
 * Read the comments below to figure out how to get started!
 */

// Libraries with driver code (don't remove these!)
#include <Arduino.h>                // make sure this is first
#include "RedRobot.h"

// Declare some global variables
bool started; // boolean (true or false) to keep track of if we should start
int counter;  // integer to hold a count value
const int IR0_pin = 37;
const int IR1_pin = 38;
const int IR2_pin = 39;
const int IR3_pin = 40;
int BLACK = 5000;


            //#define LF0 37
//#define LF1 38
//#define LF2 39
//#define LF3 40
// This function runs ONCE, when the microcontroller boots up
void setup() {
    // Initialize all components on the robot before doing any work
  Serial.begin(9600);
  Serial.println("test");
  delay(2000);
  RedRobot::InitRedRobot();         // call this first
  RedRobot::InitDCMotors();
  RedRobot::InitServo();
  RedRobot::InitLineSensors();
  //RedRobot::InitAuton();            // call this to activate the AutonomousLoop

  // Initialize our variables
  started = false;
  counter = 0;
}



// This function runs over and over (in a loop) when you are in autonomous mode.
// As an example, this code moves out of the starting box at start, and 
// Look at RedRobot.h to see the robot interface: what functions you can call and how.
void AutonomousLoop() { 
    if (!started) { // e.g. get out of the starting box
         started = true;

         RedRobot::WriteDCMotor(2, -55); 
         RedRobot::WriteDCMotor(3, 58);
         //move forward at speed 20 for 1 second
         delay(2500);
    }

         RedRobot::WriteDCMotor(2, 0); 
         RedRobot::WriteDCMotor(3, 0);
    
    //int IR0 = analogRead(IR0_pin);
    uint16_t sensor_values[6];
    RedRobot::ReadLineSensor(sensor_values);
    int IR1 = sensor_values[1];
    int IR2 = sensor_values[2];

    //int IR3 = analogRead(IR3_pin)
    
    //Serial.print("IR1: ");
    //Serial.println(IR1);
    //Serial.print("IR2: ");
    //Serial.println(IR2);
    //Serial.println("-------");

    //how to test for black threshold
    //how to test for noise threshold
    
    // repeatedly move the servo and get in scoring position
    // remember that the below code will run repeatedly since we are in
    // the AutonomousLoop!

    // set all servos to angle 0
    RedRobot::SetServo(0, 0);
    RedRobot::SetServo(1, 0);
    RedRobot::SetServo(2, 0);
    RedRobot::SetServo(3, 0);


    int left_speed = 0;
    int right_speed = 0;

    // if(IR1 < BLACK && IR2 < BLACK)
    // {
    //     left_speed = 40;
    //   right_speed = 40;
    //     RedRobot::WriteDCMotor(2, constrain(left_speed, -100, 100));
    //     RedRobot::WriteDCMotor(3, constrain(right_speed, -100, 100));
    //   delay(100);
    //  //IR1 = sensor_values[1];
    //  //IR2 = sensor_values[2];
 
    // }
 
    // else if(IR2 < BLACK && IR1 > BLACK) //right one is on black, left one is white
    // {
    //   left_speed = 40;
    //   right_speed = -40;
    //     RedRobot::WriteDCMotor(2, constrain(left_speed, -100, 100));
    //     RedRobot::WriteDCMotor(3, constrain(right_speed, -100, 100));
    //   delay(100);
    //  //IR1 = sensor_values[1];
    //  //IR2 = sensor_values[2];

    
    // }

    // else if(IR2 > BLACK && IR1 < BLACK) //right one is on white, left on is black
    // {
    //   left_speed = -40;
    //   right_speed = 40;
    //     RedRobot::WriteDCMotor(2, constrain(left_speed, -100, 100));
    //     RedRobot::WriteDCMotor(3, constrain(right_speed, -100, 100));
    //   delay(100);
    //  //IR1 = sensor_values[1];
    //  //IR2 = sensor_values[2];
    // }
    // else{
    //      RedRobot::WriteDCMotor(2, constrain(0, -100, 100));
    //     RedRobot::WriteDCMotor(3, constrain(0, -100, 100));
    // }

    // Serial.print("IR1: ");
    // Serial.println(IR1);
    // Serial.print("IR2: ");
    // Serial.println(IR2);
    // Serial.println("-------");
  

    // // Print to the serial console to debug!
    // //Serial.print("[AUTO] Running ");
    // //Serial.print(counter);
    // //Serial.println();

    // // increment the counter
    // counter = counter + 1;
}


