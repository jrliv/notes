int a = 10;
int b = 20;

Console.WriteLine("((a > b) ? (a > b) : (b <= a))  = " + ((a > b) ? "(a > b)" : "(b <= a)"));
Console.WriteLine("((a > b) ? 100 : 200)  = " + ((a > b) ? 100 : 200));
Console.WriteLine("((a < b) ? 100 : 200)  = " + ((a < b) ? 100 : 200));

//  ((a > b) ? (a > b) : (b <= a))  = (b <= a)
//  ((a > b) ? 100 : 200)  = 200
//  ((a < b) ? 100 : 200)  = 100