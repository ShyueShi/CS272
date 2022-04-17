#include <Metro.h>
#define LED 13
#define input 14
#define out 0

Metro * timer;
int buttonState=0;
int count=0;
int threshold=10;
int sysState=0;
int ledState=0;

void setup() {
  Serial.begin(9600);
  timer = new Metro(800);
  pinMode(LED,OUTPUT);
  pinMode(input,INPUT);
  pinMode(out,OUTPUT);
}

void loop() {
  if(buttonState==0){
    //Serial.println(digitalRead(input));
    if(digitalRead(input) == 1){
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
   // Serial.println(digitalRead(input));
    if(digitalRead(input) == 0){
      count++;
    }
    else{
      count=0;
    }
    if(count>threshold){
      count=0;
      buttonState=0;
      ledState=1;
      
    }
    if(ledState==1 && digitalRead(input)==1){
      ledState=0;
      digitalWrite(LED,HIGH);
      timer->reset();
      if(sysState==0){
        digitalWrite(out,HIGH);
        sysState=1;
      }
      else{
        digitalWrite(out,LOW);
        sysState=0;
      }
    }

    if(timer->check()==1){
        digitalWrite(LED,LOW);
    }
    
  }
  
}
