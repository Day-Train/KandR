#include <stdio.h>

#define IN      1       /* inside a word */
#define OUT     0       /* outside a word */
#define MAXWORDS	50 /* maximum number of words in input */

/** Exercise 1-13: Write a program to print a histogram of the lengths of words
	in its input. It is easy to draw the histogram with the bars
	horizontal; a vertical orientation is more challening.
 */

/* Pseudo-code */
/*
  instantiate int array word_array, it will hold the length of each word

  while (c = getchar()) 
	if (inside a word)
		++word_array[i]
	else
		++i;

  draw function
	while (MAXLENGTH > 0)
		for (i = 0, i < word_array.length; i++)
			if MAXLENGTH > word_array[i]
				print ' '
			else 
				print '#'
		MAXLENGTH--
		print newline
			 

  
 */

/* counts digits, white space, others */
int main(int argc, char argv[])
{
	int i, j, k, c, state;
	int max_length;		/* maximum length of a word */
	int word_array[MAXWORDS];
	for (j = 0; j < MAXWORDS; j++) {
		word_array[j] = 0;
	}

	k = 0;
	max_length = 20;
        state = OUT;
        while ((c = getchar()) != EOF) {
                if (c == ' ' || c == '\n' || c == '\t') {
                        state = OUT;
			k++;
                } else if (state == OUT) {
                        state = IN;
			++word_array[k];
                } else {
			++word_array[k];
                }
        }

	while (max_length > 0) {
		for (i = 0; i < MAXWORDS; i++) {
			if (max_length > word_array[i]) {
				printf(" ");
			} else {
				printf("#");
			}
		}
		--max_length;
		printf("\n");
	}
        return 0;
}
