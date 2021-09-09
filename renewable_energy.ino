#include <Servo.h>
#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

float my_0 = 0;
float my_1 = 0;
float my_2 = 0;
float my_3 = 0;
float servo = 0;
float servo_final = 0;

Servo servo_9;

void _delay(float seconds) {
  long endTime = millis() + seconds * 1000;
  while(millis() < endTime) _loop();
}

void setup() {
  pinMode(A0+0,INPUT);
  pinMode(A0+1,INPUT);
  pinMode(A0+2,INPUT);
  pinMode(A0+3,INPUT);

  my_0 = 0;
  my_1 = 0;
  my_2 = 0;
  my_3 = 0;
  
  for(int count=0;count<9;count++){
    servo_9.attach(9);
    servo_9.write(servo);
    if(((analogRead(A0+0) > my_0) && (analogRead(A0+1) > my_1)) && ((analogRead(A0+2) > my_2) && (analogRead(A0+3) > my_3))){
      my_0 = analogRead(A0+0);
      my_1 = analogRead(A0+1);
      my_2 = analogRead(A0+2);
      my_3 = analogRead(A0+3);
    
      servo_final = servo;
    }
  servo += 10;
  }
  servo_9.attach(9);
  servo_9.write(servo_final);
}
