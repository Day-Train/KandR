#include <stdio.h>

/* Exercise 1-6: Verify that the expression getchar() != EOF is 0 or 1.
 */

/* copy input to output; 1st version */
int main(int argc, char *argv[])
{
	int c;
	int boolean;

	while (boolean = ((c = getchar()) != EOF)) {
		putchar(c);
		printf("%d", boolean);
	}
	return 0;
}
