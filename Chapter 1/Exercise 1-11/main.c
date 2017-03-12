#include <stdio.h>

#define	IN	1	/* inside a word */
#define	OUT	0	/* outside a word */

/** Exercise 1-11: How would you test the word count program? What kinds of 
	input are most likely to uncover bugs if there are any?
 */

/**
	It's important to design a suite of tests that provide adequate
	coverage for all potential inputs. While it's infeasible to cover 
	every conceivable input there are a couple of things to keep in mind.

	1. Partition your input space - develop a set of test cases that provide
	sample coverage across your domain of inputs.
		Consider trivial cases (ex. "hello world"), they can be used
		as a yardstick to ensure expected behaviour

		Test empty or null sets. What behaviour do you expect with no
		input?

		Test 			

	2. Test special and boundary cases - develop a set of test cases that
	provide coverage for potential edge cases
		Test special or non-English Latin Alphabet characters

		Test escape characters in or alongside words
 */

/* count lines, words, and characters in input */
int main(int argc, char *argv[])
{
	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF ) {
		++nc:
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++nw;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);
	return 0;
}
