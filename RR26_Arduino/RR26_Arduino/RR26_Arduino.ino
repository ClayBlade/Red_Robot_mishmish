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
const int 

// This function runs ONCE, when the microcontroller boots up
void setup() {
    // Initialize all components on the robot before doing any work
  RedRobot::InitRedRobot();         // call this first
  RedRobot::InitDCMotors();
  RedRobot::InitServo();
  RedRobot::InitLineSensors();
  RedRobot::InitAuton();            // call this to activate the AutonomousLoop

  // Initialize our variables
  started = false;
  counter = 0;
}

// This function runs over and over (in a loop) when you are in autonomous mode.
// As an example, this code moves out of the starting box at start, and 
// Look at RedRobot.h to see the robot interface: what functions you can call and how.
void AutonomousLoop() { 
    //To do:
        //motor 2 left, motor 3 right
        //Check Motor pins
            //dir
            //#define MOTOR0_PHASE 9
            //#define MOTOR1_PHASE 10
            //#define MOTOR2_PHASE 7
            //#define MOTOR3_PHASE 8

            //speed
            //#define MOTOR0_EN 14
            //#define MOTOR1_EN 43 // TXD0
            //#define MOTOR2_EN 36
            //#define MOTOR3_EN 35'''
            //ranges from -100 to 100, sign is phase, magnitude is duty cycle
        //Make code work for new IR sensor ~> Pinout for new IR sensor
        //Black threshold
        //noise threshold
            //IR pins: GND/3x3, 3, 2, 1, 0
        //Button/Timer to go from Auton -> Manual
        
    //simple plan obj:
        //(orient pipe upwards first?)
        //get out of zone
        //follow line to trench
        //push zone in

    if (!started) { // e.g. get out of the starting box
        started = true;

        RedRobot::WriteDCMotor(2, 20); 
        RedRobot::WriteDCMotor(3, 20);
        //move forward at speed 20 for 1 second
        delay(1000);
    }
    
    // repeatedly move the servo and get in scoring position
    // remember that the below code will run repeatedly since we are in
    // the AutonomousLoop!

    // set all servos to angle 0
    RedRobot::SetServo(0, 0);
    RedRobot::SetServo(1, 0);
    RedRobot::SetServo(2, 0);
    RedRobot::SetServo(3, 0);

    // Print to the serial console to debug!
    Serial.print("[AUTO] Running ");
    Serial.print(counter);
    Serial.println();

    // increment the counter
    counter = counter + 1;
}


