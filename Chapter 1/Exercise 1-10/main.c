#include <stdio.h>

/** Exercise 1-9: Write a program to copy its input to its output, replacing 
	each tab by \t, each backspace by \b, and each backslash by \\. This
	makes tabs and backspaces visible in an unambiguous way.
 */
int main(int argc, char *argv[])
{
	/* Pseudo-code */
	/* while (getchar != EOF)
		if (char == escape character)
			putchar escape literal
		else
			putchar original char
	 */

	int c;

	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			putchar('\\');
			putchar('t');
		} else if (c == '\b') {
			putchar('\\');
			putchar('b');
		} else if (c == '\\') {
			putchar('\\');
			putchar('\\');
		} else {
			putchar(c);
		}
	}
		
	return 0;
}

void recursive_checker(void)
{

}
