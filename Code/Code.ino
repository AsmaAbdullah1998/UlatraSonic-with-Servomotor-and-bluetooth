
#define trigPin 13
#define echoPin 12
#include <Servo.h> 

long duration; 
long timeStart;
int distance; 
Servo Servo1; 



void setup(){
  Serial.begin(9600); 

  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 


  Servo1.write(0); 
  Servo1.attach(11); 

  while(!Serial)
  {
    
  }

  
}

void loop(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance = ");
  Serial.println(distance);

  if(distance <=15){
    timeStart = millis();
    while(distance <=15){
      if(millis() - timeStart == 3000){
        Serial.println("3 Seconds!");
        Servo1.write(90);
        delay(100);
        break;
      }
      
    }
    
  }else{
    delay(1000);
    Servo1.write(0);
  }


  



  


  
}
