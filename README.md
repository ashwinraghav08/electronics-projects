#include <AccelStepper.h>

// Stepper motor pins (28BYJ-48 with ULN2003 driver)
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

// IMPORTANT: 28BYJ-48 pin order for AccelStepper is IN1, IN3, IN2, IN4
AccelStepper stepper(AccelStepper::FULL4WIRE, IN1, IN3, IN2, IN4);

// Joystick pin
#define JOY_X A0

// Settings
const int DEADZONE = 80;       // ignore small joystick movement
const int MAX_SPEED = 2000;    // top motor speed (steps/sec)
const int ACCEL_STEP = 20;     // acceleration step size

int currentSpeed = 0;

void setup() {
  stepper.setMaxSpeed(MAX_SPEED);
}

void loop() {
  int x = analogRead(JOY_X) - 512;  // read joystick X, centered at 0

  if (abs(x) < DEADZONE) {
    // Joystick released → stop
    currentSpeed = 0;
  } else if (x > 0) {
    // Joystick right → accelerate clockwise
    currentSpeed += ACCEL_STEP;
    if (currentSpeed > MAX_SPEED) currentSpeed = MAX_SPEED;
  } else {
    // Joystick left → accelerate counterclockwise
    currentSpeed -= ACCEL_STEP;
    if (currentSpeed < -MAX_SPEED) currentSpeed = -MAX_SPEED;
  }

  stepper.setSpeed(currentSpeed);
  stepper.runSpeed();  // run motor at current speed
}
