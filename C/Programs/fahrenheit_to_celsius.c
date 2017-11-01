#include <stdio.h>

main ()
{
	int  fahrenheit, celsius;

	for (fahrenheit = 0; fahrenheit <= 100; fahrenheit = fahrenheit + 5)	// sets fahrenheit and loops through conversions
	{
		celsius = 5 * (fahrenheit - 32) / 9;	// converts fahrenheit to celsius
		printf("%d\t%d\n", fahrenheit, celsius);	// prints values of fahrenheit and celsius after conversions
	}
}

