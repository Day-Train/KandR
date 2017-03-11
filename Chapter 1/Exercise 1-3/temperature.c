#include <stdio.h>

/* Exercise 1-3: Modify the temperature conversion program to print a heading
	above the table.
 */

/* print Fahrenheit-Celsius table
	for fahr = 0, 20, ..., 300 */

int main(int argc, char *argv[])
{
	float fahr, celsius;
	int lower, upper, step;

	char *header_fahr = "Fahrenheit";
	char *header_cels = "Celsius";

	lower = 0;	/* lower limit of temperature table */
	upper = 300; 	/* upper limit */
	step = 20;	/* step size */

	fahr = lower;
	printf("%s\t %s\n", header_fahr, header_cels);
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr - 32.0);
		printf("%3.0f\t %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
	return 0;
}
