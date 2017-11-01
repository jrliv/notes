// Example program that writes to a file then reads and prints its data.
#include <stdio.h>

main()
{
    char input;
    FILE *file_pointer; // create pointer to file datatype

    printf("Enter information: \n\n");
    file_pointer = fopen("datafile.txt", "w");  // open file and write

    while ((input = getchar()) != EOF)  // write characters to file until EOF (EOF = Ctrl+d)
    {
        putc(input, file_pointer);        
    }
    fclose(file_pointer);   // close the file

    printf("Here is the information you entered: \n\n");
    file_pointer = fopen("datafile.txt", "r");  // open file and read

    while ((input = getc(file_pointer)) != EOF)  // read characters from file until EOF
    {
        printf("%c", input);    // print characters from file
    }
    fclose(file_pointer);
}