//EMil Crestian  5  Oct  2018; motor spin up/down based on the presence of magnetic field 
//Based on how long the button is pressed;
#include <stdio.h>
#include <wiringPi.h>
#include <math.h>

int led_delay = 200;
void setup();
void motor_spin_up();
void motor_spin_down();


void main () 
{
	setup(); 	// Initialize setup sequence
	while (1) 
	{
    if (digitalRead(1)) 
    {
    motor_spin_up(10000);
    }
    while(digitalRead(1)); 
    motor_spin_down(10000);

	}
}


void setup() 
{
	//initialize wiringPi sequence
	wiringPiSetup();
	//Set directionality of GPIO port 0
	pinMode(23,PWM_OUTPUT);
  pinMode(1,INPUT);
}

void motor_spin_up  (int blinky_blink) 
{
  int time_to_hold;
  int bleh;
  time_to_hold = blinky_blink / 1023 * 1000;
  for (bleh= 0; bleh < 1024; bleh ++ ) 
  {
    pwmWrite(23,bleh);
    delay(time_to_hold);
  }
}

void motor_spin_down  (int blinky_blink) 
{
  int time_to_hold;
  int bleh;
  time_to_hold = blinky_blink / 1023 * 1000;
  for (bleh= 1023; bleh = 0 ; bleh -- ) 
  {
    pwmWrite(23,bleh);
    delay(time_to_hold);
  }
}
