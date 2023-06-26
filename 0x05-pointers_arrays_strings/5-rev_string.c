#include "main.h"

/**
 * rev_string - function that reverses a string
 * @s: string to be reversed
 */
void rev_string(char *s)
{
	char rev = s[0];
	int longi = 0;
	int x;

	while (s[longi] != '\0')
	{
		longi++;
	}
	for (x = 0; x < longi; longi++)
	{
		longi--;
		rev = s[x];
		s[x] = s[longi];
		s[longi] = rev;
	}
}
