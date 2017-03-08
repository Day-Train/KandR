Exercise 4-2: Extend atof to handle scientific notation of the form

	123.45e-6

Where a floating-point number may be followed by e or E and an optionally
signed exponent.

This source file includes the function atof(). As a convenience a main method
 is included which reads command line arguments passed to it as a string and 
converts it to a double.

Example use:
	$./atof.out "123.45e-2"
