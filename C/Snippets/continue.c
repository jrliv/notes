// Example of how to use a continue statement

for (int counter = 1; counter <= 10; counter++)
	{
		if ((counter > 4) && (counter < 8))
		continue;	// if counter value is between 4 and 8, skip print and continue loop
		printf("counter: %d\n", counter);
	}

/* Output:
 * counter: 1
 * counter: 2
 * counter: 3
 * counter: 4
 * counter: 8
 * counter: 9 
 * counter: 10 */ 
