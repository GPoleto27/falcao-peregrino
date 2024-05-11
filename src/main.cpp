#include <Arduino.h>
#include <Servo.h>

#define REVERSE_SWITCH 2
#define END_SWITCH 3
#define RUN_SWITCH 4
#define ESC_PIN 9
#define THROTTLE_MIN 1100
#define THROTTLE_MAX 1900
#define THROTTLE_OFF 1500

Servo esc;

void reverse()
{
  esc.writeMicroseconds(THROTTLE_MIN);
}

void forward()
{
  esc.writeMicroseconds(THROTTLE_MAX);
}

void stop()
{
  esc.writeMicroseconds(THROTTLE_OFF);
}

void setup()
{
  pinMode(REVERSE_SWITCH, INPUT_PULLUP);
  pinMode(END_SWITCH, INPUT_PULLUP);
  pinMode(RUN_SWITCH, INPUT);

  attachInterrupt(digitalPinToInterrupt(REVERSE_SWITCH), reverse, FALLING);
  attachInterrupt(digitalPinToInterrupt(END_SWITCH), stop, FALLING);

  esc.attach(ESC_PIN);
  stop();

  while (!digitalRead(RUN_SWITCH))
    ;
  forward();
}

void loop() {}
