//EMil Crestian 19 Sep 2018; Push button 
//Based on how long the button is pressed;
#include <stdio.h>
#include <wiringPi.h>


int led_delay = 200;
void setup();
void toggle_led();


void main () 
{
	setup(); 	// Initialize setup sequence
	int num_blinks, i; // Declare variables to be used in the main program;
	int led_counter=0;
	while (1) 
	{
		led_counter =0;
		while(!digitalRead(2)) 
		{
			delay(1000);
			if (!digitalRead(2)) 
			{
				led_counter++;
			}

//		printf("Button was pressed for %d seconds \n", led_counter);
			if (led_counter !=0) 
			{	
				printf("Button was pressed for %d seconds \n", led_counter);
			}
			else 
			{
				printf("The push was not long enough\n");
			}
		 
		
		}
		for (i=0;i < led_counter;i++) 
		{
			toggle_led();
		}
	}
}


void setup() 
{
	//initialize wiringPi sequence
	wiringPiSetup();
	//Set directionality of GPIO port 0
	pinMode(2,INPUT);
	pinMode(0,OUTPUT);
}

void toggle_led () 
{
	digitalWrite(0,HIGH);
	delay(led_delay);
	digitalWrite(0,LOW);
	delay(led_delay);
}
