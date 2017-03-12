#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/** Exercise 4-3: Add the modulus (%) operator and provisions for negative
        numbers

        TODO: Known issue where input ending on unary minus '-' erroneously
        returns 0.
 */

/** Exercise 4-4: Add commands to print the top element of the stack without
        popping, to duplicate it, and to swap the top two elements. Add a
        command to clear the stack.

        TODO: Need to actually test this...
 */

/** Exercise 4-5: Add access to library functions like sin, exp, and pow.
        See <math.h> in Appendix B, Section 4.

        Need ability to read in library functions from stdin and parse them as
         operators akin to the unary or binary operators like '+' or '-'.
        Examples below:

                $x sin
                >sin(x)

                $x sqrt
                >sqrt(x)

                $x n ldexp
                >x*2^n

        TODO: Need to implement the following operations
                floor()
                ldexp()
                frexp()
                modf()
                fmod()
 */

#define MAXOP		100
#define NUMBER 		'0'
#define SINE		1024
#define COSINE		1025
#define TANGENT		1026
#define ARCSINE		1027
#define ARCCOSINE	1028
#define ARCTANGENT	1029
#define ARCTANGENT2	1030
#define HYPERSINE	1031
#define HYPERCOSINE	1032
#define HYPERTANGENT	1033
#define EXPONENTIAL	1034
#define NATURALLOG	1035
#define LOG10		1036
#define POWER		1037
#define SQUAREROOT	1038
#define CEILING		1039
#define FLOOR		1040
#define FABSVAL		1041
#define LDEXP		1042
#define FREXP		1043
#define MODF		1044
#define FMOD		1045

int getop(char []);
void push(double);
double pop(void);
void print_element(void);
void duplicate_element(void);
void swap_elements(void);
void clear_stack(void);

double sin(double);
double cos(double);
double tan(double);
double asin(double);
double acos(double);
double atan(double);
double atan2(double, double);
double sinh(double);
double cosh(double);
double tanh(double);
double exp(double);
double log(double);
double log10(double);
double pow(double, double);
double sqrt(double);
double ceil(double);
//double floor(double);
double fabs(double);
//double ldexp(double, int);
//double frexp(double, int *exp);
//double modf(double, double *ip);
//double fmod(double, double);
int strcmp(const char *, const char *);

/* reverse Polish calculator */
int main(int argc, char *argv[])
{
	int type;
	double op2;
	int dividend;
	int modulus;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		if (type == NUMBER) {
			push(atof(s));
		} else if (type == '+') {
			push(pop() + pop());
		} else if (type == '*') {
			push(pop() * pop());
		} else if (type == '-') {
			op2 = pop();
			push(pop() - op2);
		} else if (type == '/') {
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else 
				printf("error: zero divisor\n");
		} else if (type == '%') {
			modulus = pop();
			dividend = pop();
			if (modulus != 0)
				push(dividend % modulus);
			else printf("error: zero modulus\n");
		} else if (type == SINE) {
			push(sin(pop()));
		} else if (type == COSINE) {
			push(cos(pop()));
		} else if (type == TANGENT) {
			push(tan(pop()));
		} else if (type == ARCSINE) {
			push(asin(pop()));
		} else if (type == ARCCOSINE) {
			push(acos(pop()));
		} else if (type == ARCTANGENT) {
			push(atan(pop()));
		} else if (type == ARCTANGENT2) {
			op2 = pop();
			push(atan2(op2, pop()));
		} else if (type == HYPERSINE) {
			push(sinh(pop()));
		} else if (type == HYPERCOSINE) {
			push(cosh(pop()));
		} else if (type == HYPERTANGENT) {
			push(tanh(pop()));
		} else if (type == EXPONENTIAL) {
			push(exp(pop()));
		} else if (type == NATURALLOG) {
			push(log(pop()));
		} else if (type == LOG10) {
			push(log10(pop()));
		} else if (type == POWER) {
			op2 = pop();
			push(pow(op2, pop()));
		} else if (type == SQUAREROOT) {
			push(sqrt(pop()));
		} else if (type == CEILING) {
			push(ceil(pop()));
		//} else if (type == FLOOR) {
		//	push(floor(pop()));
		} else if (type == FABSVAL) {
			push(fabs(pop()));
		//} else if (type == LDEXP) {
		//	op2 = pop();
		//	push(ldexp(op2, pop()));
		//} else if (type == FREXP) {
		//	op2 = pop();
		//	push(frexp(op2, pop()));
		//} else if (type == MODF) {
		//	op2 = pop();
		//	push(modf(op2, pop()));
		//} else if (type == FMOD) {
		//	op2 = pop();
		//	push(fmod(op2, pop()));
		} else if (type == '\n') {
			printf("\t%.8g\n", pop());
		} else {
			printf("error: unknown command %s\n", s);
		}
	}
	return 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

