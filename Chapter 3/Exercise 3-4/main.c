#include <stdio.h>
#include <string.h>

/** Exercise 3-4: In a two's complement number representation, our version of
	itoa does not handle the largest negative number, that is, the value of
	 n equal to -(2^(wordsize-1)). Explain why not. Modify it to print that
	 value correctly, regardless fo the machine on which it runs.
 */

#define MAXLINE	100

void iota(int, char[]);
void reverse(char[]);

int main(int argc, char *argv[])
{
	char s[MAXLINE];
	int n = -2147483647;
	itoa(n, s);

	printf("Program returned: %s\n", s);
	return 0;
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
	int i, sign;

	if ((sign = n) < 0)	/* record sign */
		n = -n;		/* make n positive */
	i = 0;
	do {				/* generate digits in reverse order */
		s[i++] = n % 10 + '0';	/* get next digit */
	} while ((n /= 10) > 0);	/* delete it */
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s) -1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
