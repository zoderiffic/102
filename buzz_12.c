//EMil Crestian 29 Oct 2018
//TMB Buzzer with reed switch;
#include <stdio.h>
#include <wiringPi.h>


void setup();


void main () 
{
	setup(); 	// Initialize setup sequence

  int count=0;
	while (1) 
	{
    count = 0; // RESET COUNTER ONCE NO MAGNETIC FIELD PRESENT
    while (!digitalRead(0);) // WHILE MAGNETIC FIELD IS PRESENT
    {
      if (count < 4)  // COUNT IS INCREMENTED EVERY 5 seconds; 4*5 = 20 seconds while below 20 seconds buzz once
      {
        one_buzz();
        delay(5000);
        count++
      }
      else  // ONCE COUNT IS GREATER OR EQUAL THAN 4 DO A THRE BUZZ THINGIE;
      {
        three_buzz();
        delay(5000);
      }
      
    }
	}
	

}


void setup() 
{
	//initialize wiringPi sequence
	wiringPiSetup();
	//Set directionality of GPIO port 0
	pinMode(0,INPUT);// REEDSWITCH
  pinMode(1,OUTPUT); //Buzzer
}

void one_buzz () 
{
  digitalWrite(1,HIGH);
  delay(100);
  digitalWrite(1,LOW);
  delay(100);
}

void three_buzz () 
{
  digitalWrite(1,HIGH);
  delay(100);
  digitalWrite(1,LOW);
  delay(100);
  digitalWrite(1,HIGH);
  delay(100);
  digitalWrite(1,LOW);
  delay(100);
  digitalWrite(1,HIGH);
  delay(100);
  digitalWrite(1,LOW);
  delay(100);
}
