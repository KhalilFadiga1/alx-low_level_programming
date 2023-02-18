#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point
 * Return - (0)
 */
int main(void)
{
	int ones = '0';
	int tens = '0';

	for (tens = '0';tens < '9'; tens++)/* printing of tens */
	{
		
		for (ones = '0';ones < '9'; one++)/* printing of ones */
		{
			if (!((ones == tens) || (tens > ones)))/* remove repetition */
			{
				putchar(tens);
				putchar(ones);
				if (!(ones == '9' && tens == '8'))
				{
					putchar(',');
					putchar(' ');
				}
			}	
		}
	}
	putchar('\n');
	return (0);
}	
