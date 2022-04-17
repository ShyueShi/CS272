#include <Metro.h>
#define buttonInput 0
#define buttonOutput 23
#define outputBrightness 21
#define outputTimer 20
#define leftSensor 14
#define rightSensor 19

Metro * counter;
int buttonState=0;
int count=0;
int threshold=5;
int ledState=0;
int prevLeftSensor;
int currLeftSensor;
int prevRightSensor;
int currRightSensor;
int leftSensorFirst;
int rightSensorFirst;
int people;
int buttonStatus;
int buttonPressed;
int prevTime;
int currTime;

void setup() {
  prevTime = 600+((analogRead(outputTimer)/4)*0.9)/256*6000;
  currTime=600+((analogRead(outputTimer)/4)*0.9)/256*6000;
  counter = new Metro(100);
  pinMode(buttonInput,INPUT);
  pinMode(buttonOutput,OUTPUT);
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor,INPUT);
  pinMode(outputBrightness, INPUT);
  pinMode(outputTimer, INPUT);
}

void loop() {
  buttonStatus=checkButton();
  checkTimer(ledState);
  
  if(buttonStatus ==1){
    if(ledState==0){
      buttonPressed=1;
      ledState=1;
    }
    else{
      ledState=0;
    }
  }
  if(buttonPressed==0){
    prevLeftSensor = currLeftSensor;
    prevRightSensor = currRightSensor;
    currLeftSensor = digitalRead(leftSensor);
    currRightSensor = digitalRead(rightSensor);

    if(prevLeftSensor == 1 && currLeftSensor == 0){
      //drop edge in left sensor
      if(rightSensorFirst==0){
        //person entering
        leftSensorFirst=1;
      }
    }

    if(prevLeftSensor==0 && currLeftSensor==1){
      //rise edge in left sensor
      if(rightSensorFirst==1){
        //person just left the room
        people--;
        if(people <= 0){
          ledState=0;
        }
        rightSensorFirst=0;
      }
    }
  
    if(prevRightSensor==1 && currRightSensor==0){
      //drop edge in right sensor
      if(leftSensorFirst==0){
        //person leaving
        rightSensorFirst=1;
      }
    }

    if(prevRightSensor==0 && currRightSensor==1){
      //rise edge in right sensor
      if(leftSensorFirst==1){
        //light the lamp and person entered the room
        people++;
        ledState=1;
        leftSensorFirst=0;
      }
    }
    if(currTime==0){
      people=0;
      ledState=0;
      currTime=prevTime;
    }
  }
  
  
  
  if(ledState==1){
    analogWrite(buttonOutput, 51.2+((analogRead(outputBrightness)/4)*0.8));
    
  }
  else{
    analogWrite(buttonOutput,0);
    people=0;
    checkTimer(ledState);
  }
  
}

int checkButton(){
  if(buttonState==0){
    if(digitalRead(buttonInput) == 1){
      count++;
    }
    else{
      count=0;
    }
    if(count>threshold){
      count=0;
      buttonState=1;
    }
  }
  else{
    if(digitalRead(buttonInput) == 0){
      count++;
    }
    else{
      count=0;
    }
    if(count>threshold){
      count=0;
      buttonState=0;
      return 1;
    }
  }
  return 0;
}

void checkTimer(int ledState){
  if(ledState==1&&buttonPressed==0){
    if(counter->check()==1){
    counter->reset();
    double time = 600+((analogRead(outputTimer)/4)*0.9)/256*6000;
    //Serial.println(time);
    if(prevTime-time>50 ||time-prevTime>50){
      currTime=time;
      prevTime=time;
    }
    currTime = currTime - 1;
    }
  }
  else{
    currTime = 600+((analogRead(outputTimer)/4)*0.9)/256*6000;
  }
  
}
