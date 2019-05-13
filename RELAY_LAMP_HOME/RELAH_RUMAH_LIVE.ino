// SOURCE CODE INI
// TERAKHIR DI UPDATE TGL 04 APRIL 2019

#include <Wire.h>
#include "RTClib.h"

int Relay1 = 4;
int Relay2 = 5;
int Relay3 = 6;
int Relay4 = 7;
RTC_DS1307 rtc;

void setup() {
  Serial.begin(9600);
  rtc.begin();

  if (! rtc.isrunning())
  {
  Serial.println("RTC is Not running");
  }
  
  pinMode(Relay1, OUTPUT);
  digitalWrite(Relay1, LOW);

  pinMode(Relay2, OUTPUT);
  digitalWrite(Relay2, LOW);

  /*pinMode(Relay2, OUTPUT);
  digitalWrite(Relay2, LOW);*/
}

void loop() {
  DateTime now = rtc.now();
// Serial.println(now,DEC);
 Serial.print(now.day());
 Serial.print("/");
 Serial.print(now.month());
 Serial.print("/");
 Serial.print(now.year());
 Serial.print(" ");
 Serial.print(now.hour());
 Serial.print(":");
 Serial.print(now.minute());
 Serial.print(":");
 Serial.println(now.second());
 delay(1000);
  
  if(now.hour() >= 17 || now.hour() < 5){
    digitalWrite(Relay1,LOW);
    digitalWrite(Relay2,LOW);
    Serial.println("LIGHT ON /UPDATE ON 05/03/2019");
   } else {
      digitalWrite(Relay1,HIGH);
      digitalWrite(Relay2,HIGH);
      Serial.println("LIGHT OFF /UPDATE ON 05/03/2019");
   }

   /*if(now.minute() >= 17 || now.minute() < 5){
    digitalWrite(Relay2,LOW);
    Serial.println("LIGHT ON");
   } else {
      digitalWrite(Relay2,HIGH);
      Serial.println("LIGHT OFF");
   }*/
}
