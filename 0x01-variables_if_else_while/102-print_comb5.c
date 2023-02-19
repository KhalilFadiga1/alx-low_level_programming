#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry Point
 * Result: 0 (Success)
 */
int main(void)
{
	int th = '0';
	int hund = '0';
	int tens = '0';
	int ones = '0';

	for (th = '0'; th <= '9';th++)/*printing of thousands digits */
	{
		for (hund = '0';hund <= '9';hund++)/*printing of hundreds digits */
		{
			for (tens = '0';tens <= '9';tens++)/*printing of tens digits*/
			{
				for (ones = '0'; ones < '9'; ones++)/* printing of ones digits */
				{
					if (!((th == hund) || (hund == tens) || (tens == ones) || (th > hund) || (hund > tens) || (tens > ones)))
					{
						putchar(th);
						putchar(hund);
						putchar(' ');
						putchar(tens);
						putchar(ones);
						if (!(ones == '9' && tens == '8' && hund == '7' && th == '6'))
						{
							putchar(',');
							putchar(' ');
						}
					}
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
