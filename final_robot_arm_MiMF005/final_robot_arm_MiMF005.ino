#include <Stepper.h>
#include <Servo.h>

const int stepsPerRevolution = 200;

Stepper rotationStepper(stepsPerRevolution,  22, 24, 26, 28);
Stepper upAndDownStepper(stepsPerRevolution,  46, 48, 50, 52);
Servo grpperServo;  // create servo object to control a servo

#define S1 4
#define S0 5
#define S3 6
#define S2 7
#define sensorOut 8

// Stores frequency read by the photodiodes
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;

void setup() {  
   rotationStepper.setSpeed(10);
   upAndDownStepper.setSpeed(10);
    grpperServo.attach(21);


   
  // Setting the outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  
  // Setting the sensorOut as an input
  pinMode(sensorOut, INPUT);  
  // Setting frequency scaling to 20%  
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);  
   // Begins serial communication 
  Serial.begin(9600);
}
void loop() {
  // Setting RED (R) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW); 
  
  // Reading the output frequency
  redFrequency = pulseIn(sensorOut, LOW);
  
   // Printing the RED (R) value
  Serial.print("R = ");
  Serial.print(redFrequency);  
  delay(100);
  
  // Setting GREEN (G) filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  
  // Reading the output frequency
  greenFrequency = pulseIn(sensorOut, LOW);
  
  // Printing the GREEN (G) value  
  Serial.print(" G = ");
  Serial.print(greenFrequency);  
  delay(100);
 
  // Setting BLUE (B) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  
//   Reading the output frequency
  blueFrequency = pulseIn(sensorOut, LOW);
  
 //  Printing the BLUE (B) value 
  Serial.print(" B = ");
  Serial.println(blueFrequency);  
  delay(100);

if((redFrequency <75 && redFrequency >65)&&(greenFrequency < 81 && greenFrequency > 71 ) && (blueFrequency <82 && blueFrequency >72)){
   Serial.println("it is green color "); 
   delay(1000);
   placeGreenObject();
   
  }
  if((redFrequency <90 && redFrequency >75)&&(greenFrequency < 95 && greenFrequency > 85 ) && (blueFrequency <80 && blueFrequency >65)){
   Serial.println(" it is blue color "); 
      delay(1000);
      placeBlueObject();

  }
  if((redFrequency <75 && redFrequency >60)&&(greenFrequency < 120 && greenFrequency > 105 ) && (blueFrequency <100 && blueFrequency >90)){
   Serial.println(" it is red color"); 
      delay(1000);
      placeRedObject();
  

  }
  
  
}
 void placeRedObject(){  //   code to  place the red objects
   int rotationSteps = 60;  // dgree of rotation of the base 
    int pickSteps = 55 ;  // dgree of the rotation of the up down joint 
     int grapSteps = 30 ;   // the orientation
     
     for(int i = 120 ; i>50 ; i--){
      grpperServo.write(i); 
    delay(10);
    }
                           // waits 15ms for the servo to reach the position 
     upAndDownStepper.step(-pickSteps);
    delay(500);
    
   for(int i = 50 ; i<120 ; i++){
      grpperServo.write(i); 
    delay(10);
    }    
   upAndDownStepper.step(grapSteps);
    delay(500);
    rotationStepper.step(rotationSteps);
     delay(500);
      upAndDownStepper.step(-pickSteps);
    delay(500);
      for(int i = 120 ; i>50 ; i--){
      grpperServo.write(i); 
    delay(10);
    } 
     for(int i = 50 ; i<120 ; i++){
      grpperServo.write(i); 
    delay(10);
    } 
    upAndDownStepper.step(pickSteps);
    delay(500);
    rotationStepper.step(-rotationSteps);
     delay(500);

  }
 
   void placeBlueObject(){  //  function to place the  blue object 
   int rotationSteps = 60;  // dgree of rotation of the base 
    int pickSteps = 55;  // dgree of the rotation of the up down joint 
     int grapSteps = 30 ;   // the orientation
     
     for(int i = 120 ; i>50 ; i--){
      grpperServo.write(i); 
    delay(10);
    }
                           // waits 15ms for the servo to reach the position 
     upAndDownStepper.step(-pickSteps);
    delay(500);
    
   for(int i = 50 ; i<120 ; i++){
      grpperServo.write(i); 
    delay(10);
    }    
   upAndDownStepper.step(grapSteps);
    delay(500);
    rotationStepper.step(-rotationSteps);
     delay(500);
      upAndDownStepper.step(-pickSteps);
    delay(500);
      for(int i = 120 ; i>50 ; i--){
      grpperServo.write(i); 
    delay(10);
    } 
     for(int i = 50 ; i<120 ; i++){
      grpperServo.write(i); 
    delay(10);
    } 
    upAndDownStepper.step(pickSteps);
    delay(500);
    rotationStepper.step(rotationSteps);
     delay(500);

  }
  void placeGreenObject(){  //  function to place the  blue object 
   int rotationSteps = 90;  // dgree of rotation of the base 
    int pickSteps = 55 ;  // dgree of the rotation of the up down joint 
     int grapSteps = 30 ;   // the orientation
     
     for(int i = 120 ; i>50 ; i--){
      grpperServo.write(i); 
    delay(10);
    }
                           // waits 15ms for the servo to reach the position 
     upAndDownStepper.step(-pickSteps);
    delay(500);
    
   for(int i = 50 ; i<120 ; i++){
      grpperServo.write(i); 
    delay(10);
    }    
   upAndDownStepper.step(grapSteps);
    delay(500);
    rotationStepper.step(-rotationSteps);
     delay(500);
      upAndDownStepper.step(-pickSteps);
    delay(500);
      for(int i = 120 ; i>50 ; i--){
      grpperServo.write(i); 
    delay(10);
    } 
     for(int i = 50 ; i<120 ; i++){
      grpperServo.write(i); 
    delay(10);
    } 
    upAndDownStepper.step(pickSteps);
    delay(500);
    rotationStepper.step(rotationSteps);
     delay(500);

  }
 
 
