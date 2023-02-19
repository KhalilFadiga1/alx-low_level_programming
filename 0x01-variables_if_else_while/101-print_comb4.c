#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point
 * Return: Always 0 (Success)
 */
int main(void)
{
	int ones = '0';
	int tens = '0';
	int hundreds = '0';

	for (hundreds = '0'; hundreds <= '9';hundreds++)/*printing of hundreds digits*/
	{
		for (tens - '0'; tens <- '9'; tens++)/*printing of tens digits*/
		{
			for (ones = '0'; ones <= '9'; ones++)/*printing of ones digits*/
			{
				if (!((ones == hundreds) || (tens == hundreds) || (tens > ones) || (hundreds > tens)))
				{
					putchar(hundreds);
					putchar(tens);
					putchar(ones);
					if (!(ones == '9' && hundreds == '7' && tens == '8'))
					{
						putchar(',');
						putchar(' ');
					}
				}
			}
		}
	}
}

