#include <IRremote.h>

// C++ code
//
int led=9;
const unsigned long eventTime=1000;
unsigned long temp=0;
  unsigned long startMillis;
 unsigned long currentMillis;
void setup()
{
  
  pinMode(led, OUTPUT);
   pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop()
{
  
            Serial.println("welcome to LDR Tutorial");
            int sensorvalue=analogRead(A0);
            Serial.println(sensorvalue);
            delay(5);
  if(sensorvalue>900)
  {
        bool flag=0;
         while(1)
    {      currentMillis=millis();
         if(currentMillis-temp>=eventTime)
      {
           Serial.println("check");
        sensorvalue=analogRead(A0);
           
        if(sensorvalue<900)
       {
          flag=1;
          break;
       }
        temp=currentMillis;
           Serial.println("c");
     Serial.println(currentMillis);
           Serial.println("s");
     Serial.println(startMillis);
           Serial.println("c-s");
     Serial.println(currentMillis-startMillis);
         if(currentMillis-startMillis>=60000)
        {
         break;
        }
      }
     }
        if(!flag)
    { 
          Serial.println("LED IS ON");
          digitalWrite(led,HIGH);
          
     }
  // delay(10);
   }
    else
  {
      currentMillis=millis();
      startMillis=currentMillis;
      Serial.println("c");
     Serial.println(currentMillis);
           Serial.println("s");
     Serial.println(startMillis);
           Serial.println("c-s");
     Serial.println(currentMillis-startMillis);
      Serial.println("LED IS OFF");
     digitalWrite(9,LOW);
  }
}