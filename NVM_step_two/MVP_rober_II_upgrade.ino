
#include <Servo.h>
#define trigPin 2   // attaches the UltraSonic trig
#define echoPin 3   // attaches the UltraSonic echo
#define servoPin 9 // attaches the servo on pin 9 to the servo object


Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;                        // variable to store the servo position
long randNumber;                     // variable random numbers
long durationindigit, distanceincm; // variable UltraSonic distance in volt and cm
int iniAngle=67;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin,  OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(servoPin);
  randomSeed(analogRead(0));
  myservo.write(iniAngle);                    
}

void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  durationindigit = pulseIn(echoPin, HIGH);
  distanceincm = (durationindigit/54);
  Serial.println(distanceincm);
  

  if (distanceincm < 30 ){
    Serial.println("Outside the permissible range of distances");

    randNumber = random(1, 3);
    Serial.println(randNumber);
    //randNumber = 1;

    if (randNumber == 1 || randNumber == 2) {

      Serial.println("izquierda");

      for (pos = iniAngle; pos <= 180; pos += 2) { // goes from 0 degrees to 180 degrees in steps of 1 degree
        myservo.write(pos);                  // tell servo to go to position in variable 'pos'
        delay(2);                           // waits 15 ms for the servo to reach the position
      }
      delay(2000);
     myservo.write(iniAngle-20);

      for (pos = iniAngle-20; pos <= 180; pos += 2) { // goes from 0 degrees to 180 degrees in steps of 1 degree
        myservo.write(pos);                  // tell servo to go to position in variable 'pos'
        delay(2);                           // waits 15 ms for the servo to reach the position
      }
      delay(6000);
     myservo.write(iniAngle-40);

      for (pos = iniAngle-40; pos <= 180; pos += 3) { // goes from 0 degrees to 180 degrees in steps of 1 degree
        myservo.write(pos);                  // tell servo to go to position in variable 'pos'
        delay(2);                           // waits 15 ms for the servo to reach the position
      }
      delay(5000);
     myservo.write(iniAngle-50);

      for (pos = iniAngle-50; pos <= 180; pos += 2) { // goes from 0 degrees to 180 degrees in steps of 1 degree
        myservo.write(pos);                  // tell servo to go to position in variable 'pos'
        delay(2);                           // waits 15 ms for the servo to reach the position
      }
      delay(6000);
     myservo.write(iniAngle);


    } else { 

      Serial.println("derecha");

      for (pos = iniAngle; pos >= 0; pos -= 2) {   // goes from 180 degrees to 0 degrees
        myservo.write(pos);                  // tell servo to go to position in variable 'pos'
        delay(2);                           // waits 15 ms for the servo to reach the position
      }
      delay(2000);
     myservo.write(iniAngle-20);

     for (pos = iniAngle-20; pos >= 0; pos -= 2) {   // goes from 180 degrees to 0 degrees
        myservo.write(pos);                  // tell servo to go to position in variable 'pos'
        delay(2);                           // waits 15 ms for the servo to reach the position
      }
      delay(6000);
     myservo.write(iniAngle-40);

     for (pos = iniAngle-40; pos >= 0; pos -= 3) {   // goes from 180 degrees to 0 degrees
        myservo.write(pos);                  // tell servo to go to position in variable 'pos'
        delay(2);                           // waits 15 ms for the servo to reach the position
      }
      delay(5000);
     myservo.write(iniAngle-50);

     for (pos = iniAngle-50; pos >= 0; pos -= 2) {   // goes from 180 degrees to 0 degrees
        myservo.write(pos);                  // tell servo to go to position in variable 'pos'
        delay(2);                           // waits 15 ms for the servo to reach the position
      }
      delay(6000);
     myservo.write(iniAngle);

    }
   // delay(2000);
   // myservo.write(iniAngle);                    // tell servo to go to position 90° degrees
  }
  
  delay(300);                             // waits 300 ms for the servo to reach the position
}
