//EMil Crestian 17 Sep 2018; Push button 
#include <stdio.h>
#include <wiringPi.h>

int bounce;
int two_sec_delay = 500;
void setup();
void toggle_led();
void i_sr();
void red_light();
void yellow_light();
void green_light();

void main () 
{
	setup(); 	// Initialize setup sequence
  while(1)
  {
    digitalWrite(3,LOW);
    green_light();
    delay(5000);
    yellow_light();
    delay(1000);
    red_light();
    delay(4000);

  }
	

}


void setup() 
{
	//initialize wiringPi sequence
	wiringPiSetup();
  wiringPiISR(4,INT_EDGE_FALLING,&i_sr);
	//Set directionality of GPIO port 0
	pinMode(4,INPUT);
	pinMode(12,OUTPUT); // Yellow
	pinMode(0,OUTPUT); //Green
	pinMode(2,OUTPUT); // Red
}

void yellow_light () 
{
	digitalWrite(12,HIGH);
	digitalWrite(0,LOW);
	digitalWrite(2,LOW);
}

void red_light () 
{
	digitalWrite(2,HIGH);
	digitalWrite(0,LOW);
	digitalWrite(12,LOW);
}

void green_light () 
{
	digitalWrite(0,HIGH);
	digitalWrite(2,LOW);
	digitalWrite(12,LOW);
}


void i_sr ()
{
  int bleh;
  for (bleh = 0; bleh < 3; bleh++) {
	digitalWrite(0,HIGH);
	digitalWrite(2,HIGH);
	digitalWrite(12,HIGH);
  delay(200);

	digitalWrite(0,LOW);
	digitalWrite(2,LOW);
	digitalWrite(12,LOW);
  delay(200);
  }

}

  
