int sum;
int start = Environment.TickCount;

Console.WriteLine("Hello!");
sum = 2 + 2;
Console.WriteLine("2 + 2 = " + sum);
Console.WriteLine();

int end = Environment.TickCount;
Console.WriteLine("It took {0} seconds to say hello and add 2 + 2.",
(end - start) / 1000.0);

//  Hello!
//  2 + 2 = 4

//  It took 0.016 seconds to say hello and add 2 + 2.