Exercise 4-1: Write a function strrindex(s,t), which returns the position of
the rightmost occurrence of t in s, or -1 if there is none.

This source file includes a single source file with the function strrindex
satisfying the above prompt. As a convenience a main method is included which
reads command line arguments passed to it for the line to search and pattern
to search for. Note that this source file omits the getline() function 
described in K&R in favor of passing command line arguments.

Example use:
	$./strrindex.out "This is the string to search" "Pattern to search for"
