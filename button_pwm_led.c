//EMil Crestian  8 Oct  2018;
//dim and righten led based on 4 button inputs
#include <stdio.h>
#include <wiringPi.h>

int increment = 20;
int led_delay = 500;
void setup();
void bright_led_0();
void dim_led_0();
void bright_led_1();
void dim_led_1();
int pwm1=0; 
int pwm2=0;

void main () 
{
	setup(); 	// Initialize setup sequence
	int user_value;
  pwmWrite(23,pwm1);
  pwmWrite(26,pwm2);
	while (1) 
  {
    while (!digitalRead(0))
        {
         if (pwm1 > 1024 - increment)
         {
          pwm1 = pwm1 ;
         }

         else 
         {pwm1 = pwm1 + increment;}
          delay(led_delay);
          pwmWrite(23,pwm1);
        }

    while (!digitalRead(1))
        {
          if (pwm1 > increment) {
          pwm1 = pwm1 - increment ;} 
          else { pwm1 = pwm1 ;
          pwmWrite(23,pwm1);
          }
          delay(led_delay);
        }
    while (!digitalRead(3))
        {
          if (pwm2 > 1024 - increment) {
        pwm2 = pwm2;} 
          else { pwm2 = pwm2 + increment;}
        delay(led_delay);
        pwmWrite(26,pwm2);}
        }
    while (!digitalRead(2))
        {
          if (pwm2 > increment) {
        pwm2 = pwm2 - increment;} 
          else { pwm2 = pwm2;}
        pwmWrite(26,pwm2);
          delay(led_delay);
        }
  }




void setup() 
{
	//initialize wiringPi sequence
	wiringPiSetup();
	//Set directionality of GPIO port 0
	pinMode(23,PWM_OUTPUT); // LED 0 
	pinMode(26,PWM_OUTPUT); // LED1
	pinMode(0,INPUT); // LED1
	pinMode(1,INPUT); // LED1
	pinMode(2,INPUT); // LED1
	pinMode(3,INPUT); // LED1


}

void bright_led_0  ( ) 
{

  int bleh; 
  for (bleh= 0; bleh < 1024; bleh = bleh +20 ) 
  {
    pwmWrite(23,bleh);
    delay(500);
  }
}

void dim_led_0  () 
{
  int time_to_hold;
  int bleh;
  for (bleh= 0;  bleh <1024 ; bleh +20 ) 
  {
    pwmWrite(23,1024-bleh);
    delay(500);
  }
}



void bright_led_1  ( ) 
{

  int bleh; 
  for (bleh= 0; bleh < 1024; bleh = bleh +20 ) 
  {
    pwmWrite(26,bleh);
    delay(500);
  }
}

void dim_led_1  () 
{
  int time_to_hold;
  int bleh;
  for (bleh= 0;  bleh <1024 ; bleh +20 ) 
  {
    pwmWrite(26,1024-bleh);
    delay(500);
  }
}
