//EMil Arsen and Nasser
//Elevator Project 15 Dec 2018
//Based on how long the button is pressed;


/* TODO:
 * Verify interrupt service routine on pin 0 and 1;
 * Verify circuit/direction of the motor:
 *    Moving down PWM is not working  for now, should be an easier fix 
 *
 * Implement and connect buzzer
 *
 *
 *
 */
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
void inside_second_floor();
void inside_third_floor();
void check_floor();
void buzz();
int direction;
int duration;
int current_floor = 1;
int old_floor=1;
int new_floor = 1;


void main () 
{
	setup(); 	// Initialize setup sequence
  while(1)
  {
  }
 }
  

void check_floor () // Check if floor requested is different than current floor
{
  
    int floor_delta = old_floor - new_floor;
    printf("New Floor   : %d    Old floor   : %d    Floor_delta     : %d\n", new_floor, old_floor, floor_delta);


    
    switch(new_floor) 
    {
      case 1: 
        digitalWrite(27,HIGH);
        break;
      case 2:
        digitalWrite(28,HIGH);
      case 3: 
        digitalWrite(29,HIGH);
        break;
      default:
        delay(1);
     }

    //If the floors are different move either up and down and decrement/increment delta change the delay for the motor running based on actual measurements;
    while ( floor_delta < 0) 
    {
      move_down (7500);
      floor_delta++;
    }
    while( floor_delta > 0) 
    {
      move_up(7500);
      floor_delta--;
    }

    delay(5000);
    digitalWrite(27,LOW);
    digitalWrite(28,LOW);
    digitalWrite(29,LOW);

}



void setup() 
{
	//initialize wiringPi sequence
	wiringPiSetup();
	//Set directionality of GPIO port 0
	pinMode(23,PWM_OUTPUT); // Motor moving up
	pinMode(26,PWM_OUTPUT); // Motor moving down
  wiringPiISR(0,INT_EDGE_FALLING,&outside_first_floor); //pushbuttons for floor
  wiringPiISR(1,INT_EDGE_FALLING,&outside_second_floor);
  wiringPiISR(2,INT_EDGE_FALLING,&outside_third_floor);
  wiringPiISR(3,INT_EDGE_FALLING,&inside_first_floor);
  wiringPiISR(8,INT_EDGE_FALLING,&inside_second_floor);
  wiringPiISR(9,INT_EDGE_FALLING,&inside_third_floor);
  pinMode(27,OUTPUT);
  pinMode(28,OUTPUT);
  pinMode(29,OUTPUT);
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


void inside_second_floor ()
{
  old_floor= new_floor;
  new_floor = 2;
  check_floor();
}

void inside_third_floor ()
{
  old_floor= new_floor;
  new_floor = 3;
  check_floor();
}

void move_up  (int time_to_hold) 
{
    pwmWrite(23,1000);
    pwmWrite(26,0);
    delay(time_to_hold);
    pwmWrite(23,0);
}

void move_down  (int time_to_hold) 
{
    pwmWrite(23,0);
    pwmWrite(26,1000);
    delay(time_to_hold);
    pwmWrite(26,0);
}

void buzz () 
{
  delay(1);
}
