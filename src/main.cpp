
#include <string.h>

#include <Wire.h>
#include "RTClib.h"



RTC_DS3231 rtc;


int displayTime = 2; 

String incomming;

long r, g, b;
volatile bool received = false;
bool timeoutTimer = false;
bool longTimeout = false;
bool offtime = false;
DateTime timestamp;
volatile bool activity = false;
volatile int lastActivityTimestamp;
long nextUpdate;
long timeoutAmount = 12000;
volatile int timeoutCount = 2;





void serialEvent()
{
   
    incomming = Serial.readString();
    if (incomming.startsWith("#"))
    {
      switch(incomming.length())
        {
           // Get rid of '#' and convert it to integer
         long number = (long) strtol( &incomming[1], NULL, 16);

         // Split them up into r, g, b values
        r = number >> 16;
        g = number >> 8 & 0xFF;
        b = number & 0xFF;
        
      case 4:
         
         long number = (long) strtol( &incomming[1], NULL, 10);

        
         

         
        
         received = true;

      
 

        //incomming = "";
    
    
     }
}

void setup ()
{
 


Serial.begin(9600);
}


void loop()
{

}