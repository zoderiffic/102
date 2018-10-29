//Emil Crestian 29 Oct 2018; Radar thingie
// Determine the distance of an object and wherever it is moving in closer or further away
//


#include <stdio.h>
#include <wiringPi.h>

void setup();

void main() 
{
  int counter = 0;
  float distance_new = 0;
  float distance_old = 0;
  while(1) 
  {
    counter = 0; 
    digitalWrite(3,LOW);
    delay(1000); //1 second delay between sampling;
    digitalWrite(3,HIGH); //send the impulse
    delayMicroseconds(10); //output signal needs to be ~10us
    digitalWrite(3,LOW); // Terminate the impulse
    while(!digitalRead(2))
    {
      delayMicroseconds(5);
    }
    
    while(digitalRead(2))
    {
      delayMicroseconds(5);
      counter++;
    }
    distance_old = distance_new;
    distance_new = (5.0*counter)/148.0;
    printf("\nDistance to object is %f inches \n", distance_new);
    if (distance_old > distance new) 
    {
     //TURN ON GREEN LED; TURN OFF RED LED;
     digitalWrite(0,HIGH);
     digitalWrite(1,LOW);
    }
    else 
    {
      //TURN ON RED LED; TURN  OFF GREEN LED
      digitaWrite(0,LOW);
      digitalWrite(1,HIGH);
    }
  }

}

void setup() 
{

  wiringPiSetup();
  pinMode(2,INPUT); //Echo output from the radar chip
  pinMode(3,OUTPUT); // Trigger input on the radar chip
  pinmode(1,OUTPUT); //RED LED
  pinmode(0,OUPUT); //GREEN LED
 
}

