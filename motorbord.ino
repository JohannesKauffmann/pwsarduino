#include <Servo.h>

// motor 1
int enA = 11; //pin voor de snelheidscontrole
int in1 = 13; //pins voor voor- en achteruit
int in2 = 12;
//motor 2
int enB = 6;
int in3 = 8;
int in4 = 7;

//dit zijn de pins die aangeven of de sensoren iets hebben geregistreerd
int sensor1 = 5;
int sensor2 = 4;
int sensor3 = 3;
int sensor4 = 2;

Servo myservo; //maakt een servo-object om de servo mee te besturen

int pos = 0; //een variabele om de positie van de servo in te bewaren

void setup() {
  //de pins die naar de H-bridge gaan zijn allemaal outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  //de pins van het sensorbord zijn allemaal inputs
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);

  //maakt de servo op het servo-object vast aan pin 9
  myservo.attach(9);

}

void loop() {
  // put your main code here, to run repeatedly:​
