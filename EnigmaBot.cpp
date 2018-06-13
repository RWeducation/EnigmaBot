/*
  EnigmaBot.cpp - Library for interfacing with RWeducation's EnigmaBot (DIY robotics kit).
  Created by Suraj Bhawal, June 9, 2018.
  Released into the public domain.
*/

#include "Arduino.h"
#include "EnigmaBot.h"

void EnigmaBot::setSpeed(int speed){
  if (speed < 0) speed = 0;
  if (speed > 255) speed = 255;
  analogWrite(pwmpin, speed);
}

EnigmaBot::EnigmaBot()
{
  pinMode(LED13, OUTPUT);

  //Ultrasonic pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(pwmpin, OUTPUT);
  pinMode(LMF,OUTPUT);
  pinMode(LMR,OUTPUT);
  pinMode(RMF,OUTPUT);
  pinMode(RMR,OUTPUT);

}


void EnigmaBot::blinkled()
{
  digitalWrite(LED13,HIGH);
  delay(1000);
  digitalWrite(LED13,LOW);
  delay(1000);
}

int EnigmaBot::readDistance(){
  int distance, duration;
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance = duration * 0.034 / 2;
  return distance;
}

void EnigmaBot::moveStop(){

  digitalWrite(LMF, LOW);
  digitalWrite(LMR, LOW);
  digitalWrite(RMF, LOW);
  digitalWrite(RMR, LOW);
}



void EnigmaBot::moveForward(int speed){

  setSpeed(speed);

  digitalWrite(LMF, HIGH);
  digitalWrite(LMR, LOW);
  digitalWrite(RMF, HIGH);
  digitalWrite(RMR, LOW);
}

void EnigmaBot::moveBackward(int speed){

  setSpeed(speed);

  digitalWrite(LMF, LOW);
  digitalWrite(LMR, HIGH);
  digitalWrite(RMF, LOW);
  digitalWrite(RMR, HIGH);
}

void EnigmaBot::moveLeft(int speed){

  setSpeed(speed);

  digitalWrite(LMF, LOW);
  digitalWrite(LMR, HIGH);
  digitalWrite(RMF, HIGH);
  digitalWrite(RMR, LOW);
}

void EnigmaBot::moveRight(int speed){

  setSpeed(speed);

  digitalWrite(LMF, HIGH);
  digitalWrite(LMR, LOW);
  digitalWrite(RMF, LOW);
  digitalWrite(RMR, HIGH);
}
