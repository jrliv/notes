// Example of how to use a few different string functions.
#include <stdio.h>
#include <string.h>

main ()
{
    char strOne[] = {"Here is a string."};
    char strTwo[17];
    
    strcpy(strTwo, strOne); // copies strOne into strTwo

    if (!strcmp(strOne, strTwo))    // strcmp() compares strOne and strTwo
    {
        printf("The strings are equal.\n");
    }
    else
    {
        printf("The strings are different.\n");
    }

    char strThree[] = {"I like "};
    char strFour[] = {"C programming."};

    printf("%s\n", strcat(strThree, strFour));  // strcat() concatenates strThree and strFour
}