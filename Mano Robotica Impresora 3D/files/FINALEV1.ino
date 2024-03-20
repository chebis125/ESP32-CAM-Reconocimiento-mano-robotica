
#include <Servo.h>

const int buttonPin1 = 2;   // pushbutton pin   
const int buttonPin2 = 4; 
const int buttonPin3 = 7;  
const int buttonPin4 = 8;              
const int buttonPin5 = 12;              
const int buttonPin6 = 13;
                   
int b1 = 0;   //buttonState variable
int b2 = 0;
int b3 = 0;
int b4 = 0;
int b5 = 0;
int b6 = 0;
                           
Servo pouce_bending;  // create servo object to control a servo
Servo pouce_rotation;
Servo index;
Servo baby;
Servo ring;
Servo middle;

int time_loop=10; //define the delay for decreasing the speed of bending

void setup() {
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);
  pinMode(buttonPin6, INPUT); 

  pouce_bending.attach(11);  // attaches the servo on pin to the servo object
  pouce_rotation.attach(5);
  index.attach(10);
  baby.attach(9);
  ring.attach(6);
  middle.attach(3);
  
  pouce_bending.write(0);   // initialize servo
  delay(200);
  pouce_rotation.write(0);
  delay(200);
  index.write(0);
  delay(200);
  baby.write(0);
  delay(200);
  ring.write(0);
  delay(200);
  middle.write(0);
  delay(200);
   
  }

int pos_baby =0;  // variable to store the servo position
int pos_ring =0;
int pos_middle =0;
int pos_index =0;
int pos_thumb_bending =0;
int pos_thumb_rotation =0;


