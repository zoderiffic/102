#include <stdio.h>


void main () {
	int input_integer;
	printf("Enter integer value \n");
	input_integer = getchar();
	if (input_integer%2==0 ) {
	       printf("The integer is even\n");}

	else {
		printf("The integer is odd\n");
	}

}	

