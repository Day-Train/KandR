#include <stdio.h>
#include <string.h>

/** Exercise 3-2: Write a function escape(s,t) that converts characters like 
	newline and tab into visible escape sequences like \n and \t as it 
	copies the string to to s. Use a switch. Write a function for the other
	 direction as well, converting escape sequences into the real 
	characters.
 */

void escape(char s[], char t[]);
void real_escape(char s[], char t[]);

int main(int argc, char *argv[])
{
	int i;
	char s[] = "Hello World \t How are you? \n";
	char t[strlen(s)];

	escape(s, t);
	for (i = 0; i < strlen(t); i++) {
		printf("%c", t[i]);
	}

	real_escape(t, s);
	for (i = 0; i < strlen(s); i++) {
		printf("%c", s[i]);
	}
	return 0;
}

void escape(char s[], char t[])
{
	/* Pseudo-code */
	/* for (each character in s)
		switch (char)
			case (escape char)
				convert and copy to t[]
			default
				copy to t[]
	 */
	int i;
	int s_length = strlen(s);
	int t_length = strlen(t);

	for (i = 0; i < s_length; i++) {
		switch (s[i]) {
		case '\n':
			t[i] = '\\';
			t[++i] = 'n';
			break;
		case '\t':
			t[i] = '\\';
			t[++i] = 't';
			break;
		default:
			t[i] = s[i];
			break;
		}
	}
}

void real_escape(char s[], char t[])
{
	/* Pseudo-code */
	/* for (each character in s)
		switch (char)
			case (back slash)
				switch (++i char)
					case (n)
						copy newline to t[]
					case (t)
						copy tab to t[]
				default
					copy literal backslash
			default
				copy to t[]
	 */
	int i = 0;
	int j = 0;
	int s_length = strlen(s);
	int t_length = strlen(t);

	for (i = 0; i < s_length; i++) {
		switch (s[i]) {
		case '\\':
			switch (s[++i]) {
			case 'n':
				t[j] = '\n';
				j++;
				i++;
				break;
			case 't':
				t[j] = '\t';
				j++;
				i++;
				break;
			default:
				t[j] = '\\';
				j++;
				break;
			}
		default:
			t[i] = s[i];
			j++;
			break;
		}
	}	
}
