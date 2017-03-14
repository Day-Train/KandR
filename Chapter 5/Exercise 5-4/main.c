#include <stdio.h>

/** Exercise 5-4: Write the function strend(s,t), which returns 1 if the string
	 t occurs at the end of string s, and zero otherwise.
 */

int strend(char *, char *);

int main(int argc, char argv[])
{
	char stringA[] = "Hello World";
        char stringB[] = "Hello World";

        char *s;
        char *t;

        s = &stringA;
        t = &stringB;

	printf("%d", strend(s, t));

	return 0;
}

int strend(char *s, char *t)
{
	/* Pseudo-code */
	/*
	 go to end of s, t
	 while ((*s-- == *t--) != 0)
		match = 0;
	 */

	while (*s != '\0') {
		s++;
	}
	while (*t != '\0') {
		t++;
	}
	int match = 1;
	while (match = (*t-- == *s--)) {
		;
	}
	return match;
}
