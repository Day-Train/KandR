#include <stdio.h>

/** Exercise 1-14: Write a program to print a historgram of the frequencies 
	of different characters in its input.
 */

/* Pseudo-code */
/*
  instantiate character_array where each index corresponds to A-Za-z0-9\t\n...
  character

  while (c = getchar())
	if (c == 'a')
		character_array[i]++
	else if (c == 'b')
		character_array[j]++
	etc...

  draw function
  for each element in character_array
	print character 
	print '#' a[i] times
 */

/* character map */
/* abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ' ' '\n' '\t' */

int main(int argc, char argv[])
{
	int i, c, characters, state;
	characters = 3;
	int character_array[characters];

	for (i = 0; i < characters; i++) {
		character_array[characters] = 0;
	} 

        while ((c = getchar()) != EOF) {
                if (c == 'a') {
			character_array[0]++;
		} else if (c == 'b') {
			character_array[1]++;
                } else if (c == 'c') {
			character_array[2]++;
                }
        }

	for (i = 0; i < characters; i++) {
		printf("c\t");
		while (character_array[i] > 0) {
			printf("#");
			--character_array[i];
		}
		printf("\n");
	}
	return 0;
}