const char* sine = "sin";
const char* cosine = "cos";
const char* tangent = "tan";
const char* arcsin = "asin";
const char* arccos = "acos";
const char* arctan = "atan";
const char* arctan2 = "atan2";
const char* hypsine = "sinh";
const char* hypcos = "cosh";
const char* hyptan = "tanh";
const char* exponent = "exp";
const char* natlog = "log";
const char* logten = "log10";
const char* power = "pow";
const char* squareroot = "sqrt";
const char* ceiling = "ceil";
//const char* floor = "floor";
const char* fabsval = "fabs";
//const char* ldexp = "ldexp";
//const char* frexp = "frexp";
//const char* modf = "modf";
//const char* fmod = "fmod";
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
	if (!isdigit(c) && c != '.' && c != '-') { 	/* not a number */
		if (c == '+' || c == '*' || c == '/' || c == '%' || c == '\n')	{
			return c;	/* standard binary operators*/
		} else { 		/* parse for library function */
			i = 0;
			while (isalpha(s[++i] = c = getch())) {
			}
			s[i] = '\0';
			if (c != EOF) {
				ungetch(c);
			}
			
			if (strcmp(s, sine) == 0) {	 /* if string == sin return SINE */
				return SINE;
			} else if (strcmp(s, cosine) == 0) {
				return COSINE;
			} else if (strcmp(s, tangent) == 0) {
				return TANGENT;
			} else if (strcmp(s, arcsin) == 0) {
				return ARCSINE;
			} else if (strcmp(s, arccos) == 0) {
				return ARCCOSINE;
			} else if (strcmp(s, arctan) == 0) {
				return ARCTANGENT;
			} else if (strcmp(s, arctan2) == 0) {
				return ARCTANGENT2;
			} else if (strcmp(s, hypsine) == 0) {
				return HYPERSINE;
			} else if (strcmp(s, hypcos) == 0) {
				return HYPERCOSINE;
			} else if (strcmp(s, hyptan) == 0) {
				return HYPERTANGENT;
			} else if (strcmp(s, exponent) == 0) {
				return EXPONENTIAL;
			} else if (strcmp(s, power) == 0) {
				return POWER;
			} else if (strcmp(s, natlog) == 0) {
				return NATURALLOG;
			} else if (strcmp(s, logten) == 0) {
				return LOG10;
			} else if (strcmp(s, squareroot) == 0) {
				return SQUAREROOT;
			} else if (strcmp(s, ceiling) == 0) {
				return CEILING;
			//} else if (strcmp(s, floor) == 0) {
			//	return FLOOR;
			} else if (strcmp(s, fabsval) == 0) {
				return FABSVAL;
			//} else if (strcmp(s, ldexp) == 0) {
			//	return LDEXP;
			//} else if (strcmp(s, frexp) == 0) {
			//	return FREXP;
			//} else if (strcmp(s, modf) == 0) {
			//	return MODF;
			//} else if (strcmp(s, fmod) == 0) {
			//	return FMOD;
			}
		}
	}
	if (c == '-') {			/* deal with minus */
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
	if (c == '.') {			/* collect decimal part */
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

/* print top element of the stack to stdout */
void print_element(void)
{
	if (sp > 0)
		printf("%f\n", val[sp]);
	else {
		printf("error: stack empty\n");
	}
}

/* take top element of stack and duplicate it, pushing it onto stack */
void duplicate_element(void)
{
	if (sp < MAXVAL && sp > 0)
		val[sp++] = val[sp];
	else if (sp >= MAXVAL)
		printf("error: stack full can't push %g\n", val[sp]);
	else if (sp == 0)
		printf("error: stack empty\n");
}

/* swap top two elements of the stack */
void swap_elements(void)
{
	double temp = val[sp];
	val[sp] = val[sp--];
	val[sp] = temp;
}

/* clear the stack */
void clear_stack(void)
{
	while (sp > 0) {
		val[--sp] = 0.0;
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
