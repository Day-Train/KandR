#include <stdio.h>

/** Exercise 3-1: Our binary search makes two test in the loop, when one would 
	suffice. Write a version with only one test inside the loop and measure
	 the difference in runtime.
 */

int binsearch(int, int[], int);

int main(int argc, char *argv[])
{
	int x = 3;
	int v[] = {1,2,3,4,5,6,7,8,9,10};
	int n = 9;

        return binsearch(x, v, n);
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid]) {
			high = mid - 1;
		} else if (x > v[mid]) {
			low = mid + 1;
		} else {		/* found match */
			return mid;
		}
	}
	return -1; 			/* no match */
}
