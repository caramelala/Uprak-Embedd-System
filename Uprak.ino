#include <Servo.h>
Servo myservo;
 int servoPin123 = 3;


const int trigPin = 9;
 const int echopin = 10;


long duration;
int distance;

void setup() {
myservo.attach(servoPin123);
pinMode(echopin , INPUT);
Serial.begin(9600);
}


void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(1);
digitalWrite(trigPin, HIGH); // Sets the trigPin on HIGH state for 10 micro seconds
delayMicroseconds(5);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echopin , HIGH);
distance= duration *0.034/2; // Calculating the distance
Serial.print("Distance: "); 
Serial.println(distance);

if (distance<6){
  myservo.write(0); }

else if(distance>=6) {
  myservo.write(180);
}

}