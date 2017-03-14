#include <stdio.h>

/** Exercise 5-5: Write versions of the library functions strncpy, strncat, and
	 strncmp, which operate on at most the first n characters of their 
	argument strings. For example, strncpy(s,t,n) copies at most n 
	characters of to to s.
 */

/*
	TODO: Bug - strncmp behavior not entirely expected. Need better
	tests and documentable expected outcomes.
 */

void my_strncat(char *, char *, int);
void my_strncpy(char *, char *, int);
int my_strncmp(char *, char *, int);

int main(int argc, char argv[])
{
	char s[100] = "Hello World";
        char t[100] = "Hello Wa";

	int n = 8;

	printf("%d", my_strncmp(s, t, n));
	return 0;
}

/* strncmp: return an integer greater than, equal to, or less than zero as the
	first n characters are lexically greater than, equal to, or less than 
	the first n characters of s */
int my_strncmp(char *s, char *t, int n)
{
	int i = 0;
	while (i++ < n && (*s++ == *t++)) {
		;
	}
	return *t - *s;
}

/* strncpy: copy at most first n characters of t into s; s must be big enough
	 */
void my_strncpy(char *s, char *t, int n)
{
	int i = 0;
	while (i++ < n && (*s++ = *t++)) {
		;
	}
}

/* strncat: concatenate at most first n characters of t to end of s; s must be 
	big enough */
void my_strncat(char *s, char *t, int n)
{
	int i = 0;
        while (*s) {            /* go to null byte */
                ++s;
        }
	while (i++ < n && (*s++ = *t++)) {
		;
	}
}
