// Example of using scanf to work with input
#include <stdio.h>

main()
{
	char first[20], last[20];

	printf("Enter your first and last name:\n");
	scanf("%s %s", first, last);	// gets input from the user
	printf("Hello %s %s\n", first, last);	// prints the full name from the user
}
