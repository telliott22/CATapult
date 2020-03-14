/*
  
  Cat treat catapult 
  
*/

#include <Servo.h>
Servo myservo;

#include <Stepper.h>

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
const int rolePerMinute = 10;         // Adjustable range of 28BYJ-48 stepper is 0~17 rpm

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {

  myStepper.setSpeed(rolePerMinute);
  // initialize the serial port:
//  Serial.begin(9600);

  myservo.attach(2);
  myservo.write(90);// move servos to center position -> 90°
}

void loop() {

  myservo.write(90); //closeservo

  myStepper.setSpeed(rolePerMinute);

  myStepper.step(stepsPerRevolution);
  myStepper.step(stepsPerRevolution);

  delay(500);

  myservo.write(180); //open servo

  myStepper.setSpeed(17);

  myStepper.step(-stepsPerRevolution);
  myStepper.step(-stepsPerRevolution);
  
  delay(2000);

}
