#include <stdio.h>

/** Exercise 3-1: Wrte a version with only one test inside the loop and measure
	the difference in run-time.
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
	while (low < high) {
		mid = (low + high) / 2;
		if (x <= v[mid]) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}

	return (x == v[low]) ? low : -1;
}
