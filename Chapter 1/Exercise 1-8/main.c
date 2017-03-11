#include <stdio.h>

/* Exercise 1-8: Write a program to count blanks, tabs, and newlines.
 */

int main(int argc, char *argv[])
{
	int c, blanks, tabs, newlines;

	blanks = 0;
	tabs = 0;
	newlines = 0;
	
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			++newlines;
		} else if (c == '\t') {
			++tabs;
		} else if (c == ' ') {
			++blanks;
		}
	}
	printf("There were %d blanks, %d tabs, and %d newlines", blanks, tabs, newlines);
	return 0;
}
