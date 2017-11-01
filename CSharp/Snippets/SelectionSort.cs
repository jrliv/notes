static int[] Sort(params int[] numbers)
{
  for (int i = 0; i < numbers.Length - 1; i++)
  {
    for (int j = i + 1; j < numbers.Length; j++)
    {
      if (numbers[i] > numbers[j])
      {
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
      }
    }
  }
  return numbers;
}

static void Print(params int[] numbers)
{
  for (int i = 0; i < numbers.Length; i++)
  {
    Console.Write("{0}", numbers[i]);
    
    if (i < (numbers.Length - 1))
    {
      Console.Write(", ");
    }
  }
}

static void Main()
{
  int[] numbers = { 12, 45, 23, -8, 200, 10, -5, 3 };
  
  Console.Write("Before sorting: ");
  Print(numbers);
  Console.WriteLine();

  numbers = Sort(numbers);
  Console.Write("After sorting: ");
  Print(numbers);
}

//  Before sorting: 12, 45, 23, -8, 200, 10, -5, 3
//  After sorting: -8, -5, 3, 10, 12, 23, 45, 200
