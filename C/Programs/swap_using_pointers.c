// Example of using pointers to swap values
#include <stdio.h>

main()
{
    int numOne = 50;
    int numTwo = 100;

    printf("Before:\n");
    printf("numOne = %d\n", numOne);
    printf("numTwo = %d\n", numTwo);
    printf("\n");

    swap(&numOne, &numTwo); // unary operator (&) for the arguments point to their location in memory

    printf("After:\n");
    printf("numOne = %d\n", numOne);
    printf("numTwo = %d\n", numTwo);
}

int swap(int *x, int *y)
{
    int temp = *x;  // temporarily store a value to swap
    *x = *y;
    *y = temp;
}