//EMil Crestian 17 Sep 2018; Push button 
#include <stdio.h>
#include <wiringPi.h>

int bounce;
int two_sec_delay = 500;
void setup();
void toggle_led();
void i_sr();

void main () 
{
	setup(); 	// Initialize setup sequence
	int num_blinks, i; // Declare variables to be used in the main program;
	while (1) 
	{
   for(i=0; ; i++) 
   { 
    delay(1000);
    printf ("%d\n", i);    
		if(bounce > 0) 
    {
      printf("Button bounced %d times\n",bounce);
      bounce = 0;
	  }
   }
  }
	

}


void setup() 
{
	//initialize wiringPi sequence
	wiringPiSetup();
  wiringPiISR(4,INT_EDGE_FALLING,&i_sr);
	//Set directionality of GPIO port 0
	pinMode(4,INPUT);
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


void i_sr ()
{
  bounce++;
}

  
