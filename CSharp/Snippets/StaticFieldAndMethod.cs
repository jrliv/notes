/* Example of how to use a static field and method to print a sequence of numbers that increments. 
From Fundamentals of Computer Programming with C# 
http://www.introprogramming.info/wp-content/uploads/2013/07/Books/CSharpEn/Fundamentals-of-Computer-Programming-with-CSharp-Nakov-eBook-v2013.pdf */
class Program
{
  static void Main(string[] args)
  {
    Console.WriteLine("Sequence[1...3]: {0}, {1}, {2}",
    Sequence.NextValue(), Sequence.NextValue(), Sequence.NextValue());
  }
}

// This is the implemented class that contains the used static field and method.
public class Sequence
{
  // Static field, holding the current sequence value
  private static int currentValue = 0;

  // Intentionally deny instantiation of this class
  private Sequence()
  { }

  // Static method for taking the next sequence value
  public static int NextValue()
  {
    currentValue++;
    return currentValue;
  }
}

//  Sequence[1...3]: 1, 2, 3