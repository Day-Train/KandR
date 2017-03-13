#include <ctype.h>
#include <stdio.h>

/** Exercise 5-1: As written, getint treats a + or - not followed by a digit as
        a valid representation of zero. Fix it to push such a character back on the input.
 */

int getch(void);
void ungetch(int);
int getint(int *);
int getint2(int *);

int main(int argc, char argv[])
{
	int x = 0;
	int *ip;
	ip = &x;
	getint(ip);
	printf("%d\n", *ip);
	return 0;
}

/* getint2: get next integer from input into *pn */
int getint2(int *pn)
{
        /* Pseudo-code */
        /*
          while (there's white space)
                skip ahead
          if (character is not a digit, +/- sign or EOF indicator)
                return from routine
          is c == '-'?
                if yes sign = -1
                if no sign = 1
          if (c is a +/- sign)
                be on the lookout for digits, get the next character
		if next character != digit unget
          for (pointer with initial value 0; getch() returns a digit; get another digit)
                pointer *= 10 pointer + c
          pointer * sign to preserve +/-
          return
         */

        int c, sign;
        while (isspace(c = getch())) /* skip white space */
                ;
        if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
                ungetch(c);     /* it's not a number */
                return 0;
        }
        sign = (c == '-') ? -1 : 1;
        if (c == '+' || c == '-')
                c = getch();
		if (!isdigit(c)) {
			ungetch(sign == 1 ? '+' : '-');
			return 0;
		}
        for (*pn = 0; isdigit(c); c = getch())
                *pn = 10 * *pn + (c - '0');
        *pn *= sign;
        if (c != EOF)
                ungetch(c);
        return c;
}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
	/* Pseudo-code */
	/*
	  while (there's white space)
		skip ahead
	  if (character is not a digit, +/- sign or EOF indicator)
		return from routine
	  is c == '-'?
		if yes sign = -1
		if no sign = 1
	  if (c is a +/- sign)
		be on the lookout for digits, get the next character
	  for (pointer with initial value 0; getch() returns a digit; get another digit)
		pointer *= 10 pointer + c
	  pointer * sign to preserve +/-
	  return
	 */
	
	int c, sign;

	while (isspace(c = getch())) /* skip white space */
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);	/* it's not a number */
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
        return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
        if (bufp >= BUFSIZE)
                printf("ungetch: too many characters\n");
        else
                buf[bufp++] = c;
}
