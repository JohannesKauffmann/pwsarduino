#include <Servo.h>

// motor 1
int enA = 11; //pin voor de snelheidscontrole
int in1 = 10; //pins voor voor- en achteruit
int in2 = 9;
//motor 2
int enB = 6;
int in3 = 8;
int in4 = 7;

//dit zijn de pins die aangeven of de sensoren iets hebben geregistreerd
int sensorright = 5;
int sensorfront = 4;
int sensorleft = 3;
int sensorback = 2;

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
  pinMode(sensorright, INPUT);
  pinMode(sensorfront, INPUT);
  pinMode(sensorleft, INPUT);
  pinMode(sensorback, INPUT);

  //maakt de servo op het servo-object vast aan pin 9
  myservo.attach(12);

}

void straight(){
      // motor A gaat aan
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
  // maakt de snelheid van de motor 200 deze komt uit de range van 0-255
analogWrite(enA, 200);
  // turn on motor B
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
  // maakt de snelheid van de motor 200 deze komt uit de range van 0-255
analogWrite(enB, 200);
delay(20);
}

void left(){
//hier moet je eerst nog neerzetten dat de servo draait naar de linker kant en hierdoor de bocht van het object weg maakt.
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
  // maakt de snelheid van de motor 100 deze komt uit de range van 0-255
analogWrite(enA, 100);
  // turn on motor B
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
  // maakt de snelheid van de motor 100 deze komt uit de range van 0-255
analogWrite(enB, 100);
myservo.write(20);
delay(1700);
}

void right(){
  
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
  // maakt de snelheid van de motor 100 deze komt uit de range van 0-255
analogWrite(enA, 100);
  // turn on motor B
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
  // maakt de snelheid van de motor 100 deze komt uit de range van 0-255
analogWrite(enB, 100);
myservo.write(160);
delay(1700);

}

void achteruit(){
 //motor 1 gaat naar achtern met snelheid 90
 digitalWrite(in1, HIGH);
 digitalWrite(in2, LOW);
 // maakt de snelheid van de motor 120 deze komt uit de range van 0-255
 analogWrite(enA, 120);
 // turn on motor B
 digitalWrite(in3, HIGH);
 digitalWrite(in4, LOW);
 // maakt de snelheid van de motor 120 deze komt uit de range van 0-255
 analogWrite(enB, 120);
 myservo.write(40);
 delay(1700);
}


void loop() {
int val1 = digitalRead(sensorright);
  if (val1 == HIGH) {
  void left();
}
int val2 = digitalRead(sensorfront);
if (val2 == HIGH) {
  void achteruit();
}
int val3 = digitalRead(sensorleft);
if (val3 == HIGH) {
  void right();
}
if (val2 == HIGH && val3 == HIGH) {
  void right();
}
if (val2 == HIGH && val1 == HIGH) {
  void left();
}
}

//we moeten testen als hij niet alle sensoren meet. dus dat alle sensoren high geven. dus moeten we dat even testen
