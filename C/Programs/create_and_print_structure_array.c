// Example program showing how to create and print a structure and array of the structure type
#include <stdio.h>

main()
{
    // define the student structure
    struct student
    {
        int id;
        char *name;
        char *address;
        char *class;
    };

    // define and populate the array of student type
    struct student stu_db[] = {
        [0] = {15648, "Brandon Johnson", "45 Blue Bird Lane", "Freshman"},
        [1] = {54896, "Emily Culbert", "1234 Walnut Street", "Senior"},
        [2] = {21487, "Gonzo Richardson", "728 Fieldsdale Road", "Junior"}
        };

    printf("Here are the current students in the database: \n\n");

    // for statement to loop through the array and print its elements
    for (int i = 0; i < 3; i++)
    {
        printf("ID: %d\t Name: %s\t Address: %s\t Class: %s\n", 
        stu_db[i].id, stu_db[i].name, stu_db[i].address, stu_db[i].class);
    }
}