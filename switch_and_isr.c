//EMil Crestian  23  Oct  2018; motor spin cw/ccw/stop based on the button press;
//Based on how long the button is pressed;
#include <stdio.h>
#include <wiringPi.h>
#include <math.h>

int button_pressed = 0;
int led_delay = 200;
void setup();
void motor_cw();
void motor_ccw();
void motor_stop();
void ISR ();


void main () 
{
	setup(); 	// Initialize setup sequence
	while (1) 
	{
    switch (button_pressed) 
    {
      case 1 :
        motor_cw();
        break;
      case 2 :
        motor_ccw();
        break;
      case 3 :
        motor_stop();
        break;
      default : 
        motor_stop();
    }


	}
}


void setup() 
{
	//initialize wiringPi sequence
	wiringPiSetup();
	//Set directionality of GPIO port 0
	pinMode(23,PWM_OUTPUT);
	pinMode(26,PWM_OUTPUT);
  wiringPiISR(1,INT_EDGE_FALLING,&ISR1);
  wiringPiISR(2,INT_EDGE_FALLING,&ISR2);
  wiringPiISR(3,INT_EDGE_FALLING,&ISR3);

}

void ISR1 () 
{
  button_pressed = 1;
}

void ISR2 () 
{
  button_pressed = 2;
}

void ISR3 () 
{
  button_pressed = 3;
}

void motor_cw  () 
{
  pwmWrite(23,1000);
  pwmWrite(26,0);
}

void motor_ccw  () 
{
  pwmWrite(23,0);
  pwmWrite(26,1000);
}
void motor_stop  () 
{
  pwmWrite(23,0);
  pwmWrite(26,0);
}
