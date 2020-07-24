#include <Servo.h>


#define t1 A5
#define e1 A4

#define t2 A3
#define e2 A2

const int ir=5;
const int red=1;
#define light A0
const int buzz=3;
const int green=9;
Servo s;
long time1;
long time2;
int d1;
int d2;




void setup() {
    pinMode(t1, OUTPUT);
    pinMode(e1, INPUT);
    pinMode(t2, OUTPUT);
    pinMode(e2, INPUT);
    pinMode(ir, INPUT);
    pinMode(red, OUTPUT);
    pinMode(buzz, OUTPUT);
    pinMode(light, INPUT);
    s.attach(12);
    Serial.begin(9600);
    

}

void loop() {
  
  int ss=digitalRead(ir);
  digitalWrite(red,HIGH);

  delay(50);
  digitalWrite(t1,LOW);
  delayMicroseconds(10); 
  digitalWrite(t1,HIGH);
  delayMicroseconds(10);
  digitalWrite(t1,LOW);
  time1=pulseIn(e1,HIGH); 
  d1=time1*0.034*0.5;
  Serial.print("1- ");
  Serial.println(d1);
  

  delay(50);


  digitalWrite(t2,LOW);
  delayMicroseconds(10); 
  digitalWrite(t2,HIGH);
  delayMicroseconds(10);
  digitalWrite(t2,LOW);
  time2=pulseIn(e2,HIGH); 
  d2=time2*0.034*0.5;
  Serial.println(d2);
  
  if(d1>7 || d2>7){
    if(ss==0){
      s.write(-20);
      digitalWrite(buzz,HIGH);
      digitalWrite(red,LOW);
      delay(1000);
      }
  }
  digitalWrite(buzz,LOW);
  if (ss==1){
    s.write(90);
    delay(60);
  }

  






  
}
