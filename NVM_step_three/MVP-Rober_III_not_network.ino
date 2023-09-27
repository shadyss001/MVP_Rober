/*********
  L298N Dual H-Bridge
*********/

#define SpeedA 150 
#define SpeedB 150

// Motor A
int enablePinA = 5; // D1
int motorAPin1 = 4; // D2
int motorAPin2 = 0; // D3

// Motor B
int motorBPin3 = 14; // D5
int motorBPin4 = 12; // D6
int enablePinB = 13; // D7



void setup() {
  Serial.begin(115200);

  // sets the pins as outputs:
  pinMode(motorAPin1, OUTPUT);
  pinMode(motorAPin2, OUTPUT);
  pinMode(enablePinA, OUTPUT);

  pinMode(motorBPin3, OUTPUT);
  pinMode(motorBPin4, OUTPUT);
  pinMode(enablePinB, OUTPUT);

  // testing
  Serial.print("Testing DC Motor...");

 
  
}

void loop() {
  // Motor A
  forwardA();
  delay(3000);
  stopA();
  delay(3000);
  backwardA();
  delay(3000);
  stopA();

    // Motor B
  forwardB();
  delay(3000);
  stopB();
  delay(3000);
  backwardB();
  delay(3000);
  stopB();



}

void forwardA() {
  Serial.println("Moving Forward A");
  digitalWrite(motorAPin1, LOW);
  digitalWrite(motorAPin2, HIGH); 
  analogWrite(enablePinA,SpeedA);
}

void forwardB() {
  Serial.println("Moving Forward B");
  digitalWrite(motorBPin3, LOW);
  digitalWrite(motorBPin4, HIGH); 
  analogWrite(enablePinB,SpeedB);
}

void backwardA() {
  Serial.println("Moving Backwards A");
  digitalWrite(motorAPin1, HIGH);
  digitalWrite(motorAPin2, LOW); 
  analogWrite(enablePinA,SpeedA);
}

void backwardB() {
  Serial.println("Moving Backwards B");
  digitalWrite(motorBPin3, HIGH);
  digitalWrite(motorBPin4, LOW); 
  analogWrite(enablePinB,SpeedB);
}

void stopA(){
  Serial.println("Stop A");
  digitalWrite(motorAPin1, LOW);
  digitalWrite(motorAPin2, LOW);
}

void stopB(){
  Serial.println("Stop B");
  digitalWrite(motorBPin3, LOW);
  digitalWrite(motorBPin4, LOW);
}
