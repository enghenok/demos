#include <Stepper.h>
#include <Servo.h>

const int stepsPerRevolution = 200;
 int con = true;

Stepper rotationStepper(stepsPerRevolution,  22, 24, 26, 28);
Stepper upAndDownStepper(stepsPerRevolution,  46, 48, 50, 52);
Stepper conveyorStepper(stepsPerRevolution,  33, 35, 37, 39);
int openGripper= 100;
int closeGripper =20;
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
int conveystep = 350;


void setup() {  
   rotationStepper.setSpeed(10);
   upAndDownStepper.setSpeed(10);
   conveyorStepper.setSpeed(100);
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
        grpperServo.write(closeGripper); 

}
void loop() {
   if (con ==true)
   {
    int conveystep = 350;
        delay(2000);
     conveyorStepper.step(-conveystep);
     delay(100);
     conveyorStepper.step(-conveystep);
     delay(4000);
     con =false;
   }
   
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

if((redFrequency <48 && redFrequency >38)&&(greenFrequency < 40 && greenFrequency > 30 ) && (blueFrequency <51 && blueFrequency >41)){
   Serial.println("it is green color "); 
   delay(1000);
   placeGreenObject();
   
  }
  if((redFrequency <53 && redFrequency >43)&&(greenFrequency < 37 && greenFrequency > 27 ) && (blueFrequency <26 && blueFrequency >16)){
   Serial.println(" it is blue color "); 
      delay(1000);
      placeBlueObject();

  }
  if((redFrequency <22 && redFrequency >12)&&(greenFrequency < 23 && greenFrequency > 13 ) && (blueFrequency <19 && blueFrequency >9)){
   Serial.println(" it is red color"); 
      delay(1000);
     // placeRedObject();
     placeWhiteObject();
  

  }
  
  
}
 void placeRedObject(){ 
        con =true ;//   code to  place the red objects
   int rotationSteps = 60;  // dgree of rotation of the base 
    int pickSteps = 55 ;  // dgree of the rotation of the up down joint 
     int grapSteps = 45 ;   // the orientation
     
//     for(int i = 120 ; i>50 ; i--){
//      grpperServo.write(i); 
//    delay(10);
//    }
        grpperServo.write(openGripper);                     // waits 15ms for the servo to reach the position 
     upAndDownStepper.step(-pickSteps);
    delay(500);
    
//   for(int i = 50 ; i<120 ; i++){
//      grpperServo.write(i); 
//    delay(10);
//    }    
      grpperServo.write(closeGripper); 
   upAndDownStepper.step(grapSteps);
    delay(500);
    rotationStepper.step(rotationSteps);
     delay(500);
      upAndDownStepper.step(-pickSteps);
    delay(500);
//      for(int i = 120 ; i>50 ; i--){
//      grpperServo.write(i); 
//    delay(10);
//    } 
            grpperServo.write(openGripper); 
                    delay(2000);

            grpperServo.write(closeGripper); 
//     for(int i = 50 ; i<120 ; i++){
//      grpperServo.write(i); 
//    delay(10);
//    } 
    upAndDownStepper.step(pickSteps);
    delay(500);
    rotationStepper.step(-rotationSteps);
     delay(500);

  }
 
   void placeBlueObject(){ 
       con =true ;//  function to place the  blue object 
   int rotationSteps = 70;  // dgree of rotation of the base 
    int pickSteps = 60;  // dgree of the rotation of the up down joint 
     int grapSteps = 45 ;   // the orientation
     
//     for(int i = 120 ; i>50 ; i--){
//      grpperServo.write(i); 
//    delay(10);
//    }
       grpperServo.write(openGripper); 
                           // waits 15ms for the servo to reach the position 
     upAndDownStepper.step(pickSteps);
    delay(500);
    
//   for(int i = 50 ; i<120 ; i++){
//      grpperServo.write(i); 
//    delay(10);
//    }    
         grpperServo.write(closeGripper); 
   upAndDownStepper.step(-grapSteps);
    delay(500);
    rotationStepper.step(-rotationSteps);
     delay(500);
      upAndDownStepper.step(grapSteps);
    delay(500);
//      for(int i = 120 ; i>50 ; i--){
//      grpperServo.write(i); 
//    delay(10);
//    } 
         grpperServo.write(openGripper); 
         
//     for(int i = 50 ; i<120 ; i++){
//      grpperServo.write(i); 
//    delay(10);
//    } 
        delay(2000);

        grpperServo.write(closeGripper); 
    upAndDownStepper.step(-pickSteps);
    delay(500);
    rotationStepper.step(rotationSteps);
     delay(500);

  }
  void placeGreenObject(){
       con =true ;     //  function to place the  blue object 
   int rotationSteps = 80;  // dgree of rotation of the base 
    int pickSteps = 60 ;  // dgree of the rotation of the up down joint 
     int grapSteps = 45 ;   // the orientation
     
//     for(int i = 120 ; i>50 ; i--){
//      grpperServo.write(i); 
//    delay(10);
//    }
      grpperServo.write(openGripper); 
                           // waits 15ms for the servo to reach the position 
     upAndDownStepper.step(pickSteps);
    delay(500);
    
//   for(int i = 50 ; i<120 ; i++){
//      grpperServo.write(i); 
//    delay(10);
//    }    
       grpperServo.write(closeGripper); 
       delay(1000);
   upAndDownStepper.step(-grapSteps);
    delay(500);
    rotationStepper.step(rotationSteps);
     delay(500);
      upAndDownStepper.step(grapSteps);
    delay(500);
//      for(int i = 120 ; i>50 ; i--){
//      grpperServo.write(i); 
//    delay(10);
//    } 
        grpperServo.write(openGripper); 
        delay(2000);
//     for(int i = 50 ; i<120 ; i++){
//      grpperServo.write(i); 
//    delay(10);
//    } 
       grpperServo.write(closeGripper); 
    upAndDownStepper.step(-pickSteps);
    delay(500);
    rotationStepper.step(-rotationSteps);
     delay(500);

  }
   void placeWhiteObject(){ 

       con =true ;
    //  function to place the  blue object 
  
   
    conveyorStepper.step(-conveystep);
     delay(10);
     conveyorStepper.step(-conveystep);
      delay(10); 
     conveyorStepper.step(-conveystep);
     delay(10);
     conveyorStepper.step(-conveystep);
      delay(10);
     conveyorStepper.step(-conveystep);
     delay(10);
     conveyorStepper.step(-conveystep);
      delay(10);
     conveyorStepper.step(-conveystep);
     delay(10);
     conveyorStepper.step(-conveystep);
    

  }
 
 
