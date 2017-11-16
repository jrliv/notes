# C Notes

## Contents

* [Compilation](#compilation)
* [Libraries](#common-libraries)
* [Printing output](#printing-output)
* [Getting input](#getting-input)
* [Pointers](#pointers)
* [Arrays](#arrays)
* [Strings](#strings)
* [Working with files](#working-with-files)
* [Structures](#structures)

## Compilation

### How to compile and execute using GNU Compiler Collection (gcc)

	Basic compile: gcc programsource.c -o executable.out

	Execute the program: executable.out

### How to compile on Windows using Developer Command Prompt

Open Developer Command Prompt for Visual Studio and cd to the directory containing the source file. 

Enter <b>cl programsource.c</b>

You can use <b>/out:executable.exe</b> to name the executable file. Otherwise the file name will be the same as the source file.

## Common libraries

<ul>
	<li>stdio.h: I/O functions</li>
	<li>string.h: String functions</li>
	<li>ctype.h: Character functions</li>
	<li>math.h: Mathematics functions</li>
	<li>time.h: Time and Date functions</li>
	<li>stdlib.h: Miscellaneous functions</li>
	<li>stdbool.h: Boolean types and functions</li>
</ul>

## Printing output

printf() is a C library general-purpose function that sends formatted output. The first argument is usually a string of characters that begin with % to indicate what type of output will be printed from the second argument.

Example:

	printf("Hello World!\n");
	printf("%d\t%s\n", int_var, str_var);

Here are a few different formats for data types used:

<ul>
	<li>%d - Prints decimal integer.</li>
	<li>%6d	- Prints decimal integer of 6 chars.</li>
	<li>%f - Prints floating point.</li>
	<li>%4.2f - Prints floating point of 4 chars and 2 after decimal.</li>
	<li>%c - Prints character.</li>
	<li>%s - Prints string.</li>
	<li>%p - Pointer.</li>
	<li>%o - Octal.</li>
	<li>%x - Hexadecimal.</li>
</ul>

### Escape sequences

<ul>
	<li>Newline character: \n</li>
	<li>Tab character: \t</li>
	<li>Backspace character: \b</li>
	<li>Double-quote character: \"</li>
	<li>Backlash character: \\</li>
</ul>

### How to print a random number

To print a random number, use the <b>srand()</b> and <b>time()</b> methods to create a seed. Then assign the random value from the <b>rand()</b> method to a variable like below:

	srand(time(NULL));
    int number_to_guess = rand() % 100 + 1;	// generates a random number between 1 and 100

### How to get any type of input from a user

Store the input in a char array. Example:

	char user_input[10];
    printf("Enter your input:\n");
    scanf("%c", &user_input);

This will allow the user to enter any kind of input necessary (letters, numbers, or special chars) as long as it's not over 10 characters.

## Getting input

### scanf()

scanf() is a C library function that allows a program to get data from the user. Like printf() it has a set of arguments for formatting and a second set for the values. The second group of arguments for scanf often include an ampersand symbol because they refer to pointers and not an actual location.

Example:

	scanf("%s", input_str);

### getchar()

getchar() is another C stdio library function that reads a single character from stdin (standard input).

getchar() has no parameters and its sole function is to read the next character as an unsigned char and return its value converted to an integer.

### gets() and puts()

The gets() and puts() functions are two other options that can be used for working with input and output.

*Note: I tried used these once and couldn't get them to work. Maybe I was doing something wrong. Will update if I learn anything new about these functions.

## Pointers

A pointer is a variable that "points" to the memory address of another variable. It's value is the address to the other variable. Pointers are defined like a normal variable except the ampersand symbol * is added before the pointers name like:

	int *pointer_var = 5;	// Note: this won't compile it needs a cast

The statement above means the value that is in the memory address pointed to by <b>pointer_var</b> is equal to 5.

If you tried to change the value with the statement:

	int pointer_var = 10;

It would not make sense. The statement would mean that the memory address for <b>pointer_var</b> is 10.

<b>&</b> references the address of the value (means "the address of")
<b>*</b> references the value stored in the address (means "the value pointed by")

### Example

Initialize a pointer with another variable's memory address

	int intVar = 25;
	int *ptrVar;

	ptrVar = &intVar;	// ptrVar now points to same memory location of intVar which contains 25

	*ptrVar = intVar;	// passing the value 25 from intVar to ptrVar
	
	*ptrVar = 50;	// changing ptrVar value to 50

	// ptr = 100;  doesn't work; like trying to set the memory address to 100

For those two variables <b>intVar</b> is the value while <b>&intVar</b> is the memory address of the value. <b>*ptrVar</b> is the value while <b>ptrVar</b> is the memory address of the value.

### Dereferencing pointers

One important component of using pointers with structures is the concept of ‘de-referencing’ a pointer.

To ‘de-reference’ we need to ensure we return a value, not the memory address. Use the * de-reference operator to act on the value

	*pointer = 25

The <b>&</b> operator is the reference operator (remember "address of") while <b>*</b> is the dereference operator (remember "value pointed to by").

## Arrays

### How to create an array

	int arrayOne[4];	// create array with 4 elements

	int arrayTwo[] = {54, 21, 89, 125, 3};	// create and populate array

	arrayOne[0] = 20;	// assigns 20 to index 0 of arrayOne

### Create, populate, and print an array with a loop

	int array[5];

    for (int i = 0; i < 5; i++)
    {
        array[i] = i + 1;  // populate elements
        printf("Index %d: %d\n", i, array[i]);  // print elements
    }

### To determine how many elements are in an array we can use the sizeof() function:

	elements = sizeof(my_array) / sizeof(int);

### Passing to a function

You can not pass an array as a parameter in a function. You have to pass it as a pointer. The name of an array without the [] is the address of the first element in the array.

In a function, you pass the address of the array like:

	int my_array[5];

	// pass the address of the array to the function like:
	function(my_array);

	// or
	function(&my_array[0]);

	// function being called
	int function(int the_array[])
	{
		// function code here
	}

### Declare a multidimensional array

	char names[12][25];

### Declare a 3D array

	char date[100][12][31];

## Strings

A string in C is an array of characters that end with a null (\0). C doesn't have a built in data type for strings but it has a library for working with and manipulating strings called <b><string.h></b>.

	my_name[] = {“Jae Logan”};	// will have a size of 10 elements number 0 – 9.

	my_name[0] = ‘J’; 
	my_name[1] = ‘a’; 
	my_name[2] = ‘e’; 
	my_name[3] = ‘ ’;
	my_name[4] = ‘L’; 
	my_name[5] = ‘o’; 
	my_name[6] = ‘g’; 
	my_name[7] = ‘a’;
	my_name[8] = ‘n’;
	my_name[9] = ‘\0’;

### Create and print string using character array.

	char strArray[] = {"This is my string array."};
	printf("%s\n", strArray);	// Output: This is my string array.

### Common string functions

<ul>
	<li><b>strlen()</b> – returns the length of a string</li>
	<li><b>strcpy()</b> – copies a null terminated string into a variable</li>
	<li><b>strcat()</b> – concatenates strings</li>
	<li><b>strcmp()</b> – compares the values of strings</li>
</ul>

### How to use strcmp() to compare strings

Here is a quick example of how to use <b>strcmp()</b> to compare two strings. In this example if the string in <b>player_guess</b> is equal to <b>PASS</b> then a message will be printed.

	if (strcmp(player_guess, "PASS"))
    {
        printf("You passed your turn to guess.\n");
    }

### Convert string to integer

You can use the `atoi()` or `strtol()` functions from the `stdlib.h` class.

## Working with files 

### File operations

<ul>
	<li><b>fopen()</b> – Creates a new file for use or opens a new existing file for use</li>
	<li><b>fclose()</b> – Closes a file which has been opened for use</li>
	<li><b>getc()</b> – Reads a character from a file</li>
	<li><b>putc()</b> – Writes a character to a file</li>
	<li><b>fprintf()</b> – Writes a set of data values to a file</li>
	<li><b>fscanf()</b> – Reads a set of data values from a file</li>
	<li><b>getw()</b> – Reads a integer from a file</li>
	<li><b>putw()</b> – Writes an integer to the file</li>
	<li><b>fseek()</b> – Sets the position to a desired point in the file</li>
	<li><b>ftell()</b> - Gives the current position in the file</li>
</ul>

### Open a file

	FILE *pointer_to_file
	pointer_to_file = fopen("filename", "mode");

The FILE statement declares a variable <b>pointer_to_file</b> as a pointer to the datatype FILE

FILE is a structure that has been defined in the stdio.h I/O library.

When opening a file, the filename can consist of any valid Unix filename.
When we open the file for use, if the file exists it will be re-initialized and the contents lost.

The second statement also specifies the purpose for which the file has been opened. The mode provides this information:

<ul>
	<li>r - open the file for read only</li>
	<li>w - open the file for over write</li>
	<li>a - open the file for appending</li>
	<li>r+ - open the file for read and over write data at beginning</li>
	<li>w+ - open the file for read and over write</li>
	<li>a+ - open the file for read and appending</li>
</ul>

	pointer_to_file = fopen("user_data", "r");	// opens user_data file for reading

### Close a file

	fclose(pointer_to_file);	// closes user_data file that argument points to

## Structures

A structure is a ‘collection’ of one or more variables, potentially of different types that are grouped together for convenience. They contain data that defines a particular set of information. They are similar to rows of a table in a database. 

A structure name and non-structure variable can have the same name. Also member variable names that are the same can exist inside of multiple structures.

### How to create a structure

Use the keyword struct to define. The names of structures are often called structure tags.

	struct graph_point
	{
		int x, y;	// members of the structure
	};

Once the structure has been defined a new variable of the structure type can be created.

	struct graph_point point;	// create variable point with structure members x and y
	struct graph_point point = {10, 25};	// create variable and populate members

### Nesting structures

You can nest structures like using two coordinates to construct a rectangle.

	struct rectangle
	{
		// create members of rectangle struct from nested graph_point struct
		struct graph_point a;
		struct graph_point b;
	};

It is also possible to define a structure which in turn can contain another structure as a member.

	struct structure_one
	{
		int i;
		float f;
	};

	struct structure_two
	{
		char c;
		struct structure_one my_struct;
	};

	struct structure_two your_struct;

	your_struct.c = 'J';
	your_struct.my_struct.i = 4;
	your_struct.my_struct.f = 3.5;	

### Referencing structures

The structure member operator ‘.’ connects the structure name and the member name

	printf (“%d, %d”, point.x, point.y)	// prints out x and y members of struct variable point

	/* if declare a variable of struct rectangle called rect_one 
	a single member of the sub-struct graph_point can be referenced: */
	
	struct rectangle rect_one;
	rect_one.a.x;

### Using structures

The only legal operations we can perform on structures are copying the structure or assigning it as a single unit, passing its address with the unary operator ‘&’ and accessing its members

Pointers can be created using the structures type then initialized the usual way using & to point to the address:

	customer_db *cust_pointer;
	cust_pointer = &single_cust;

If you have an array of structures, you can use a pointer and increment it to step through the individual structures in the array one at a time:

	cust_pointer++;

### Structure scenario example

You run a retail store and want a database of customers. A structure can be used to create a database-like structure for each customer.

	struct customer_db
	{
		int account;
		int balance;
		char name[40];
		char address[80];
		char phone[15];
	};

Now you can create customer_db type variables:

	customer_db single_cust; 
	customer_db all_cust[75];

You can also create the variables directly after the structure.

	struct customer_db
	{
		int account;
		int balance;
		char name[40];
		char address[80];
		char phone[15];
	} single_cust, all_cust;

You can also create a structure type variable and populate it's members like previously:

	customer_db all_cust = {189654, 800, "Tom Joyner", "462 Ridge Street", "756-536-7485"};

Refer to individual members of the structures:

	single_cust.account = 354675;
	all_cust[10].name = "Brandon";

### Dereferencing structures

If you are using a pointer to a structure when you need to act on a member of the structure, you need to de-reference the pointer to the structure to return or act on the member.

You do this by using the structure de-reference operator <b>-></b>

	*struct_pointer;
	struct_pointer -> name = "Brandon";

This ‘arrow’ operator allows us to de-reference the pointer to an object with members.

You can also place a pointer in paraenthesis to dereference it as well.

	(*struct_pointer).name = "Brandon";

### Creating custom types

Using the C keyword <b>typedef</b> you can define your own data types and structures.

Here is an exmaple of defining a datatype.

	typedef int inches;	// defines a new datatype inches based on int
	inches width, height;	// inches type variables

Here is an example of defining a structure then using it.

	typedef struct
	{
		int account;
		int balance;
		char name[40];
		char address[80];
		char phone[15];
	} customer_db;

	customer_db *cust_pointer;
	cust_pointer -> name = "Brandon";