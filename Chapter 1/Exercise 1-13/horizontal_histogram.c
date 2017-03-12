#include <stdio.h>

#define IN      1       /* inside a word */
#define OUT     0       /* outside a word */

/** Exercise 1-13: Write a program to print a histogram of the lengths of words
	in its input. It is easy to draw the histogram with the bars
	horizontal; a vertical orientation is more challening.
 */

/* Pseudo-code */
/* 
  while (c = getchar()) 
	if (inside a word)
		increment word_length
	else
		print '#' word_length times
		word_length = 0
		print newline
 */

/* counts digits, white space, others */
int main(int argc, char argv[])
{
	int i, c, state, word_length;

	word_length = 0;
        state = OUT;
        while ((c = getchar()) != EOF) {
                if (c == ' ' || c == '\n' || c == '\t') {
                        state = OUT;
			if (word_length > 0) {
				for (i = 0; i < word_length; i++) {
					printf("#");
				}
			}
                        printf("\n");
			word_length = 0;
                } else if (state == OUT) {
                        state = IN;
                        ++word_length;
                } else {
                        ++word_length;
                }
        }
        return 0;
}
