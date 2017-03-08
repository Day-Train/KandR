#include <stdio.h>

/* Write the function strrindex(s,t), which returns the position of the
rightmost occurrence of t in s, or -1 if there is none. */

int strrindex(char source[], char searchfor[]);

/* find rightmost index matching pattern */
int main(int argc, char *argv[])
{
	int index = -1;

	index = strrindex(argv[1], argv[2]);

	printf("We returned the value %d\n", index);
	return index;
}

/* strrindex: return rightmost index of t in s, -1 if none */
/* pseudo-code below:

	while (there are more characters in line) {
		if (line contains pattern)
			save the index
	}
	print index
*/
int strrindex(char s[], char t[])
{
	int i = 0;
	int j, k;
	int index = -1;

	while (s[i] != '\0') {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) {
		}
		if (k > 0 && t[k] == '\0') {
			index = i;
		}
		i++;
	}
	return index;
}

