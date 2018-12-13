//EMil Crestian  5  Oct  2018; motor spin up/down based on the presence of magnetic field 
//Based on how long the button is pressed;
#include <stdio.h>
#include <wiringPi.h>
#include <math.h>

int led_delay = 200;
void setup();
void move_up();
void move_down();
void outside_first_floor();
void outside_second_floor();
void outside_third_floor();
void inside_first_floor();
void check_floor();
void buzz();
int direction;
int duration;
int current_floor = 1;
int old_floor=0;
int new_floor;


void main () 
{
	setup(); 	// Initialize setup sequence
  while(1)
  {
  }
 }
  

void check_floor ()
{
  
    int floor_delta = old_floor - new_floor;
    printf("New Floor   : %d    Old floor   : %d    Floor_delta     : %d\n", new_floor, old_floor, floor_delta);
    while ( floor_delta < 0) 
    {
      move_down (3000);
      floor_delta++;
    }
    while( floor_delta > 0) 
    {
      move_up(3000);
      floor_delta--;
    }

}



void setup() 
{
	//initialize wiringPi sequence
	wiringPiSetup();
	//Set directionality of GPIO port 0
	pinMode(23,PWM_OUTPUT);
	pinMode(26,PWM_OUTPUT);
  wiringPiISR(0,INT_EDGE_FALLING,&outside_first_floor);
  wiringPiISR(1,INT_EDGE_FALLING,&outside_second_floor);
  wiringPiISR(2,INT_EDGE_FALLING,&outside_third_floor);
  wiringPiISR(3,INT_EDGE_FALLING,&inside_first_floor);
}

void outside_first_floor () 
{
  old_floor = new_floor;
  new_floor = 1;
  check_floor();
}

void outside_second_floor () 
{
  old_floor = new_floor;
  new_floor = 2;
  check_floor();
}

void outside_third_floor () 
{
  old_floor = new_floor;
  new_floor = 3;
  check_floor();
}

void inside_first_floor ()
{
  old_floor= new_floor;
  new_floor = 1;
  check_floor();
}


void move_up  (int time_to_hold) 
{
    pwmWrite(23,1000);
    pwmWrite(26,0);
    delay(time_to_hold);
    pwmWrite(23,0);
    pwmWrite(26,0);
}

void move_down  (int time_to_hold) 
{
    pwmWrite(23,0);
    pwmWrite(26,1000);
    delay(time_to_hold);
    pwmWrite(26,0);
    pwmWrite(23,0);
}

void buzz () 
{
  delay(1);
}
