#include <Servo.h>

int DIAL_PIN = 0;
int SERVO_PIN = 9;

Servo motor;
int motor_position = 0;
int motor_direction = 1;
int dial_value = 0;

void setup() {
  pinMode(SERVO_PIN, OUTPUT);
  motor.attach(SERVO_PIN);
  Serial.begin(9600);
}

void stepMotor() {
  motor.write(motor_position);
  motor_position = motor_position + motor_direction;
  if(motor_position > 180) {
    motor_direction = -1;
    motor_position = 180;
  } else if(motor_position < 0) {
    motor_direction = 1;
    motor_position = 0;
  }
}


void loop() {
  dial_value = 50000 / ((log(analogRead(DIAL_PIN) + 1) + 1) * 1000);
  Serial.println(dial_value);
  stepMotor();
  delay(dial_value);
}
