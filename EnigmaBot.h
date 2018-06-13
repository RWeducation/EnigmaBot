/*
  EnigmaBot.h - Library for interfacing with RWeducation's EnigmaBot (DIY robotics kit).
  Created by Suraj Bhawal, June 9, 2018.
  Released into the public domain.
*/

#ifndef EnigmaBot_h
#define EnigmaBot_h
#include "Arduino.h"

//built-in LED
#define LED13 13

//Ultrasonic pins
#define trigPin 8
#define echoPin 7

//Left motor
#define LMF A0
#define LMR A1

//Right motor
#define RMF A2
#define RMR A3

//Motor driver PWM pin
#define pwmpin 5

//IR pins
#define IR1 6
#define IR2 4
#define IR3 3
#define IR4 2


class EnigmaBot
{
  public:
    EnigmaBot();
    void blinkled();
    int readDistance();
    void moveStop();
    void moveForward(int speed);
    void moveBackward(int speed);
    void moveLeft(int speed);
    void moveRight(int speed);
  private:
    void setSpeed(int speed);
};

#endif
