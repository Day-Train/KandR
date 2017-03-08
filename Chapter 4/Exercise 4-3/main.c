#include <stdio.h>
#include <stdlib.h>

#define MAXOP	100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);

/* Exercise 4-3: Add the modulus (%) operator and provisions for negative
	numbers

	TODO: Known issue where input ending on unary minus '-' erroneously
	returns 0.
 */

/* reverse Polish calculator */
int main(int argc, char *argv[])
{
	int type;
	double op2;
	int dividend;
	int modulus;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '%':
			modulus = pop();
			dividend = pop();
			if (modulus != 0)
				push(dividend % modulus);
			else
				printf("error: zero modulus\n");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
/* Binary minus operator will be followed by whitespace unary minus operator 
	will be followed by a digit or period.
	 */
int getop(char s[])
{
	int i, c, d;
	
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.' && c != '-') {
		return c;	/* not a number */
	}
	if (c == '-') {		/* deal with minus */
		d = getch();
		if (d == ' ') {		/* unary minus */
			return c;
		} else if (d == EOF) {
			ungetch(d);
			return c;
		} else {
			ungetch(d);
		}
	}
	i = 0;
	if (isdigit(c) || c == '-') {	/* collect integer part */
		while (isdigit(s[++i] = c = getch()))
		;
	}
	if (c == '.') {		/* collect decimal part */
		while (isdigit(s[++i] = c = getch()))
		;
	}
	s[i] = '\0';
	if (c != EOF) {
		ungetch(c);
	}
	return NUMBER;
}

#define MAXVAL  100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
        if (sp < MAXVAL)
                val[sp++] = f;
        else
                printf("error: stack full can't push %g\n", f);
}

double pop(void)
{
        if (sp > 0)
                return val[--sp];
        else {
                printf("error: stack empty\n");
                return 0.0;
        }
}

#define BUFSIZE	100

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
