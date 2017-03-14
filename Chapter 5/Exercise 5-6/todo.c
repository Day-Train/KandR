/**
	TODO: Old Versions
 */
/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
	/* Pseudo-code */
	/*
	  for (i; i < buffersize && you don't return (EOF || '\n'); i++)
		read character into s 
	  if (return a '\n')
		insert newline
		increment array
	  insert null byte
	  return array size
	 */
       int c, i;

       for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
                s[i] = c;
        }
        if (c == '\n') {
                s[i] = c;
                ++i;
        }
        s[i] = '\0';
        return i;
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
        /* Pseudo-code */

        /*
          if (n is negative)
                record sign
                make n positive
          do
                take least significant digit and put in array
                increment array index by 1
          while
                dividing n by 10 to remove least significant digit
                dividing n by 10 > 0
          if (sign is negative)
                put negative sign in array
                increment array index by 1
          put null byte in array
         */
        int i, sign;

        if ((sign = n) < 0)     /* record sign */
                n = -n;         /* make n positive */
        i = 0;
        do {                    /* generate digits in reverse order */
                s[i++] = n % 10 + '0';  /* get next digit */
        } while ((n /= 10 ) > 0);       /* delete it */
        if (sign < 0)
                s[i++] = '-';
        s[i] = '\0';
        reverse(s);
}

/* recursive_itoa: convert n to characters in s */
void recursive_itoa(int n, int i, int sign, char s[])
{
        /* Pseudo-code */

        /*
          if (n is negative)
                record sign
                make n positive
          if (n > 0)
                take least significant digit and put in array
                divide n by 10 to remove least significant digit
                increment array index by 1
                call this function again, passing index and n
          else if (n == 0)
                put sign in array
                put null byte in array
         */

        if (sign == 0) {                        /* sign unset flag */
                if ((sign = n) < 0) {           /* records sign on first pass only */
                        n = -n;                 /* make n positive */
                }
        }
        if (n > 0) {                            /* generates digits in reverse order */
                s[i++] = n % 10 + '0';          /* get next digit */
                n /= 10;                        /* delete it */
                recursive_itoa(n, i, sign, s);  /* recursively call function */
        } else if (n == 0) {                    /* all digits stored */
                if (sign < 0) {
                        s[i++] = '-';           /* record sign */
                }
                s[i++] = '\0';                  /* include null byte */
                reverse(s);
        }
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
        int c, i, j;

        for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
                c = s[i];
                s[i] = s[j];
                s[j] = c;
        }
}
