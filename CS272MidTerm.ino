int inputValue=0;
int inputPin=0;
int currentCounter=0;
int displayNumber=0;
int startTime=0;
unsigned long ledTime=0;
boolean gotValue=false;
int led1=9;
int led2=10;
int led3=11;
int led4=12;
int led5=14;
int led6=15;
int led7=16;
int redled=7;
int yellowled=8;
int greenled=17;
int blueled=6;
int ledStatus = 1;

void setup() {
  Serial.begin(9600);
    pinMode(inputPin, INPUT);
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
    pinMode(led5, OUTPUT);
    pinMode(led6, OUTPUT);
    pinMode(led7, OUTPUT);
    pinMode(redled, OUTPUT);
    pinMode(blueled, OUTPUT);
    pinMode(yellowled, OUTPUT);
    pinMode(greenled, OUTPUT);
}

void loop() {
    inputValue=digitalRead(inputPin);
  
    if(inputValue==0){
      digitalWrite(redled,LOW);
      digitalWrite(blueled,LOW);
      digitalWrite(yellowled,LOW);
      digitalWrite(greenled,LOW);
      currentCounter=readValue();
      startTime=millis();
      gotValue=true;
    }
    Serial.println(currentCounter);
    if(gotValue==true){
        if(currentCounter!=0){
      
            if((millis()-startTime)>=1000){
                currentCounter=currentCounter-1;
                startTime=millis();
            }
            
            displayNumber=currentCounter/60;
            if(displayNumber==0){
                digitalWrite(led1, HIGH);
                digitalWrite(led2, LOW);
                digitalWrite(led3, LOW);
                digitalWrite(led4, LOW);
                digitalWrite(led5, LOW);
                digitalWrite(led6, LOW);
                digitalWrite(led7, LOW);
            }
            else if(displayNumber==1){
              //light 4,7
              digitalWrite(led1, HIGH);
              digitalWrite(led2, HIGH);
              digitalWrite(led3, HIGH);
              digitalWrite(led4, LOW);
              digitalWrite(led5, HIGH);
              digitalWrite(led6,HIGH);
              digitalWrite(led7,LOW);
            }
            else if(displayNumber==2){
              //light 1,3,4,5,6
              digitalWrite(led1, LOW);
              digitalWrite(led2, HIGH);
              digitalWrite(led3, LOW);
              digitalWrite(led4, LOW);
              digitalWrite(led5, LOW);
              digitalWrite(led6, LOW);
              digitalWrite(led7, HIGH);
            }
            else if(displayNumber==3){
              //light 1,3,4,6,7
              digitalWrite(led1, LOW);
              digitalWrite(led2, HIGH);
              digitalWrite(led3, LOW);
              digitalWrite(led4, LOW);
              digitalWrite(led5, HIGH);
              digitalWrite(led6, LOW);
              digitalWrite(led7, LOW);
            }
            else if(displayNumber==4){
              //light 1,2,4,7
              digitalWrite(led1, LOW);
              digitalWrite(led2, LOW);
              digitalWrite(led3, HIGH);
              digitalWrite(led4, LOW);
              digitalWrite(led5, HIGH);
              digitalWrite(led6, HIGH);
              digitalWrite(led7, LOW);
            }
            else if(displayNumber==5){
              //light 1,2,3,6,7
              digitalWrite(led1, LOW);
              digitalWrite(led2, LOW);
              digitalWrite(led3, LOW);
              digitalWrite(led4, HIGH);
              digitalWrite(led5, HIGH);
              digitalWrite(led6, LOW);
              digitalWrite(led7, LOW);
            }
            else if(displayNumber==6){
              //light 1,2,3,5,6,7
              digitalWrite(led1, LOW);
              digitalWrite(led2, LOW);
              digitalWrite(led3, LOW);
              digitalWrite(led4, HIGH);
              digitalWrite(led5, LOW);
              digitalWrite(led6, LOW);
              digitalWrite(led7, LOW);;
            }
            else if(displayNumber==7){
              //light 3,4,7
              digitalWrite(led1, HIGH);
              digitalWrite(led2, HIGH);
              digitalWrite(led3, LOW);
              digitalWrite(led4, LOW);
              digitalWrite(led5, HIGH);
              digitalWrite(led6, HIGH);
              digitalWrite(led7, LOW);
            }
            else if(displayNumber==8){
              //light 1,2,3,4,5,6,7
              digitalWrite(led1, LOW);
              digitalWrite(led2, LOW);
              digitalWrite(led3, LOW);
              digitalWrite(led4, LOW);
              digitalWrite(led5, LOW);
              digitalWrite(led6, LOW);
              digitalWrite(led7, LOW);;
            }
            else{
              //light 1,2,3,4,6,7
              digitalWrite(led1, LOW);
              digitalWrite(led2, LOW);
              digitalWrite(led3, LOW);
              digitalWrite(led4, LOW);
              digitalWrite(led5, HIGH);
              digitalWrite(led6, LOW);
              digitalWrite(led7, LOW);;
            } 
      }
      else{
          //light 2,3,4,5,6,7
          digitalWrite(led1, HIGH);
          digitalWrite(led2, LOW);
          digitalWrite(led3, LOW);
          digitalWrite(led4, LOW);
          digitalWrite(led5, LOW);
          digitalWrite(led6, LOW);
          digitalWrite(led7, LOW);
          unsigned long currentTime=millis();
          if(currentTime-ledTime>=1000){
                ledTime=currentTime;
                if(ledStatus==1){
                    ledStatus=2;
                    digitalWrite(redled, HIGH);
                    digitalWrite(blueled, LOW);
                    digitalWrite(yellowled, HIGH);
                    digitalWrite(greenled, LOW);
                }
                else if(ledStatus==2){
                    ledStatus=3;
                    digitalWrite(redled, LOW);
                    digitalWrite(blueled, LOW);
                    digitalWrite(yellowled, LOW);
                    digitalWrite(greenled, LOW);
                }
                else if(ledStatus==3){
                    ledStatus=4;
                    digitalWrite(redled, HIGH);
                    digitalWrite(blueled, HIGH);
                    digitalWrite(yellowled, LOW);
                    digitalWrite(greenled, LOW);
                }
                else{
                    ledStatus=1;
                    digitalWrite(redled, LOW);
                    digitalWrite(blueled, LOW);
                    digitalWrite(yellowled, HIGH);
                    digitalWrite(greenled, HIGH);
           }
            
          }
       }
  
  }
  else{
        digitalWrite(led1, HIGH);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        digitalWrite(led5, LOW);
        digitalWrite(led6, LOW);
        digitalWrite(led7, LOW);
        
        digitalWrite(redled, LOW);
        digitalWrite(blueled, LOW);
        digitalWrite(yellowled, LOW);
        digitalWrite(greenled, LOW);
  }
}

int readValue(){
  int value=0;
  int highBit=32768;
  int lowBit=128;

  delay(10);
  
  for(int i=0;i<8;i++){
      value=value+(digitalRead(inputPin)*highBit);
      highBit=highBit/2;  
      delay(10);
  }
  delay(10);
  while(digitalRead(inputPin)==0);
  delay(10);
  for(int i=0;i<8;i++){
      value=value+(digitalRead(inputPin)*lowBit);
      lowBit=lowBit/2;
      delay(10);
  }
  return value;
}
