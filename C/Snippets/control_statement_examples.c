/* This is a program that demonstrates a simple statements including: */
/* if then else, while, do, for, break, continue, and switch          */
/* prog2.c Jan. 2005 by Ted Mims */ 

#include <stdio.h> 
main () 
{ 
  int my_integer;
  float my_float;
  char my_character;
  my_float = 20.05;
  my_integer = (int) my_float;
  // how to cast a float as integer
  printf("The integer is %d \n", my_integer);
  my_integer = (my_float > 10) ? 1000 : 500; 
  // will store 1000 in my_integer
  if ( my_float < 10 )
    {
      my_float = 100.01;
    }
  else
    {
      my_float = 300.30;
    }
 // in the if the else above the { } are not needed since there is only one
 // statement following them.   
   
 my_integer = 20;
 while ( my_integer > 0 )
   {
     my_integer = my_integer - 5;
     printf(" my integer is %d \n", my_integer);
   }
   
 for ( my_integer = 1; my_integer <= 10; my_integer++)
   {
     printf(" my_integer is %d \n", my_integer);
   }
   
 // A break statement may be used to exit a loop of switch statement
 for ( my_integer = 1; my_integer <= 10; my_integer++)
   {
     if ( my_integer > 5 ) 
       break;
     printf(" my_integer is %d \n", my_integer);
   }
 // A continue statement may be used to cause the loop counter to 
 // increment and the current iteration of the loop to be aborted
 // and the next iteration of the loop to begin.
 
 for ( my_integer = 1; my_integer <= 10; my_integer++)
   {
     if ( (my_integer > 4 ) && (my_integer < 8 ) ) 
       continue;
     printf(" my_integer is %d \n", my_integer);
   }
 
 my_character = 'f';
 while ( my_character >= 'a')
   {  
     // The switch statement
     switch (my_character)
       {
         case 'a':
           printf("my_character is %c \n", my_character);
           my_character = my_character - 1;
           break;  // note you need the break statement after each case
                   // try leaving it out and see what happens
         case 'b':
           printf("my_character is %c \n", my_character);
           my_character = my_character - 1;
           break;
         case 'c':
           printf("my_character is %c \n", my_character);
           my_character = my_character - 1;
           break;
         case 'd':
           printf("my_character is %c \n", my_character);
           my_character = my_character - 1;
           break;
         default:
          printf("my_character is %c \n", my_character);
          my_character = my_character - 1;
          break;
       } // end of the switch    
    } // end of while
 } // end of main 
 
 