//EMil Crestian  1 Oct  2018; PWM various brightness LED 
//Based on how long the button is pressed;
#include <stdio.h>
#include <wiringPi.h>


int led_delay = 200;
void setup();
void bright_led();
void dim_led();


void main () 
{
	setup(); 	// Initialize setup sequence
	int user_value;
	while (1) 
	{
    printf("How much time should the LED take to ramp up/down?\n");
    scanf("%d", &user_value);
    bright_led(user_value);
    dim_led(user_value);

	}
}


void setup() 
{
	//initialize wiringPi sequence
	wiringPiSetup();
	//Set directionality of GPIO port 0
	pinMode(23,PWM_OUTPUT);
}

void bright_led  (int blinky_blink) 
{
  int time_to_hold;
  int bleh;
  time_to_hold = round(blinky_blink / 1023 * 1000);
  for (bleh= 0; bleh < 1024; bleh ++ ) 
  {
    pwmWrite(23,bleh);
    delay(time_to_hold);
  }
}

void dim_led  (int blinky_blink) 
{
  int time_to_hold;
  int bleh;
  time_to_hold = round(blinky_blink / 1023 * 1000);
  for (bleh= 1023; bleh = 0 ; bleh -- ) 
  {
    pwmWrite(23,bleh);
    delay(time_to_hold);
  }
}
