/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 5 Sep 2023
 by SS & RAGV : Add Ultrasonic Sensor
 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>
#define trigPin 2   // attaches the UltraSonic trig
#define echoPin 3   // attaches the UltraSonic echo
#define servoPin 9 // attaches the servo on pin 9 to the servo object

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;                        // variable to store the servo position
long randNumber;                     // variable random numbers
long durationindigit, distanceincm; // variable UltraSonic distance in volt and cm

void setup() {
  Serial.begin (9600);
  pinMode(trigPin,  OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(servoPin);
  randomSeed(analogRead(0));
}

void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  durationindigit = pulseIn(echoPin, HIGH);
  distanceincm = (durationindigit/54);


  if (distanceincm < 20 ||  distanceincm < 0){
    Serial.println("Outside the permissible range of distances");

    randNumber = random(1, 4);
    if (randNumber == 1 || randNumber == 4) {

      for (pos = 90; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees in steps of 1 degree
        myservo.write(pos);                  // tell servo to go to position in variable 'pos'
        delay(15);                           // waits 15 ms for the servo to reach the position
      }

    } else { 

      for (pos = 90; pos >= 0; pos -= 1) {   // goes from 180 degrees to 0 degrees
        myservo.write(pos);                  // tell servo to go to position in variable 'pos'
        delay(15);                           // waits 15 ms for the servo to reach the position
      }

    }

    myservo.write(90);                    // tell servo to go to position 90° degrees
  }
  
  delay(300);                             // waits 300 ms for the servo to reach the position
}
