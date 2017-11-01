/* ======================================================================

NAME: arraywork.c

AUTHOR: Jack Reynolds
DATE  : 9/3/2010

COMMENT: 	1. Create and initialize two int arrays, old_array and new_array
			2. Initialize old_array to the values 1,2,3,4,5,6,7,8,9
			3. Initialize new_array to the values 22,17,43,86,7,33,4,65,90,0
			4. Print the arrays (pass the arrays to a function)
			5. Average the values in old_array (use a function)
			6. Sum the values in new_array (use a function)
			7. Find the largest value in new_array and print its position in the array
			8. Swap the values from old_array into new_array (use a function)
			9. Print old_array and new_array (pass the arrays to a function to confirm)
			
			
			Question: Why can't I find the size of the array within the function itself?

====================================================================== */

#include <stdio.h>


/* declare our functions */
void print_array (int array_to_print[], int array_size);
int average_array (int array_to_average[], int array_size);
int sum_array (int array_to_sum[], int array_size);
int find_largest (int array_to_examine[], int array_size);
void swap_values (int array_one[], int array_two[], int array_size);

main()
{

/* create and initialize our arrays and our size_of_array variable */
	int old_array[] = {0,1,2,3,4,5,6,7,8,9};
	int new_array[] = {22,17,43,86,7,33,4,65,90,0};
	int size_of_array;

/* determine the size of old_array and pass it to the print_array function */
	printf ("\nThe values of the array old_array are\n");
	size_of_array = (sizeof(old_array) / sizeof(int));
	print_array(old_array, size_of_array);

/* determine the size of new_array and pass it to the print_array function */
	printf ("\nThe values of the array new_array are\n");
	size_of_array = (sizeof(new_array) / sizeof(int));
	print_array(new_array, size_of_array);

/* determine the size of new_array and pass it to the average_array function */
	printf ("\nDetermining the average of old_array\n");
	size_of_array = (sizeof(new_array) / sizeof(int));
	average_array (old_array, size_of_array);

/* determine the size of new_array and pass it to the sum_array function */
	printf ("\nDetermining the sum of new_array\n");
	size_of_array = (sizeof(new_array) / sizeof(int));
	sum_array (new_array, size_of_array);

/* determine the size of old_array and pass it to the find_largest function */
	printf ("\nDetermining the largest element in new_array\n");
	size_of_array = (sizeof(new_array) / sizeof(int));
	find_largest (new_array, size_of_array);

/* determine the size of new_array and pass it to the swap_values function */
	printf ("\nFlipping values in the arrays\n");
	size_of_array = (sizeof(new_array) / sizeof(int));
	swap_values (new_array, old_array, size_of_array);

/* determine the size of old_array and pass it to the print_array function */
	printf ("\nThe values of the array old_array are\n");
	size_of_array = (sizeof(old_array) / sizeof(int));
	print_array(old_array, size_of_array);

/* determine the size of new_array and pass it to the print_array function */
	printf ("\nThe values of the array new_array are\n");
	size_of_array = (sizeof(new_array) / sizeof(int));
	print_array(new_array, size_of_array);
	

}

/* create our functions*/
void print_array(int array_to_print[], int array_size)
{
	int counter;
	for (counter = 0; counter <= (array_size - 1); counter++)
	printf ("The value of the %d th element of the array is %d \n", counter, array_to_print[counter]);
}

int average_array(int array_to_average[], int array_size)
{
	int counter, average, sum;
	sum = 0;
	for (counter = 0; counter <= (array_size - 1); counter++)
	sum = sum + array_to_average[counter];
	average = sum / (array_size);
	printf ("The average the array is %d \n\n", average );
}

int sum_array(int array_to_sum[], int array_size)
{
	int counter, sum;
	sum = 0;
	for (counter = 0; counter <= (array_size - 1); counter++)
	sum = sum + array_to_sum[counter];
	printf ("The sum the array is %d \n\n", sum );
}

int find_largest(int array_to_examine[], int array_size)
{
	int counter, largest, position;
	largest = 0;
	position = 0;
	for (counter = 0; counter <= (array_size - 1); counter++)
	if (array_to_examine[counter] > largest) 
		{largest = array_to_examine[counter];
			position = counter;
		}
	printf ("The largest element in the array is %d and its position is %d\n\n", largest, position );
}

void swap_values(int array_one[], int array_two[], int array_size)
{
	int temp_array[10];	
	int counter;
/* populate temp_array with values from array_one */
	for (counter = 0; counter <= (array_size - 1); counter++)
		{temp_array[counter] = array_one[counter];
			array_one[counter] = array_two[counter];
			array_two[counter] = temp_array[counter];
		}
}
	
	



