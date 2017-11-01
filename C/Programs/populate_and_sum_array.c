// Example program of how to populate, print, and sum an array
#include <stdio.h>

int array[5];

main()
{
    int j = 1;
    int sum = 0;
    
    for (int i = 0; i < 5; i++)
    {
        array[i] = j * 10;  // populate array elements by 10
        printf("Index %d: %d\n", i, array[i]);  // print array 
        j++;
    }

    for (int k = 0; k < 5; k++)
    {
        sum +=array[k]; // add values of array elements to get their sum
    }

    printf("\n");
    printf("The sum of all elements in array is: %d\n", sum);
}