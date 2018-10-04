#include <stdio.h>
#include <wiringPi.h>


int two_sec_delay = 2000;
void setup();
void toggle_led();


void main () 
{
	setup(); 	// Initialize setup sequence
	int num_blinks, i; // Declare variables to be used in the main program;
	printf("How many times would you like your LED to blink?\n"); //Ask for input for number of blinks
	scanf("%d", &num_blinks); // Read in the value as a decimal number and store it as number of blinks 


	printf("Blinking LED %d times\n",num_blinks);
	for(i=0;i<num_blinks;i++) // Toggle LED for every num_blinks;
	{
		toggle_led();
	}

}


void setup() 
{
	//initialize wiringPi sequence
	wiringPiSetup();
	//Set directionality of GPIO port 0
	pinMode(0,OUTPUT);
}

void toggle_led () 
{
	digitalWrite(0,HIGH);
	delay(two_sec_delay);
	digitalWrite(0,LOW);
	delay(two_sec_delay);
}
