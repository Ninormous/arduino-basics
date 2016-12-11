/**
 * This sketch tests running two motors connected to an Adafruit V1 Motor Shield.  It will loop throught the following:
 *   -Drive forward
 *   -Drive backward
 *   -Turn left in place
 *   -Turn right in place
 *   -Drive forward in a leftward arc
 *   -Drive backward in a leftward arc
 *   -Drive forward in a rightward arc
 *   -Drive backward in a rightward arc
 *   
 *   There is an excellent overview of the motor shield available at: https://learn.adafruit.com/adafruit-motor-shield
 */
 
#include <AFMotor.h>

// Setup motors
AF_DCMotor leftMotor(2, MOTOR12_1KHZ);
AF_DCMotor rightMotor(3, MOTOR12_1KHZ);

const int DELAY_MS = 500; // 500 ms
 
void setup() {
  // set up Serial library at 9600 bps
  Serial.begin(9600);
  Serial.println("Motor Test");
}
 
void loop() {
  // Run through a test sequence

  // Drive forward and backward
  forward(90, 90, DELAY_MS);
  pause(DELAY_MS);
  backward(90, 90, DELAY_MS);
  pause(DELAY_MS);

  // Turn left in place, then right in place
  turnLeft(90, DELAY_MS);
  pause(DELAY_MS);
  turnRight(90, DELAY_MS);
  pause(DELAY_MS);

  // arc forward to the right, then backwards
  forward(100, 75, DELAY_MS);
  pause(DELAY_MS);
  backward(100, 75, DELAY_MS);
  pause(DELAY_MS);

  // arc forward to the left, then backwards
  forward(75, 100, DELAY_MS);
  pause(DELAY_MS);
  backward(75, 100, DELAY_MS);
  pause(DELAY_MS);
}

/**
 * Release the motors for delayMs milliseconds
 */
void pause(int delayMs) {
  Serial.println("Pause");
  leftMotor.run(RELEASE);
  rightMotor.run(RELEASE);
  delay(delayMs);
}

/**
 * Turn right in place at motorPercent speed for delayMs milliseconds
 */
void turnRight(int motorPercent, int delayMs) {
  Serial.print("Turn Right - ");

  setSpeedByPercent(motorPercent, motorPercent);
  
  leftMotor.run(BACKWARD);
  rightMotor.run(FORWARD);
  delay(delayMs);
}

/**
 * Turn left in place at motorPercent speed for delayMs milliseconds
 */
void turnLeft(int motorPercent, int delayMs) {
  Serial.print("Turn Left - ");

  setSpeedByPercent(motorPercent, motorPercent);
  
  leftMotor.run(FORWARD);
  rightMotor.run(BACKWARD);
  delay(delayMs);
}

/**
 * Drive forward for delayMs milliseconds with left and right motors at leftMotorPercent and rightMotorPercent speeds
 */
void forward(int leftMotorPercent, int rightMotorPercent, int delayMs) {
  Serial.print("Forward - ");

  setSpeedByPercent(leftMotorPercent, rightMotorPercent);
  
  leftMotor.run(FORWARD);
  rightMotor.run(FORWARD);
  delay(delayMs);
}

/**
 * Drive backward for delayMs milliseconds with left and right motors at leftMotorPercent and rightMotorPercent speeds
 */
void backward(int leftMotorPercent, int rightMotorPercent, int delayMs) {
  Serial.print("Backward - ");

  setSpeedByPercent(leftMotorPercent, rightMotorPercent);
  
  leftMotor.run(BACKWARD);
  rightMotor.run(BACKWARD);
  delay(delayMs);
}

/**
 * Sets the motor speeds, mapping from percent (1 - 100) to the motor shield range from 1 - 255.
 */
void setSpeedByPercent(int leftMotorPercent, int rightMotorPercent) {
  printMotorPercentages(leftMotorPercent, rightMotorPercent);
  leftMotor.setSpeed(mapPercentToSpeed(leftMotorPercent));
  rightMotor.setSpeed(mapPercentToSpeed(rightMotorPercent));
}

/**
 * Prints the motor percentages to serial.
 */
void printMotorPercentages(int leftMotorPercent, int rightMotorPercent) {
  Serial.print("Left Motor: ");
  Serial.print(leftMotorPercent);
  Serial.print("%, Right Motor: " );
  Serial.print(rightMotorPercent);
  Serial.print("%\n");
}

/**
 * Maps from a percent (1 - 100) to the motor shields acceptable range from 1 - 255
 */
int mapPercentToSpeed(int percent) {
  return map(percent, 1, 100, 1, 255);
}

