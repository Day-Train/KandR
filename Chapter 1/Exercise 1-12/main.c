#include <stdio.h>

#define IN	1	/* inside a word */
#define OUT	0	/* outside a word */

/** Exercise 1-12: Write a program that prints its input one word per line
 */

/* count lines, words, and characters in input */
int main(int argc, char *argv[])
{
	int c, state;

	state = OUT;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
			printf("\n");
		} else if (state == OUT) {
			state = IN;
			putchar(c);
		} else {
			putchar(c);
		}
	}
	return 0;
}
