#include <stdio.h>

/** Exercise 5-6: Rewrite appropriate programs from earlier chapters and 
	exercises with pointers instead of array indexing. Good possibilities
	include #getline, atoi, #itoa, and their variants, #reverse, strindex and
	 getop.
 */

/*
	TODO: itoa_pointer produces bugs during reverse_pointer subroutine. 
	Bug with one or both functions.
 */

int getline_pointer(char *, int);
void itoa_pointer(int, char *);
void reverse_pointer(char *);

int main(int argc, char argv[])
{
	int n = -243255;
	char str[8];

	itoa_pointer(n, str);

	printf("%s\n", str);
	return 0;
}

/* getline_pointer: read a line insto str, return length */
int getline_pointer(char *str, int lim)
{
	int i = 0;
	int c;
	char *s = str;
	while (*s++ = (c = getchar()) != EOF && c != '\n') {
		;
	}
	if (c == '\n') {
		*s++ = c;
	}
	*s = '\0';
	return (int) (s - str);
}

/* itoa_pointer: convert n to characters in s */
void itoa_pointer(int n, char *str)
{
        /* Pseudo-code */

        /*
          if (n is negative)
                record sign
                make n positive
          do
                take least significant digit and put in array
                increment array index by 1
          while
                dividing n by 10 to remove least significant digit
                dividing n by 10 > 0
          if (sign is negative)
                put negative sign in array
                increment array index by 1
          put null byte in array
         */
        int sign;
	char *s = str;

        if ((sign = n) < 0)     /* record sign */
                n = -n;         /* make n positive */
        do {                    /* generate digits in reverse order */
                *s++ = n % 10 + '0';  /* get next digit */
        } while ((n /= 10 ) > 0);       /* delete it */
        if (sign < 0)
                *s++ = '-';
        *s = '\0';
        reverse_pointer(str);
}

/* reverse_pointer: reverse string s in place */
void reverse_pointer(char *str)
{
	char *p = str;

	while (*p) {
		p++;
	}
	p--;
	
	for ( int temp ; str <= p; str++, p--) {
		temp = *str;
		*str = *p;
		str++;
		p--;
	}
}
