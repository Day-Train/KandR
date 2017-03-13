#include <stdio.h>

/** Exercise 5-3: Write a pointer version of the function strcat that we showed
	 in Chapter 2: strcat(s,t) copies the string to to the end of s.
 */

/*
	TODO: Compiler throws warning: assignment from incompatible pointer type
	on lines 22 & 23.
 */

void strcat_pointer(char *, char *);

int main(int argc, char argv[]) 
{
	char stringA[] = "Hello World";
	char stringB[] = "How are you today?";

	char *s;
	char *t;

	s = &stringA;
	t = &stringB;

	strcat_pointer(s, t);
	printf("%s\n", s);
	return 0;
}

/* strcat_pointer: concatenate t to end of s; s must be big enough */
void strcat_pointer(char *s, char *t)
{
	/* Pseudo-code */
	/*
	  find i where *s == '\0'
		while (*t != '\0')
			s[i++]  = *t++
	 */
	while (*s) {		/* go to null byte */
		++s;
	}
	while (*s++ = *t++) {	/* now at null byte, begin copy */
		;
	}
}