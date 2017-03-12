#include <stdio.h>

/** Exercise 1-4: Write a program to print the corresponding Celsius to
	Fahrenheit table.
 */

/* print Fahrenheit-Celsius table
	for fahr = 0, 20, ..., 300 */

int main(int argc, char *argv[])
{
	float fahr, celsius;
	int lower, upper, step;

	lower = -20;	/* lower limit of temperature table */
	upper = 300; 	/* upper limit */
	step = 20;	/* step size */

	celsius = lower;
	while (celsius <= upper) {
		fahr = (9.0/5.0) * celsius + 32.0;
		printf("%6.1f %3.0f\n", celsius, fahr);
		celsius = celsius + step;
	}
	return 0;
}
