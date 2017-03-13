#include <stdio.h>
#include <string.h>

/** Exercise 4-12: Adapt the ideas of printd to write a recursive version of
	itoa; that is, convert an integer into a string by calling a recursive
	routine.
 */

void printd(int);
void itoa(int, char[]);
void reverse(char s[]);

int main(int argc, char argv[])
{
	char s[100];
	int input = 99;

	itoa(input, s);

	printf("%s\n", s);
	return 0;
}

/* printd: print n in decimal */
void printd(int n)
{
	if (n < 0) {
		putchar('-');
		n = -n;
	}
	if (n / 10)
		printd(n / 10);
	putchar(n % 10 + '0');
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
	int i, sign;

	if ((sign = n) < 0)	/* record sign */
		n = -n;		/* make n positive */
	i = 0;
	do {			/* generate digits in reverse order */
		s[i++] = n % 10 + '0';	/* get next digit */
	} while ((n /= 10 ) > 0);	/* delete it */
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
