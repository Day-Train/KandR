#include <stdio.h>
#include <string.h>

/** Exercise 4-13: Write a recursive version of the function reverse(s), which
	reverses the string s in place.
 */

void reverse(char[]);
void recursive_reverse(int, int, char[]);

int main(int argc, char argv[])
{
	char s[100] = "Hello World!";
	char t[100] = "Hello World!";
	reverse(s);

	int i = 0;
	int j = strlen(t) - 1;
	recursive_reverse(i, j, t);

	printf("reverse: %s\n", s);
	printf("recursive reverse: %s\n", t);
	return 0;
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
	/* Pseudo-code */
	/*
	  
	 */

        int c, i, j;

        for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
                c = s[i];
                s[i] = s[j];
                s[j] = c;
        }
}

/* recursive_reverse: recursively reverse string s in place */
void recursive_reverse(int i, int j, char s[])
{
	int c;

	c = s[i];
	s[i] = s[j];
	s[j] = c;
	i++;
	j--;

	if (i < j)
		recursive_reverse(i, j, s);
}