void loop() {

b1 = digitalRead(buttonPin1);   //read the digital state of buttonPin with digitalRead() function and store the value in buttonState variable
b2 = digitalRead(buttonPin2);
b3 = digitalRead(buttonPin3);
b4 = digitalRead(buttonPin4);
b5 = digitalRead(buttonPin5);
b6 = digitalRead(buttonPin6);

int pos =0;


//1 => ALL CLOSED
    if (b1 == HIGH && b2 == LOW && b3 == LOW && b4 == LOW && b5== LOW && b6 == LOW ) {
 for (pos = pos_index ; pos <= 180; pos += 1) {    // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    index.write(pos);   // tell servo to go to position in variable 'pos'      
    delay(time_loop);    // waits time_loop ms for the servo to reach the position                       
  }
  for (pos = pos_middle; pos <= 180; pos += 1) {
    middle.write(pos);             
    delay(time_loop);                       
  }
  for (pos = pos_ring ; pos <= 180; pos += 1) {
    ring.write(pos);             
    delay(time_loop);                       
  }
  for (pos =pos_baby; pos <= 180; pos += 1) {
    baby.write(pos);             
    delay(time_loop);                       
  }
  for (pos = pos_thumb_rotation; pos <= 20; pos += 1) {
    pouce_rotation.write(pos);             
    delay(time_loop);                       
  }
  for (pos = pos_thumb_bending ; pos <= 180; pos += 1) {
    pouce_bending.write(pos);             
    delay(time_loop);                       
  }

pos_baby =180;
pos_ring =180;
pos_middle =180;
pos_index =180;
pos_thumb_bending =180;
pos_thumb_rotation =20;
 
    }

//2 => 2  ROCK
    if (b1 == LOW && b2 == HIGH && b3 == LOW && b4 == LOW && b5== LOW && b6 == LOW ) {
   
  for (pos = pos_middle; pos <= 180; pos += 1) {
    middle.write(pos);             
    delay(time_loop);                       
  }
  for (pos = pos_ring; pos <= 180; pos += 1) {
    ring.write(pos);             
    delay(time_loop);                       
  }
  for (pos = pos_thumb_rotation; pos <= 60; pos += 1) {
    pouce_rotation.write(pos);             
    delay(time_loop);                       
  }
  for (pos = pos_thumb_bending; pos <= 180; pos += 1) {
    pouce_bending.write(pos);             
    delay(time_loop);                       
  }
pos_baby =0;
pos_ring =180;
pos_middle =180;
pos_index =0;
pos_thumb_bending =180;
pos_thumb_rotation =60;
    }
    
//3 => 3 PEACE
    if (b1 == LOW && b2 == LOW && b3 == HIGH && b4 == LOW && b5== LOW && b6 == LOW ) {
  for (pos = pos_ring ; pos <= 180; pos += 1) {
    ring.write(pos);             
    delay(time_loop);                       
  }
  for (pos =pos_baby; pos <= 180; pos += 1) {
    baby.write(pos);             
    delay(time_loop);                       
  }
  for (pos = pos_thumb_rotation; pos <= 20; pos += 1) {
    pouce_rotation.write(pos);             
    delay(time_loop);                       
  }
  for (pos = pos_thumb_bending ; pos <= 180; pos += 1) {
    pouce_bending.write(pos);             
    delay(time_loop);                       
  }
pos_baby =180;
pos_ring =180;
pos_middle =0;
pos_index =0;
pos_thumb_bending =180;
pos_thumb_rotation =20;
    }
 
//4 => 4  SURF
    if (b1 == LOW && b2 == LOW && b3 == LOW && b4 == HIGH && b5== LOW && b6 == LOW ) {
  for (pos = pos_index ; pos <= 180; pos += 1) {    
    index.write(pos);       
    delay(time_loop);                      
  }
  for (pos = pos_middle; pos <= 180; pos += 1) {
    middle.write(pos);             
    delay(time_loop);                       
  }
  for (pos = pos_ring ; pos <= 180; pos += 1) {
    ring.write(pos);             
    delay(time_loop);                       
  }
  

pos_baby =0;
pos_ring =180;
pos_middle =180;
pos_index =180;
pos_thumb_bending =0;
pos_thumb_rotation =0;
 
    }

//5 => OK
    if (b1 == LOW && b2 == LOW && b3 == LOW && b4 == LOW && b5== HIGH && b6 == LOW ) {
 for (pos = pos_index ; pos <= 120; pos += 1) {    
    index.write(pos);        
    delay(time_loop);                        
  }
  for (pos = pos_middle; pos <= 20; pos += 1) {
    middle.write(pos);             
    delay(time_loop);                       
  }
  for (pos = pos_ring ; pos <= 20; pos += 1) {
    ring.write(pos);             
    delay(time_loop);                       
  }
  for (pos =pos_baby; pos <= 10; pos += 1) {
    baby.write(pos);             
    delay(time_loop);                       
  }
  for (pos = pos_thumb_rotation; pos <= 60; pos += 1) {
    pouce_rotation.write(pos);             
    delay(time_loop);                       
  }
  for (pos = pos_thumb_bending ; pos <= 100; pos += 1) {
    pouce_bending.write(pos);             
    delay(time_loop);                       
  }

pos_baby =10;
pos_ring =20;
pos_middle =20;
pos_index =120;
pos_thumb_bending =100;
pos_thumb_rotation =60;
 
 
    }

//6 => 6  RESET
    if (b1 == LOW && b2 == LOW && b3 == LOW && b4 == LOW && b5== LOW && b6 == HIGH ) {
 

  for (pos = pos_thumb_bending; pos >= 0; pos -= 1) { 
    pouce_bending.write(pos);             
    delay(time_loop); 
  }
  for (pos = pos_thumb_rotation; pos >= 0; pos -= 1) { 
    pouce_rotation.write(pos);             
    delay(time_loop); 
  }
  for (pos = pos_index; pos >= 0; pos -= 1) { 
    index.write(pos);             
    delay(time_loop); 
  }
  for (pos = pos_middle; pos >= 0; pos -= 1) { 
    middle.write(pos);             
    delay(time_loop); 
  }
  for (pos = pos_ring; pos >= 0; pos -= 1) { 
    ring.write(pos);             
    delay(time_loop); 
  }
  for (pos = pos_baby; pos >= 0; pos -= 1) { 
    baby.write(pos);             
    delay(time_loop); 
  }
pos_baby =0;
pos_ring =0;
pos_middle =0;
pos_index =0;
pos_thumb_bending =0;
pos_thumb_rotation =0;
    }

    }

