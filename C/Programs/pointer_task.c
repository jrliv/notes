/* Task using pointers.

Create a program that:
1. Creates two integer variables, one a 'regular' variable called my_int and one a 'pointer' called my_pointer
2. Initialize the pointer to point to my_int
3. Set the variable pointed to by my_pointer to five (5) using the pointer
4. Print the value contained in my_int
5. Print the value pointed to by my_pointer
6. Increment the value in my_int by incrementing the value in the pointer
7. Print the value pointed to by my_pointer
8. Print the value contained in my_int */

#include <stdio.h>

main()
{
    int my_int;
    int *my_pointer = &my_int;
    
    *my_pointer = 5;
    
    printf("my_int = %d\n", my_int);
    printf("*my_pointer = %d\n", *my_pointer);

    *my_pointer += 1;

    printf("*my_pointer = %d\n", *my_pointer);
    printf("my_int = %d\n", my_int);

}