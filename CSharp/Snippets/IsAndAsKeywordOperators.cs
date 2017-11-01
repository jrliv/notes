string str = "I like beer.";

Console.Write("is str a string? ");
Console.WriteLine(str is string);

//  is str a string? True

object[] objArray = new object[] { "hello", 4321, "world", 8, null };

for (int i = 0; i < objArray.Length; ++i)
{
  string strArray = objArray[i] as string;
  Console.Write("Element {0}: ", i);
  if (strArray != null)
  {
    Console.WriteLine("'" + strArray + "'");
  }
  else
  {
    Console.WriteLine("Not a string.");
  }
}

//	Element 0: 'hello'
//	Element 1: Not a string.
//	Element 2: 'world'
//	Element 3: Not a string.
//	Element 4: Not a string.