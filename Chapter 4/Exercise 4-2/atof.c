#include <ctype.h>
#include <stdio.h>

/** Exercise 4-2: Extend atof to handle scientific notation of the form:
        123.45e-6
*/

double atof(char source[]);

/* pass as command line argument string to be returned */
void main(int argc, char *argv[])
{
	double sum;
	sum = atof(argv[1]);
	printf("You entered the value %f\n", sum);

}

/* atof: convert string s to double */
double atof(char s[])
{
	double val, power;
	int i, sign, exponent;

	for (i = 0; isspace(s[i]); i++) {
	}
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-') {
		i++;
	}
	for (val = 0.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
	}
	if (s[i] == '.') {
		i++;
	}
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	if (s[i] == 'e' || s[i] == 'E') {
		i++;
	}
	if (s[i] == '-') {
		i++;
		for (exponent = 0.0; isdigit(s[i]); i++) {
			exponent = 10.0 * exponent + (s[i] - '0');
		}
		for (int j = 1; j <= exponent; j++) {
			power *= 10.0;
		}
	}
	if (s[i] == '+') {
		i++;
		for (exponent = 0.0; isdigit(s[i]); i++) {
                        exponent = 10.0 * exponent + (s[i] - '0');
                }
                for (int j = 1; j <= exponent; j++) {
                        power /= 10.0;
                }
	} else {
		for (exponent = 0.0; isdigit(s[i]); i++) {
                        exponent = 10.0 * exponent + (s[i] - '0');
                }
                for (int j = 1; j <= exponent; j++) {
                        power /= 10.0;
                }
	}
	
	return sign * val / power;
}
