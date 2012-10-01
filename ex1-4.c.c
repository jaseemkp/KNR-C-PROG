#include <stdio.h>
/* celsius to farenhiet table */
main()
{
	float celsius, fahr;
	float lower, upper, step;

	lower = 0; /* lower limit of celsius */
	upper = 500; /* upper limit */
	step = 20; /* step size */
	
	printf("CELSIUS TO FARENHIET\n");

	celsius = lower;
	while (celsius <= upper) {
		fahr = (celsius * (9.0/5.0)) + 32.0;
		printf("%3.0f\t %6.2f\n", celsius, fahr);
		celsius = celsius + step;
		}
} 

 

