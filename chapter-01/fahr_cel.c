#include <stdio.h>
/* print Farenheit-Celsius table
	for fahr = 0, 20, ..., 300 */
main()
{
	int fahr, celsius;
	int lower, upper, step;
	
	lower = 0; /* lower limit of temp scale*/
	upper = 300; /* upper limt */
	step = 20; /* step size */

	fahr = lower;
	while(fahr <= upper) {
		celsius = 5 * (fahr-32) / 9;
		printf("%3d\t%6d\n", fahr, celsius);
		fahr = fahr + step;
	}
}
