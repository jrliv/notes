int? x = null;
int y = x ?? 4;
Console.WriteLine(y); // 4

string str = "I like beer.";
string nullStr = null;
Console.Write("nullStr = ");
Console.WriteLine(nullStr ?? "String is null"); //  nullStr = String is null
Console.WriteLine(str ?? "String is null"); // I like beer.