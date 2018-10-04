//ENGR 102 Sherry Abbasi LED on Program
#include <stdio.h>
#include <wiringPi.h>
int main()
{
wiringPiSetup(); //sets up the GPIO pins based on wiringPi chart
pinMode(0, OUTPUT); //defines GPIO 0 (pin11) as an output
digitalWrite(0, HIGH); //sets the value of GPIO 0 (pin11) at logic 1 (3.3 V)
delay(5000); //creates a delay of 5000 ms
digitalWrite(0, LOW); //sets the value of GPIO 0 (pin11) at logic 0 (0 V)
}
