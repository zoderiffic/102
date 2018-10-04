//EMil Crestian 17 Sep 2018; Push button 
#include <stdio.h>
#include <wiringPi.h>


int two_sec_delay = 500;
void setup();
void toggle_led();


void main () 
{
	setup(); 	// Initialize setup sequence
	int num_blinks, i; // Declare variables to be used in the main program;

	while (1) 
	{
		while (digitalRead(2))
		{
			digitalWrite(0,HIGH);
			digitalWrite(3,LOW);
		}
		digitalWrite(0,LOW);
		toggle_led();
		toggle_led();
		toggle_led();	
	}
	

}


void setup() 
{
	//initialize wiringPi sequence
	wiringPiSetup();
	//Set directionality of GPIO port 0
	pinMode(2,INPUT);
	pinMode(3,OUTPUT);
	pinMode(0,OUTPUT);
}

void toggle_led () 
{
	digitalWrite(3,HIGH);
	delay(two_sec_delay);
	digitalWrite(3,LOW);
	delay(two_sec_delay);
}
