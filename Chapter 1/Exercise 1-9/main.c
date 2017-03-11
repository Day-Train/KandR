#include <stdio.h>

/** Exercise 1-9: Write a program to copy its input to its output, replacing
	each string of one or more blanks by a single blank.
 */

int main(int argc, char *argv[])
{
	/* Pseudo-code */
	/* while (getchar != EOF)
		if (char == multiple blanks)
			putchar single blank
		else
			putchar original char
	 */

	int c;
	int blank = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			++blank;
			if (blank < 2)
				putchar(c);
		} else {
			blank = 0;
			putchar(c);
		}
	}
		
	return 0;
}

void recursive_checker(void)
{

}
